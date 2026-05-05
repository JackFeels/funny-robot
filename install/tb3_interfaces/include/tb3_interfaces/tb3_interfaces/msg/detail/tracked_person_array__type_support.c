// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tb3_interfaces:msg/TrackedPersonArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tb3_interfaces/msg/detail/tracked_person_array__rosidl_typesupport_introspection_c.h"
#include "tb3_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tb3_interfaces/msg/detail/tracked_person_array__functions.h"
#include "tb3_interfaces/msg/detail/tracked_person_array__struct.h"


// Include directives for member types
// Member `persons`
#include "tb3_interfaces/msg/tracked_person.h"
// Member `persons`
#include "tb3_interfaces/msg/detail/tracked_person__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tb3_interfaces__msg__TrackedPersonArray__init(message_memory);
}

void tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_fini_function(void * message_memory)
{
  tb3_interfaces__msg__TrackedPersonArray__fini(message_memory);
}

size_t tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__size_function__TrackedPersonArray__persons(
  const void * untyped_member)
{
  const tb3_interfaces__msg__TrackedPerson__Sequence * member =
    (const tb3_interfaces__msg__TrackedPerson__Sequence *)(untyped_member);
  return member->size;
}

const void * tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__get_const_function__TrackedPersonArray__persons(
  const void * untyped_member, size_t index)
{
  const tb3_interfaces__msg__TrackedPerson__Sequence * member =
    (const tb3_interfaces__msg__TrackedPerson__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__get_function__TrackedPersonArray__persons(
  void * untyped_member, size_t index)
{
  tb3_interfaces__msg__TrackedPerson__Sequence * member =
    (tb3_interfaces__msg__TrackedPerson__Sequence *)(untyped_member);
  return &member->data[index];
}

void tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__fetch_function__TrackedPersonArray__persons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tb3_interfaces__msg__TrackedPerson * item =
    ((const tb3_interfaces__msg__TrackedPerson *)
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__get_const_function__TrackedPersonArray__persons(untyped_member, index));
  tb3_interfaces__msg__TrackedPerson * value =
    (tb3_interfaces__msg__TrackedPerson *)(untyped_value);
  *value = *item;
}

void tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__assign_function__TrackedPersonArray__persons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tb3_interfaces__msg__TrackedPerson * item =
    ((tb3_interfaces__msg__TrackedPerson *)
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__get_function__TrackedPersonArray__persons(untyped_member, index));
  const tb3_interfaces__msg__TrackedPerson * value =
    (const tb3_interfaces__msg__TrackedPerson *)(untyped_value);
  *item = *value;
}

bool tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__resize_function__TrackedPersonArray__persons(
  void * untyped_member, size_t size)
{
  tb3_interfaces__msg__TrackedPerson__Sequence * member =
    (tb3_interfaces__msg__TrackedPerson__Sequence *)(untyped_member);
  tb3_interfaces__msg__TrackedPerson__Sequence__fini(member);
  return tb3_interfaces__msg__TrackedPerson__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_member_array[1] = {
  {
    "persons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tb3_interfaces__msg__TrackedPersonArray, persons),  // bytes offset in struct
    NULL,  // default value
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__size_function__TrackedPersonArray__persons,  // size() function pointer
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__get_const_function__TrackedPersonArray__persons,  // get_const(index) function pointer
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__get_function__TrackedPersonArray__persons,  // get(index) function pointer
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__fetch_function__TrackedPersonArray__persons,  // fetch(index, &value) function pointer
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__assign_function__TrackedPersonArray__persons,  // assign(index, value) function pointer
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__resize_function__TrackedPersonArray__persons  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_members = {
  "tb3_interfaces__msg",  // message namespace
  "TrackedPersonArray",  // message name
  1,  // number of fields
  sizeof(tb3_interfaces__msg__TrackedPersonArray),
  tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_member_array,  // message members
  tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_init_function,  // function to initialize message memory (memory has to be allocated)
  tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_type_support_handle = {
  0,
  &tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tb3_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tb3_interfaces, msg, TrackedPersonArray)() {
  tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tb3_interfaces, msg, TrackedPerson)();
  if (!tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_type_support_handle.typesupport_identifier) {
    tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tb3_interfaces__msg__TrackedPersonArray__rosidl_typesupport_introspection_c__TrackedPersonArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
