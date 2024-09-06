// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:srv/Plus2.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__PLUS2__STRUCT_H_
#define TUTORIAL_INTERFACES__SRV__DETAIL__PLUS2__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Plus2 in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__Plus2_Request
{
  int64_t input2;
} tutorial_interfaces__srv__Plus2_Request;

// Struct for a sequence of tutorial_interfaces__srv__Plus2_Request.
typedef struct tutorial_interfaces__srv__Plus2_Request__Sequence
{
  tutorial_interfaces__srv__Plus2_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__Plus2_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Plus2 in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__Plus2_Response
{
  int64_t output2;
} tutorial_interfaces__srv__Plus2_Response;

// Struct for a sequence of tutorial_interfaces__srv__Plus2_Response.
typedef struct tutorial_interfaces__srv__Plus2_Response__Sequence
{
  tutorial_interfaces__srv__Plus2_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__Plus2_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__PLUS2__STRUCT_H_
