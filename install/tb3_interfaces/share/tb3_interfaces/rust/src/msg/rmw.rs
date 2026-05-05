#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "tb3_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tb3_interfaces__msg__TrackedPerson() -> *const std::ffi::c_void;
}

#[link(name = "tb3_interfaces__rosidl_generator_c")]
extern "C" {
    fn tb3_interfaces__msg__TrackedPerson__init(msg: *mut TrackedPerson) -> bool;
    fn tb3_interfaces__msg__TrackedPerson__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackedPerson>, size: usize) -> bool;
    fn tb3_interfaces__msg__TrackedPerson__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackedPerson>);
    fn tb3_interfaces__msg__TrackedPerson__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackedPerson>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackedPerson>) -> bool;
}

// Corresponds to tb3_interfaces__msg__TrackedPerson
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackedPerson {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cx: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cy: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub width: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub height: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub score: f32,

}



impl Default for TrackedPerson {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tb3_interfaces__msg__TrackedPerson__init(&mut msg as *mut _) {
        panic!("Call to tb3_interfaces__msg__TrackedPerson__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackedPerson {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TrackedPerson__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TrackedPerson__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TrackedPerson__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackedPerson {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackedPerson where Self: Sized {
  const TYPE_NAME: &'static str = "tb3_interfaces/msg/TrackedPerson";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tb3_interfaces__msg__TrackedPerson() }
  }
}


#[link(name = "tb3_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tb3_interfaces__msg__TrackedPersonArray() -> *const std::ffi::c_void;
}

#[link(name = "tb3_interfaces__rosidl_generator_c")]
extern "C" {
    fn tb3_interfaces__msg__TrackedPersonArray__init(msg: *mut TrackedPersonArray) -> bool;
    fn tb3_interfaces__msg__TrackedPersonArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackedPersonArray>, size: usize) -> bool;
    fn tb3_interfaces__msg__TrackedPersonArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackedPersonArray>);
    fn tb3_interfaces__msg__TrackedPersonArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackedPersonArray>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackedPersonArray>) -> bool;
}

// Corresponds to tb3_interfaces__msg__TrackedPersonArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackedPersonArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub persons: rosidl_runtime_rs::Sequence<super::super::msg::rmw::TrackedPerson>,

}



impl Default for TrackedPersonArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tb3_interfaces__msg__TrackedPersonArray__init(&mut msg as *mut _) {
        panic!("Call to tb3_interfaces__msg__TrackedPersonArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackedPersonArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TrackedPersonArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TrackedPersonArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TrackedPersonArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackedPersonArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackedPersonArray where Self: Sized {
  const TYPE_NAME: &'static str = "tb3_interfaces/msg/TrackedPersonArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tb3_interfaces__msg__TrackedPersonArray() }
  }
}


#[link(name = "tb3_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tb3_interfaces__msg__TargetInfo() -> *const std::ffi::c_void;
}

#[link(name = "tb3_interfaces__rosidl_generator_c")]
extern "C" {
    fn tb3_interfaces__msg__TargetInfo__init(msg: *mut TargetInfo) -> bool;
    fn tb3_interfaces__msg__TargetInfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TargetInfo>, size: usize) -> bool;
    fn tb3_interfaces__msg__TargetInfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TargetInfo>);
    fn tb3_interfaces__msg__TargetInfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TargetInfo>, out_seq: *mut rosidl_runtime_rs::Sequence<TargetInfo>) -> bool;
}

// Corresponds to tb3_interfaces__msg__TargetInfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TargetInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub locked: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cx: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cy: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub width: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub height: f32,

}



impl Default for TargetInfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tb3_interfaces__msg__TargetInfo__init(&mut msg as *mut _) {
        panic!("Call to tb3_interfaces__msg__TargetInfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TargetInfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TargetInfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TargetInfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tb3_interfaces__msg__TargetInfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TargetInfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TargetInfo where Self: Sized {
  const TYPE_NAME: &'static str = "tb3_interfaces/msg/TargetInfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tb3_interfaces__msg__TargetInfo() }
  }
}


