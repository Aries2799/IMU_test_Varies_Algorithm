#include "ros/ros.h"
#include "imu_yesense_ros/attitude.h" 
#include "AttitudeCalculator.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "attitude_publisher");
    ros::NodeHandle nh;

    AttitudeCalculator calculator; 
    ros::Rate loop_rate(100); 
    ros::Publisher attitude_pub = nh.advertise<imu_yesense_ros::attitude>("attitude", 1000);

    while (ros::ok()) {
        Attitude latestAttitude = calculator.getLatestAttitude();


        imu_yesense_ros::attitude msg;
        msg.roll = latestAttitude.roll;
        msg.pitch = latestAttitude.pitch;
        msg.yaw = latestAttitude.yaw;

        attitude_pub.publish(msg);

        // ROS_INFO("Published Attitude - Roll: %f, Pitch: %f, Yaw: %f", msg.roll, msg.pitch, msg.yaw);

        ros::spinOnce();
        loop_rate.sleep();
    }

    }
