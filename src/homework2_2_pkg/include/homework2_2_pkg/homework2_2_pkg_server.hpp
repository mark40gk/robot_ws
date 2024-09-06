#ifndef HOMEWORK2_2_PKG_SERVER_HPP
#define HOMEWORK2_2_PKG_SERVER_HPP

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/plus.hpp"
#include "tutorial_interfaces/srv/plus2.hpp"

class Server : public rclcpp::Node
{
public:
    Server();

private:
    void Callback(
        const std::shared_ptr<tutorial_interfaces::srv::Plus::Request> request,
        std::shared_ptr<tutorial_interfaces::srv::Plus::Response> response);

    rclcpp::Service<tutorial_interfaces::srv::Plus>::SharedPtr service_server_;
    rclcpp::Client<tutorial_interfaces::srv::Plus2>::SharedPtr client_;
};

#endif // HOMEWORK2_2_PKG_SERVER_HPP
