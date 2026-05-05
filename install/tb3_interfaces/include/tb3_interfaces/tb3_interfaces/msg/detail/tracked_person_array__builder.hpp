// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tb3_interfaces:msg/TrackedPersonArray.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__BUILDER_HPP_
#define TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tb3_interfaces/msg/detail/tracked_person_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tb3_interfaces
{

namespace msg
{

namespace builder
{

class Init_TrackedPersonArray_persons
{
public:
  Init_TrackedPersonArray_persons()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tb3_interfaces::msg::TrackedPersonArray persons(::tb3_interfaces::msg::TrackedPersonArray::_persons_type arg)
  {
    msg_.persons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tb3_interfaces::msg::TrackedPersonArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tb3_interfaces::msg::TrackedPersonArray>()
{
  return tb3_interfaces::msg::builder::Init_TrackedPersonArray_persons();
}

}  // namespace tb3_interfaces

#endif  // TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__BUILDER_HPP_
