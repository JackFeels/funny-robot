// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tb3_interfaces:msg/TargetInfo.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__STRUCT_H_
#define TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TargetInfo in the package tb3_interfaces.
typedef struct tb3_interfaces__msg__TargetInfo
{
  bool locked;
  int32_t target_id;
  float cx;
  float cy;
  float width;
  float height;
} tb3_interfaces__msg__TargetInfo;

// Struct for a sequence of tb3_interfaces__msg__TargetInfo.
typedef struct tb3_interfaces__msg__TargetInfo__Sequence
{
  tb3_interfaces__msg__TargetInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tb3_interfaces__msg__TargetInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__STRUCT_H_
