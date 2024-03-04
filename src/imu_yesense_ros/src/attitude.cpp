#include <iostream>
#include <cmath> // 引入数学库
#include <unistd.h>
#include <time.h>
#include "imu_sensor_yesense.h"

// 定义一个函数，用于计算Roll, Pitch, Yaw
void calculateAttitude(const ImuData& imu_data) {
    const double pi = 3.14159265358979323846;
    double acc_x = imu_data.acc_x;
    double acc_y = imu_data.acc_y;
    double acc_z = imu_data.acc_z;
    double mag_x = imu_data.magnetic_x;
    double mag_y = imu_data.magnetic_y;
    double mag_z = imu_data.magnetic_z;

    // 计算Pitch和Roll
    double pitch = atan2(-acc_x, sqrt(acc_y * acc_y + acc_z * acc_z)) * 180.0 / pi;
    double roll = atan2(acc_y, acc_z) * 180.0 / pi;

    // 调整磁力计读数
    double mag_x_comp = mag_x * cos(pitch * pi / 180) + mag_z * sin(pitch * pi / 180);
    double mag_y_comp = mag_x * sin(roll * pi / 180) * sin(pitch * pi / 180) + mag_y * cos(roll * pi / 180) - mag_z * sin(roll * pi / 180) * cos(pitch * pi / 180);

    // 计算Yaw
    double yaw = atan2(-mag_y_comp, mag_x_comp) * 180.0 / pi;

    // 输出结果
    std::cout << "Roll: " << roll << ", Pitch: " << pitch << ", Yaw: " << yaw << std::endl;
}

int main() {
    int count = 0;
    timespec timestamp;
    ImuSensorYesense* imu_sensor = new ImuSensorYesense; // 创建读取
    imu_sensor->startWork();

    imu_sensor->onMessageReceived = [&](ImuData imu_data) {
        if (count % 1 == 0) {
            clock_gettime(CLOCK_MONOTONIC, &timestamp);
            calculateAttitude(imu_data); // 调用姿态解算函数
            std::cout << "Timestamp: " << timestamp.tv_sec << "." << timestamp.tv_nsec << std::endl;
        }
        count++;
    };

    while (1) {
        sleep(1); // 简化示例，实际使用时应避免使用无限循环
    }

    delete imu_sensor;
}