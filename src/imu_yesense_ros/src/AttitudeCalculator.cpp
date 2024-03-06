
#include "AttitudeCalculator.h"
#include <cmath>

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
    exInt = 0.0; eyInt = 0.0; ezInt = 0.0;
    Kp = 2.0; Ki = 0.05;
}


void AttitudeCalculator::printImuData(const ImuData& imu_data) const {
    timespec timestamp;
    clock_gettime(CLOCK_MONOTONIC, &timestamp);
    // std::cout << "++++++++++++++  " << timestamp.tv_sec << "." << timestamp.tv_nsec << "   ++++++++++++++" << std::endl;
    // std::cout << "acc              " << imu_data.acc_x << ", " << imu_data.acc_y << ", " << imu_data.acc_z << std::endl;
    // std::cout << "angular_velocity " << imu_data.angular_velocity_x << ", " << imu_data.angular_velocity_y << ", " << imu_data.angular_velocity_z << std::endl;
}
void AttitudeCalculator::initializeQuaternion() {

}

AttitudeCalculator::~AttitudeCalculator() {
    delete imu_sensor;
}

Attitude AttitudeCalculator::getLatestAttitude() const {
    return latest_attitude;
}

void AttitudeCalculator::calculateAttitude(const ImuData& imu_data) {
    // if (isFirstUpdate) {
    //     lastUpdateTime = std::chrono::steady_clock::now();
    //     isFirstUpdate = false;
    //     return; 
    // }

    // auto now = std::chrono::steady_clock::now();
    // std::chrono::duration<double> elapsed = now - lastUpdateTime;
    // double dt = elapsed.count();  // 以秒为单位
    // lastUpdateTime = now;
    const double alpha = 0.98; // 互补滤波系数
    const double dt = 0.0025; 

    double gx = imu_data.angular_velocity_x ;
    double gy = imu_data.angular_velocity_y ;
    double gz = imu_data.angular_velocity_z ;

    double ax = imu_data.acc_x;
    double ay = imu_data.acc_y;
    double az = imu_data.acc_z;

    // 归一化加速度计测量值
    double norm = sqrt(ax * ax + ay * ay + az * az);
    ax /= norm;
    ay /= norm;
    az /= norm;

    // 估计重力方向
    double vx = 2.0 * (q1 * q3 - q0 * q2);
    double vy = 2.0 * (q0 * q1 + q2 * q3);
    double vz = q0 * q0 - q1 * q1 - q2 * q2 + q3 * q3;

    // 计算误差项
    double ex = (ay * vz - az * vy);
    double ey = (az * vx - ax * vz);
    double ez = (ax * vy - ay * vx);

    // 误差项积分
    exInt += ex * Ki * dt;
    eyInt += ey * Ki * dt;
    ezInt += ez * Ki * dt;

    // 调整陀螺仪测量值，对每个轴进行互补滤波
    gx = alpha * (gx) + (1 - alpha) * (Kp * (ex) + (exInt));
    gy = alpha * (gy) + (1 - alpha) * (Kp * (ey) + (eyInt));
    gz = alpha * (gz) + (1 - alpha) * (Kp * (ez) + (ezInt));

    // 四元数积分更新
    double q0Dot = 0.5 * (-q1 * gx - q2 * gy - q3 * gz);
    double q1Dot = 0.5 * (q0 * gx + q2 * gz - q3 * gy);
    double q2Dot = 0.5 * (q0 * gy - q1 * gz + q3 * gx);
    double q3Dot = 0.5 * (q0 * gz + q1 * gy - q2 * gx);

    q0 += q0Dot * dt;
    q1 += q1Dot * dt;
    q2 += q2Dot * dt;
    q3 += q3Dot * dt;

    // 四元数归一化
    norm = sqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
    q0 /= norm;
    q1 /= norm;
    q2 /= norm;
    q3 /= norm;

    // 欧拉角计算
    latest_attitude.pitch = asin(-2 * q1 * q3 + 2 * q0 * q2) * 180.0 / M_PI;
    latest_attitude.roll = atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * 180.0 / M_PI;
    latest_attitude.yaw = atan2(2 * (q1 * q2 + q0 * q3), q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3) * 180.0 / M_PI;
}
