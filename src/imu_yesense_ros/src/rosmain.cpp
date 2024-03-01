#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "imu_sensor_yesense.h"
#include "imu_yesense_ros/ImuExtended.h"

int main(int argc, char **argv){
  ros::init(argc, argv, "imu_publisher");
  ros::NodeHandle nh;

  ros::Publisher imu_pub = nh.advertise<sensor_msgs::Imu>("imu_data", 1000);
  int count = 0;
  timespec timestamp;
  ImuSensorYesense* imu_sensor = new ImuSensorYesense;       ///< 创建读取
  imu_sensor->startWork();

  imu_sensor->onMessageReceived = [&](ImuData imu_data){
    if(count % 200 == 0){
      clock_gettime(CLOCK_MONOTONIC, &timestamp);

      sensor_msgs::Imu imu_msg;
      imu_msg.header.stamp = ros::Time::now();
      imu_msg.header.frame_id = "imu_link";  // Adjust the frame_id according to your TF configuration
      // Populate orientation, angular_velocity, and linear_acceleration from imu_data
      // Note: You might need to convert the data to the appropriate format and coordinate system
      imu_msg.linear_acceleration.x = imu_data.acc_x;
      imu_msg.linear_acceleration.y = imu_data.acc_y;
      imu_msg.linear_acceleration.z = imu_data.acc_z;

      imu_msg.angular_velocity.x = imu_data.angular_velocity_roll;
      imu_msg.angular_velocity.y = imu_data.angular_velocity_pitch;
      imu_msg.angular_velocity.z = imu_data.angular_velocity_yaw;

      // Orientation (if available) should be converted from Euler angles (or other formats) to a quaternion
      // Example: imu_msg.orientation = tf::createQuaternionMsgFromRollPitchYaw(imu_data.angle_roll, imu_data.angle_pitch, imu_data.angle_yaw);

      imu_pub.publish(imu_msg);

      // Printing is optional, as data is now being published to a ROS topic
      // std::cout << "Published IMU data" << std::endl;
    }
    count ++;
  };

  ros::Rate loop_rate(10);  // Adjust the rate as needed
  while(ros::ok()){
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
