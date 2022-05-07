cmake_minimum_required(VERSION 3.0.2)
project(marker_3d_pose)

find_package(catkin REQUIRED COMPONENTS
  fiducial_msgs
  geometry_msgs
  roscpp
  rospy
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES marker_3d_pose
#  CATKIN_DEPENDS fiducial_msgs geometry_msgs roscpp rospy
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(marker_3d_pose src/marker_3d_pose.cpp)
add_dependencies(marker_3d_pose ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(
marker_3d_pose
${catkin_LIBRARIES}
)