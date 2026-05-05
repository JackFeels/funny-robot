// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tb3_interfaces:msg/TrackedPerson.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__TRAITS_HPP_
#define TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tb3_interfaces/msg/detail/tracked_person__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tb3_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrackedPerson & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: cx
  {
    out << "cx: ";
    rosidl_generator_traits::value_to_yaml(msg.cx, out);
    out << ", ";
  }

  // member: cy
  {
    out << "cy: ";
    rosidl_generator_traits::value_to_yaml(msg.cy, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: score
  {
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackedPerson & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: cx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cx: ";
    rosidl_generator_traits::value_to_yaml(msg.cx, out);
    out << "\n";
  }

  // member: cy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cy: ";
    rosidl_generator_traits::value_to_yaml(msg.cy, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackedPerson & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tb3_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tb3_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tb3_interfaces::msg::TrackedPerson & msg,
  std::ostream & out, size_t indentation = 0)
{
  tb3_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tb3_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tb3_interfaces::msg::TrackedPerson & msg)
{
  return tb3_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tb3_interfaces::msg::TrackedPerson>()
{
  return "tb3_interfaces::msg::TrackedPerson";
}

template<>
inline const char * name<tb3_interfaces::msg::TrackedPerson>()
{
  return "tb3_interfaces/msg/TrackedPerson";
}

template<>
struct has_fixed_size<tb3_interfaces::msg::TrackedPerson>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tb3_interfaces::msg::TrackedPerson>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tb3_interfaces::msg::TrackedPerson>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON__TRAITS_HPP_
