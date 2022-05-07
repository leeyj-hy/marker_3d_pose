#include <ros/ros.h>
#include "fiducial_msgs/FiducialTransformArray.h"




void marker_3d_translation_rotation(const fiducial_msgs::FiducialTransformArray &msg)
{
  for(int i=0; i<msg.transforms.size() ; i++)
  {
    ROS_INFO("MARKER_ID : %d", msg.transforms[i].fiducial_id);
    ROS_INFO("TRANS_X : %f", msg.transforms[i].transform.translation.x);
    ROS_INFO("TRANS_Y : %f", msg.transforms[i].transform.translation.y);
    ROS_INFO("TRANS_Z : %f", msg.transforms[i].transform.translation.z);
    ROS_INFO("QUATER_X : %f", msg.transforms[i].transform.rotation.x);
    ROS_INFO("QUATER_Y : %f", msg.transforms[i].transform.rotation.y);
    ROS_INFO("QUATER_Z : %f", msg.transforms[i].transform.rotation.z);
    ROS_INFO("QUATER_W : %f", msg.transforms[i].transform.rotation.w);
    ROS_INFO("====================");

  }
  //ROS_INFO("x : %d, y: %d, z: %d",ts.transform.translation->x, ts.transform.translation->y, ts.transform.translation->z);
  

}
/*
						std_msgs/Header header
  uint32 seq
  time stamp
  string frame_id
int32 image_seq
fiducial_msgs/FiducialTransform[] transforms
  int32 fiducial_id
  geometry_msgs/Transform transform
    geometry_msgs/Vector3 translation
      float64 x
      float64 y
      float64 z
    geometry_msgs/Quaternion rotation
      float64 x
      float64 y
      float64 z
      float64 w
  float64 image_error
  float64 object_error
  float64 fiducial_area

                        */
int main(int argc, char **argv)
{

	ros::init(argc, argv, "marker_3d_pose");

 
  	ros::NodeHandle nh;

  
  	ros::Subscriber sub = nh.subscribe("/fiducial_transforms", 10, marker_3d_translation_rotation);

 
  	ros::spin();

  	return 0;
}