#include "ros/ros.h"
#include "imu_yesense_ros/attitude.h"  // 替换<your_package_name>为你的包名
#include "AttitudeCalculator.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "attitude_publisher");
    ros::NodeHandle nh;

    AttitudeCalculator calculator; // 假设这已经启动了IMU数据读取和姿态计算
    ros::Rate loop_rate(100); 
    ros::Publisher attitude_pub = nh.advertise<imu_yesense_ros::attitude>("attitude", 1000);

    while (ros::ok()) {
        Attitude latestAttitude = calculator.getLatestAttitude();

        // 填充自定义消息
        imu_yesense_ros::attitude msg;
        msg.roll = latestAttitude.roll;
        msg.pitch = latestAttitude.pitch;
        msg.yaw = latestAttitude.yaw;

        // 发布姿态信息
        attitude_pub.publish(msg);

        // ROS_INFO("Published Attitude - Roll: %f, Pitch: %f, Yaw: %f", msg.roll, msg.pitch, msg.yaw);

        ros::spinOnce();
        loop_rate.sleep();
    }

    }
