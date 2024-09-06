cmake_minimum_required(VERSION 3.5)
project(homework2_2_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tutorial_interfaces REQUIRED)


add_executable(server src/homework2_2_pkg_server.cpp)
ament_target_dependencies(server
  rclcpp
  tutorial_interfaces)


  include_directories(include)

  
add_executable(client src/homework2_2_pkg_client.cpp)
ament_target_dependencies(client
  rclcpp
  tutorial_interfaces)

add_executable(final_server src/homework2_2_pkg_final_server.cpp)
ament_target_dependencies(final_server
  rclcpp
  tutorial_interfaces)

install(TARGETS
  server
  client
  final_server
  DESTINATION lib/${PROJECT_NAME})

ament_package()
