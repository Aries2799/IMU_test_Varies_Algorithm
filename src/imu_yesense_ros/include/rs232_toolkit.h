/*
 * rs232_toolkit.h
 *
 *  Created on: 2018-3-15
 *      Author: moxiaobo
 */

#ifndef RS232_TOOLKIT_H_
#define RS232_TOOLKIT_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <inttypes.h>


  /// 串口通讯的基本的常用的参数
  struct UartBasicConfig{
    uint32_t baud_rate;      ///< 波特率
    uint32_t data_bit_size;  ///< 数据位长度
    uint32_t stop_bit_size;  ///< 停止位长度
    char parity;             ///< 校验位
    uint32_t vtime;          ///< 阻塞式通讯时的数据等待时间，单位是100毫秒
    uint32_t vmin;           ///< 阻塞式通讯时的最小读取量
    UartBasicConfig(uint32_t b=0, uint32_t dbs=8,uint32_t sbs=1, char p='n', uint32_t vt=0,uint32_t vm=0):
      baud_rate(b),
      data_bit_size(dbs),
      stop_bit_size(sbs),
      parity(p),
      vtime(vt),
      vmin(vm){

    }
  };

  class Rs232Toolkit {
  private:

  public:
    Rs232Toolkit();
    virtual ~Rs232Toolkit();


    static bool SetSpeed(int fd, int speed);

    static bool SetParity(int fd, int databits, int stopbits, int parity,int vmin);

    static bool SetUartBasic(int fd,UartBasicConfig ubc);

    static void TcIoFlush(int fd);
  };


#endif /* RS232_TOOLKIT_H_ */
