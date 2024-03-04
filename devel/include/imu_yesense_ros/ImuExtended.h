// Generated by gencpp from file imu_yesense_ros/ImuExtended.msg
// DO NOT EDIT!


#ifndef IMU_YESENSE_ROS_MESSAGE_IMUEXTENDED_H
#define IMU_YESENSE_ROS_MESSAGE_IMUEXTENDED_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace imu_yesense_ros
{
template <class ContainerAllocator>
struct ImuExtended_
{
  typedef ImuExtended_<ContainerAllocator> Type;

  ImuExtended_()
    : header()
    , acc_x(0.0)
    , acc_y(0.0)
    , acc_z(0.0)
    , angular_velocity_x(0.0)
    , angular_velocity_y(0.0)
    , angular_velocity_z(0.0)
    , magnetic_x(0.0)
    , magnetic_y(0.0)
    , magnetic_z(0.0)  {
    }
  ImuExtended_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , acc_x(0.0)
    , acc_y(0.0)
    , acc_z(0.0)
    , angular_velocity_x(0.0)
    , angular_velocity_y(0.0)
    , angular_velocity_z(0.0)
    , magnetic_x(0.0)
    , magnetic_y(0.0)
    , magnetic_z(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _acc_x_type;
  _acc_x_type acc_x;

   typedef double _acc_y_type;
  _acc_y_type acc_y;

   typedef double _acc_z_type;
  _acc_z_type acc_z;

   typedef double _angular_velocity_x_type;
  _angular_velocity_x_type angular_velocity_x;

   typedef double _angular_velocity_y_type;
  _angular_velocity_y_type angular_velocity_y;

   typedef double _angular_velocity_z_type;
  _angular_velocity_z_type angular_velocity_z;

   typedef double _magnetic_x_type;
  _magnetic_x_type magnetic_x;

   typedef double _magnetic_y_type;
  _magnetic_y_type magnetic_y;

   typedef double _magnetic_z_type;
  _magnetic_z_type magnetic_z;





  typedef boost::shared_ptr< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> const> ConstPtr;

}; // struct ImuExtended_

typedef ::imu_yesense_ros::ImuExtended_<std::allocator<void> > ImuExtended;

typedef boost::shared_ptr< ::imu_yesense_ros::ImuExtended > ImuExtendedPtr;
typedef boost::shared_ptr< ::imu_yesense_ros::ImuExtended const> ImuExtendedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::imu_yesense_ros::ImuExtended_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::imu_yesense_ros::ImuExtended_<ContainerAllocator1> & lhs, const ::imu_yesense_ros::ImuExtended_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.acc_x == rhs.acc_x &&
    lhs.acc_y == rhs.acc_y &&
    lhs.acc_z == rhs.acc_z &&
    lhs.angular_velocity_x == rhs.angular_velocity_x &&
    lhs.angular_velocity_y == rhs.angular_velocity_y &&
    lhs.angular_velocity_z == rhs.angular_velocity_z &&
    lhs.magnetic_x == rhs.magnetic_x &&
    lhs.magnetic_y == rhs.magnetic_y &&
    lhs.magnetic_z == rhs.magnetic_z;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::imu_yesense_ros::ImuExtended_<ContainerAllocator1> & lhs, const ::imu_yesense_ros::ImuExtended_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace imu_yesense_ros

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d610238899c9b65ff1d2c524fd6e233f";
  }

  static const char* value(const ::imu_yesense_ros::ImuExtended_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd610238899c9b65fULL;
  static const uint64_t static_value2 = 0xf1d2c524fd6e233fULL;
};

template<class ContainerAllocator>
struct DataType< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >
{
  static const char* value()
  {
    return "imu_yesense_ros/ImuExtended";
  }

  static const char* value(const ::imu_yesense_ros::ImuExtended_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"float64 acc_x\n"
"float64 acc_y\n"
"float64 acc_z\n"
"float64 angular_velocity_x\n"
"float64 angular_velocity_y\n"
"float64 angular_velocity_z\n"
"float64 magnetic_x\n"
"float64 magnetic_y\n"
"float64 magnetic_z\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::imu_yesense_ros::ImuExtended_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.acc_x);
      stream.next(m.acc_y);
      stream.next(m.acc_z);
      stream.next(m.angular_velocity_x);
      stream.next(m.angular_velocity_y);
      stream.next(m.angular_velocity_z);
      stream.next(m.magnetic_x);
      stream.next(m.magnetic_y);
      stream.next(m.magnetic_z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ImuExtended_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::imu_yesense_ros::ImuExtended_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::imu_yesense_ros::ImuExtended_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "acc_x: ";
    Printer<double>::stream(s, indent + "  ", v.acc_x);
    s << indent << "acc_y: ";
    Printer<double>::stream(s, indent + "  ", v.acc_y);
    s << indent << "acc_z: ";
    Printer<double>::stream(s, indent + "  ", v.acc_z);
    s << indent << "angular_velocity_x: ";
    Printer<double>::stream(s, indent + "  ", v.angular_velocity_x);
    s << indent << "angular_velocity_y: ";
    Printer<double>::stream(s, indent + "  ", v.angular_velocity_y);
    s << indent << "angular_velocity_z: ";
    Printer<double>::stream(s, indent + "  ", v.angular_velocity_z);
    s << indent << "magnetic_x: ";
    Printer<double>::stream(s, indent + "  ", v.magnetic_x);
    s << indent << "magnetic_y: ";
    Printer<double>::stream(s, indent + "  ", v.magnetic_y);
    s << indent << "magnetic_z: ";
    Printer<double>::stream(s, indent + "  ", v.magnetic_z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // IMU_YESENSE_ROS_MESSAGE_IMUEXTENDED_H