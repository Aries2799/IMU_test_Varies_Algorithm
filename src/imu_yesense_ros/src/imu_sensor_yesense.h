/*
 * imu_sensor_yesense.h
 *
 *  Created on: 2019-12-20
 *      Author: moxiaobo
 */

#ifndef IMU_SENSOR_YESENSE_H_
#define IMU_SENSOR_YESENSE_H_

#include "rs232_toolkit.h"
#include <thread>
#include <functional>


#pragma pack(1)
  /// 元生陀螺仪主体数据结构，长度为14*3 = 42 B
  struct YesenseData {
    struct {
      uint8_t id;
      uint8_t size;
      int32_t x,y,z;
    } acc,angle_v,angle;
  };
  /// 元生陀螺仪报文结构，长度为42+2+2+1+2 = 49 B
  struct YesenseFrame {
    uint16_t header;
    uint16_t count;
    uint8_t size;
    YesenseData data;
    struct {
      uint8_t checksum_low;
      uint8_t checksum_high;
    };
  };

  
#pragma pack()
typedef struct ImuData{
  int32_t timestamp;
  union{
    uint8_t buffer_byte[36];
    struct{
      float angle_roll,angle_pitch,angle_yaw;
      float angular_velocity_roll,angular_velocity_pitch,angular_velocity_yaw;
      float acc_x,acc_y,acc_z;
    };
  };
};
  class ImuSensorYesense: public Rs232Toolkit {
  private:
    ImuData imu_data_;

    int32_t last_timestamp_;
    static const size_t kFrameSize = 49;
    static const size_t kHeaderSize = 2;
    static const size_t kBufferSize = kFrameSize - kHeaderSize;
    static const size_t kChecksumSize = kBufferSize - 2;
    static const size_t kDataSize = 42;
  protected:
    void RunRoutine(void);
 
  public:
    std::function<void(ImuData)> onMessageReceived;
    void startWork();
    ImuSensorYesense();
 
    virtual ~ImuSensorYesense();

    int set_imu_data(YesenseFrame&);
    ImuData& get_imu_data();

};

#endif /* IMU_SENSOR_H_ */
