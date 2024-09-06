// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:srv/Plus.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__PLUS__STRUCT_H_
#define TUTORIAL_INTERFACES__SRV__DETAIL__PLUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Plus in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__Plus_Request
{
  int64_t input;
} tutorial_interfaces__srv__Plus_Request;

// Struct for a sequence of tutorial_interfaces__srv__Plus_Request.
typedef struct tutorial_interfaces__srv__Plus_Request__Sequence
{
  tutorial_interfaces__srv__Plus_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__Plus_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Plus in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__Plus_Response
{
  int64_t output;
} tutorial_interfaces__srv__Plus_Response;

// Struct for a sequence of tutorial_interfaces__srv__Plus_Response.
typedef struct tutorial_interfaces__srv__Plus_Response__Sequence
{
  tutorial_interfaces__srv__Plus_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__Plus_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__PLUS__STRUCT_H_
