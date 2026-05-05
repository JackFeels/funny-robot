// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tb3_interfaces:msg/TargetInfo.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__STRUCT_HPP_
#define TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tb3_interfaces__msg__TargetInfo __attribute__((deprecated))
#else
# define DEPRECATED__tb3_interfaces__msg__TargetInfo __declspec(deprecated)
#endif

namespace tb3_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TargetInfo_
{
  using Type = TargetInfo_<ContainerAllocator>;

  explicit TargetInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->locked = false;
      this->target_id = 0l;
      this->cx = 0.0f;
      this->cy = 0.0f;
      this->width = 0.0f;
      this->height = 0.0f;
    }
  }

  explicit TargetInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->locked = false;
      this->target_id = 0l;
      this->cx = 0.0f;
      this->cy = 0.0f;
      this->width = 0.0f;
      this->height = 0.0f;
    }
  }

  // field types and members
  using _locked_type =
    bool;
  _locked_type locked;
  using _target_id_type =
    int32_t;
  _target_id_type target_id;
  using _cx_type =
    float;
  _cx_type cx;
  using _cy_type =
    float;
  _cy_type cy;
  using _width_type =
    float;
  _width_type width;
  using _height_type =
    float;
  _height_type height;

  // setters for named parameter idiom
  Type & set__locked(
    const bool & _arg)
  {
    this->locked = _arg;
    return *this;
  }
  Type & set__target_id(
    const int32_t & _arg)
  {
    this->target_id = _arg;
    return *this;
  }
  Type & set__cx(
    const float & _arg)
  {
    this->cx = _arg;
    return *this;
  }
  Type & set__cy(
    const float & _arg)
  {
    this->cy = _arg;
    return *this;
  }
  Type & set__width(
    const float & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const float & _arg)
  {
    this->height = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tb3_interfaces::msg::TargetInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const tb3_interfaces::msg::TargetInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tb3_interfaces::msg::TargetInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tb3_interfaces::msg::TargetInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tb3_interfaces::msg::TargetInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tb3_interfaces::msg::TargetInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tb3_interfaces::msg::TargetInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tb3_interfaces::msg::TargetInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tb3_interfaces::msg::TargetInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tb3_interfaces::msg::TargetInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tb3_interfaces__msg__TargetInfo
    std::shared_ptr<tb3_interfaces::msg::TargetInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tb3_interfaces__msg__TargetInfo
    std::shared_ptr<tb3_interfaces::msg::TargetInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetInfo_ & other) const
  {
    if (this->locked != other.locked) {
      return false;
    }
    if (this->target_id != other.target_id) {
      return false;
    }
    if (this->cx != other.cx) {
      return false;
    }
    if (this->cy != other.cy) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetInfo_

// alias to use template instance with default allocator
using TargetInfo =
  tb3_interfaces::msg::TargetInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tb3_interfaces

#endif  // TB3_INTERFACES__MSG__DETAIL__TARGET_INFO__STRUCT_HPP_
