#include "AttitudeCalculator.h"

AttitudeCalculator::AttitudeCalculator() : imu_sensor(new ImuSensorYesense()) {
    imu_sensor->startWork();
    imu_sensor->onMessageReceived = [this](const ImuData& imu_data) {
        this->calculateAttitude(imu_data);
        this->printImuData(imu_data);
    };
}

AttitudeCalculator::~AttitudeCalculator() {
    delete imu_sensor;
}

Attitude AttitudeCalculator::getLatestAttitude() const {
    return latest_attitude;
}

void AttitudeCalculator::calculateAttitude(const ImuData& imu_data) {
    const double pi = 3.14159265358979323846;

    double acc_x = imu_data.acc_x;
    double acc_y = imu_data.acc_y;
    double acc_z = imu_data.acc_z;
    double mag_x = imu_data.magnetic_x;
    double mag_y = imu_data.magnetic_y;
    double mag_z = imu_data.magnetic_z;
    
    // std::cout << "acc_x " << acc_x << "acc_y" << acc_y<< "acc_z" << acc_z << std::endl;

    // 计算Pitch和Roll（以度为单位）
    double pitch = atan2(-acc_x, sqrt(acc_y * acc_y + acc_z * acc_z)) * 180.0 / pi;
    double roll = atan2(acc_y, acc_z) * 180.0 / pi;

    // 调整磁力计读数
    double mag_x_comp = mag_x * cos(pitch * pi / 180) + mag_z * sin(pitch * pi / 180);
    double mag_y_comp = mag_x * sin(roll * pi / 180) * sin(pitch * pi / 180) + mag_y * cos(roll * pi / 180) - mag_z * sin(roll * pi / 180) * cos(pitch * pi / 180);

    // 计算Yaw
    double yaw = atan2(-mag_y_comp, mag_x_comp) * 180.0 / pi;
    
    // std::cout << "pitch " << pitch << "roll" << roll<< "yaw" << yaw << std::endl;

    // 更新latest_attitude
    latest_attitude.roll = roll;
    latest_attitude.pitch = pitch;
    latest_attitude.yaw = yaw;
}


void AttitudeCalculator::printImuData(const ImuData& imu_data) const {
    timespec timestamp;
    clock_gettime(CLOCK_MONOTONIC, &timestamp);
    // std::cout << "++++++++++++++  " << timestamp.tv_sec << "." << timestamp.tv_nsec << "   ++++++++++++++" << std::endl;
    // std::cout << "acc              " << imu_data.acc_x << ", " << imu_data.acc_y << ", " << imu_data.acc_z << std::endl;
    // std::cout << "angular_velocity " << imu_data.angular_velocity_x << ", " << imu_data.angular_velocity_y << ", " << imu_data.angular_velocity_z << std::endl;
}
