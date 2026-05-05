// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tb3_interfaces:msg/TrackedPersonArray.idl
// generated code does not contain a copyright notice

#ifndef TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__STRUCT_HPP_
#define TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'persons'
#include "tb3_interfaces/msg/detail/tracked_person__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tb3_interfaces__msg__TrackedPersonArray __attribute__((deprecated))
#else
# define DEPRECATED__tb3_interfaces__msg__TrackedPersonArray __declspec(deprecated)
#endif

namespace tb3_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrackedPersonArray_
{
  using Type = TrackedPersonArray_<ContainerAllocator>;

  explicit TrackedPersonArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit TrackedPersonArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _persons_type =
    std::vector<tb3_interfaces::msg::TrackedPerson_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tb3_interfaces::msg::TrackedPerson_<ContainerAllocator>>>;
  _persons_type persons;

  // setters for named parameter idiom
  Type & set__persons(
    const std::vector<tb3_interfaces::msg::TrackedPerson_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tb3_interfaces::msg::TrackedPerson_<ContainerAllocator>>> & _arg)
  {
    this->persons = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tb3_interfaces__msg__TrackedPersonArray
    std::shared_ptr<tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tb3_interfaces__msg__TrackedPersonArray
    std::shared_ptr<tb3_interfaces::msg::TrackedPersonArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackedPersonArray_ & other) const
  {
    if (this->persons != other.persons) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackedPersonArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackedPersonArray_

// alias to use template instance with default allocator
using TrackedPersonArray =
  tb3_interfaces::msg::TrackedPersonArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tb3_interfaces

#endif  // TB3_INTERFACES__MSG__DETAIL__TRACKED_PERSON_ARRAY__STRUCT_HPP_
