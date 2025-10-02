#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
import sys
from moveit_commander import PlanningSceneInterface, roscpp_initialize
from geometry_msgs.msg import PoseStamped

def main():
    # 初始化
    roscpp_initialize(sys.argv)
    rospy.init_node('add_table_scene_node', anonymous=True)

    # 实例化 PlanningSceneInterface 对象
    scene = PlanningSceneInterface()
    rospy.sleep(2)  # 等待 PlanningSceneInterface 初始化

    # 定义桌子的名称
    table_id = 'table'
    
    # 定义桌面的尺寸 (必须和 .world 文件中的桌面尺寸完全一样!)
    table_size = [1.0, 0.8, 0.05]

    # 定义桌面的位姿 (Pose)
    table_pose = PoseStamped()
    # 参考坐标系，通常是 world 或者 base_link
    table_pose.header.frame_id = 'world' 
    # 桌面的中心点位置 (也必须和 .world 文件中的桌面 pose 完全一样!)
    # 注意: .world 文件中整个 table model 的 pose 是 (0.8, 0, 0)
    # 而桌面 surface 的 link 在 model 内的 pose 是 (0, 0, 0.725)
    # 所以，桌面在 world 坐标系下的最终 pose 是 (0.8, 0, 0.725)
    table_pose.pose.position.x = 0.8
    table_pose.pose.position.y = 0.0
    table_pose.pose.position.z = 0.725
    table_pose.pose.orientation.w = 1.0

    # 从场景中移除旧的桌子 (防止重复添加)
    scene.remove_world_object(table_id)
    rospy.sleep(1)

    # 将桌面作为一个碰撞体添加到场景中
    scene.add_box(table_id, table_pose, table_size)
    
    rospy.loginfo("Table added to MoveIt planning scene.")

    # 让节点保持运行，直到被手动关闭
    rospy.spin()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass