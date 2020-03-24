//
// Created by jennaparrillo on 3/24/20.
//

#pragma once

#include <nav_msgs/Path.h>
#include <visualization_msgs/MarkerArray.h>
#include <ros/ros.h>

class NavArray {
public:
    NavArray() : pub(n.advertise<visualization_msgs::MarkerArray>( "/visualization_marker_array", 1000 )){}
    void publish_array();
private:
    ros::NodeHandle n;
    ros::Publisher pub;
    //Frequency of arrows. Bigger number = less arrows.
    const int FREQUENCY_DEFAULT = 7;
    void callback(const nav_msgs::Path msg);
};

