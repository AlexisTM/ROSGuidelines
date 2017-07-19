/**
 * Application header
 * 
 * ...
 * ...
 * ...
 * 
 */

#ifndef MY_APPLICATION_ROS_H
#define MY_APPLICATION_ROS_H

// C++ standard libraries
#include <iostream>
#include <string>
#include <algorithm>

// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_srvs/SetBool.h>

/**
 * @brief      Class to sort ros strings.
 */
class StringSorterROS {
public:
  StringSorterROS( ros::NodeHandle &_nh_in, ros::NodeHandle &_pnh_in);
  ~StringSorterROS();
private:
  ros::NodeHandle &nh, &pnh;

  bool subs_active;
  ros::Subscriber str_sub;
  ros::Publisher str_pub;
  void strCb(const std_msgs::String::ConstPtr &_p_msg);

  ros::ServiceServer enable_srv;
  bool enableCb(std_srvs::SetBool::Request  &_req,
                std_srvs::SetBool::Response &_res);
};

#endif //MY_APPLICATION_ROS_H