// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tb3_interfaces:msg/TrackedPerson.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__BUILDER_HPP_
#define TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tb3_interfaces/msg/detail/tracked_person__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tb3_interfaces
{

namespace msg
{

namespace builder
{

class Init_TrackedPerson_score
{
public:
  explicit Init_TrackedPerson_score(::tb3_interfaces::msg::TrackedPerson & msg)
  : msg_(msg)
  {}
  ::tb3_interfaces::msg::TrackedPerson score(::tb3_interfaces::msg::TrackedPerson::_score_type arg)
  {
    msg_.score = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tb3_interfaces::msg::TrackedPerson msg_;
};

class Init_TrackedPerson_height
{
public:
  explicit Init_TrackedPerson_height(::tb3_interfaces::msg::TrackedPerson & msg)
  : msg_(msg)
  {}
  Init_TrackedPerson_score height(::tb3_interfaces::msg::TrackedPerson::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_TrackedPerson_score(msg_);
  }

private:
  ::tb3_interfaces::msg::TrackedPerson msg_;
};

class Init_TrackedPerson_width
{
public:
  explicit Init_TrackedPerson_width(::tb3_interfaces::msg::TrackedPerson & msg)
  : msg_(msg)
  {}
  Init_TrackedPerson_height width(::tb3_interfaces::msg::TrackedPerson::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_TrackedPerson_height(msg_);
  }

private:
  ::tb3_interfaces::msg::TrackedPerson msg_;
};

class Init_TrackedPerson_cy
{
public:
  explicit Init_TrackedPerson_cy(::tb3_interfaces::msg::TrackedPerson & msg)
  : msg_(msg)
  {}
  Init_TrackedPerson_width cy(::tb3_interfaces::msg::TrackedPerson::_cy_type arg)
  {
    msg_.cy = std::move(arg);
    return Init_TrackedPerson_width(msg_);
  }

private:
  ::tb3_interfaces::msg::TrackedPerson msg_;
};

class Init_TrackedPerson_cx
{
public:
  explicit Init_TrackedPerson_cx(::tb3_interfaces::msg::TrackedPerson & msg)
  : msg_(msg)
  {}
  Init_TrackedPerson_cy cx(::tb3_interfaces::msg::TrackedPerson::_cx_type arg)
  {
    msg_.cx = std::move(arg);
    return Init_TrackedPerson_cy(msg_);
  }

private:
  ::tb3_interfaces::msg::TrackedPerson msg_;
};

class Init_TrackedPerson_id
{
public:
  Init_TrackedPerson_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackedPerson_cx id(::tb3_interfaces::msg::TrackedPerson::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_TrackedPerson_cx(msg_);
  }

private:
  ::tb3_interfaces::msg::TrackedPerson msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tb3_interfaces::msg::TrackedPerson>()
{
  return tb3_interfaces::msg::builder::Init_TrackedPerson_id();
}

}  // namespace tb3_interfaces

#endif  // TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__BUILDER_HPP_
