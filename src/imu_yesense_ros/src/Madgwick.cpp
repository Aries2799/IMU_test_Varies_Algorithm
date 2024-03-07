#include "AttitudeCalculator.h"
#include <cmath>
#include "ImuFilter.h" // 确保引入ImuFilter头文件

AttitudeCalculator::AttitudeCalculator() : isFirstUpdate(true) {
    imu_sensor = new ImuSensorYesense();
    imu_sensor->startWork();
    imu_sensor->onMessageReceived = [this](const ImuData& imu_data) {
        if (isFirstUpdate) {
            initializeQuaternion();
            isFirstUpdate = false;
            lastUpdateTime = std::chrono::steady_clock::now();
        }
        this->calculateAttitude(imu_data);
        this->printImuData(imu_data);
    };

    q0 = 1.0; q1 = 0.0; q2 = 0.0; q3 = 0.0;

    // 实例化Madgwick滤波器
    imuFilter = new ImuFilter();
    imuFilter->setAlgorithmGain(0.1); // 根据需要调整增益
    imuFilter->setDriftBiasGain(0.01); // 根据需要调整漂移偏差增益
}

AttitudeCalculator::~AttitudeCalculator() {
    delete imu_sensor;
    delete imuFilter; // 清理ImuFilter实例
}

void AttitudeCalculator::calculateAttitude(const ImuData& imu_data) {
    // 根据上一个更新计算时间差（秒）
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - lastUpdateTime;
    double dt = elapsed.count();
    lastUpdateTime = now;

    // 使用Madgwick算法更新姿态
    imuFilter->madgwickAHRSupdate(
        imu_data.angular_velocity_x, imu_data.angular_velocity_y, imu_data.angular_velocity_z,
        imu_data.acc_x, imu_data.acc_y, imu_data.acc_z,
        imu_data.magnetic_x, imu_data.magnetic_y, imu_data.magnetic_z,
        dt);

    // 从滤波器获取更新后的四元数
    imuFilter->getOrientation(q0, q1, q2, q3);

    // 四元数转换为欧拉角
    // 注意：根据您的四元数到欧拉角的转换函数可能有所不同
    latest_attitude.pitch = asin(-2 * q1 * q3 + 2 * q0 * q2) * 180.0 / M_PI;
    latest_attitude.roll = atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * 180.0 / M_PI;
    latest_attitude.yaw = atan2(2 * (q1 * q2 + q0 * q3), q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3) * 180.0 / M_PI;
}
