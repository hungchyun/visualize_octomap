//
// Created by hcchou on 2020-10-19.
//

#include <octomap_msgs/conversions.h>
#include <octomap/octomap.h>
#include <ros/ros.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "publish_octomap");
    ros::NodeHandle nh;
    // ROS loop, specify the frequency.
    ros::Rate loop_rate(100);
    // Octomap publisher.
    ros::Publisher octomap_pub = nh.advertise<octomap_msgs::Octomap>("octomap", 1000);
    // Read .bt octree file.
    octomap::OcTree octree("/home/hcchou/Downloads/fr_079.bt");
    // Define octo message and set data.
    octomap_msgs::Octomap octo_msg;
    octomap_msgs::binaryMapToMsg(octree, octo_msg);
    octo_msg.header.frame_id = "octomap";
    octo_msg.header.stamp = ros::Time::now();
    // Publish octomap in a while loop.
    while(ros::ok()) {
        octomap_pub.publish(octo_msg);
        ros::spinOnce();
        loop_rate.sleep();
        // ROS_INFO("Publish octomap.");
    }
    ros::spin();
    return 0;
}