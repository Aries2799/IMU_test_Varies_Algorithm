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

  
  ros::Publisher imu_pub = nh.advertise<imu_yesense_ros::ImuExtended>("imu_extended_data", 1000);
  int count = 0;
  timespec timestamp;
  ImuSensorYesense* imu_sensor = new ImuSensorYesense;
  imu_sensor->startWork();

  imu_sensor->onMessageReceived = [&](ImuData imu_data){
    if(count % 200 == 0){
      clock_gettime(CLOCK_MONOTONIC, &timestamp);

      imu_yesense_ros::ImuExtended imu_extended_msg;

      imu_extended_msg.header.stamp = ros::Time::now();
      imu_extended_msg.header.frame_id = "imu_link"; 

     
      imu_extended_msg.acc_x = imu_data.acc_x;
      imu_extended_msg.acc_y = imu_data.acc_y;
      imu_extended_msg.acc_z = imu_data.acc_z;
      imu_extended_msg.angular_velocity_roll = imu_data.angular_velocity_roll;
      imu_extended_msg.angular_velocity_pitch = imu_data.angular_velocity_pitch;
      imu_extended_msg.angular_velocity_yaw = imu_data.angular_velocity_yaw;
      imu_extended_msg.angle_roll = imu_data.angle_roll; 
      imu_extended_msg.angle_pitch = imu_data.angle_pitch;
      imu_extended_msg.angle_yaw = imu_data.angle_yaw;

    
      imu_pub.publish(imu_extended_msg);

  
      std::cout << "Published IMU Extended data" << std::endl;
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
