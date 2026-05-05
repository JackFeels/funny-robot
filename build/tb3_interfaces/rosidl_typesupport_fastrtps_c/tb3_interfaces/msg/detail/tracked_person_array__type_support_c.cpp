// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tb3_interfaces:msg/TrackedPersonArray.idl
// generated code does not contain a copyright notice
#include "tb3_interfaces/msg/detail/tracked_person_array__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tb3_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tb3_interfaces/msg/detail/tracked_person_array__struct.h"
#include "tb3_interfaces/msg/detail/tracked_person_array__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "tb3_interfaces/msg/detail/tracked_person__functions.h"  // persons

// forward declare type support functions
size_t get_serialized_size_tb3_interfaces__msg__TrackedPerson(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tb3_interfaces__msg__TrackedPerson(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tb3_interfaces, msg, TrackedPerson)();


using _TrackedPersonArray__ros_msg_type = tb3_interfaces__msg__TrackedPersonArray;

static bool _TrackedPersonArray__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TrackedPersonArray__ros_msg_type * ros_message = static_cast<const _TrackedPersonArray__ros_msg_type *>(untyped_ros_message);
  // Field name: persons
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tb3_interfaces, msg, TrackedPerson
      )()->data);
    size_t size = ros_message->persons.size;
    auto array_ptr = ros_message->persons.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _TrackedPersonArray__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TrackedPersonArray__ros_msg_type * ros_message = static_cast<_TrackedPersonArray__ros_msg_type *>(untyped_ros_message);
  // Field name: persons
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, tb3_interfaces, msg, TrackedPerson
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->persons.data) {
      tb3_interfaces__msg__TrackedPerson__Sequence__fini(&ros_message->persons);
    }
    if (!tb3_interfaces__msg__TrackedPerson__Sequence__init(&ros_message->persons, size)) {
      fprintf(stderr, "failed to create array for field 'persons'");
      return false;
    }
    auto array_ptr = ros_message->persons.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tb3_interfaces
size_t get_serialized_size_tb3_interfaces__msg__TrackedPersonArray(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TrackedPersonArray__ros_msg_type * ros_message = static_cast<const _TrackedPersonArray__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name persons
  {
    size_t array_size = ros_message->persons.size;
    auto array_ptr = ros_message->persons.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_tb3_interfaces__msg__TrackedPerson(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TrackedPersonArray__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tb3_interfaces__msg__TrackedPersonArray(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tb3_interfaces
size_t max_serialized_size_tb3_interfaces__msg__TrackedPersonArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: persons
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_tb3_interfaces__msg__TrackedPerson(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tb3_interfaces__msg__TrackedPersonArray;
    is_plain =
      (
      offsetof(DataType, persons) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TrackedPersonArray__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tb3_interfaces__msg__TrackedPersonArray(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TrackedPersonArray = {
  "tb3_interfaces::msg",
  "TrackedPersonArray",
  _TrackedPersonArray__cdr_serialize,
  _TrackedPersonArray__cdr_deserialize,
  _TrackedPersonArray__get_serialized_size,
  _TrackedPersonArray__max_serialized_size
};

static rosidl_message_type_support_t _TrackedPersonArray__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TrackedPersonArray,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tb3_interfaces, msg, TrackedPersonArray)() {
  return &_TrackedPersonArray__type_support;
}

#if defined(__cplusplus)
}
#endif
