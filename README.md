# Point Cloud Projection

## Setup
* Download the [`rviz_camera_stream`](https://github.com/uml-robotics/rviz_camera_stream) plugin to your `src` directory: `git clone git@github.com:uml-robotics/rviz_camera_stream.git`
* Enable a "Toggle fullscreen mode" shortcut `Super + F11` in keyboard settings

## Running
* `roslaunch point_cloud_projection point_cloud_projection.launch`
* `rosrun point_cloud_projection marker_node`
* Run the `fetch_projector.rviz` Rviz config: `roscd point_cloud_projection && rviz -d rviz/fetch_projector.rviz`
* Run `image_view` with `rosrun image_view image_view image:=/proj_view/image`
* Make the image fullscreen on the projector screen by pressing `Super + F11`

## Launch Files
`camera_publisher.launch` uses `projector_camera_info.yaml` to publish `/proj_view/camera_info`, which is a topic of type sensor_msgs::CameraInfo

`tf_publisher.launch` creates 2 static transform publishers `proj_link` and `proj_view`. `proj_link` is the center of the bottom of the projector, and `proj_view` is the lense of the projector

`point_cloud_projection.launch` launches both `camera_publisher.launch` and `tf_publisher.launch`
