#include <fcntl.h>
#include <termios.h>
#define STDIN_FILENO 0

#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include "homework3_pkg/dynamixel_sdk.h"                                  // Uses Dynamixel SDK library

// Control table address
#define TORQUE_ENABLE           24                  // Control table address is different in Dynamixel model
#define GOAL_POSITION           30
#define PRESENT_POSITION        36

// Protocol version
#define PROTOCOL_VERSION                1.0                 // See which protocol version is used in the Dynamixel

// Default setting

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
int Getch()
{
#if defined(__linux__) || defined(__APPLE__)
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
#elif defined(_WIN32) || defined(_WIN64)
  return _Getch();
#endif
}

int Kbhit(void)
{
#if defined(__linux__) || defined(__APPLE__)
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

#elif defined(_WIN32) || defined(_WIN64)
  return _Kbhit();
#endif
}
public: 
void Activate (int value, int dxl_id)
{

  dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler(DEVICENAME);
  dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

  int index = 0;
  int dxl_comm_result = COMM_TX_FAIL;             // Communication result
  int dxl_goal_position=value;   // Goal position

  uint8_t dxl_error = 0;                          // Dynamixel error
  uint16_t dxl_present_position = 0;              // Present position

  //ㅡㅡㅡㅡㅡㅡ포트 여는 코드ㅡㅡㅡㅡㅡㅡ
  if (portHandler->openPort())
  {
    printf("Succeeded to open the port!\n");
  }
  else
  {
    printf("Failed to open the port!\n");
    printf("Press any key to terminate...\n");
    Getch();
  }
  //ㅡㅡㅡㅡㅡㅡ포트 여는 코드ㅡㅡㅡㅡㅡㅡ



  //ㅡㅡㅡㅡㅡㅡ보드레이트 설정 코드ㅡㅡㅡㅡㅡㅡ 
  if (portHandler->setBaudRate(BAUDRATE))
  {
    printf("Succeeded to change the baudrate!\n");
  }
  else
  {
    printf("Failed to change the baudrate!\n");
    printf("Press any key to terminate...\n");
    Getch();
  }
  //ㅡㅡㅡㅡㅡㅡ보드레이트 설정 코드ㅡㅡㅡㅡㅡㅡ 


  //ㅡㅡㅡㅡㅡㅡ다이나믹셀 켜는 코드ㅡㅡㅡㅡㅡㅡ
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, dxl_id, TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
  if (dxl_comm_result != COMM_SUCCESS)
  {
    printf("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
  }
  else if (dxl_error != 0)
  {
    printf("%s\n", packetHandler->getRxPacketError(dxl_error));
  }
  else
  {
    printf("Dynamixel has been successfully connected \n");
  }
  //ㅡㅡㅡㅡㅡㅡ다이나믹셀 켜는 코드ㅡㅡㅡㅡㅡㅡ


  


    //ㅡㅡㅡㅡㅡㅡ목표위치 설정ㅡㅡㅡㅡㅡㅡ
    dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, dxl_id, GOAL_POSITION, dxl_goal_position, &dxl_error);
    if (dxl_comm_result != COMM_SUCCESS)
    {
      printf("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
    }
    else if (dxl_error != 0)
    {
      printf("%s\n", packetHandler->getRxPacketError(dxl_error));
    }
    //ㅡㅡㅡㅡㅡㅡ목표위치 설정ㅡㅡㅡㅡㅡㅡ




    //ㅡㅡㅡㅡㅡㅡ목표위치까지 갈때까지 계속 움직이지 ㅡㅡㅡㅡㅡㅡ
    
    {
      // Read present position
      dxl_comm_result = packetHandler->read2ByteTxRx(portHandler, dxl_id, PRESENT_POSITION, &dxl_present_position, &dxl_error);
      if (dxl_comm_result != COMM_SUCCESS)
      {
        printf("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
      }
      else if (dxl_error != 0)
      {
        printf("%s\n", packetHandler->getRxPacketError(dxl_error));
      }

      printf("[ID:%03d] GoalPos:%03d ", dxl_id, dxl_goal_position );

    }//ㅡㅡㅡㅡㅡㅡ목표위치까지 갈때까지 계속 움직이지 ㅡㅡㅡㅡㅡㅡ




  

  }




};

