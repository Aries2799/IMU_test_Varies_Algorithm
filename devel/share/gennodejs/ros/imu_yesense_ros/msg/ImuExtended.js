// Auto-generated. Do not edit!

// (in-package imu_yesense_ros.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ImuExtended {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.acc_x = null;
      this.acc_y = null;
      this.acc_z = null;
      this.angular_velocity_roll = null;
      this.angular_velocity_pitch = null;
      this.angular_velocity_yaw = null;
      this.angle_roll = null;
      this.angle_pitch = null;
      this.angle_yaw = null;
    }
    else {
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
      if (initObj.hasOwnProperty('angular_velocity_roll')) {
        this.angular_velocity_roll = initObj.angular_velocity_roll
      }
      else {
        this.angular_velocity_roll = 0.0;
      }
      if (initObj.hasOwnProperty('angular_velocity_pitch')) {
        this.angular_velocity_pitch = initObj.angular_velocity_pitch
      }
      else {
        this.angular_velocity_pitch = 0.0;
      }
      if (initObj.hasOwnProperty('angular_velocity_yaw')) {
        this.angular_velocity_yaw = initObj.angular_velocity_yaw
      }
      else {
        this.angular_velocity_yaw = 0.0;
      }
      if (initObj.hasOwnProperty('angle_roll')) {
        this.angle_roll = initObj.angle_roll
      }
      else {
        this.angle_roll = 0.0;
      }
      if (initObj.hasOwnProperty('angle_pitch')) {
        this.angle_pitch = initObj.angle_pitch
      }
      else {
        this.angle_pitch = 0.0;
      }
      if (initObj.hasOwnProperty('angle_yaw')) {
        this.angle_yaw = initObj.angle_yaw
      }
      else {
        this.angle_yaw = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ImuExtended
    // Serialize message field [acc_x]
    bufferOffset = _serializer.float64(obj.acc_x, buffer, bufferOffset);
    // Serialize message field [acc_y]
    bufferOffset = _serializer.float64(obj.acc_y, buffer, bufferOffset);
    // Serialize message field [acc_z]
    bufferOffset = _serializer.float64(obj.acc_z, buffer, bufferOffset);
    // Serialize message field [angular_velocity_roll]
    bufferOffset = _serializer.float64(obj.angular_velocity_roll, buffer, bufferOffset);
    // Serialize message field [angular_velocity_pitch]
    bufferOffset = _serializer.float64(obj.angular_velocity_pitch, buffer, bufferOffset);
    // Serialize message field [angular_velocity_yaw]
    bufferOffset = _serializer.float64(obj.angular_velocity_yaw, buffer, bufferOffset);
    // Serialize message field [angle_roll]
    bufferOffset = _serializer.float64(obj.angle_roll, buffer, bufferOffset);
    // Serialize message field [angle_pitch]
    bufferOffset = _serializer.float64(obj.angle_pitch, buffer, bufferOffset);
    // Serialize message field [angle_yaw]
    bufferOffset = _serializer.float64(obj.angle_yaw, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ImuExtended
    let len;
    let data = new ImuExtended(null);
    // Deserialize message field [acc_x]
    data.acc_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [acc_y]
    data.acc_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [acc_z]
    data.acc_z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angular_velocity_roll]
    data.angular_velocity_roll = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angular_velocity_pitch]
    data.angular_velocity_pitch = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angular_velocity_yaw]
    data.angular_velocity_yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angle_roll]
    data.angle_roll = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angle_pitch]
    data.angle_pitch = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angle_yaw]
    data.angle_yaw = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 72;
  }

  static datatype() {
    // Returns string type for a message object
    return 'imu_yesense_ros/ImuExtended';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2eb288617eb70de805bdc572560b798f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 acc_x
    float64 acc_y
    float64 acc_z
    float64 angular_velocity_roll
    float64 angular_velocity_pitch
    float64 angular_velocity_yaw
    float64 angle_roll
    float64 angle_pitch
    float64 angle_yaw
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ImuExtended(null);
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

    if (msg.angular_velocity_roll !== undefined) {
      resolved.angular_velocity_roll = msg.angular_velocity_roll;
    }
    else {
      resolved.angular_velocity_roll = 0.0
    }

    if (msg.angular_velocity_pitch !== undefined) {
      resolved.angular_velocity_pitch = msg.angular_velocity_pitch;
    }
    else {
      resolved.angular_velocity_pitch = 0.0
    }

    if (msg.angular_velocity_yaw !== undefined) {
      resolved.angular_velocity_yaw = msg.angular_velocity_yaw;
    }
    else {
      resolved.angular_velocity_yaw = 0.0
    }

    if (msg.angle_roll !== undefined) {
      resolved.angle_roll = msg.angle_roll;
    }
    else {
      resolved.angle_roll = 0.0
    }

    if (msg.angle_pitch !== undefined) {
      resolved.angle_pitch = msg.angle_pitch;
    }
    else {
      resolved.angle_pitch = 0.0
    }

    if (msg.angle_yaw !== undefined) {
      resolved.angle_yaw = msg.angle_yaw;
    }
    else {
      resolved.angle_yaw = 0.0
    }

    return resolved;
    }
};

module.exports = ImuExtended;
