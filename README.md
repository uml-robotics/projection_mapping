# Point Cloud Projection

## Setup
* Download the [`rviz_camera_stream`](https://github.com/lucasw/rviz_camera_stream) plugin to your `src` directory: `git clone https://github.com/lucasw/rviz_camera_stream`
* Enable a "Toggle fullscreen mode" shortcut `Super + F11` in keyboard settings

## Running
* `roslaunch point_cloud_projection camera_publisher.launch`
* `roslaunch point_cloud_projection tf_publisher.launch`
* Run the `projector.rviz` Rviz config: `roscd point_cloud_projection && rviz -d rviz/*.rviz`
* Run `image_view` with `rosrun image_view image_view image:=/proj_view/image`
* Make the image fullscreen on the projector screen by pressing `Super + F11`
