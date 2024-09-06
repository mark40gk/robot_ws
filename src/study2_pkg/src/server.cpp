#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

#include <memory>

void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
          std::shared_ptr<example_interfaces::srv::AddTwoInts::Response>  response)
//서비스 요청을 처리하는 콜백 함수, request, response 두개의 포인터를 인자로 받음
{
  response->sum = request->a + request->b; 
  //request 에 두개 숫자 받아서 더한것을 response 에 넣는다.
  // ->는 포인터 연산자, a->b면 a가 가리키는 객체의 b 멤버에 접근
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
                request->a, request->b);
  //들어오는 값 출력 (로거를 사용해서)
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
  //나가는 값 출력 (로거를 사용해서)

}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv); 
  //ROS2 클라이언트 라이브러리 초기화

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server"); 
  //add_two_ints_server 라는 이름의 노드
  //make_shared는 std::shared_ptr를 생성하는 편리한 방법

  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service =
    node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", &add);
  //add_two_ints라는 이름의 서비스 노드를 만들고 add 함수를 네트웍에 자동으로 advertise 한다.


  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");
  //서비스가 준비되었음을 나타내는 로그 메시지 출력 

  rclcpp::spin(node);
  rclcpp::shutdown();
}
