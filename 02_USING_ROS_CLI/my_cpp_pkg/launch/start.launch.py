
from launch import LaunchDescription
from launch_ros.actions import Node
 
def generate_launch_description():
   return LaunchDescription([
       Node(
           package='turtlesim',
           namespace='romrobot',
           executable='turtlesim_node',
       ),
       Node(
           package='my_cpp_pkg',
           namespace='romrobot',
           executable='talker',
       ),
       Node(
           package='turtlesim',
           executable='mimic',
           namespace='romrobot',
           name='mimic',
           remappings=[
               ('/input/pose', '/romrobot/turtle1/pose'),
               ('/output/cmd_vel', '/romrobot/turtle1/cmd_vel')
           ]
       )
   ])
