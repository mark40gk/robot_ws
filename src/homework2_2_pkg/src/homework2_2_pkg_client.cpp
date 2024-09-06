#include "homework2_2_pkg/homework2_2_pkg_client.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <memory>

ClientNode::ClientNode(const std::string &node_name)
: Node(node_name)
{
    client_ = this->create_client<tutorial_interfaces::srv::Plus>("value1");

    while (!client_->wait_for_service(std::chrono::seconds(1)))
    {
        if (!rclcpp::ok())
        {
            RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
            rclcpp::shutdown();
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Service not available, waiting again...");
    }
}

void ClientNode::Send(int64_t input)
{
    auto request = std::make_shared<tutorial_interfaces::srv::Plus::Request>();
    request->input = input;

    auto future = client_->async_send_request(request, 
        [this](rclcpp::Client<tutorial_interfaces::srv::Plus>::SharedFuture future_response) {
            if (future_response.valid()) 
            {
                RCLCPP_INFO(this->get_logger(), "Received response: %ld", future_response.get()->output);
            } 
            else
             {
                RCLCPP_ERROR(this->get_logger(), "Failed to receive response");
            }
        });

    if (rclcpp::spin_until_future_complete(shared_from_this(), future) != rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to call service");
    }
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    if (argc != 2)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Usage: %s <input_value>", argv[0]);
        return 1;
    }

    auto node = std::make_shared<ClientNode>("value1_client");
    int64_t input_value = atoll(argv[1]);
    node->Send(input_value);

    rclcpp::shutdown();
    return 0;
}
