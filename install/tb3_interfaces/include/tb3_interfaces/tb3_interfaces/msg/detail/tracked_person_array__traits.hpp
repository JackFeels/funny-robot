// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tb3_interfaces:msg/TrackedPersonArray.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__TRAITS_HPP_
#define TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tb3_interfaces/msg/detail/tracked_person_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'persons'
#include "tb3_interfaces/msg/detail/tracked_person__traits.hpp"

namespace tb3_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrackedPersonArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: persons
  {
    if (msg.persons.size() == 0) {
      out << "persons: []";
    } else {
      out << "persons: [";
      size_t pending_items = msg.persons.size();
      for (auto item : msg.persons) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackedPersonArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: persons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.persons.size() == 0) {
      out << "persons: []\n";
    } else {
      out << "persons:\n";
      for (auto item : msg.persons) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackedPersonArray & msg, bool use_flow_style = false)
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
  const tb3_interfaces::msg::TrackedPersonArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  tb3_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tb3_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tb3_interfaces::msg::TrackedPersonArray & msg)
{
  return tb3_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tb3_interfaces::msg::TrackedPersonArray>()
{
  return "tb3_interfaces::msg::TrackedPersonArray";
}

template<>
inline const char * name<tb3_interfaces::msg::TrackedPersonArray>()
{
  return "tb3_interfaces/msg/TrackedPersonArray";
}

template<>
struct has_fixed_size<tb3_interfaces::msg::TrackedPersonArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tb3_interfaces::msg::TrackedPersonArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tb3_interfaces::msg::TrackedPersonArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__TRAITS_HPP_
