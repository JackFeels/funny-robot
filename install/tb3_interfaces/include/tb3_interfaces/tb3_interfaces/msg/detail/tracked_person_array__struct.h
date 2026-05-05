// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tb3_interfaces:msg/TrackedPersonArray.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__STRUCT_H_
#define TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'persons'
#include "tb3_interfaces/msg/detail/tracked_person__struct.h"

/// Struct defined in msg/TrackedPersonArray in the package tb3_interfaces.
typedef struct tb3_interfaces__msg__TrackedPersonArray
{
  tb3_interfaces__msg__TrackedPerson__Sequence persons;
} tb3_interfaces__msg__TrackedPersonArray;

// Struct for a sequence of tb3_interfaces__msg__TrackedPersonArray.
typedef struct tb3_interfaces__msg__TrackedPersonArray__Sequence
{
  tb3_interfaces__msg__TrackedPersonArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tb3_interfaces__msg__TrackedPersonArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__STRUCT_H_
