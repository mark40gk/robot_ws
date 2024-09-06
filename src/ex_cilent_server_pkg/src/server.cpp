#include "rclcpp/rclcpp.hpp"
//ROS2 라이브러리
#include "example_interfaces/srv/add_two_ints.hpp"
//ROS2의 기본 서비스 메시지인 add_two_ints 포함
#include <memory>
//스마트 포인터를 사용하기 위한

void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
          std::shared_ptr<example_interfaces::srv::AddTwoInts::Response>      response)
//서비스 요청을 처리하기 위한 콜백함수, 클라이언트로부서 두개의 정수를 받아 합을 응답 반환
//const~~첫줄: 서비스 요청을 나타내는 스마트 포인터. 요청된 두 정수 a와 b에 접근 가능
//두번쨰줄: 서비스 응답을 나타내는 스마트 포인터, 결과를 클라이언트에게 반환하기 위해 사용
{
  response->sum = request->a + request->b; 
  //요청에서 받은 두 정수 a와 b를 더한 결과를 응답객체의 sum필드에 저장
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
                request->a, request->b);
  //RCLCPP_INFO는 ROS2 로그함수,요쳥된 두 정수를 로그에 출력
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}
//더한 결과를 로그에 출력, long int는 큰 범위의 정수를 저장하기 위해 사용 

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv); 
  //ROS2 클라이언트 라이브러리 초기화

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server"); 
  //add_two_ints라는 이름의 서비스 노드를 만들고 add 함수를 네트웍에 자동으로 advertise 한다.

  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service =
    node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", &add);
    //흰색 글씨는 다른이름으로 해도 됨
    //서비스 서버를 나타내는 스마트 포인터, add_two_ints라는 이름의 서비스서버 생성
    //서비스 요청이 들어오면 add함수가 호출되도록 설정 

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");
  //서비스가 준비되었음을 알리는 로그 메시지 출력

  rclcpp::spin(node);
  //이 함수는 노드가 계속 실행되도록 하고, 서비스 요청이 들어올 때까지 대기
  rclcpp::shutdown();
  //ros2 클라이언트 라이브러리 종료
}
