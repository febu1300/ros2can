cmake_minimum_required(VERSION 3.5)
project(ros2_pcan)

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
find_package(std_msgs REQUIRED)

#find_package(can_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)


#add_executable(ros2pcan src/ros2pcan.cpp)
add_executable(teleop2pcan src/teleop2pcan.cpp)

#TARGET_LINK_LIBRARIES(ros2pcan dl -lboost_system  -DNO_RT -lpcanbasic )# -pthread  -lcrypt -lm -lpthread)
TARGET_LINK_LIBRARIES(teleop2pcan dl -lboost_system -DNO_RT -lpcanbasic )# -pthread  -lcrypt -lm -lpthread)
#TARGET_LINK_LIBRARIES(teleop2pcan dl -lboost_system  -DNO_RT -lpcanbasic)
#ament_target_dependencies(ros2pcan rclcpp  std_msgs can_msgs)
ament_target_dependencies(teleop2pcan  rclcpp geometry_msgs std_msgs)

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
 
 
 install(TARGETS
  teleop2pcan
 
  DESTINATION lib/${PROJECT_NAME})
#install(TARGETS  ros2pcan  DESTINATION lib/${PROJECT_NAME})
ament_package()
