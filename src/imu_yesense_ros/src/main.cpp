#include "ros/ros.h"
#include "geometry_msgs/Vector3.h"
#include "AttitudeCalculator.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "attitude_publisher");
    ros::NodeHandle nh;

    // 创建姿态信息的Publisher
    ros::Publisher attitude_pub = nh.advertise<geometry_msgs::Vector3>("attitude", 1000);

    AttitudeCalculator calculator; // 假设这已经启动了IMU数据读取和姿态计算

    ros::Rate loop_rate(10); // 设置循环率，例如10Hz

    while (ros::ok()) {
        // 获取最新的姿态数据
        Attitude latestAttitude = calculator.getLatestAttitude();

        // 填充ROS消息
        geometry_msgs::Vector3 msg;
        msg.x = latestAttitude.roll;  // Roll
        msg.y = latestAttitude.pitch; // Pitch
        msg.z = latestAttitude.yaw;   // Yaw

        // 发布姿态信息
        attitude_pub.publish(msg);

        // ROS_INFO("Published Attitude - Roll: %f, Pitch: %f, Yaw: %f", latestAttitude.roll, latestAttitude.pitch, latestAttitude.yaw);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
