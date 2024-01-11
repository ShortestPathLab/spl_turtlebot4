#include "commander_server/turtlebot4_commander.hpp"

commander_server::turtlebot4_commander::turtlebot4_commander(
    int robot_id, const std::string &ip, const std::string &port,
    const rclcpp::NodeOptions &options)
    : Node("Turtlebot4_Commander", options), ip_(ip), port_(port),
      id_(robot_id) {
  RCLCPP_INFO(this->get_logger(),
              "Starting commander_server::turtlebot4_commander");

  this->navigate_to_pose_client_ptr_ =
      rclcpp_action::create_client<NavigateToPose>(this, "/navigate_to_pose");

  // Connect to the central controller
  boost::asio::io_service io_service;
  sock_(io_service);
  try {
    sock_.connect(
        ip::tcp::endpoint(ip::address::from_string(ip_), std::stoi(port_)));
  } catch (boost::system::system_error &e) {
    RCLCPP_WARN(this->get_logger(), "Error: %s", e.what());
  }
}

Pose commander_server::turtlebot4_commander::get_request() {
  boost::system::error_code ec;

  // no need to build a string everytime should be const but lazy
  const std::string request("GET /?agent_id=" + id_ + " HTTP/1.1\r\n\r\n");
  sock_.send(buffer(request));

  std::string response;
  do {
    char buf[1024];
    size_t bytes_transferred = sock_.receive(buffer(buf), {}, ec);
    if (!ec) {
      response.append(buf, buf + bytes_transferred);
    }
  } while (!ec);

  if response
    .empty() { RCLCPP_WARN(this->get_logger(), "Response was empty"); }

  uint64_t split = response.rfind('\n', response.length());
  string data = response.substr(split, response.length() - split);
  json json_received = json::parse(data);

  // read the position from the json in format [x, y, theta]
  std::vector<json> position = json_received["position"];
  int x = position[0].get<int>();
  int y = position[1].get<int>();
  int theta = position[2].get<int>();

  return get_pose_stamped(x, y, theta);
}

void commander_server::turtlebot4_commander::post_request(Pose pose,
                                                          std::string status) {
  json::object_t payload;
  payload["agent_id"] = id_;
  payload["status"] = status;
  payload["position"] = json::array(
      {pose.pose.position.x, pose.pose.position.y, pose.pose.orientation.z});

  std::string serial_payload = payload.dump();
  std::string request(
      "POST / HTTP/1.1\r\n" + "Host: " + std::to_string(id_) + " \r\n" +
      "Connection: close\r\n" + "Accept: */*\r\n" + "User-Agent: " +
      std::to_string(id_) + "\r\n" + "Content-Type: applications/json\r\n" +
      "Content-Length: " + std::to_string(serial_payload.length()) + "\r\n" +
      "\r\n" + serial_payload);
  sock.send(buffer(request));
  do {
    char buf[1024];
    size_t bytes_transferred = sock.receive(buffer(buf), {}, ec);
    if (!ec) {
      response.append(buf, buf + bytes_transferred);
    }
  } while (!ec);

  if response
    .empty() { RCLCPP_WARN(this->get_logger(), "Response was empty"); }

  RCLCPP_INFO(this->get_logger(), "Response: %s", response);
}

void commander_server::turtlebot4_commander::navigate_to_pose(Pose pose) {
  RCLCPP_INFO(this->get_logger(), "Sending Waypoints to Robot");

  this->navigate_to_pose_send_goal(pose);
}

commander_server::Pose
commander_server::turtlebot4_commander::get_pose_stamped() {
  Pose pose = Pose();

  pose.header.frame_id = "map";
  pose.header.stamp = self.get_clock().now().to_msg();

  pose.pose.position.x = x;
  pose.pose.position.y = y;

  pose.pose.orientation.z = sin(radians(theta) / 2);
  pose.pose.orientation.w = cos(radians(theta) / 2);
  return pose;
}

void commander_server::turtlebot4_commander::navigate_to_pose_send_goal(
    Pose pose) {

  auto goal_msg = NavigateToPose::Goal();
  goal_msg.pose = pose;

  this->navigate_to_pose_client_ptr_->wait_for_action_server();

  auto send_goal_options =
      rclcpp_action::Client<NavigateToPose>::SendGoalOptions();
  send_goal_options.goal_response_callback =
      std::bind(&commander_server::turtlebot4_commander::
                    navigate_to_pose_goal_response_callback,
                this, std::placeholders::_1);
  send_goal_options.feedback_callback =
      std::bind(&commander_server::turtlebot4_commander::
                    navigate_to_pose_feedback_callback,
                this, std::placeholders::_1, std::placeholders::_2);
  send_goal_options.result_callback = std::bind(
      &commander_server::turtlebot4_commander::navigate_to_pose_result_callback,
      this, std::placeholders::_1);

  this->navigate_to_pose_client_ptr_->async_send_goal(goal_msg,
                                                      send_goal_options);
}

void commander_server::turtlebot4_commander::
    navigate_to_pose_goal_response_callback(
        const GoalHandleNavigateToPose::SharedPtr goal_handle) {

  if (!goal_handle) {
    RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
  } else {
    RCLCPP_INFO(this->get_logger(),
                "Goal accepted by server, waiting for result");
  }
}

void commander_server::turtlebot4_commander::navigate_to_pose_feedback_callback(
    GoalHandleNavigateToPose::SharedPtr,
    const std::shared_ptr<const NavigateToPose::Feedback> feedback) {
  // RCLCPP_INFO(this->get_logger(), "Waypoint Number: %d",
  // feedback->current_pose;
}

void commander_server::turtlebot4_commander::navigate_to_pose_result_callback(
    const GoalHandleNavigateToPose::WrappedResult &result) {

  switch (result.code) {
  case rclcpp_action::ResultCode::SUCCEEDED:
    RCLCPP_INFO(this->get_logger(), "Goal was successful");
    break;
  case rclcpp_action::ResultCode::ABORTED:
    RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
    return;
  case rclcpp_action::ResultCode::CANCELED:
    RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
    return;
  default:
    RCLCPP_ERROR(this->get_logger(), "Unknown result code");
    return;
  }
}

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<commander_server::turtlebot4_commander>(
      0, "192.168.0.204", "8080");

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
