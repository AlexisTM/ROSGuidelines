/**
 * Application node
 * 
 * ...
 * ...
 * ...
 * 
 */

#include <ros/ros.h>
#include <guide_roscpp/application.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "string_sorter_node");
  ROS_INFO("[ROSNODE] Starting string_sorter_node...");
  ros::NodeHandle nh, pnh("~");

  try{
    StringSorterROS string_sorter(nh, pnh);
    ros::spin();
  } catch(std::runtime_error& e) {
    ROS_ERROR("string_sorter_node exception: %s", e.what());
    return -1;
  }

  return 0;
}
