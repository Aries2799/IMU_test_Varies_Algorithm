cmake_minimum_required(VERSION 3.0.2)
project(imu_yesense_ros)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  message_generation
)

add_message_files(
  FILES
  ImuExtended.msg
)

generate_messages(
  DEPENDENCIES
  sensor_msgs
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp sensor_msgs message_runtime
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(imu_yesense_ros_node src/rosmain.cpp src/imu_sensor_yesense.cpp src/rs232_toolkit.cpp)
add_dependencies(imu_yesense_ros_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(imu_yesense_ros_node ${catkin_LIBRARIES})
