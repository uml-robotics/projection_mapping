//
// Created by jennaparrillo on 3/24/20.
//

#pragma once

#include <nav_msgs/Path.h>
#include <visualization_msgs/MarkerArray.h>
#include <rviz_visual_tools/rviz_visual_tools.h>
#include <ros/ros.h>

class NavArray {
public:
    NavArray() {visual_tools.reset(new rviz_visual_tools::RvizVisualTools("base_scan","/visualization_marker_array"));}
    void publish_array();
private:
    ros::NodeHandle n;
    rviz_visual_tools::RvizVisualToolsPtr visual_tools;
    //Frequency of arrows. Bigger number = less arrows.
    const int FREQUENCY_DEFAULT = 9;
    visualization_msgs::MarkerArray marker_array;
    void callback(const nav_msgs::Path msg);
};

