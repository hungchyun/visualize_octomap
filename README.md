# visualize_octomap

#### Generate .bt File via .pcd File
`$rosrun visualize_octomap pcd2octree_node`

#### Publish Octomap via .bt File
`$rosrun visualize_octomap visualize_octomap_node`

#### Example

#####1. Download dataset
`mkdir -p demo/b3-2016-04-05-15-51-36`  
`wget -P demo/b3-2016-04-05-15-51-36 https://storage.googleapis.com/cartographer-public-data/bags/backpack_3d/with_intensities/b3-2016-04-05-15-51-36.bag`  

#####2. Use Google Cartographer dataset, b3-2016-04-05-15-51-36, to generate .pbstream file (Cartographer part)  
`source ${google_cartographer}/install_isolated/setup.bash`  
`roslaunch cartographer_ros offline_backpack_3d.launch bag_filenames:=demo/b3-2016-04-05-15-51-36/b3-2016-04-05-15-51-36.bag`  

#####3. Generate .pcd file (Cartographer part)  
`roslaunch cartographer_ros assets_writer_backpack_3d.launch bag_filenames:=demo/b3-2016-04-05-15-51-36/b3-2016-04-05-15-51-36.bag pose_graph_filename:=demo/b3-2016-04-05-15-51-36/b3-2016-04-05-15-51-36.bag.pbstream`  

#####4. Convert .pcd to .bt (visualize_octomap part)  
source devel/setup.bash  
`roslaunch visualize_octomap pcd2octree.launch`  

#####5. Publish octomap (visualize_octomap part)    
`roslaunch visualize_octomap publish_octomap.launch`  

