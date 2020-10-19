# visualize_octomap

#### Generate .bt File via .pcd File
`$rosrun visualize_octomap pcd2octree_node`

#### Publish Octomap via .bt File
`$rosrun visualize_octomap visualize_octomap_node`

#### Example

**Download dataset**  
`mkdir -p demo/b3-2016-04-05-15-51-36`  
`wget -P demo/b3-2016-04-05-15-51-36 https://storage.googleapis.com/cartographer-public-data/bags/backpack_3d/with_intensities/b3-2016-04-05-15-51-36.bag`  

**Use Google Cartographer dataset, b3-2016-04-05-15-51-36, to generate .pbstream file**  
`source install_isolated/setup.bash`  
`roslaunch cartographer_ros offline_backpack_3d.launch bag_filenames:=demo/b3-2016-04-05-15-51-36/b3-2016-04-05-15-51-36.bag`  

**Generate .pcd file**  
`roslaunch cartographer_ros assets_writer_backpack_3d.launch bag_filenames:=demo/b3-2016-04-05-15-51-36/b3-2016-04-05-15-51-36.bag pose_graph_filename:=demo/b3-2016-04-05-15-51-36/b3-2016-04-05-15-51-36.bag.pbstream`  

**Convert .pcd to .bt**  
`roslaunch visualize_octomap pcd2octree.launch`  

**Publish octomap**    
`roslaunch visualize_octomap publish_octomap.launch`  

