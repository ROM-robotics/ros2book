cmake_minimum_required(VERSION 3.5)
project(pub_sub)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rom_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(desire_publisher src/publisher.cpp)
ament_target_dependencies(desire_publisher rclcpp rom_msgs)

add_executable(desire_subscriber src/subscriber.cpp)
ament_target_dependencies(desire_subscriber rclcpp rom_msgs)

add_executable(server src/service_server.cpp)
ament_target_dependencies(server rclcpp rom_msgs)

add_executable(client src/service_client.cpp)
ament_target_dependencies(client rclcpp rom_msgs)

install(TARGETS
	desire_publisher
  desire_subscriber
  server
  client
	DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()

