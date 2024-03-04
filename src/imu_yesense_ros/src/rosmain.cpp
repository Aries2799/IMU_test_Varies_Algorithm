#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "std_msgs/Float64.h"
#include "geometry_msgs/Vector3.h" // 引入Vector3消息类型

#include "../include/imu_sensor_yesense.h"
#include "../include/imu_yesense_ros/ImuExtended.h" 
#include "../include/AttitudeCalculator.h"


int main(int argc, char **argv){
  ros::init(argc, argv, "imu_publisher");
  ros::NodeHandle nh;

  ros::Publisher attitude_pub = nh.advertise<geometry_msgs::Vector3>("attitude", 1000);

  ros::Publisher imu_pub = nh.advertise<imu_yesense_ros::ImuExtended>("imu_extended_data", 1000);
  int count = 0;
  timespec timestamp;
  ImuSensorYesense* imu_sensor = new ImuSensorYesense;
  imu_sensor->startWork();

  imu_sensor->onMessageReceived = [&](ImuData imu_data){
    if(count % 1 == 0){
      clock_gettime(CLOCK_MONOTONIC, &timestamp);

      imu_yesense_ros::ImuExtended imu_extended_msg;

      imu_extended_msg.header.stamp = ros::Time::now();
      imu_extended_msg.header.frame_id = "imu_link"; 
      imu_extended_msg.acc_x = imu_data.acc_x;
      imu_extended_msg.acc_y = imu_data.acc_y;
      imu_extended_msg.acc_z = imu_data.acc_z;
      imu_extended_msg.angular_velocity_x = imu_data.angular_velocity_x;
      imu_extended_msg.angular_velocity_y = imu_data.angular_velocity_y;
      imu_extended_msg.angular_velocity_z = imu_data.angular_velocity_z;
      imu_extended_msg.magnetic_x = imu_data.magnetic_x; 
      imu_extended_msg.magnetic_y = imu_data.magnetic_y;
      imu_extended_msg.magnetic_z = imu_data.magnetic_z;

    
      imu_pub.publish(imu_extended_msg);

  
    //   std::cout << "Published IMU Extended data" << std::endl;

        ImuData imu_data;
        // 假设imu_data已经根据你的IMU硬件被适当地填充

        Attitude attitude = AttitudeCalculator::calculateAttitude(imu_data);

        // 将姿态数据打包进Vector3消息
        geometry_msgs::Vector3 attitude_msg;
        attitude_msg.x = attitude.roll; // Roll
        attitude_msg.y = attitude.pitch; // Pitch
        attitude_msg.z = attitude.yaw; // Yaw

        // 发布姿态消息
        attitude_pub.publish(attitude_msg);

        // ROS_INFO("Published Attitude - Roll: %f, Pitch: %f, Yaw: %f", attitude.roll, attitude.pitch, attitude.yaw);
     
    }
    count++;
  };

  ros::Rate loop_rate(10); 
  while(ros::ok()){
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
