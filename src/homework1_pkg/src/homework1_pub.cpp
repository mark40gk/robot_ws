
#include <chrono> 
// 시간 관련 함수와 클래스 제공
#include <functional> 
//함수 객체, 람다 표현식, std::bind 등 기능 제공
#include <memory>
//스마트 포인터와 관련한 기능 제공
#include <string>
//문자열 처리에 필요한 std::string 포함
#include "rclcpp/rclcpp.hpp"
//ROS2의 RCLCPP의 해더파일, 
#include "std_msgs/msg/string.hpp"
//표준 메시지 타입인 std_msgs::msg::string의 해더

class MinimalPublisher : public rclcpp::Node
//MinimalPublisher 클래스 정의
//rclcpp:Node 클래스 상속 받아 ROS2 노드 기능 사용 가능
{
public:
//public이기 때문에 외부에서도 접근 가능
  MinimalPublisher() 
  //minimalPublisher 클래스의 생성자, 생성자 호출시 노드 초기화
  : Node("first_publisher"), count_(0)
  //생성자의 초기화 리스트는 부모 클래스인 rclcpp::Node 생성자 호출
  //노드 이름은 first_publisher
  //count_(0)는 멤버변수를 0으로 초기화, 메시지에 포함될 숫자 관
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    //this는 포인터
    //this는 MinimalPublisher를 가리키며, create_publisher함수는 이 객체에서 호출
    //< > 안에것은 타입
    //퍼블리셔를 생성,std_msgs::msgs::msg::String타입의 메시지를 topic이름의 토픽에 발행
    //10은 퍼블리셔의 큐사이즈를 나타냄,큐는 메시지가 전송되기 전에 저장되는 버퍼
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(70), std::bind(&MinimalPublisher::TimerCallback, this));
    //this는 MinimalPublisher를 가리키며, create_wall_paper는 타이머 설정 함수
    //500ms마다 콜백 함수 호출
    //std::bind는 함수 객체 생성 도구, 함수들을 인수들과 결합하여 함수객체 생성 가능
    //타이머가 만료될때마다 TimerCallback함수 호출

  }

private:
//private이기 때문에 외부에서 접근 불가능
  void TimerCallback()
  //타이머가 만료될때마다 호출되는 콜백함수
  {
    auto message = std_msgs::msg::String();
    //auto를 사용하면 변수의 타입을 컴파일러가 자동으로 추론
    //String뒤에 ()가 있는 이유는 기본 생성자를 호출하기 위해
    message.data = "gook luck " + std::to_string(count_++);
    //message의 data 필드에 good luck 문자열과 count_ 값을 붙인 문자열 저장
    //cout_는 매번 증가함

    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    //로그 메시지를 출력.
    //get_logger()는 현재 노드의 log를 가져옴, &s는 출력 메시지 형식 지정
    //message.data.c_str()는 실제 메시지의 내용 가져옴,c_str는  데이터 변환 메서드
    publisher_->publish(message);
    //생성한 메시지를 퍼블리셔를 통해 ROs2 네트워크에 퍼블리시
  }
  rclcpp::TimerBase::SharedPtr timer_;
  //SharedPtr는 rclcpp 라이브러리에서 제공하는 스마트 포인터
  //timer_는 ROS2 타이머를 가리키는 스마트 포인터
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  //SharedPtr는 rclcpp 라이브러리에서 제공하는 스마트 포인터
  //publisher_는 <std_msgs::msg::String> 타입의 메시지 퍼를리시하는 스마트 포인터
  size_t count_;
  //메시지의 일련번호를 관리하는 변수
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  //ROS2 노드 초기화
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  //spin을 통해 함수가 계속 반복됨
  //std::make_shared<MinimalPublisher>()는 C++ 표준 라이브러리 함수
  //MinimalPublisher 클래스의 객체를 std::shared_ptr로 생성
  rclcpp::shutdown();
  //ROS2 종료
  return 0;
  //프로그램 종료
}
