#ifndef ATTITUDE_CALCULATOR_H
#define ATTITUDE_CALCULATOR_H

#include "imu_sensor_yesense.h"

struct Attitude {
    double roll, pitch, yaw;
};

class AttitudeCalculator {
public:
    static Attitude calculateAttitude(const ImuData& imu_data);
};

#endif // ATTITUDE_CALCULATOR_H
