/**
 * Application program
 * 
 * ...
 * ...
 * ...
 * 
 */

#include <guide_roscpp/application.h>

/**
 * @brief      Constructs the object.
 *
 * @param      _nh_in   The nodehandle in
 * @param      _pnh_in  The private nodehandle in
 */
StringSorterROS::StringSorterROS( ros::NodeHandle &_nh_in, ros::NodeHandle &_pnh_in) :
    nh(_nh_in),
    pnh(_pnh_in) {

  subs_active = true;
  str_sub = nh.subscribe("/hello", 20, &StringSorterROS::strCb, this);
  str_pub = nh.advertise<std_msgs::String>("/sorted",10);

  enable_srv = nh.advertiseService("/enable_string_sorter", &StringSorterROS::enableCb, this);

  ROS_INFO_STREAM("[ROSNODE] string_sorter_node started - subscriptions active...\n");
}

/**
 * @brief      Destroys the object.
 */
StringSorterROS::~StringSorterROS() {
}

void StringSorterROS::strCb(const std_msgs::String::ConstPtr &_p_msg_in) {
  ROS_INFO_STREAM("StringSorterROS::strCb(...)\n");

  std::string str = _p_msg_in->data;
  std::sort(str.begin(), str.end());

  std_msgs::StringPtr p_msg(new std_msgs::String());
  p_msg->data = str;

  str_pub.publish(p_msg);
}

/**
 * @brief      Enables the callback.
 *
 * @param      _req  The request
 * @param      _res  The response
 *
 * @return     { returns True on success, False of failure, sends back _res to the client. }
 */
bool StringSorterROS::enableCb(std_srvs::SetBool::Request  &_req,
                               std_srvs::SetBool::Response &_res) {
  ROS_INFO_STREAM("StringSorterROS::enableCb(...)");
  if (_req.data) {
    if (!subs_active) {
      ROS_INFO_STREAM("Enabling string_sorter_node ...\n");
      str_sub = nh.subscribe("/hello", 20, &StringSorterROS::strCb, this);
      subs_active = true;
    } else {
        ROS_INFO_STREAM("Already enabled ...\n");
    }
  } else {
    if (subs_active) {
      ROS_INFO_STREAM("Disabling string_sorter_node ...\n");
      str_sub.shutdown();
      subs_active = false;
    } else {
        ROS_INFO_STREAM("Already disabled ...\n");
    }
  }

  _res.success = true;
  _res.message = "success";
  return true;
}
