#!/usr/bin/env python

import rospy
import moveit_commander
import sys

def test_moveit_basic():
    """测试MoveIt基本功能"""
    
    print("=== MoveIt诊断测试 ===")
    
    try:
        # 初始化
        moveit_commander.roscpp_initialize(sys.argv)
        rospy.init_node('moveit_diagnostic_test')
        
        # 创建MoveIt接口
        robot = moveit_commander.RobotCommander()
        scene = moveit_commander.PlanningSceneInterface()
        # 尝试正确的规划组名称
        try:
            group = moveit_commander.MoveGroupCommander("manipulator_i10")
            print("✓ 使用规划组: manipulator_i10")
        except:
            try:
                group = moveit_commander.MoveGroupCommander("aubo_i10")
                print("✓ 使用规划组: aubo_i10")
            except:
                print("✗ 无法创建规划组")
                return False
        
        print("✓ MoveIt初始化成功")
        
        # 检查机器人信息
        try:
            print(f"✓ 规划组: {robot.get_group_names()}")
        except:
            print("✓ 规划组信息获取失败")
        
        # 检查当前状态
        print(f"✓ 当前规划组: {group.get_name()}")
        print(f"✓ 规划框架: {group.get_planning_frame()}")
        print(f"✓ 末端执行器: {group.get_end_effector_link()}")
        
        # 获取当前关节值
        current_joints = group.get_current_joint_values()
        print(f"✓ 当前关节值: {[round(j, 3) for j in current_joints]}")
        
        # 获取当前位姿
        current_pose = group.get_current_pose().pose
        print(f"✓ 当前位置: x={current_pose.position.x:.3f}, y={current_pose.position.y:.3f}, z={current_pose.position.z:.3f}")
        
        # 测试规划到当前位置（应该很快）
        print("\n--- 测试规划功能 ---")
        group.set_joint_value_target(current_joints)
        plan = group.plan()
        
        if plan[0]:  # plan是一个元组 (success, trajectory, planning_time, error_code)
            print("✓ 规划成功！")
            print(f"✓ 轨迹点数: {len(plan[1].joint_trajectory.points)}")
            print(f"✓ 规划时间: {plan[2]:.3f}秒")
        else:
            print("✗ 规划失败！")
            print(f"✗ 错误代码: {plan[3]}")
            return False
            
        # 测试执行
        print("\n--- 测试执行功能 ---")
        print("准备执行轨迹...")
        result = group.execute(plan[1], wait=True)
        
        if result:
            print("✓ 执行命令发送成功")
        else:
            print("✗ 执行命令发送失败")
            
        return True
        
    except Exception as e:
        print(f"✗ 错误: {str(e)}")
        return False
    
    finally:
        moveit_commander.roscpp_shutdown()

if __name__ == '__main__':
    test_moveit_basic()