cmake_minimum_required(VERSION 3.0.2)
project(IL_Keyence_ros)

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

add_executable(IL_GetMeasurement src/IL_GetMeasurement.cpp)
target_link_libraries(IL_GetMeasurement ${catkin_LIBRARIES})
#add_dependencies(IL_GetMeasurement IL_GetMeasurement_generate_messages_cpp)
