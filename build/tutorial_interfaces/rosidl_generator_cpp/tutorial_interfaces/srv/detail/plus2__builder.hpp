// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:srv/Plus2.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__PLUS2__BUILDER_HPP_
#define TUTORIAL_INTERFACES__SRV__DETAIL__PLUS2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/srv/detail/plus2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace srv
{

namespace builder
{

class Init_Plus2_Request_input2
{
public:
  Init_Plus2_Request_input2()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::srv::Plus2_Request input2(::tutorial_interfaces::srv::Plus2_Request::_input2_type arg)
  {
    msg_.input2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::Plus2_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::Plus2_Request>()
{
  return tutorial_interfaces::srv::builder::Init_Plus2_Request_input2();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace srv
{

namespace builder
{

class Init_Plus2_Response_output2
{
public:
  Init_Plus2_Response_output2()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::srv::Plus2_Response output2(::tutorial_interfaces::srv::Plus2_Response::_output2_type arg)
  {
    msg_.output2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::Plus2_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::Plus2_Response>()
{
  return tutorial_interfaces::srv::builder::Init_Plus2_Response_output2();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__PLUS2__BUILDER_HPP_
