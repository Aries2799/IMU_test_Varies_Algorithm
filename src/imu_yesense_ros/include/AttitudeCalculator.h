#ifndef ATTITUDE_CALCULATOR_H
#define ATTITUDE_CALCULATOR_H

#include "imu_sensor_yesense.h"
#include <cmath>
#include <iostream>

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
};

#endif // ATTITUDE_CALCULATOR_H
