//
// Created by hcchou on 2020-10-19.
//

#include <iostream>
#include <string>

#include <octomap/octomap.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <ros/ros.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pcd2octree_node");
    ros::NodeHandle nh;
    std::string input_pcd_file, output_octree_file;
    nh.param<std::string>("/pcd2octree_node/input_pcd_file", input_pcd_file, "input_pcd_file.pcd");
    ROS_INFO("Search input pcd file from %s", input_pcd_file.c_str());
    nh.param<std::string>("/pcd2octree_node/output_octree_file", output_octree_file, "output_octree_file.bt");
    ROS_INFO("Save output octree file %s", output_octree_file.c_str());
    pcl::PointCloud<pcl::PointXYZRGBA> pointcloud;
    pcl::io::loadPCDFile<pcl::PointXYZRGBA> (input_pcd_file, pointcloud);
    octomap::OcTree octree(0.05);
    for(auto p:pointcloud.points) {
        octree.updateNode(octomap::point3d(p.x, p.y, p.z), true);
    }
    octree.updateInnerOccupancy();
    octree.writeBinary(output_octree_file);
    ROS_INFO("Generate octree file done.")
    return 0;
}