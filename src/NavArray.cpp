//
// Created by jennaparrillo on 3/24/20.
//

#include "point_cloud_projection/NavArray.h"
#include <iostream>

void NavArray::publish_array() {
    ros::Subscriber sub = n.subscribe("/move_base/NavfnROS/plan", 1000, &NavArray::callback, this);

    while(ros::ok())
        ros::spinOnce();
}

void NavArray::callback(const nav_msgs::Path msg) {
    visualization_msgs::MarkerArray marker_array;
    int size = msg.poses.size();
    //Edits the frequency of arrows if there aren't enough poses
    int frequency = (size >= FREQUENCY_DEFAULT + 1) ? FREQUENCY_DEFAULT : size - 1;
    int final_pose = size - 1 - ((size - 1) % frequency);

    int marker_count = 1;
    int next;
    for (int i = frequency; i <= size - 1; i = next) {
        visualization_msgs::Marker marker;
        marker.header.frame_id = "map";
        marker.header.stamp = ros::Time();
        marker.id = marker_count;
        marker.type = visualization_msgs::Marker::ARROW;
        marker.action = visualization_msgs::Marker::ADD;

        int prev_pose = (i == size -1) ? final_pose : i - frequency;
        geometry_msgs::Point p1;
        p1.x = msg.poses.at(prev_pose).pose.position.x;
        p1.y = msg.poses.at(prev_pose).pose.position.y;
        p1.z = msg.poses.at(prev_pose).pose.position.z;
        geometry_msgs::Point p2;
        p2.x = msg.poses.at(i).pose.position.x;
        p2.y = msg.poses.at(i).pose.position.y;
        p2.z = msg.poses.at(i).pose.position.z;
        marker.points.push_back(p1);
        marker.points.push_back(p2);

        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = 0.0;
        marker.pose.orientation.w = 1.0;

        marker.scale.x = 0.02;
        marker.scale.y = 0.04;
        marker.scale.z = 0.05;
        marker.color.a = 1.0;
        marker.color.r = 1.0;
        marker.color.g = 1.0;
        marker.color.b = 0.0;

        marker_array.markers.push_back(marker);

        //std::cout << "Count: " << marker_count << " Starting point: (" << p1.x << " , " << p1.y << " , " << p1.z << ") Ending point: (" << p2.x << " , " << p2.y << " , " << p2.z << ")" << std::endl;

        ++marker_count;
        //Determines the next pose
        next = (i == final_pose) ? (size -1) : (i + frequency);
    }
    pub.publish( marker_array );
}