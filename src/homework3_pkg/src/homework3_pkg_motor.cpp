#include "homework3_pkg/homework3_pkg_trydynamixel.hpp"//헤더파일

int Motor::Getch()
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
#endif //Getch
}

int Motor::Kbhit(void)
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
#endif//Kbhit
}

void Motor::Activate (int value, int dxl_id)
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
  }
  else
  {
    printf("Failed to change the baudrate!\n");
    printf("Press any key to terminate...\n");
    Getch();
  }
  //ㅡㅡㅡㅡㅡㅡ보드레이트 설정 코드ㅡㅡㅡㅡㅡㅡ 


  //ㅡㅡㅡㅡㅡㅡ다이나믹셀 켜는 코드ㅡㅡㅡㅡㅡㅡ
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, dxl_id, ADDR_MX_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
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
  }
  //ㅡㅡㅡㅡㅡㅡ다이나믹셀 켜는 코드ㅡㅡㅡㅡㅡㅡ


  


    //ㅡㅡㅡㅡㅡㅡ목표위치 설정ㅡㅡㅡㅡㅡㅡ
    dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, dxl_id, ADDR_MX_GOAL_POSITION, dxl_goal_position, &dxl_error);
    if (dxl_comm_result != COMM_SUCCESS)
    {
      printf("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
    }
    else if (dxl_error != 0)
    {
      printf("%s\n", packetHandler->getRxPacketError(dxl_error));
    }
    //ㅡㅡㅡㅡㅡㅡ목표위치 설정ㅡㅡㅡㅡㅡㅡ




    //ㅡㅡㅡㅡㅡㅡ목표위치로ㅡㅡㅡㅡㅡㅡ
    
    {
      // Read present position
      dxl_comm_result = packetHandler->read2ByteTxRx(portHandler, dxl_id, ADDR_MX_PRESENT_POSITION, &dxl_present_position, &dxl_error);
      if (dxl_comm_result != COMM_SUCCESS)
      {
        printf("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
      }
      else if (dxl_error != 0)
      {
      printf("%s\n", packetHandler->getRxPacketError(dxl_error));
      }

      printf("[ID:%03d] GoalPos:%03d ", dxl_id, dxl_goal_position );
      printf("\n");


    }   
   //ㅡㅡㅡㅡㅡㅡ목표위치로ㅡㅡㅡㅡㅡㅡ


  }



