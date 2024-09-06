
#include <functional>
//std::bind와 같은 함수 객체 및 함수 포인터 관련 기능 사용하기 위한 
#include <memory>
//스마트 포인터 해더파일
#include "rclcpp/rclcpp.hpp"
//ROS2 라이브러리의 해더파일
#include "std_msgs/msg/string.hpp"
//std_msgs::msg::String 타입을 사용하기 위한 해더 파일

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("first_subscriber")
  //노드의 이름을 first_subscriber로 설정
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("output_topic", 10);
      //publisher_ 은 스마트포인터

    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::TopicCallback, this, std::placeholders::_1));
      //subscription_ 은 스마트포인터
      
  }

private:
  void TopicCallback(const std_msgs::msg::String & msg) const
  //const기에 객체 상태 변경 불가능
  {
    RCLCPP_INFO(this->get_logger(), "middle value is: '%s'", msg.data.c_str());
    //RCLCPP_INFO: 로그 메시지를 출력하는 매크로
     auto new_msg = std_msgs::msg::String();
    new_msg.data = msg.data; 
    publisher_->publish(new_msg);
    //새 메시지를 퍼블리셔를 통해 발향
    RCLCPP_INFO(this->get_logger(), "Published: '%s'", new_msg.data.c_str());
      
  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  //메시지를 수신하는 구독자의 스마트포인터

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  //메시지를 발행하는 퍼블리셔의 스마트포인터
};





int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
 //ROS2의 라이프사이클 초기화
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
 //노드를 생성하고 노드가 실행되도록 함, 노드는 콜백을 기다리며 작업
  rclcpp::shutdown();
  return 0;
}
