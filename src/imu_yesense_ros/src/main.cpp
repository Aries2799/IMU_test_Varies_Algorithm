#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "imu_sensor_yesense.h"
#include "imu_yesense_ros/ImuExtended.h"
#include "Fusion.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "imu_publisher");
    ros::NodeHandle nh;

    ros::Publisher imu_pub = nh.advertise<imu_yesense_ros::ImuExtended>("imu_extended_data", 1000);
    int count = 0;
    timespec timestamp;
    ImuSensorYesense* imu_sensor = new ImuSensorYesense;
    imu_sensor->startWork();

    // AHRS initialization
    FusionAhrs ahrs;
    FusionAhrsInitialise(&ahrs);

    float samplePeriod; 
    timespec last_timestamp;
    bool first_measurement = true; 

    imu_sensor->onMessageReceived = [&](ImuData imu_data){
        if(count % 1 == 0){
            timespec current_timestamp;
            clock_gettime(CLOCK_MONOTONIC, &current_timestamp);


            if (!first_measurement) {
                float delta_t = (current_timestamp.tv_sec - last_timestamp.tv_sec) 
                            + (current_timestamp.tv_nsec - last_timestamp.tv_nsec) / 1000000000.0f;
                samplePeriod = delta_t;
            } else {
                first_measurement = false;
            }

            last_timestamp = current_timestamp;
            // Fusion algorithm update
            FusionVector gyroscope = {imu_data.angular_velocity_x, imu_data.angular_velocity_y, imu_data.angular_velocity_z}; // Assuming degrees/s
            FusionVector accelerometer = {imu_data.acc_x, imu_data.acc_y, imu_data.acc_z}; // Assuming g
            FusionAhrsUpdateNoMagnetometer(&ahrs, gyroscope, accelerometer, samplePeriod);
            FusionEuler euler = FusionQuaternionToEuler(FusionAhrsGetQuaternion(&ahrs));

            imu_yesense_ros::ImuExtended imu_extended_msg;

            imu_extended_msg.header.stamp = ros::Time::now();
            imu_extended_msg.header.frame_id = "imu_link";

            // Original IMU data
            imu_extended_msg.acc_x = imu_data.acc_x;
            imu_extended_msg.acc_y = imu_data.acc_y;
            imu_extended_msg.acc_z = imu_data.acc_z;
            imu_extended_msg.angular_velocity_x = imu_data.angular_velocity_x;
            imu_extended_msg.angular_velocity_y = imu_data.angular_velocity_y;
            imu_extended_msg.angular_velocity_z = imu_data.angular_velocity_z;
            imu_extended_msg.magnetic_x = imu_data.magnetic_x; 
            imu_extended_msg.magnetic_y = imu_data.magnetic_y;
            imu_extended_msg.magnetic_z = imu_data.magnetic_z;

            // Adding Euler angles from AHRS
            imu_extended_msg.roll = euler.angle.roll;
            imu_extended_msg.pitch = euler.angle.pitch;
            imu_extended_msg.yaw = euler.angle.yaw;

            imu_pub.publish(imu_extended_msg);

            std::cout << "Published IMU Extended data" << std::endl;
            std::cout << "Published IMU Extended data with sample period: " << samplePeriod << " s" << std::endl;
        }
        count++;
    };

    ros::Rate loop_rate(10); // Or set to actual loop rate based on your sensor's configuration
    while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
