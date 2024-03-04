#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/Vector3.h" // 引入Vector3消息类型
#include "../include/AttitudeCalculator.h"
#include "../include/imu_sensor_yesense.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "attitude_publisher");
    ros::NodeHandle nh;

    // 使用Vector3消息类型创建一个发布者
    ros::Publisher attitude_pub = nh.advertise<geometry_msgs::Vector3>("attitude", 1000);

    ros::Rate loop_rate(10); // 10Hz

    while (ros::ok()) {
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

        ROS_INFO("Published Attitude - Roll: %f, Pitch: %f, Yaw: %f", attitude.roll, attitude.pitch, attitude.yaw);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
