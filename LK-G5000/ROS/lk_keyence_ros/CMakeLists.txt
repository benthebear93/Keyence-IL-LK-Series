cmake_minimum_required(VERSION 3.0.2)
project(lk_keyence_ros)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

## Declare a catkin package
catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(LK_GetMeasurement src/LK_GetMeasurement.cpp)
target_link_libraries(LK_GetMeasurement ${catkin_LIBRARIES})
#add_dependencies(LK_GetMeasurement LK_GetMeasurement_generate_messages_cpp)
