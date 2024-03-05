#ifndef ATTITUDE_CALCULATOR_H
#define ATTITUDE_CALCULATOR_H

#include "imu_sensor_yesense.h"
#include <chrono> 

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


    double q0, q1, q2, q3;

    double exInt, eyInt, ezInt;

    double Kp, Ki;

    std::chrono::steady_clock::time_point lastUpdateTime;

    bool isFirstUpdate;


    void initializeQuaternion();
};

#endif // ATTITUDE_CALCULATOR_H
