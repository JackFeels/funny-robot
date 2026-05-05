#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to tb3_interfaces__msg__TrackedPerson

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TrackedPerson::default())
  }
}

impl rosidl_runtime_rs::Message for TrackedPerson {
  type RmwMsg = super::msg::rmw::TrackedPerson;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        cx: msg.cx,
        cy: msg.cy,
        width: msg.width,
        height: msg.height,
        score: msg.score,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      cx: msg.cx,
      cy: msg.cy,
      width: msg.width,
      height: msg.height,
      score: msg.score,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      cx: msg.cx,
      cy: msg.cy,
      width: msg.width,
      height: msg.height,
      score: msg.score,
    }
  }
}


// Corresponds to tb3_interfaces__msg__TrackedPersonArray

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackedPersonArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub persons: Vec<super::msg::TrackedPerson>,

}



impl Default for TrackedPersonArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TrackedPersonArray::default())
  }
}

impl rosidl_runtime_rs::Message for TrackedPersonArray {
  type RmwMsg = super::msg::rmw::TrackedPersonArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        persons: msg.persons
          .into_iter()
          .map(|elem| super::msg::TrackedPerson::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        persons: msg.persons
          .iter()
          .map(|elem| super::msg::TrackedPerson::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      persons: msg.persons
          .into_iter()
          .map(super::msg::TrackedPerson::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to tb3_interfaces__msg__TargetInfo

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TargetInfo::default())
  }
}

impl rosidl_runtime_rs::Message for TargetInfo {
  type RmwMsg = super::msg::rmw::TargetInfo;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        locked: msg.locked,
        target_id: msg.target_id,
        cx: msg.cx,
        cy: msg.cy,
        width: msg.width,
        height: msg.height,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      locked: msg.locked,
      target_id: msg.target_id,
      cx: msg.cx,
      cy: msg.cy,
      width: msg.width,
      height: msg.height,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      locked: msg.locked,
      target_id: msg.target_id,
      cx: msg.cx,
      cy: msg.cy,
      width: msg.width,
      height: msg.height,
    }
  }
}


