// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tb3_interfaces:msg/TrackedPerson.idl
// generated code does not contain a copyright notice
#include "tb3_interfaces/msg/detail/tracked_person__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tb3_interfaces__msg__TrackedPerson__init(tb3_interfaces__msg__TrackedPerson * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // cx
  // cy
  // width
  // height
  // score
  return true;
}

void
tb3_interfaces__msg__TrackedPerson__fini(tb3_interfaces__msg__TrackedPerson * msg)
{
  if (!msg) {
    return;
  }
  // id
  // cx
  // cy
  // width
  // height
  // score
}

bool
tb3_interfaces__msg__TrackedPerson__are_equal(const tb3_interfaces__msg__TrackedPerson * lhs, const tb3_interfaces__msg__TrackedPerson * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
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
  // score
  if (lhs->score != rhs->score) {
    return false;
  }
  return true;
}

bool
tb3_interfaces__msg__TrackedPerson__copy(
  const tb3_interfaces__msg__TrackedPerson * input,
  tb3_interfaces__msg__TrackedPerson * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // cx
  output->cx = input->cx;
  // cy
  output->cy = input->cy;
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  // score
  output->score = input->score;
  return true;
}

tb3_interfaces__msg__TrackedPerson *
tb3_interfaces__msg__TrackedPerson__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TrackedPerson * msg = (tb3_interfaces__msg__TrackedPerson *)allocator.allocate(sizeof(tb3_interfaces__msg__TrackedPerson), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tb3_interfaces__msg__TrackedPerson));
  bool success = tb3_interfaces__msg__TrackedPerson__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tb3_interfaces__msg__TrackedPerson__destroy(tb3_interfaces__msg__TrackedPerson * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tb3_interfaces__msg__TrackedPerson__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tb3_interfaces__msg__TrackedPerson__Sequence__init(tb3_interfaces__msg__TrackedPerson__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TrackedPerson * data = NULL;

  if (size) {
    data = (tb3_interfaces__msg__TrackedPerson *)allocator.zero_allocate(size, sizeof(tb3_interfaces__msg__TrackedPerson), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tb3_interfaces__msg__TrackedPerson__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tb3_interfaces__msg__TrackedPerson__fini(&data[i - 1]);
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
tb3_interfaces__msg__TrackedPerson__Sequence__fini(tb3_interfaces__msg__TrackedPerson__Sequence * array)
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
      tb3_interfaces__msg__TrackedPerson__fini(&array->data[i]);
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

tb3_interfaces__msg__TrackedPerson__Sequence *
tb3_interfaces__msg__TrackedPerson__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TrackedPerson__Sequence * array = (tb3_interfaces__msg__TrackedPerson__Sequence *)allocator.allocate(sizeof(tb3_interfaces__msg__TrackedPerson__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tb3_interfaces__msg__TrackedPerson__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tb3_interfaces__msg__TrackedPerson__Sequence__destroy(tb3_interfaces__msg__TrackedPerson__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tb3_interfaces__msg__TrackedPerson__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tb3_interfaces__msg__TrackedPerson__Sequence__are_equal(const tb3_interfaces__msg__TrackedPerson__Sequence * lhs, const tb3_interfaces__msg__TrackedPerson__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tb3_interfaces__msg__TrackedPerson__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tb3_interfaces__msg__TrackedPerson__Sequence__copy(
  const tb3_interfaces__msg__TrackedPerson__Sequence * input,
  tb3_interfaces__msg__TrackedPerson__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tb3_interfaces__msg__TrackedPerson);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tb3_interfaces__msg__TrackedPerson * data =
      (tb3_interfaces__msg__TrackedPerson *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tb3_interfaces__msg__TrackedPerson__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tb3_interfaces__msg__TrackedPerson__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tb3_interfaces__msg__TrackedPerson__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
