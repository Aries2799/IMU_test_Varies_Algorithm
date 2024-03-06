#include "ros/ros.h"
#include "imu_yesense_ros/attitude.h" 
#include "imu_yesense_ros/ImuExtended.h" 

#include "AttitudeCalculator.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "attitude_publisher");
    ros::NodeHandle nh;

    AttitudeCalculator calculator; 
    ros::Rate loop_rate(100); 
    ros::Publisher attitude_pub = nh.advertise<imu_yesense_ros::attitude>("attitude", 1000);
    ros::Publisher imu_pub = nh.advertise<imu_yesense_ros::ImuExtended>("imu_extended_data", 1000);
    
    while (ros::ok()) {
        Attitude latestAttitude = calculator.getLatestAttitude();

        imu_yesense_ros::ImuExtended imu_extended_msg;
        imu_extended_msg.header.stamp = ros::Time::now();
        imu_extended_msg.header.frame_id = "imu_link"; 
        
        imu_extended_msg.acc_x = latestAttitude.ax;
        imu_extended_msg.acc_y = latestAttitude.ay;
        imu_extended_msg.acc_z = latestAttitude.az;
        imu_extended_msg.angular_velocity_x = latestAttitude.gx;
        imu_extended_msg.angular_velocity_y = latestAttitude.gy;
        imu_extended_msg.angular_velocity_z = latestAttitude.gz;
        imu_extended_msg.magnetic_x = latestAttitude.mx; 
        imu_extended_msg.magnetic_y = latestAttitude.my;
        imu_extended_msg.magnetic_z = latestAttitude.mz;

        imu_pub.publish(imu_extended_msg);

        imu_yesense_ros::attitude msg;
        msg.roll = latestAttitude.roll;
        msg.pitch = latestAttitude.pitch;
        msg.yaw = latestAttitude.yaw;

        attitude_pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
