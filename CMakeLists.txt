cmake_minimum_required(VERSION 2.8.12)
project(calib)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_module)
#SET(CMAKE_CXX_FLAGS "-O2 -g -Wall ${CMAKE_CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 14)

find_package(Glog REQUIRED)
find_package(Ceres REQUIRED)
find_package(OpenCV REQUIRED)
find_package(OpenGV REQUIRED)
find_package(PCL REQUIRED)
find_package(Eigen3 REQUIRED)

#add_subdirectory(third_party/opengv)

add_definitions(${PCL_DEFINITIONS})

###########
## Build ##
###########

include_directories(
    ${PCL_INCLUDE_DIRS}
    ${CERES_INCLUDE_DIRS}
)


link_directories(
    ${PCL_LIBRARY_DIRS}
)

add_executable(
    Calib2D3Dtest
    Calib2D3Dtest.cpp
    BasicPly.cpp
    FileFinder.cpp
    image_utility.cpp
    MotionCompute.cpp
    Rejector.cpp
    utility.cpp
)


target_link_libraries(
    Calib2D3Dtest
    ${OpenCV_LIBRARIES}
    ${CERES_LIBRARIES}
    ${GLOG_LIBRARY}
    ${OPENGV_LIBS}
)
target_include_directories(
    Calib2D3Dtest
    PRIVATE
    ${OpenCV_INCLUDE_DIRECTORIES}
)