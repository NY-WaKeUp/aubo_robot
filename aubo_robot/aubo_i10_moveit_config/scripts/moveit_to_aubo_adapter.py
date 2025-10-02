#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
import actionlib
from control_msgs.msg import FollowJointTrajectoryAction
from trajectory_msgs.msg import JointTrajectoryPoint

class MoveItAuboAdapter:
    def __init__(self):
        rospy.init_node('moveit_to_aubo_adapter')

        # 1. 创建一个 Publisher，用于向 aubo_driver 发送单个轨迹点
        #    话题名称 /moveItController_cmd 必须与 aubo_driver.cpp 中订阅的名称完全一致
        self.point_publisher = rospy.Publisher('/moveItController_cmd', JointTrajectoryPoint, queue_size=100)
        
        # 2. 创建一个 Action Server，用于接收来自 MoveIt 的轨迹
        #    Action 名称 'follow_joint_trajectory' 是 MoveIt 默认使用的
        self.action_server = actionlib.SimpleActionServer(
            'follow_joint_trajectory', 
            FollowJointTrajectoryAction, 
            execute_cb=self.execute_trajectory_callback, 
            auto_start=False
        )
        
        # 3. 启动 Action Server
        self.action_server.start()
        
        rospy.loginfo("MoveIt to Aubo Adapter is ready and waiting for a trajectory.")

    def execute_trajectory_callback(self, goal):
        rospy.loginfo("Received a trajectory from MoveIt with %d points.", len(goal.trajectory.points))
        
        # 获取轨迹中的所有点
        trajectory_points = goal.trajectory.points
        
        # 记录上一个点的时间，用于计算两点间的延迟
        last_time = rospy.Duration(0.0)

        