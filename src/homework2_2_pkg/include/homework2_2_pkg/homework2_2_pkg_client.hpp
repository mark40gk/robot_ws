#ifndef HOMEWORK2_2_PKG_CLIENT_HPP
#define HOMEWORK2_2_PKG_CLIENT_HPP

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/plus.hpp"

class ClientNode : public rclcpp::Node
{
public:
    explicit ClientNode(const std::string &node_name);

    void Send(int64_t input);

private:
    rclcpp::Client<tutorial_interfaces::srv::Plus>::SharedPtr client_;
};

#endif  // HOMEWORK2_2_PKG_CLIENT_HPP
