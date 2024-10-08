cmake_minimum_required(VERSION 3.5)
project(homework1_pkg)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker src/homework1_pub.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/homework1_sub1.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(listener2 src/homework1_sub2.cpp)
ament_target_dependencies(listener2 rclcpp std_msgs)
install(TARGETS 
  talker
  listener
  listener2
  DESTINATION lib/${PROJECT_NAME})

ament_package()
