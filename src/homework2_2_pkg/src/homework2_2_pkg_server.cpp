#include "homework2_2_pkg/homework2_2_pkg_server.hpp"
#include "rclcpp/rclcpp.hpp"

Server::Server() : Node("node_b")
{
    service_server_ = this->create_service<tutorial_interfaces::srv::Plus>(
        "value1", std::bind(&Server::Callback , this, std::placeholders::_1, std::placeholders::_2));

    client_ = this->create_client<tutorial_interfaces::srv::Plus2>("value2");

    while (!client_->wait_for_service(std::chrono::seconds(1))) 
    {
        RCLCPP_INFO(this->get_logger(), "Waiting for C service to be available...");
    }
}

void Server::Callback(
    const std::shared_ptr<tutorial_interfaces::srv::Plus::Request> request,
    std::shared_ptr<tutorial_interfaces::srv::Plus::Response> response)
{
    response->output = request->input + 1;

    auto server2_request = std::make_shared<tutorial_interfaces::srv::Plus2::Request>();
    RCLCPP_INFO(this->get_logger(), "Incoming request = %ld", request->input);

    server2_request->input2 = response->output;

    auto future = client_->async_send_request(server2_request, 
        [this](rclcpp::Client<tutorial_interfaces::srv::Plus2>::SharedFuture future_response)
         {
            if (future_response.valid()) 
            {
                RCLCPP_INFO(this->get_logger(), "Received response from final server = %ld", future_response.get()->output2);
            } 
            else
             {
                RCLCPP_ERROR(this->get_logger(), "Failed to receive response");
            }
        });
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Server>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
