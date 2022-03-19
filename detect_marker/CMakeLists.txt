cmake_minimum_required(VERSION 3.1)
project(detect_marker)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${OpenCV_LIBRARY_DIRS})

set(detect_marker_src src/detect_marker.cpp)

add_executable(detect_marker ${detect_marker_src})
target_link_libraries(detect_marker ${OpenCV_LIBRARIES})

target_compile_options(detect_marker PRIVATE -O3 -std=c++11 )

