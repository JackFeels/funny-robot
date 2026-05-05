// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tb3_interfaces:msg/TrackedPerson.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__STRUCT_H_
#define TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TrackedPerson in the package tb3_interfaces.
typedef struct tb3_interfaces__msg__TrackedPerson
{
  int32_t id;
  float cx;
  float cy;
  float width;
  float height;
  float score;
} tb3_interfaces__msg__TrackedPerson;

// Struct for a sequence of tb3_interfaces__msg__TrackedPerson.
typedef struct tb3_interfaces__msg__TrackedPerson__Sequence
{
  tb3_interfaces__msg__TrackedPerson * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tb3_interfaces__msg__TrackedPerson__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__STRUCT_H_
