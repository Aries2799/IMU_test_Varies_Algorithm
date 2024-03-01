cmake_minimum_required(VERSION 3.5)

project(imu_yesense)
# SET(CMAKE_C_COMPILER "aarch64-linux-gnu-gcc")
# SET(CMAKE_CXX_COMPILER "aarch64-linux-gnu-g++")
set(CMAKE_BUILD_TYPE Release)
include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

aux_source_directory(${PROJECT_SOURCE_DIR} ALL_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR} MAIN)

message(${PROJECT_SOURCE_DIR})

include_directories(
  ${PROJECT_SOURCE_DIR}
)
link_directories(
  ${PROJECT_SOURCE_DIR}/lib
)
add_executable(${PROJECT_NAME} ${ALL_SRCS} ${MAIN})
target_link_libraries(${PROJECT_NAME} -lpthread)
