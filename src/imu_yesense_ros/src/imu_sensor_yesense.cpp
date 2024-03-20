/*
 * imu_sensor_yesense.cpp
 *
 *  Created on: 2019-12-20
 *      Author: moxiaobo
 */

#include "../include/imu_sensor_yesense.h"

#include "termios.h"

#include <ostream>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
using namespace std;
ImuSensorYesense::ImuSensorYesense() {
    memset(&imu_data_,0,sizeof(imu_data_));
}




ImuSensorYesense::~ImuSensorYesense() {

}

int ImuSensorYesense::set_imu_data(YesenseFrame& frame){

  static uint32_t count = 0;


  struct timespec time;
  int32_t time_dt = 0;
  static  int32_t time_dt_max = 0;
  clock_gettime(CLOCK_MONOTONIC ,&time);
  last_timestamp_ = time.tv_sec *1000 + time.tv_nsec / 1e6;
  time_dt = last_timestamp_ - imu_data_.timestamp ;
  if(time_dt > time_dt_max && count != 0){
    time_dt_max = time_dt;
    std::cout << "read time max is "  << time_dt_max << std::endl;
  }

  count ++;

  // std::cout << last_timestamp_ << "time  " << time_dt << "  max  " << time_dt_max << std::endl;
   imu_data_.timestamp = last_timestamp_;

#ifdef DEBUGG
  std::cout<< "This imu massage use " << imu_data_.timestamp
           << " s. " << std::endl;
#endif
  double factor = 1e6;
  double rad = 3.1415926/180;
  imu_data_.magnetic_x             = frame.data.angle.y / factor;
  imu_data_.magnetic_y            = frame.data.angle.x / factor;
  imu_data_.magnetic_z              = frame.data.angle.z / factor;
  imu_data_.angular_velocity_x  = frame.data.angle_v.x / factor * 1;
  imu_data_.angular_velocity_y = frame.data.angle_v.y / factor * 1;
  imu_data_.angular_velocity_z   = frame.data.angle_v.z / factor * 1;
  imu_data_.acc_x                  = frame.data.acc.x / factor;
  imu_data_.acc_y                  = frame.data.acc.y / factor;
  imu_data_.acc_z                  = frame.data.acc.z / factor;
#ifdef DEBUG
  std::cout<< *this;
#endif
    return 0;
}

ImuData& ImuSensorYesense::get_imu_data(){
  return imu_data_;
}


void ImuSensorYesense::RunRoutine(void){

  cout<<"Hello, IMU-Y sensor! "<< endl;
  bool init_flag = true;
  /*************** buffer initial ***************/
  const unsigned char preamble[kHeaderSize] = {0x59, 0x53};
  YesenseFrame frame = {0x5359};
  uint8_t byte_buffer;
  uint8_t *datas_buffer = (uint8_t *)&(frame.count) ;
  int count = 0;

  size_t success_count = 0;
  unsigned int preamble_error_count = 0;
  unsigned int CRC_check_error_count = 0;

  /**************** Open port and set config *************************/
  int fd = open("/dev/ttyUSB0",O_RDONLY | O_NOCTTY );//| O_NDELAY);
  if (fd<0) {
    perror("[Error:IMU] Can not open ser1.\n");
    goto end;
  }
  if (!SetSpeed(fd,B460800)) perror("speed set action encounter error.\n");
  if (!SetParity(fd,8,1,'n',kBufferSize)) {
    perror("parity set action encounter error.\n");
  }


  tcflush(fd, TCIOFLUSH);
  while(1){
    // read(fd,&byte_buffer,1);
    // // printf("0x%02x ", byte_buffer);
    // count ++;
    // if(count == 49){
    //   std::cout<< std::endl;
    //   count = 0;
    // }
    /**************** check preamble ***************/
    while(1){

      while (read(fd,&byte_buffer,1)<1);
      if (byte_buffer != preamble[0]) continue;
      if (read(fd,&byte_buffer,1)<1) continue;
      if (byte_buffer != preamble[1]) continue;
      else break;
    }

    unsigned int time_out_count = 0;

    if(time_out_count >= 99){
      /****  if timeout ,go out  *****/
      preamble_error_count = 3;
      printf("[Error:IMU-Y] time_out_count >= 99\n");
      imu_data_.timestamp = 0;   ///< 标志陀螺仪模块出错
      while(read(fd,&byte_buffer,1)>-1)printf("%02X ",byte_buffer);
      break;
    }

    size_t receive_count = 0;

    while(receive_count < kBufferSize){
      receive_count += read(fd,datas_buffer+receive_count,kBufferSize-receive_count);
    }
    uint8_t high=0,low=0;
    for (uint32_t i=0; i< kChecksumSize; i++) {
      low += datas_buffer[i];
      high += low;
    }

    if(low == frame.checksum_low && high == frame.checksum_high){
      set_imu_data(frame);

      char *imu_data = new char[sizeof(ImuData)];
      memcpy(imu_data, &imu_data_, sizeof(ImuData));
      this->onMessageReceived(imu_data_);
      ++success_count;
      if(success_count>=(1U<<31)){
        printf("\nsuccess_count overflow.\n");
        success_count = 0;
      }
      if(false and success_count%400==1){
        printf("success_count = 400.");
        std::cout<<std::endl;
      }
    }
    else{
      CRC_check_error_count ++;
      printf("success_count = %ld\n",success_count);
      success_count = 0;
      printf("check  sum %02x,  %02x,  %02x,  %02x, %d  %02x  %02x\n", high,frame.checksum_high, low, frame.checksum_low, frame.count, datas_buffer[45],datas_buffer[46]);
      for(int i = 0;i<46;i++){
        printf("%02x,",datas_buffer[i]);
      }
      printf("\n");
      imu_data_.timestamp = 0;  ///< 标志陀螺仪模块出错
    }
    /*****************************************/
  }
  close(fd);

end:
  std::cout<<"Bye,IMU sensor."<< std::endl;

  return ;
}


void ImuSensorYesense::startWork(){
  std::thread work_thread(std::bind(&ImuSensorYesense::RunRoutine, this));
	work_thread.detach();
}





