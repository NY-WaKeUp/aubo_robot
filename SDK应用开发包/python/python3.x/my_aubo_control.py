#! /usr/bin/env python

from robotcontrol import *
import numpy as np
import serial
import struct
import rospy
from nglove.srv import TriggerCalibration, TriggerCalibrationRequest # 将 'nglove' 替换为您的包名
from typing import Tuple

SENSOR_MAPPING = {
    "index_distal":   {"start": 29, "rows": 2, "cols": 2},
    "index_middle":   {"start": 33, "rows": 2, "cols": 2},
    "index_proximal": {"start": 37, "rows": 2, "cols": 2},
    "middle_distal":  {"start": 41, "rows": 2, "cols": 2},
    "middle_middle":  {"start": 45, "rows": 2, "cols": 2},
    "middle_proximal":{"start": 49, "rows": 2, "cols": 2},
    "ring_distal":    {"start": 53, "rows": 2, "cols": 2},
    "ring_middle":    {"start": 57, "rows": 2, "cols": 2},
    "ring_proximal":  {"start": 61, "rows": 2, "cols": 2},
    "pinky_distal":   {"start": 65, "rows": 2, "cols": 2},
    "pinky_middle":   {"start": 69, "rows": 2, "cols": 2},
    "pinky_proximal": {"start": 73, "rows": 2, "cols": 2},
    "thumb_distal":   {"start": 77, "rows": 2, "cols": 6},
    "thumb_middle":   {"start": 89, "rows": 2, "cols": 6},
    "thumb_proximal": {"start": 101, "rows": 2, "cols": 6},
    "palm_main":      {"start": 4, "rows": 5, "cols": 5},
    "palm_secondary": {"start": 0, "rows": 2, "cols": 2}
}
class MyAuboi10(Auboi5Robot):
    _initial_waypoint={'joint': [-1.2505847215652466, -0.6142553091049194, 0.4769490361213684, -2.0503764152526855, 0.3202041685581207, -0.7853981852531433],
                  'ori':[0.6532777290836816, -0.27059980761388086, -0.6532821870059223, 0.2706036528640324], 
                  'pos':[2.462214636789195e-06, -0.9229812614789412, 0.8665109536996233]}
    _prepare_waypoint={'joint': [-1.258115291595459, -0.681435227394104, 1.0853233337402344, -1.3747549057006836, 0.31266269087791443, -0.7854018211364746], 
                  'ori':[0.6532613441206525, -0.2706187702222664, -0.6532822206840257, 0.2706241630365153], 
                  'pos':[0.02101493499566756, -1.0201682915758754, 0.44627922862177166]
                  }
    def __init__(self, ip='192.168.1.100', port=8899):
        super().__init__()
        self.ip = ip
        self.port = port
        self.ros_initialized = False
        self.trigger_calibration_service = None
    def _initialize_ros(self):
        """初始化ROS节点并连接到标定服务"""
        if self.ros_initialized:
            return
        if not self.ros_initialized:
            rospy.init_node('robot_calibration_client_node', anonymous=True)
            service_name = 'trigger_calibration_read'
            logger.info(f"正在等待ROS服务 '{service_name}'...")
            try:
                rospy.wait_for_service(service_name, timeout=10.0)
                self.trigger_calibration_service = rospy.ServiceProxy(
                    service_name, 
                    TriggerCalibration
                )
                self.ros_initialized = True
                logger.info("成功连接到标定服务！")
            except rospy.ROSException:
                logger.error(f"等待服务超时。请确保C++数据采集节点正在运行。")
                raise  # 抛出异常，让主程序知道失败
    def set_and_startup(self):
        '''启动、连接、一些常用的参数并初始化ros客户端'''
        try:
            logger_init()
            logger.info("{0} test beginning...".format(Auboi5Robot.get_local_time()))
            self.rshd = self.create_context()
            logger.info(f"robot.rshd={self.rshd}") # 打印上下文信息
            result = self.connect(self.ip, self.port)  # 连接机械臂
            
            if result != RobotErrorType.RobotError_SUCC:
                logger.info("connect server{0}:{1} failed.".format(self.ip, self.port))
                return False # 连接失败返回 False
            else:
                # 设置机器人参数
                self.robot_shutdown()
                self.robot_startup()
                self.set_collision_class(6)
                self.init_profile()
                self.set_joint_maxacc((0.5, 0.5, 0.5, 0.5, 0.5, 0.5))
                self.set_joint_maxvelc((0.1, 0.1, 0.1, 0.1, 0.1, 0.1))
                primary_waypoint = self.get_current_waypoint()
                logger.info(primary_waypoint)
                print(f"当前位置：{primary_waypoint['pos']} <class 'list'> ，当前姿态：{primary_waypoint['ori']} <class 'list'>")
                # --- 新增：初始化ROS ---
                self._initialize_ros() 
                return True # 成功连接并启动返回 True


        except RobotError as e:
            logger.error("{0} robot Event:{1}".format(self.get_local_time(), e))
            return False # 异常情况返回 False 
    def close(self):
        '''关闭,断连机械臂'''
        if self.connected:
            self.robot_shutdown()
            self.disconnect()
        self.uninitialize()
        logger.info(f"{self.get_local_time()} test completed")
    def move_z_in_step(self, distance:int=0.0001, direction:str='up'):
        """当前位置为以{direction}方向移动末端{distance}距离(m)
        

        Args:
            distance (int): default:0.0001(m)
            direction (str): default:'up','down'

        Returns:
            RobotErrorType: RobotError_SUCC
        """
        self.check_event()
        if self.rshd >= 0 and self.connected:
            current_waypoint=self.get_current_waypoint()
            current_pos=np.array(current_waypoint['pos'])
            if direction=='up': 
                current_pos+=[0,0,distance]
            else: current_pos-=[0,0,distance]
            result=self.move_to_target_in_cartesian(current_pos.tolist(),current_waypoint['ori'])
            if result != RobotErrorType.RobotError_SUCC:
                self.raise_error(RobotErrorType.RobotError_Move, result, "move error")
            else:
                return RobotErrorType.RobotError_SUCC
        else:
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
    def move_x_in_step(self, distance:int=0.0001, direction:str='left'):
        """当前位置为以{direction}方向移动末端{distance}距离(m)

        Args:
            distance (int): default:0.0001(m)
            direction (str): 'left'(default)/'right'

        Returns:
            RobotErrorType: RobotError_SUCC
        """
        self.check_event()
        if self.rshd >= 0 and self.connected:
            current_waypoint=self.get_current_waypoint()
            current_pos=np.array(current_waypoint['pos'])
            if direction=='left': 
                current_pos+=[distance,0,0]
            else: current_pos-=[distance,0,0]
            result=self.move_to_target_in_cartesian(current_pos.tolist(),current_waypoint['ori'])
            if result != RobotErrorType.RobotError_SUCC:
                self.raise_error(RobotErrorType.RobotError_Move, result, "move error")
            else:
                return RobotErrorType.RobotError_SUCC
        else:
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
    def move_y_in_step(self ,distance:int=0.0001, direction:str='front'):
        """当前位置为以{direction}方向移动末端{distance}距离(m)

        Args:
            distance (int): default:0.0001(m)
            direction (str): 'front'(default)/'back'

        Returns:
            RobotErrorType: RobotError_SUCC
        """
        self.check_event()
        if self.rshd >= 0 and self.connected:
            current_waypoint=self.get_current_waypoint()
            current_pos=np.array(current_waypoint['pos'])
            if direction=='front': 
                current_pos-=[0,distance,0]
            else: current_pos+=[0,distance,0]
            result=self.move_to_target_in_cartesian(current_pos.tolist(),current_waypoint['ori'])
            if result != RobotErrorType.RobotError_SUCC:
                self.raise_error(RobotErrorType.RobotError_Move, result, "move error")
            else:
                return RobotErrorType.RobotError_SUCC
        else:
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
    def apply_force_and_read_onepoint(self, target_force_N:float, target_point_absolute_index:int)-> Tuple[float,float]:
        """施加一个目标力，并在达到该力时调用ROS服务触发数据采集。"""
        torlerance=0.01 
        step_in_m=0.0001
        timeout=10
        start_time=time.time()
        while time.time() - start_time < timeout:
            current_force=self.get_force()
            if not isinstance(current_force, float):
                time.sleep(0.01)
                continue
            if abs(current_force - target_force_N) <= torlerance:
                    logger.info(f"目标力 {target_force_N:.2f}N 达成!")
                    # --- 核心：调用ROS服务 ---
                    try:
                        res = self.trigger_calibration_service(target_point_absolute_index, current_force)
                        if res.success:
                            logger.info(f"服务调用成功，传感器读数: {res.sensor_reading:.4f}")
                            return current_force, res.sensor_reading
                        else:
                            logger.error("标定服务报告采集失败。")
                            return None, None
                    except rospy.ServiceException as e:
                        logger.error(f"调用服务时发生错误: {e}")
                        return None, None
            if current_force < target_force_N:
                self.move_z_in_step(step_in_m,'down')
            else:
                logger.warn(f"力值 {current_force:.2f}N 超出目标 {target_force_N:.2f}N，正在后退...")
                self.move_z_in_step(step_in_m,'up')
        logger.error(f"超时！未能达到目标力 {target_force_N}N。")
        return None,None
    
    def calibration_a_region(self, start_waypoint: dict, region_name: str, x_spacing: float=0.00350, y_spacing: float=0.00350):
        """
        以给定的起始点为基准，全自动标定一个传感器区域。

        Args:
            start_waypoint (dict): 目前已在的本区域第一个点(0,0)的路点信息。
            region_name (str): 正在标定的区域名，用于从SENSOR_MAPPING中查找信息。
            x_spacing (float): 点在X方向的间距 (米)。
            y_spacing (float): 点在Y方向的间距 (米)。
        """
        self.check_event()
        if not (self.rshd >= 0 and self.connected):
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
        # --- 标定流程参数 ---
        forces_to_apply = [1, 3, 5, 7, 9] # 要施加的力值列表 (牛顿)
        lift_height = 0.01 # 每次移动前的抬起高度 (1cm)

        try:
            region_info = SENSOR_MAPPING[region_name]
            start_pos = start_waypoint['pos']
            start_ori = start_waypoint['ori']
            self.move_to_target_in_cartesian(start_pos,start_ori)
            
            for row in range(SENSOR_MAPPING[region_name]["rows"]):  # 遍历行 
                for col in range(SENSOR_MAPPING[region_name]["cols"]):  # 遍历列 
                    
                    # 1. 计算当前目标点的物理坐标和绝对索引当然是从row=0，col=0开始
                    # xy轴与当前坐标系是反的，z是一样的
                    on_pos = (
                        start_pos[0] - col * x_spacing,
                        start_pos[1] - row * y_spacing,
                        start_pos[2]
                    )
                    
                    relative_index = row * region_info['cols'] + col
                    absolute_index = region_info['start'] + relative_index
                    
                    logger.info(f"\n{'='*20} 开始标定点: {region_name}({row},{col}), 绝对索引: {absolute_index} {'='*20}")

                    # 2. 移动到当前点的上方“接近点”这里应该是tuple或者list都行
                    above_pos = (on_pos[0], on_pos[1], on_pos[2] + lift_height)
                    self.move_to_target_in_cartesian(above_pos, start_ori)
                    
                    # 3. 对当前点施加一系列不同的力
                    for force in forces_to_apply:
                        logger.info(f"--- 尝试施加 {force:.2f}N 的力 ---")
                        
                        # A. 先移动到接触表面
                        self.move_to_target_in_cartesian(on_pos, start_ori)
                        
                        # B. 调用力闭环控制函数进行按压和数据采集
                        force_read, sensor_read = self.apply_force_and_read_onepoint(force, absolute_index)
                        
                        if force_read is not None:
                            logger.info(f"成功记录数据点: (力: {force_read:.4f}N, 读数: {sensor_read:.4f})")
                        else:
                            logger.error("未能记录此力值的数据点。")

                        # C. 每次施力后都抬起，为下一次施力或移动到下个点做准备
                        self.move_to_target_in_cartesian(above_pos, start_ori)
                        time.sleep(0.5) # 短暂暂停
            
            logger.info(f"\n区域 '{region_name}' 的 6x2 标定流程全部完成！")
            return RobotErrorType.RobotError_SUCC

        except KeyError:
            logger.error(f"区域名 '{region_name}' 无效或 SENSOR_MAPPING 中不存在。")
            return RobotErrorType.RobotError_ERROR_ARGS
        except Exception as e:
            logger.error(f"标定过程中发生未知错误: {e}")
            self.raise_error(RobotErrorType.RobotError_Move, -1, "calibration error")       
    def get_force(self)->float:
        """
        连接串口，发送指令，并解析返回的主读数.
        在函数内部处理串口的打开和关闭，确保每次调用都是独立的.
        :return: 主读数的浮点值，如果失败则返回 None.
        """
        PORT = '/dev/ttyUSB0'
        BAUDRATE = 9600
        COMMAND_TO_SEND = bytes([0x01, 0x03, 0x00, 0x00, 0x00, 0x0D, 0x84, 0x0F])
        ser = None
        try:
            ser = serial.Serial(PORT, BAUDRATE, timeout=1)
            ser.reset_input_buffer()
            ser.write(COMMAND_TO_SEND)
            time.sleep(0.2)  # 等待设备响应
            response = ser.readall()
            
            if response and len(response) >= 9 and response[0] == 0x01 and response[1] == 0x03:
                main_reading_bytes = response[3:7]
                result = struct.unpack('>f', main_reading_bytes)[0]
                if isinstance(result, float):
                    output_str = f"✅ 当前主读数: {result:<15.6f}"
                else:
                    output_str = f"❌ 读取失败: {result:<30}"
                print(output_str, end='\r')
                return result
            else:
                # 返回一个错误信息字符串，而不是None，方便主循环打印
                return f"无效响应: {response.hex() if response else '无响应'}"
                
        except serial.SerialException as e:
            return f"串口错误: {e}"
        except Exception as e:
            return f"未知错误: {e}"
        finally:
            if ser and ser.is_open:
                ser.close()
    def calibration_index_finger(self, first_point_of_first_region_on_waypoint:dict):
        """在到达右上角第一个点上面接触之后，开始标定食指"""
        self.check_event()
        if self.rshd >= 0 and self.connected:
            result=self.move_to_target_in_cartesian(first_point_of_first_region_on_waypoint['pos'],first_point_of_first_region_on_waypoint['ori'])
            self.calibration_a_region(first_point_of_first_region_on_waypoint,SENSOR_MAPPING.keys[0],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004,'back')
            self.move_z_in_step(0.01,'down')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[1],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004,'back')
            self.move_z_in_step(0.01,'down')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[2],0.00350,0.00350)
            
            if result != RobotErrorType.RobotError_SUCC:
                self.raise_error(RobotErrorType.RobotError_Move, result, "move error")
            else:
                return RobotErrorType.RobotError_SUCC
        else:
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
        
    def calibration_middle_finger(self, first_point_of_first_region_on_waypoint:dict, distance:int):
        """在到达右上角第一个点上面接触之后，开始标定中指"""
        self.check_event()
        if self.rshd >= 0 and self.connected:
            result=self.move_to_target_in_cartesian(first_point_of_first_region_on_waypoint['pos'],first_point_of_first_region_on_waypoint['ori'])
            self.calibration_a_region(first_point_of_first_region_on_waypoint,SENSOR_MAPPING.keys[3],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004,'back')
            self.move_z_in_step(0.01,'down')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[4],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004,'back')
            self.move_z_in_step(0.01,'down')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[5],0.00350,0.00350)
            
            if result != RobotErrorType.RobotError_SUCC:
                self.raise_error(RobotErrorType.RobotError_Move, result, "move error")
            else:
                return RobotErrorType.RobotError_SUCC
        else:
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
    def calibration_ring_finger(self, first_point_of_first_region_on_waypoint:dict, distance:int):
        """在到达右上角第一个点上面接触之后，开始标定无名指"""
        self.check_event()
        if self.rshd >= 0 and self.connected:
            result=self.move_to_target_in_cartesian(first_point_of_first_region_on_waypoint['pos'],first_point_of_first_region_on_waypoint['ori'])
            self.calibration_a_region(first_point_of_first_region_on_waypoint,SENSOR_MAPPING.keys[6],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004,'back')
            self.move_z_in_step(0.01,'down')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[7],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004,'back')
            self.move_z_in_step(0.01,'down')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[8],0.00350,0.00350)
            
            if result != RobotErrorType.RobotError_SUCC:
                self.raise_error(RobotErrorType.RobotError_Move, result, "move error")
            else:
                return RobotErrorType.RobotError_SUCC
        else:
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
    def calibration_pinky_finger(self, first_point_of_first_region_on_waypoint:dict, distance:int):
        """在到达右上角第一个点上面接触之后，开始标定小指"""
        self.check_event()
        if self.rshd >= 0 and self.connected:
            result=self.move_to_target_in_cartesian(first_point_of_first_region_on_waypoint['pos'],first_point_of_first_region_on_waypoint['ori'])
            self.calibration_a_region(first_point_of_first_region_on_waypoint,SENSOR_MAPPING.keys[0],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004,'back')
            self.move_z_in_step(0.01,'down')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[1],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004,'back')
            self.move_z_in_step(0.01,'down')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[2],0.00350,0.00350)
            
            if result != RobotErrorType.RobotError_SUCC:
                self.raise_error(RobotErrorType.RobotError_Move, result, "move error")
            else:
                return RobotErrorType.RobotError_SUCC
        else:
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
    def calibration_thumb_finger(self, first_point_of_first_region_on_waypoint:dict, distance:int):
        """在到达右上角第一个点上面接触之后，开始标定大拇指"""
        self.check_event()
        if self.rshd >= 0 and self.connected:
            result=self.move_to_target_in_cartesian(first_point_of_first_region_on_waypoint['pos'],first_point_of_first_region_on_waypoint['ori'])
            self.calibration_a_region(first_point_of_first_region_on_waypoint,SENSOR_MAPPING.keys[0],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004*2,'back')
            self.move_z_in_step(0.01,'down')
            # self.move_x_in_step(0.001,'left')
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[1],0.00350,0.00350)
            
            self.move_y_in_step(0.0048+0.0004*2,'back')
            self.move_z_in_step(0.01,'down')
            # self.move_x_in_step(0.001,'left') # 暂时不确定是不是要这样，好像各个区域之间是垂直的
            
            current_waypoint=self.get_current_waypoint()
            
            self.calibration_a_region(current_waypoint,SENSOR_MAPPING.keys[2],0.00350,0.00350)
            
            if result != RobotErrorType.RobotError_SUCC:
                self.raise_error(RobotErrorType.RobotError_Move, result, "move error")
            else:
                return RobotErrorType.RobotError_SUCC
        else:
            logger.warn("RSHD uninitialized or not login!!!")
            return RobotErrorType.RobotError_NotLogin
    def calibration_all_sensor(self):
        self.calibration_index_finger(self.get_current_waypoint())
        self.move_x_in_step(0.090+0.004*2,'right')
        self.move_y_in_step(0.096+0.0004*4,'front')
        self.calibration_middle_finger(self.get_current_waypoint())
        self.move_x_in_step(0.090+0.004*2,'right')
        self.move_y_in_step(0.096+0.0004*4,'front')
        self.calibration_ring_finger(self.get_current_waypoint())
        self.move_x_in_step(0.090+0.004*2,'right')
        self.move_y_in_step(0.096+0.0004*4,'front')
        self.calibration_pinky_finger(self.get_current_waypoint())
        self.move_x_in_step(0.090+0.004*2,'right')
        self.move_y_in_step(0.096+0.0004*4,'front')
        self.calibration_thumb_finger(self.get_current_waypoint())
        self.move_x_in_step(0.090+0.004*2,'right')
        self.move_y_in_step(0.108+0.0004*4,'front')
        self.calibration_a_region(self.get_current_waypoint(),'plam_main')
        self.move_x_in_step(0.090+0.004*2,'right')
        self.move_y_in_step(0.025+0.0004*4,'back')
        self.calibration_a_region(self.get_current_waypoint(),'plam_secondary')
