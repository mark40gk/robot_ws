#include "rclcpp/rclcpp.hpp"

#include "homework2_2_pkg/homework2_2_pkg_final_server.hpp"

Add2Server::Add2Server(const std::string &node_name)
: Node(node_name)
{
    service2_ = this->create_service<tutorial_interfaces::srv::Plus2>(
        "value2", std::bind(&Add2Server::Callback2, this, std::placeholders::_1, std::placeholders::_2));
    
    RCLCPP_INFO(this->get_logger(), "Service 'value2' ready.");
}

void Add2Server::Callback2(
    const std::shared_ptr<tutorial_interfaces::srv::Plus2::Request> request2,
    std::shared_ptr<tutorial_interfaces::srv::Plus2::Response> response2)
{
    response2->output2 = request2->input2 + 1;
    RCLCPP_INFO(this->get_logger(), "Incoming request\n input: %ld", request2->input2);
    RCLCPP_INFO(this->get_logger(), "Sending back response: [%ld]", response2->output2);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); 

    auto node = std::make_shared<Add2Server>("value2_server"); 

    rclcpp::spin(node); 
    rclcpp::shutdown(); 

    return 0;
}
