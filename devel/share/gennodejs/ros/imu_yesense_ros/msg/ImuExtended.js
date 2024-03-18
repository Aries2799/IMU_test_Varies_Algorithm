// Auto-generated. Do not edit!

// (in-package imu_yesense_ros.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ImuExtended {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.acc_x = null;
      this.acc_y = null;
      this.acc_z = null;
      this.angular_velocity_x = null;
      this.angular_velocity_y = null;
      this.angular_velocity_z = null;
      this.magnetic_x = null;
      this.magnetic_y = null;
      this.magnetic_z = null;
      this.roll = null;
      this.pitch = null;
      this.yaw = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('acc_x')) {
        this.acc_x = initObj.acc_x
      }
      else {
        this.acc_x = 0.0;
      }
      if (initObj.hasOwnProperty('acc_y')) {
        this.acc_y = initObj.acc_y
      }
      else {
        this.acc_y = 0.0;
      }
      if (initObj.hasOwnProperty('acc_z')) {
        this.acc_z = initObj.acc_z
      }
      else {
        this.acc_z = 0.0;
      }
      if (initObj.hasOwnProperty('angular_velocity_x')) {
        this.angular_velocity_x = initObj.angular_velocity_x
      }
      else {
        this.angular_velocity_x = 0.0;
      }
      if (initObj.hasOwnProperty('angular_velocity_y')) {
        this.angular_velocity_y = initObj.angular_velocity_y
      }
      else {
        this.angular_velocity_y = 0.0;
      }
      if (initObj.hasOwnProperty('angular_velocity_z')) {
        this.angular_velocity_z = initObj.angular_velocity_z
      }
      else {
        this.angular_velocity_z = 0.0;
      }
      if (initObj.hasOwnProperty('magnetic_x')) {
        this.magnetic_x = initObj.magnetic_x
      }
      else {
        this.magnetic_x = 0.0;
      }
      if (initObj.hasOwnProperty('magnetic_y')) {
        this.magnetic_y = initObj.magnetic_y
      }
      else {
        this.magnetic_y = 0.0;
      }
      if (initObj.hasOwnProperty('magnetic_z')) {
        this.magnetic_z = initObj.magnetic_z
      }
      else {
        this.magnetic_z = 0.0;
      }
      if (initObj.hasOwnProperty('roll')) {
        this.roll = initObj.roll
      }
      else {
        this.roll = 0.0;
      }
      if (initObj.hasOwnProperty('pitch')) {
        this.pitch = initObj.pitch
      }
      else {
        this.pitch = 0.0;
      }
      if (initObj.hasOwnProperty('yaw')) {
        this.yaw = initObj.yaw
      }
      else {
        this.yaw = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ImuExtended
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [acc_x]
    bufferOffset = _serializer.float64(obj.acc_x, buffer, bufferOffset);
    // Serialize message field [acc_y]
    bufferOffset = _serializer.float64(obj.acc_y, buffer, bufferOffset);
    // Serialize message field [acc_z]
    bufferOffset = _serializer.float64(obj.acc_z, buffer, bufferOffset);
    // Serialize message field [angular_velocity_x]
    bufferOffset = _serializer.float64(obj.angular_velocity_x, buffer, bufferOffset);
    // Serialize message field [angular_velocity_y]
    bufferOffset = _serializer.float64(obj.angular_velocity_y, buffer, bufferOffset);
    // Serialize message field [angular_velocity_z]
    bufferOffset = _serializer.float64(obj.angular_velocity_z, buffer, bufferOffset);
    // Serialize message field [magnetic_x]
    bufferOffset = _serializer.float64(obj.magnetic_x, buffer, bufferOffset);
    // Serialize message field [magnetic_y]
    bufferOffset = _serializer.float64(obj.magnetic_y, buffer, bufferOffset);
    // Serialize message field [magnetic_z]
    bufferOffset = _serializer.float64(obj.magnetic_z, buffer, bufferOffset);
    // Serialize message field [roll]
    bufferOffset = _serializer.float64(obj.roll, buffer, bufferOffset);
    // Serialize message field [pitch]
    bufferOffset = _serializer.float64(obj.pitch, buffer, bufferOffset);
    // Serialize message field [yaw]
    bufferOffset = _serializer.float64(obj.yaw, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ImuExtended
    let len;
    let data = new ImuExtended(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [acc_x]
    data.acc_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [acc_y]
    data.acc_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [acc_z]
    data.acc_z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angular_velocity_x]
    data.angular_velocity_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angular_velocity_y]
    data.angular_velocity_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angular_velocity_z]
    data.angular_velocity_z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [magnetic_x]
    data.magnetic_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [magnetic_y]
    data.magnetic_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [magnetic_z]
    data.magnetic_z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [roll]
    data.roll = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pitch]
    data.pitch = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yaw]
    data.yaw = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 96;
  }

  static datatype() {
    // Returns string type for a message object
    return 'imu_yesense_ros/ImuExtended';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c35cf7f7950d0a3072b3fda30e7bb610';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    float64 acc_x
    float64 acc_y
    float64 acc_z
    float64 angular_velocity_x
    float64 angular_velocity_y
    float64 angular_velocity_z
    float64 magnetic_x
    float64 magnetic_y
    float64 magnetic_z
    float64 roll
    float64 pitch
    float64 yaw
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ImuExtended(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.acc_x !== undefined) {
      resolved.acc_x = msg.acc_x;
    }
    else {
      resolved.acc_x = 0.0
    }

    if (msg.acc_y !== undefined) {
      resolved.acc_y = msg.acc_y;
    }
    else {
      resolved.acc_y = 0.0
    }

    if (msg.acc_z !== undefined) {
      resolved.acc_z = msg.acc_z;
    }
    else {
      resolved.acc_z = 0.0
    }

    if (msg.angular_velocity_x !== undefined) {
      resolved.angular_velocity_x = msg.angular_velocity_x;
    }
    else {
      resolved.angular_velocity_x = 0.0
    }

    if (msg.angular_velocity_y !== undefined) {
      resolved.angular_velocity_y = msg.angular_velocity_y;
    }
    else {
      resolved.angular_velocity_y = 0.0
    }

    if (msg.angular_velocity_z !== undefined) {
      resolved.angular_velocity_z = msg.angular_velocity_z;
    }
    else {
      resolved.angular_velocity_z = 0.0
    }

    if (msg.magnetic_x !== undefined) {
      resolved.magnetic_x = msg.magnetic_x;
    }
    else {
      resolved.magnetic_x = 0.0
    }

    if (msg.magnetic_y !== undefined) {
      resolved.magnetic_y = msg.magnetic_y;
    }
    else {
      resolved.magnetic_y = 0.0
    }

    if (msg.magnetic_z !== undefined) {
      resolved.magnetic_z = msg.magnetic_z;
    }
    else {
      resolved.magnetic_z = 0.0
    }

    if (msg.roll !== undefined) {
      resolved.roll = msg.roll;
    }
    else {
      resolved.roll = 0.0
    }

    if (msg.pitch !== undefined) {
      resolved.pitch = msg.pitch;
    }
    else {
      resolved.pitch = 0.0
    }

    if (msg.yaw !== undefined) {
      resolved.yaw = msg.yaw;
    }
    else {
      resolved.yaw = 0.0
    }

    return resolved;
    }
};

module.exports = ImuExtended;
