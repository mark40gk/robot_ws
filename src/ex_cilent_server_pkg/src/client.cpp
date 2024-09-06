#include "rclcpp/rclcpp.hpp"
//ROS2 클라이언트 라이브러리 포함
#include "example_interfaces/srv/add_two_ints.hpp"
//ROS2에서 제공하는 기본 서비스 메시지 AddTwoInts 포함
#include <chrono>
//시간 관련 기능을 제공하는 c++표준 라이브러리
#include <cstdlib>
//C표준 라이브러리에서 제공하는 일반적인 유틸리티 함수 포함
#include <memory>

using namespace std::chrono_literals;
//빼야함------------------------------------------

int main(int argc, char **argv)
//argc와 argv는 명령줄 인수
{
  rclcpp::init(argc, argv);
//ros2 클라이언트 라이브러리 초기화

    if (argc != 3) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_two_ints_client X Y");
        return 1;
      //입력 개수가 부족하면 위의 것들 출력 후 1 반환
    }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_client"); 
  //add_two_ints_client 라는 이름의 클라이언트 노드 생성

  rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client =
    node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints"); 
  //서비스를 호출하기 위한 클라리언트 생성, 이 클라이언트는 서버에 add_two_ints라는 이름의 서비스가 등록되어야

  auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
  //request 메시지를 생성하고 이를 가리키는 포인터 생성, 이 객체는 서비스 요청 시 서버로 전송
  request->a = atoll(argv[1]);
  //첫번째 명령줄 인수를 정수로 변환하여 request 객체의 a필드에 저장
  request->b = atoll(argv[2]);
  //두번째 명령줄 인수를 정수로 변환하여 request 객체의 b 필드에 저장

  while (!client->wait_for_service(1s)) { 
  //서비스가 사용 가능할때까지 최대 1초동안 대기
    if (!rclcpp::ok()) {
    //시스템 작동 중지가 되면
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
      //위의 메시지 출력하고 루프 빠져나감
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
    //서비스가 아직 사용 가능하지 않음을 알리는 로그 메시지 출력
  }

  auto result = client->async_send_request(request);
  // 비동기 방식으로 서비스 요청을 전송하고, 결과를 받을 준비함
  
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
    //서비스 호출이 성공했다면
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %ld", result.get()->sum);
  //서비스 응답에서 sum을 가져와서 로그에 출력
  //result.get()->sum은 서비스 응답 객체의 sum 필드에 접근하여 결과 가져옴
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_two_ints");
    //서비스 호출이 실패했다면 오류 메시지 출력
  }
  rclcpp::shutdown();
  //ros2 클라이언트 라이브러리 종료, 
  return 0;
}
