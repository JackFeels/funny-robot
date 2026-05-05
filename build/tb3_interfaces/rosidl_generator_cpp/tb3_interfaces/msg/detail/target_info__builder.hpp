// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tb3_interfaces:msg/TargetInfo.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__BUILDER_HPP_
#define TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tb3_interfaces/msg/detail/target_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tb3_interfaces
{

namespace msg
{

namespace builder
{

class Init_TargetInfo_height
{
public:
  explicit Init_TargetInfo_height(::tb3_interfaces::msg::TargetInfo & msg)
  : msg_(msg)
  {}
  ::tb3_interfaces::msg::TargetInfo height(::tb3_interfaces::msg::TargetInfo::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tb3_interfaces::msg::TargetInfo msg_;
};

class Init_TargetInfo_width
{
public:
  explicit Init_TargetInfo_width(::tb3_interfaces::msg::TargetInfo & msg)
  : msg_(msg)
  {}
  Init_TargetInfo_height width(::tb3_interfaces::msg::TargetInfo::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_TargetInfo_height(msg_);
  }

private:
  ::tb3_interfaces::msg::TargetInfo msg_;
};

class Init_TargetInfo_cy
{
public:
  explicit Init_TargetInfo_cy(::tb3_interfaces::msg::TargetInfo & msg)
  : msg_(msg)
  {}
  Init_TargetInfo_width cy(::tb3_interfaces::msg::TargetInfo::_cy_type arg)
  {
    msg_.cy = std::move(arg);
    return Init_TargetInfo_width(msg_);
  }

private:
  ::tb3_interfaces::msg::TargetInfo msg_;
};

class Init_TargetInfo_cx
{
public:
  explicit Init_TargetInfo_cx(::tb3_interfaces::msg::TargetInfo & msg)
  : msg_(msg)
  {}
  Init_TargetInfo_cy cx(::tb3_interfaces::msg::TargetInfo::_cx_type arg)
  {
    msg_.cx = std::move(arg);
    return Init_TargetInfo_cy(msg_);
  }

private:
  ::tb3_interfaces::msg::TargetInfo msg_;
};

class Init_TargetInfo_target_id
{
public:
  explicit Init_TargetInfo_target_id(::tb3_interfaces::msg::TargetInfo & msg)
  : msg_(msg)
  {}
  Init_TargetInfo_cx target_id(::tb3_interfaces::msg::TargetInfo::_target_id_type arg)
  {
    msg_.target_id = std::move(arg);
    return Init_TargetInfo_cx(msg_);
  }

private:
  ::tb3_interfaces::msg::TargetInfo msg_;
};

class Init_TargetInfo_locked
{
public:
  Init_TargetInfo_locked()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetInfo_target_id locked(::tb3_interfaces::msg::TargetInfo::_locked_type arg)
  {
    msg_.locked = std::move(arg);
    return Init_TargetInfo_target_id(msg_);
  }

private:
  ::tb3_interfaces::msg::TargetInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tb3_interfaces::msg::TargetInfo>()
{
  return tb3_interfaces::msg::builder::Init_TargetInfo_locked();
}

}  // namespace tb3_interfaces

#endif  // TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__BUILDER_HPP_
