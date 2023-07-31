// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from turtlebot4_msgs:msg/UserDisplay.idl
// generated code does not contain a copyright notice

#ifndef TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__FUNCTIONS_H_
#define TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "turtlebot4_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "turtlebot4_msgs/msg/detail/user_display__struct.h"

/// Initialize msg/UserDisplay message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turtlebot4_msgs__msg__UserDisplay
 * )) before or use
 * turtlebot4_msgs__msg__UserDisplay__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
bool
turtlebot4_msgs__msg__UserDisplay__init(turtlebot4_msgs__msg__UserDisplay * msg);

/// Finalize msg/UserDisplay message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
void
turtlebot4_msgs__msg__UserDisplay__fini(turtlebot4_msgs__msg__UserDisplay * msg);

/// Create msg/UserDisplay message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turtlebot4_msgs__msg__UserDisplay__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
turtlebot4_msgs__msg__UserDisplay *
turtlebot4_msgs__msg__UserDisplay__create();

/// Destroy msg/UserDisplay message.
/**
 * It calls
 * turtlebot4_msgs__msg__UserDisplay__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
void
turtlebot4_msgs__msg__UserDisplay__destroy(turtlebot4_msgs__msg__UserDisplay * msg);

/// Check for msg/UserDisplay message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
bool
turtlebot4_msgs__msg__UserDisplay__are_equal(const turtlebot4_msgs__msg__UserDisplay * lhs, const turtlebot4_msgs__msg__UserDisplay * rhs);

/// Copy a msg/UserDisplay message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
bool
turtlebot4_msgs__msg__UserDisplay__copy(
  const turtlebot4_msgs__msg__UserDisplay * input,
  turtlebot4_msgs__msg__UserDisplay * output);

/// Initialize array of msg/UserDisplay messages.
/**
 * It allocates the memory for the number of elements and calls
 * turtlebot4_msgs__msg__UserDisplay__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
bool
turtlebot4_msgs__msg__UserDisplay__Sequence__init(turtlebot4_msgs__msg__UserDisplay__Sequence * array, size_t size);

/// Finalize array of msg/UserDisplay messages.
/**
 * It calls
 * turtlebot4_msgs__msg__UserDisplay__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
void
turtlebot4_msgs__msg__UserDisplay__Sequence__fini(turtlebot4_msgs__msg__UserDisplay__Sequence * array);

/// Create array of msg/UserDisplay messages.
/**
 * It allocates the memory for the array and calls
 * turtlebot4_msgs__msg__UserDisplay__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
turtlebot4_msgs__msg__UserDisplay__Sequence *
turtlebot4_msgs__msg__UserDisplay__Sequence__create(size_t size);

/// Destroy array of msg/UserDisplay messages.
/**
 * It calls
 * turtlebot4_msgs__msg__UserDisplay__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
void
turtlebot4_msgs__msg__UserDisplay__Sequence__destroy(turtlebot4_msgs__msg__UserDisplay__Sequence * array);

/// Check for msg/UserDisplay message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
bool
turtlebot4_msgs__msg__UserDisplay__Sequence__are_equal(const turtlebot4_msgs__msg__UserDisplay__Sequence * lhs, const turtlebot4_msgs__msg__UserDisplay__Sequence * rhs);

/// Copy an array of msg/UserDisplay messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turtlebot4_msgs
bool
turtlebot4_msgs__msg__UserDisplay__Sequence__copy(
  const turtlebot4_msgs__msg__UserDisplay__Sequence * input,
  turtlebot4_msgs__msg__UserDisplay__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TURTLEBOT4_MSGS__MSG__DETAIL__USER_DISPLAY__FUNCTIONS_H_
