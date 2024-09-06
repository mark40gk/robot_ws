#ifndef HOMEWORK2_2_PKG_FINAL_SERVER_HPP
#define HOMEWORK2_2_PKG_FINAL_SERVER_HPP


#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/plus2.hpp"

class Add2Server : public rclcpp::Node
{
public:
    explicit Add2Server(const std::string &node_name);

private:
    void Callback2(
        const std::shared_ptr<tutorial_interfaces::srv::Plus2::Request> request2,
        std::shared_ptr<tutorial_interfaces::srv::Plus2::Response> response2);

    rclcpp::Service<tutorial_interfaces::srv::Plus2>::SharedPtr service2_;
};

#endif // HOMEWORK2_2_PKG_FINAL_SERVER_HPP
