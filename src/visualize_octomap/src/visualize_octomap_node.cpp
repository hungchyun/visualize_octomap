//
// Created by hcchou on 2020-10-19.
//


#include <iostream>
#include <string>

#include <octomap_msgs/conversions.h>
#include <octomap/octomap.h>
#include <ros/ros.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "visualize_octomap_node");
    ros::NodeHandle nh;
    // ROS loop, specify the frequency.
    ros::Rate loop_rate(1);
    // Octomap publisher.
    ros::Publisher octomap_pub = nh.advertise<octomap_msgs::Octomap>("octomap", 1000);
    // Read .bt octree file.
    std::string input_octree;
    nh.param<std::string>("/visualize_octomap_node/input_octree", input_octree, "fr_079.bt");
    ROS_INFO("Search octree file from %s", input_octree.c_str());
    octomap::OcTree octree(input_octree);
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
    }
    ros::spin();
    return 0;
}