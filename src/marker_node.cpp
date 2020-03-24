//
// Created by jennaparrillo on 3/3/20.
//
#include "point_cloud_projection/NavArray.h"

int main(int argc, char** argv){
    ros::init(argc, argv, "projection_marker");

    NavArray na;
    na.publish_array();

    return 0;
}