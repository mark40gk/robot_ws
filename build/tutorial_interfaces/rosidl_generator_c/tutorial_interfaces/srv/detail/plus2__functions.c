// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:srv/Plus2.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/srv/detail/plus2__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
tutorial_interfaces__srv__Plus2_Request__init(tutorial_interfaces__srv__Plus2_Request * msg)
{
  if (!msg) {
    return false;
  }
  // input2
  return true;
}

void
tutorial_interfaces__srv__Plus2_Request__fini(tutorial_interfaces__srv__Plus2_Request * msg)
{
  if (!msg) {
    return;
  }
  // input2
}

bool
tutorial_interfaces__srv__Plus2_Request__are_equal(const tutorial_interfaces__srv__Plus2_Request * lhs, const tutorial_interfaces__srv__Plus2_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // input2
  if (lhs->input2 != rhs->input2) {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__srv__Plus2_Request__copy(
  const tutorial_interfaces__srv__Plus2_Request * input,
  tutorial_interfaces__srv__Plus2_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // input2
  output->input2 = input->input2;
  return true;
}

tutorial_interfaces__srv__Plus2_Request *
tutorial_interfaces__srv__Plus2_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__Plus2_Request * msg = (tutorial_interfaces__srv__Plus2_Request *)allocator.allocate(sizeof(tutorial_interfaces__srv__Plus2_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__srv__Plus2_Request));
  bool success = tutorial_interfaces__srv__Plus2_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__srv__Plus2_Request__destroy(tutorial_interfaces__srv__Plus2_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__srv__Plus2_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__srv__Plus2_Request__Sequence__init(tutorial_interfaces__srv__Plus2_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__Plus2_Request * data = NULL;

  if (size) {
    data = (tutorial_interfaces__srv__Plus2_Request *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__srv__Plus2_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__srv__Plus2_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__srv__Plus2_Request__fini(&data[i - 1]);
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
tutorial_interfaces__srv__Plus2_Request__Sequence__fini(tutorial_interfaces__srv__Plus2_Request__Sequence * array)
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
      tutorial_interfaces__srv__Plus2_Request__fini(&array->data[i]);
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

tutorial_interfaces__srv__Plus2_Request__Sequence *
tutorial_interfaces__srv__Plus2_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__Plus2_Request__Sequence * array = (tutorial_interfaces__srv__Plus2_Request__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__srv__Plus2_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__srv__Plus2_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__srv__Plus2_Request__Sequence__destroy(tutorial_interfaces__srv__Plus2_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__srv__Plus2_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__srv__Plus2_Request__Sequence__are_equal(const tutorial_interfaces__srv__Plus2_Request__Sequence * lhs, const tutorial_interfaces__srv__Plus2_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__srv__Plus2_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__srv__Plus2_Request__Sequence__copy(
  const tutorial_interfaces__srv__Plus2_Request__Sequence * input,
  tutorial_interfaces__srv__Plus2_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__srv__Plus2_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__srv__Plus2_Request * data =
      (tutorial_interfaces__srv__Plus2_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__srv__Plus2_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__srv__Plus2_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__srv__Plus2_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
tutorial_interfaces__srv__Plus2_Response__init(tutorial_interfaces__srv__Plus2_Response * msg)
{
  if (!msg) {
    return false;
  }
  // output2
  return true;
}

void
tutorial_interfaces__srv__Plus2_Response__fini(tutorial_interfaces__srv__Plus2_Response * msg)
{
  if (!msg) {
    return;
  }
  // output2
}

bool
tutorial_interfaces__srv__Plus2_Response__are_equal(const tutorial_interfaces__srv__Plus2_Response * lhs, const tutorial_interfaces__srv__Plus2_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // output2
  if (lhs->output2 != rhs->output2) {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__srv__Plus2_Response__copy(
  const tutorial_interfaces__srv__Plus2_Response * input,
  tutorial_interfaces__srv__Plus2_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // output2
  output->output2 = input->output2;
  return true;
}

tutorial_interfaces__srv__Plus2_Response *
tutorial_interfaces__srv__Plus2_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__Plus2_Response * msg = (tutorial_interfaces__srv__Plus2_Response *)allocator.allocate(sizeof(tutorial_interfaces__srv__Plus2_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__srv__Plus2_Response));
  bool success = tutorial_interfaces__srv__Plus2_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__srv__Plus2_Response__destroy(tutorial_interfaces__srv__Plus2_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__srv__Plus2_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__srv__Plus2_Response__Sequence__init(tutorial_interfaces__srv__Plus2_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__Plus2_Response * data = NULL;

  if (size) {
    data = (tutorial_interfaces__srv__Plus2_Response *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__srv__Plus2_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__srv__Plus2_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__srv__Plus2_Response__fini(&data[i - 1]);
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
tutorial_interfaces__srv__Plus2_Response__Sequence__fini(tutorial_interfaces__srv__Plus2_Response__Sequence * array)
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
      tutorial_interfaces__srv__Plus2_Response__fini(&array->data[i]);
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

tutorial_interfaces__srv__Plus2_Response__Sequence *
tutorial_interfaces__srv__Plus2_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__Plus2_Response__Sequence * array = (tutorial_interfaces__srv__Plus2_Response__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__srv__Plus2_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__srv__Plus2_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__srv__Plus2_Response__Sequence__destroy(tutorial_interfaces__srv__Plus2_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__srv__Plus2_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__srv__Plus2_Response__Sequence__are_equal(const tutorial_interfaces__srv__Plus2_Response__Sequence * lhs, const tutorial_interfaces__srv__Plus2_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__srv__Plus2_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__srv__Plus2_Response__Sequence__copy(
  const tutorial_interfaces__srv__Plus2_Response__Sequence * input,
  tutorial_interfaces__srv__Plus2_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__srv__Plus2_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__srv__Plus2_Response * data =
      (tutorial_interfaces__srv__Plus2_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__srv__Plus2_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__srv__Plus2_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__srv__Plus2_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
