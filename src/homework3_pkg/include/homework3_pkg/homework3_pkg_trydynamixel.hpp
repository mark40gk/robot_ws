#include "homework3_pkg/else/dynamixel_sdk.h"     
#include <fcntl.h> // c 시스템 파일
#include <termios.h>// c 시스템 파일
#include <stdlib.h>// c 시스템 파일
#include <stdio.h>// c 시스템 파일
#include <thread>// c++ 시스템 파일

#define STDIN_FILENO 0


#define ADDR_MX_TORQUE_ENABLE           24                  // Control table address is different in Dynamixel model
#define ADDR_MX_GOAL_POSITION           30
#define ADDR_MX_PRESENT_POSITION        36

#define PROTOCOL_VERSION                1.0                 // See which protocol version is used in the Dynamixel
#define BAUDRATE                        1000000
#define DEVICENAME                      "/dev/ttyUSB0"      // Check which port is being used on your controller
                                                            // ex) Windows: "COM1"   Linux: "/dev/ttyUSB0" Mac: "/dev/tty.usbserial-*"

#define TORQUE_ENABLE                   1                   // Value for enabling the torque
#define TORQUE_DISABLE                  0                   // Value for disabling the torque

#define DXL_MOVING_STATUS_THRESHOLD     10                  // Dynamixel moving status threshold

#define ESC_ASCII_VALUE                 0x1b



class Motor
{
private:
int Getch();


int Kbhit(void);


public: 
void Activate (int value, int dxl_id);

};

