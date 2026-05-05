// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tb3_interfaces:msg/TargetInfo.idl
// generated code does not contain a copyright notice
#include "tb3_interfaces/msg/detail/target_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tb3_interfaces__msg__TargetInfo__init(tb3_interfaces__msg__TargetInfo * msg)
{
  if (!msg) {
    return false;
  }
  // locked
  // target_id
  // cx
  // cy
  // width
  // height
  return true;
}

void
tb3_interfaces__msg__TargetInfo__fini(tb3_interfaces__msg__TargetInfo * msg)
{
  if (!msg) {
    return;
  }
  // locked
  // target_id
  // cx
  // cy
  // width
  // height
}

bool
tb3_interfaces__msg__TargetInfo__are_equal(const tb3_interfaces__msg__TargetInfo * lhs, const tb3_interfaces__msg__TargetInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // locked
  if (lhs->locked != rhs->locked) {
    return false;
  }
  // target_id
  if (lhs->target_id != rhs->target_id) {
    return false;
  }
  // cx
  if (lhs->cx != rhs->cx) {
    return false;
  }
  // cy
  if (lhs->cy != rhs->cy) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  return true;
}

bool
tb3_interfaces__msg__TargetInfo__copy(
  const tb3_interfaces__msg__TargetInfo * input,
  tb3_interfaces__msg__TargetInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // locked
  output->locked = input->locked;
  // target_id
  output->target_id = input->target_id;
  // cx
  output->cx = input->cx;
  // cy
  output->cy = input->cy;
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  return true;
}

tb3_interfaces__msg__TargetInfo *
tb3_interfaces__msg__TargetInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TargetInfo * msg = (tb3_interfaces__msg__TargetInfo *)allocator.allocate(sizeof(tb3_interfaces__msg__TargetInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tb3_interfaces__msg__TargetInfo));
  bool success = tb3_interfaces__msg__TargetInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tb3_interfaces__msg__TargetInfo__destroy(tb3_interfaces__msg__TargetInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tb3_interfaces__msg__TargetInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tb3_interfaces__msg__TargetInfo__Sequence__init(tb3_interfaces__msg__TargetInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TargetInfo * data = NULL;

  if (size) {
    data = (tb3_interfaces__msg__TargetInfo *)allocator.zero_allocate(size, sizeof(tb3_interfaces__msg__TargetInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tb3_interfaces__msg__TargetInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tb3_interfaces__msg__TargetInfo__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tb3_interfaces__msg__TargetInfo__Sequence__fini(tb3_interfaces__msg__TargetInfo__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tb3_interfaces__msg__TargetInfo__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tb3_interfaces__msg__TargetInfo__Sequence *
tb3_interfaces__msg__TargetInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TargetInfo__Sequence * array = (tb3_interfaces__msg__TargetInfo__Sequence *)allocator.allocate(sizeof(tb3_interfaces__msg__TargetInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tb3_interfaces__msg__TargetInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tb3_interfaces__msg__TargetInfo__Sequence__destroy(tb3_interfaces__msg__TargetInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tb3_interfaces__msg__TargetInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tb3_interfaces__msg__TargetInfo__Sequence__are_equal(const tb3_interfaces__msg__TargetInfo__Sequence * lhs, const tb3_interfaces__msg__TargetInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tb3_interfaces__msg__TargetInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tb3_interfaces__msg__TargetInfo__Sequence__copy(
  const tb3_interfaces__msg__TargetInfo__Sequence * input,
  tb3_interfaces__msg__TargetInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tb3_interfaces__msg__TargetInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tb3_interfaces__msg__TargetInfo * data =
      (tb3_interfaces__msg__TargetInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tb3_interfaces__msg__TargetInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tb3_interfaces__msg__TargetInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tb3_interfaces__msg__TargetInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
