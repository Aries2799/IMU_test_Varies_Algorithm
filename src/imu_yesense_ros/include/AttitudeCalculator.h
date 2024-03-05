#ifndef ATTITUDE_CALCULATOR_H
#define ATTITUDE_CALCULATOR_H

#include "imu_sensor_yesense.h"
#include <chrono> // 添加对chrono库的引用来处理时间

struct Attitude {
    double roll, pitch, yaw;
};

class AttitudeCalculator {
public:
    AttitudeCalculator();
    ~AttitudeCalculator();
    Attitude getLatestAttitude() const;

private:
    ImuSensorYesense* imu_sensor;
    mutable Attitude latest_attitude;
    void calculateAttitude(const ImuData& imu_data);
    void printImuData(const ImuData& imu_data) const;

    // 新增四元数成员变量
    double q0, q1, q2, q3;
    // 误差积分项
    double exInt, eyInt, ezInt;
    // PID控制器的增益
    double Kp, Ki;
    // 用于计算dt的时间点
    std::chrono::steady_clock::time_point lastUpdateTime;
    // 用于确保第一次更新时不计算dt
    bool isFirstUpdate;

    // 新增方法：四元数初始化
    void initializeQuaternion();
};

#endif // ATTITUDE_CALCULATOR_H
