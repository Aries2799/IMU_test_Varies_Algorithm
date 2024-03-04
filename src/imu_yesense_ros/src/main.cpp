// #include <iostream>
// #include <stdlib.h>
// #include <unistd.h>
// #include <time.h>
// #include "imu_sensor_yesense.h"
// int main(){
//   int count = 0;
//   timespec timestamp;
//   ImuSensorYesense* imu_sensor = new ImuSensorYesense;       ///< 创建读取
//   imu_sensor->startWork();

//   imu_sensor->onMessageReceived = [&](ImuData imu_data){
//     if(count % 200 == 0){

//       clock_gettime(CLOCK_MONOTONIC, &timestamp);
      
//       printf("acc              %+3.4f, %+3.4f, %+3.4f  \r\n",imu_data.acc_x, imu_data.acc_y, imu_data.acc_z);
//       printf("angular_velocity %+3.4f, %+3.4f, %+3.4f  \r\n",imu_data.angular_velocity_roll, imu_data.angular_velocity_pitch, imu_data.angular_velocity_yaw);
//       printf("angle            %+3.4f, %+3.4f, %+3.4f  \r\n",imu_data.magnetic_roll, imu_data.magnetic_pitch, imu_data.magnetic_yaw);
//       std::cout << "++++++++++++++  "<< timestamp.tv_sec  << "." << timestamp.tv_nsec << "   ++++++++++++++" << std::endl;
//     }
//     //<  to do 
//     count ++;
//   };
//   while(1){
//     sleep(1);
//     std::cout << "imu freq  " << count << std::endl;
//     count = 0;
//   }

//   return 0;

// }