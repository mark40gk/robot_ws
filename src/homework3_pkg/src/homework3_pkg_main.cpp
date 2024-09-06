#include "homework3_pkg/homework3_pkg_trydynamixel.hpp"//헤더파일

int main(int argc, char **argv)
{
    Motor dynamixel;

    std::thread f1(&Motor::Activate, &dynamixel, atoll(argv[1]), 1);
    std::thread f2(&Motor::Activate, &dynamixel, atoll(argv[2]), 2);
    std::thread f3(&Motor::Activate, &dynamixel, atoll(argv[3]), 3);
    // Motor 안의 Activate 함수 사용, 
    //dynamixel은 Motor의 객체, 입력되는 값의 첫번째는 1번모터에, 두번째는 2번, 세번째는 3번에 전달


    f1.join();// 스레드 종료
    f2.join();// 스레드 종료
    f3.join();// 스레드 종료

    printf("ALL TASKS WERE FINISHED\n");

    return 0;
}
