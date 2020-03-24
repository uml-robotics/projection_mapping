# Point Cloud Projection

## Setup
* Download the [`rviz_camera_stream`](https://github.com/uml-robotics/rviz_camera_stream) plugin to your `src` directory: `git clone git@github.com:uml-robotics/rviz_camera_stream.git`
* Enable a "Toggle fullscreen mode" shortcut `Super + F11` in keyboard settings

## Running
* `roslaunch point_cloud_projection camera_publisher.launch`
* `roslaunch point_cloud_projection tf_link_publisher.launch`
* `roslaunch point_cloud_projection tf_publisher.launch`
* `rosrun point_cloud_projection marker_node`
* Run the `projector.rviz` Rviz config: `roscd point_cloud_projection && rviz -d rviz/fetch_projector.rviz`
* Run `image_view` with `rosrun image_view image_view image:=/proj_view/image`
* Make the image fullscreen on the projector screen by pressing `Super + F11`
