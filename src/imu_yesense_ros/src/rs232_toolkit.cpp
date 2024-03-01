/*
 * rs232_toolkit.cpp
 *
 *  Created on: 2018-3-15
 *      Author: moxiaobo
 */

#include "rs232_toolkit.h"
#include "termios.h"
#include <iostream>

// using namespace deepros::sensor;

Rs232Toolkit::Rs232Toolkit() {

}

Rs232Toolkit::~Rs232Toolkit() {
}


bool Rs232Toolkit::SetSpeed(int fd, int speed = B115200)
{
    struct termios Opt;

    if(tcgetattr(fd, &Opt) != 0)
    {
        std::perror("tcgetattr fd");
        return false;
    }

    tcflush(fd, TCIOFLUSH);
    cfsetispeed(&Opt, speed);
    cfsetospeed(&Opt, speed);
    if(tcsetattr(fd, TCSANOW, &Opt) != 0)
    {
        std::perror("tcsetattr fd");
        return false;
    }
    tcflush(fd, TCIOFLUSH);

    return true;
}

bool Rs232Toolkit::SetParity(int fd, int databits, int stopbits, int parity,int vmin)
{
    struct termios Opt;
    if(tcgetattr(fd, &Opt) != 0)
    {
        std::perror("tcgetattr fd");
        return false;
    }
   Opt.c_cflag |= (CLOCAL | CREAD);        //

    switch(databits)        //
    {
    case 7:
        Opt.c_cflag &= ~CSIZE;
        Opt.c_cflag |= CS7;
        break;
    case 8:
        Opt.c_cflag &= ~CSIZE;
        Opt.c_cflag |= CS8;
        break;
    default:
        std::perror("Unsupported data size.\n");
        return false;
    }

    switch(parity)            //
    {
    case 'n':
    case 'N':
        Opt.c_cflag &= ~PARENB;        //
        Opt.c_iflag &= ~INPCK;        //enable parity checking
        break;
    case 'o':
    case 'O':
        Opt.c_cflag |= PARENB;        //enable parity
        Opt.c_cflag |= PARODD;        //
        Opt.c_iflag |= INPCK;            //disable parity checking
        break;
    case 'e':
    case 'E':
        Opt.c_cflag |= PARENB;        //enable parity
        Opt.c_cflag &= ~PARODD;        //
        Opt.c_iflag |= INPCK;            //disable pairty checking
        break;
    case 's':
    case 'S':
        Opt.c_cflag &= ~PARENB;
        Opt.c_cflag &= ~CSTOPB;
        Opt.c_iflag |= INPCK;            //disable pairty checking
        break;
    default:
      std::perror("Unsupported parity.\n");
      return false;
    }

    switch(stopbits)
    {
    case 1:
        Opt.c_cflag &= ~CSTOPB;
        break;
    case 2:
        Opt.c_cflag |= CSTOPB;
        break;
    default:
      std::perror("Unsupported stopbits.\n");
      return false;
    }

    Opt.c_cflag |= (CLOCAL | CREAD);

    Opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    Opt.c_oflag &= ~OPOST;
    Opt.c_oflag &= ~(ONLCR | OCRNL);

    Opt.c_iflag &= ~(ICRNL | INLCR);
    Opt.c_iflag &= ~(IXON | IXOFF | IXANY);

    tcflush(fd, TCIFLUSH);
    Opt.c_cc[VTIME] = 5;
    Opt.c_cc[VMIN] = vmin;
    if(tcsetattr(fd, TCSANOW, &Opt) != 0)
    {
        std::perror("tcsetattr fd");
        return false;
    }

    return true;
}

bool Rs232Toolkit::SetUartBasic(int fd,UartBasicConfig ubc){
  if(!SetSpeed(fd,ubc.baud_rate)) return false;
  if(!SetParity(fd,ubc.data_bit_size,ubc.stop_bit_size,ubc.parity,ubc.vmin)){
    return false;
  }
  return true;
}

void Rs232Toolkit::TcIoFlush(int fd){
  tcflush(fd, TCIOFLUSH);
}
