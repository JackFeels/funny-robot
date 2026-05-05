// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tb3_interfaces:msg/TrackedPersonArray.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__FUNCTIONS_H_
#define TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tb3_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tb3_interfaces/msg/detail/tracked_person_array__struct.h"

/// Initialize msg/TrackedPersonArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tb3_interfaces__msg__TrackedPersonArray
 * )) before or use
 * tb3_interfaces__msg__TrackedPersonArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TrackedPersonArray__init(tb3_interfaces__msg__TrackedPersonArray * msg);

/// Finalize msg/TrackedPersonArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
void
tb3_interfaces__msg__TrackedPersonArray__fini(tb3_interfaces__msg__TrackedPersonArray * msg);

/// Create msg/TrackedPersonArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tb3_interfaces__msg__TrackedPersonArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
tb3_interfaces__msg__TrackedPersonArray *
tb3_interfaces__msg__TrackedPersonArray__create();

/// Destroy msg/TrackedPersonArray message.
/**
 * It calls
 * tb3_interfaces__msg__TrackedPersonArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
void
tb3_interfaces__msg__TrackedPersonArray__destroy(tb3_interfaces__msg__TrackedPersonArray * msg);

/// Check for msg/TrackedPersonArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TrackedPersonArray__are_equal(const tb3_interfaces__msg__TrackedPersonArray * lhs, const tb3_interfaces__msg__TrackedPersonArray * rhs);

/// Copy a msg/TrackedPersonArray message.
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
tb3_interfaces__msg__TrackedPersonArray__copy(
  const tb3_interfaces__msg__TrackedPersonArray * input,
  tb3_interfaces__msg__TrackedPersonArray * output);

/// Initialize array of msg/TrackedPersonArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * tb3_interfaces__msg__TrackedPersonArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TrackedPersonArray__Sequence__init(tb3_interfaces__msg__TrackedPersonArray__Sequence * array, size_t size);

/// Finalize array of msg/TrackedPersonArray messages.
/**
 * It calls
 * tb3_interfaces__msg__TrackedPersonArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
void
tb3_interfaces__msg__TrackedPersonArray__Sequence__fini(tb3_interfaces__msg__TrackedPersonArray__Sequence * array);

/// Create array of msg/TrackedPersonArray messages.
/**
 * It allocates the memory for the array and calls
 * tb3_interfaces__msg__TrackedPersonArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
tb3_interfaces__msg__TrackedPersonArray__Sequence *
tb3_interfaces__msg__TrackedPersonArray__Sequence__create(size_t size);

/// Destroy array of msg/TrackedPersonArray messages.
/**
 * It calls
 * tb3_interfaces__msg__TrackedPersonArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
void
tb3_interfaces__msg__TrackedPersonArray__Sequence__destroy(tb3_interfaces__msg__TrackedPersonArray__Sequence * array);

/// Check for msg/TrackedPersonArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tb3_interfaces
bool
tb3_interfaces__msg__TrackedPersonArray__Sequence__are_equal(const tb3_interfaces__msg__TrackedPersonArray__Sequence * lhs, const tb3_interfaces__msg__TrackedPersonArray__Sequence * rhs);

/// Copy an array of msg/TrackedPersonArray messages.
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
tb3_interfaces__msg__TrackedPersonArray__Sequence__copy(
  const tb3_interfaces__msg__TrackedPersonArray__Sequence * input,
  tb3_interfaces__msg__TrackedPersonArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__FUNCTIONS_H_
