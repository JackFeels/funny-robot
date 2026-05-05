// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tb3_interfaces:msg/TrackedPersonArray.idl
// generated code does not contain a copyright notice
#include "tb3_interfaces/msg/detail/tracked_person_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `persons`
#include "tb3_interfaces/msg/detail/tracked_person__functions.h"

bool
tb3_interfaces__msg__TrackedPersonArray__init(tb3_interfaces__msg__TrackedPersonArray * msg)
{
  if (!msg) {
    return false;
  }
  // persons
  if (!tb3_interfaces__msg__TrackedPerson__Sequence__init(&msg->persons, 0)) {
    tb3_interfaces__msg__TrackedPersonArray__fini(msg);
    return false;
  }
  return true;
}

void
tb3_interfaces__msg__TrackedPersonArray__fini(tb3_interfaces__msg__TrackedPersonArray * msg)
{
  if (!msg) {
    return;
  }
  // persons
  tb3_interfaces__msg__TrackedPerson__Sequence__fini(&msg->persons);
}

bool
tb3_interfaces__msg__TrackedPersonArray__are_equal(const tb3_interfaces__msg__TrackedPersonArray * lhs, const tb3_interfaces__msg__TrackedPersonArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // persons
  if (!tb3_interfaces__msg__TrackedPerson__Sequence__are_equal(
      &(lhs->persons), &(rhs->persons)))
  {
    return false;
  }
  return true;
}

bool
tb3_interfaces__msg__TrackedPersonArray__copy(
  const tb3_interfaces__msg__TrackedPersonArray * input,
  tb3_interfaces__msg__TrackedPersonArray * output)
{
  if (!input || !output) {
    return false;
  }
  // persons
  if (!tb3_interfaces__msg__TrackedPerson__Sequence__copy(
      &(input->persons), &(output->persons)))
  {
    return false;
  }
  return true;
}

tb3_interfaces__msg__TrackedPersonArray *
tb3_interfaces__msg__TrackedPersonArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TrackedPersonArray * msg = (tb3_interfaces__msg__TrackedPersonArray *)allocator.allocate(sizeof(tb3_interfaces__msg__TrackedPersonArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tb3_interfaces__msg__TrackedPersonArray));
  bool success = tb3_interfaces__msg__TrackedPersonArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tb3_interfaces__msg__TrackedPersonArray__destroy(tb3_interfaces__msg__TrackedPersonArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tb3_interfaces__msg__TrackedPersonArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tb3_interfaces__msg__TrackedPersonArray__Sequence__init(tb3_interfaces__msg__TrackedPersonArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TrackedPersonArray * data = NULL;

  if (size) {
    data = (tb3_interfaces__msg__TrackedPersonArray *)allocator.zero_allocate(size, sizeof(tb3_interfaces__msg__TrackedPersonArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tb3_interfaces__msg__TrackedPersonArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tb3_interfaces__msg__TrackedPersonArray__fini(&data[i - 1]);
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
tb3_interfaces__msg__TrackedPersonArray__Sequence__fini(tb3_interfaces__msg__TrackedPersonArray__Sequence * array)
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
      tb3_interfaces__msg__TrackedPersonArray__fini(&array->data[i]);
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

tb3_interfaces__msg__TrackedPersonArray__Sequence *
tb3_interfaces__msg__TrackedPersonArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tb3_interfaces__msg__TrackedPersonArray__Sequence * array = (tb3_interfaces__msg__TrackedPersonArray__Sequence *)allocator.allocate(sizeof(tb3_interfaces__msg__TrackedPersonArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tb3_interfaces__msg__TrackedPersonArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tb3_interfaces__msg__TrackedPersonArray__Sequence__destroy(tb3_interfaces__msg__TrackedPersonArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tb3_interfaces__msg__TrackedPersonArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tb3_interfaces__msg__TrackedPersonArray__Sequence__are_equal(const tb3_interfaces__msg__TrackedPersonArray__Sequence * lhs, const tb3_interfaces__msg__TrackedPersonArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tb3_interfaces__msg__TrackedPersonArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tb3_interfaces__msg__TrackedPersonArray__Sequence__copy(
  const tb3_interfaces__msg__TrackedPersonArray__Sequence * input,
  tb3_interfaces__msg__TrackedPersonArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tb3_interfaces__msg__TrackedPersonArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tb3_interfaces__msg__TrackedPersonArray * data =
      (tb3_interfaces__msg__TrackedPersonArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tb3_interfaces__msg__TrackedPersonArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tb3_interfaces__msg__TrackedPersonArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tb3_interfaces__msg__TrackedPersonArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
