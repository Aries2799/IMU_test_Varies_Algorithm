cmake_minimum_required(VERSION 3.0.2)
project(imu_yesense_ros)

## 编译为C++11，支持最新的C++特性
add_compile_options(-std=c++11)

## 查找catkin和任何catkin包的依赖
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  message_generation
  sensor_msgs
)


## 声明ROS消息、服务和动作的生成
add_message_files(
  FILES
  ImuExtended.msg
)

generate_messages(
  DEPENDENCIES
  sensor_msgs
)

## 声明catkin特定配置
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp  sensor_msgs message_runtime geometry_msgs 
)

## 指定头文件的位置
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## 声明可执行文件
add_executable(${PROJECT_NAME}_node 
src/rosmain.cpp 
src/AttitudeCalculator.cpp 
src/imu_sensor_yesense.cpp 
src/rs232_toolkit.cpp
src/main.cpp
)

## 添加cmake目标依赖
add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## 指定链接库
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  pthread # 如果需要链接到pthread
)
