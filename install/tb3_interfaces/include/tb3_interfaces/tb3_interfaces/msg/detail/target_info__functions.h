// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tb3_interfaces:msg/TargetInfo.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__FUNCTIONS_H_
#define TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tb3_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tb3_interfaces/msg/detail/target_info__struct.h"

/// Initialize msg/TargetInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tb3_interfaces__msg__TargetInfo
 * )) before or use
 * tb3_interfaces__msg__TargetInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TargetInfo__init(tb3_interfaces__msg__TargetInfo * msg);

/// Finalize msg/TargetInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
void
tb3_interfaces__msg__TargetInfo__fini(tb3_interfaces__msg__TargetInfo * msg);

/// Create msg/TargetInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tb3_interfaces__msg__TargetInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
tb3_interfaces__msg__TargetInfo *
tb3_interfaces__msg__TargetInfo__create();

/// Destroy msg/TargetInfo message.
/**
 * It calls
 * tb3_interfaces__msg__TargetInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
void
tb3_interfaces__msg__TargetInfo__destroy(tb3_interfaces__msg__TargetInfo * msg);

/// Check for msg/TargetInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TargetInfo__are_equal(const tb3_interfaces__msg__TargetInfo * lhs, const tb3_interfaces__msg__TargetInfo * rhs);

/// Copy a msg/TargetInfo message.
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
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TargetInfo__copy(
  const tb3_interfaces__msg__TargetInfo * input,
  tb3_interfaces__msg__TargetInfo * output);

/// Initialize array of msg/TargetInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * tb3_interfaces__msg__TargetInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TargetInfo__Sequence__init(tb3_interfaces__msg__TargetInfo__Sequence * array, size_t size);

/// Finalize array of msg/TargetInfo messages.
/**
 * It calls
 * tb3_interfaces__msg__TargetInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
void
tb3_interfaces__msg__TargetInfo__Sequence__fini(tb3_interfaces__msg__TargetInfo__Sequence * array);

/// Create array of msg/TargetInfo messages.
/**
 * It allocates the memory for the array and calls
 * tb3_interfaces__msg__TargetInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
tb3_interfaces__msg__TargetInfo__Sequence *
tb3_interfaces__msg__TargetInfo__Sequence__create(size_t size);

/// Destroy array of msg/TargetInfo messages.
/**
 * It calls
 * tb3_interfaces__msg__TargetInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
void
tb3_interfaces__msg__TargetInfo__Sequence__destroy(tb3_interfaces__msg__TargetInfo__Sequence * array);

/// Check for msg/TargetInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TargetInfo__Sequence__are_equal(const tb3_interfaces__msg__TargetInfo__Sequence * lhs, const tb3_interfaces__msg__TargetInfo__Sequence * rhs);

/// Copy an array of msg/TargetInfo messages.
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
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TargetInfo__Sequence__copy(
  const tb3_interfaces__msg__TargetInfo__Sequence * input,
  tb3_interfaces__msg__TargetInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__FUNCTIONS_H_
