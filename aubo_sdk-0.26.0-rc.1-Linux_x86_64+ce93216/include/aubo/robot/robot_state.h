/** @file  robot_state.h
 *  @brief 获取机器人状态接口，如关节速度、关节角度、固件/硬件版本
 */
#ifndef AUBO_SDK_ROBOT_STATE_INTERFACE_H
#define AUBO_SDK_ROBOT_STATE_INTERFACE_H

#include <vector>

#include <aubo/global_config.h>
#include <aubo/type_def.h>

namespace arcs {
namespace common_interface {

class ARCS_ABI_EXPORT RobotState
{
public:
    RobotState();
    virtual ~RobotState();

    /**
     * \chinese
     * 获取机器人的模式状态
     *
     * @return 机器人的模式状态
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getRobotModeType(self: pyaubo_sdk.RobotState) ->
     * arcs::common_interface::RobotModeType
     *
     * @par Lua函数原型
     * getRobotModeType() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getRobotModeType","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":"Running"}
     *
     *\endchinese
     *\english
     * Get the robot mode state
     *
     * @return The robot's mode state
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getRobotModeType(self: pyaubo_sdk.RobotState) ->
     * arcs::common_interface::RobotModeType
     *
     * @par Lua function prototype
     * getRobotModeType() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getRobotModeType","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":"Running"}
     *\endenglish
     */

    RobotModeType getRobotModeType();

    /**
     * \chinese
     * 获取安全模式
     *
     * @return 安全模式
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getSafetyModeType(self: pyaubo_sdk.RobotState) ->
     * arcs::common_interface::SafetyModeType
     *
     * @par Lua函数原型
     * getSafetyModeType() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSafetyModeType","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":"Normal"}
     * \endchinese
     * \english
     * Get the safety mode
     *
     * @return The safety mode
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getSafetyModeType(self: pyaubo_sdk.RobotState) ->
     * arcs::common_interface::SafetyModeType
     *
     * @par Lua function prototype
     * getSafetyModeType() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSafetyModeType","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":"Normal"}
     * \endenglish
     */
    SafetyModeType getSafetyModeType();

    /**
     * \chinese
     * 获取机器人通电状态
     *
     * @return 机器人通电返回 true; 反之返回 false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.isPowerOn","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":true}
     * \endchinese
     * \english
     * Get the robot power-on state
     *
     * @return Returns true if the robot is powered on; otherwise returns false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.isPowerOn","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":true}
     * \endenglish
     */
    bool isPowerOn();

    /**
     * \chinese
     * 机器人是否已经停止下来
     *
     * @return 停止返回true; 反之返回false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * isSteady(self: pyaubo_sdk.RobotState) -> bool
     *
     * @par Lua函数原型
     * isSteady() -> boolean
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.isSteady","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":true}
     * \endchinese
     * \english
     * Whether the robot has stopped
     *
     * @return Returns true if stopped; otherwise returns false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * isSteady(self: pyaubo_sdk.RobotState) -> bool
     *
     * @par Lua function prototype
     * isSteady() -> boolean
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.isSteady","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":true}
     * \endenglish
     */
    bool isSteady();

    /**
     * \chinese
     * 机器人是否发生了碰撞
     *
     * @return 发生碰撞返回 true; 反之返回 false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.isCollisionOccurred","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":false}
     * \endchinese
     * \english
     * Whether a collision has occurred
     *
     * @return Returns true if a collision occurred; otherwise returns false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.isCollisionOccurred","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":false}
     * \endenglish
     */
    bool isCollisionOccurred();

    /**
     * \chinese
     * 机器人是否已经在安全限制之内
     *
     * @return 在安全限制之内返回true; 反之返回false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * isWithinSafetyLimits(self: pyaubo_sdk.RobotState) -> bool
     *
     * @par Lua函数原型
     * isWithinSafetyLimits() -> boolean
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.isWithinSafetyLimits","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":true}
     * \endchinese
     * \english
     * Whether the robot is within safety limits
     *
     * @return Returns true if within safety limits; otherwise returns false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * isWithinSafetyLimits(self: pyaubo_sdk.RobotState) -> bool
     *
     * @par Lua function prototype
     * isWithinSafetyLimits() -> boolean
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.isWithinSafetyLimits","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":true}
     * \endenglish
     */
    bool isWithinSafetyLimits();

    /**
     * \chinese
     * 获取当前的TCP位姿，其 TCP 偏移可以通过 getActualTcpOffset 获取
     *
     * 位姿表示形式为(x,y,z,rx,ry,rz)。
     * 其中x、y、z是工具中心点（TCP）在基坐标系下的位置，单位是m。
     * rx、ry、rz是工具中心点（TCP）在基坐标系下的姿态，是ZYX欧拉角，单位是rad。
     *
     * @return TCP的位姿,形式为(x,y,z,rx,ry,rz)
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getTcpPose(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getTcpPose() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpPose","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.41777839846910425,-0.13250000000000012,0.20928451364415995,3.1415792312578987,0.0,1.5707963267948963]}
     * \endchinese
     * \english
     * Get the current TCP pose. The TCP offset can be obtained by getActualTcpOffset.
     *
     * The pose is represented as (x, y, z, rx, ry, rz).
     * x, y, z are the position of the Tool Center Point (TCP) in the base coordinate system, in meters.
     * rx, ry, rz are the orientation of the TCP in the base coordinate system, as ZYX Euler angles in radians.
     *
     * @return The TCP pose, in the form (x, y, z, rx, ry, rz)
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getTcpPose(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getTcpPose() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpPose","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.41777839846910425,-0.13250000000000012,0.20928451364415995,3.1415792312578987,0.0,1.5707963267948963]}
     * \endenglish
     */
    std::vector<double> getTcpPose();

    /**
     * \chinese
     * 获取当前的 TCP 偏移，也就是 getTcpPose 返回的 pose 用到的 TCP 偏移
     *
     * @return 当前的 TCP 偏移
     * \endchinese
     * \english
     * Get the current TCP offset, which is the TCP offset used by the pose returned from getTcpPose
     *
     * @return The current TCP offset
     * \endenglish
     */
    std::vector<double> getActualTcpOffset();

    /**
     * \chinese
     * 获取下一个目标路点
     * 注意与 getTcpTargetPose 的区别，此处定义存在歧义，命名需要优化
     *
     * 位姿表示形式为(x,y,z,rx,ry,rz)。
     * 其中x、y、z是工具中心点（TCP）在基坐标系下的目标位置，单位是m。
     * rx、ry、rz是工具中心点（TCP）在基坐标系下的目标姿态，是ZYX欧拉角，单位是rad。
     *
     * @return 当前目标位姿,形式为(x,y,z,rx,ry,rz)
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getTargetTcpPose(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getTargetTcpPose() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTargetTcpPose","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.4173932217619493,-0.13250000000000012,0.43296496133045825,3.141577313781914,0.0,1.5707963267948963]}
     * \endchinese
     * \english
     * Get the next target waypoint.
     * Note the difference from getTcpTargetPose; the definition here is ambiguous and the naming needs improvement.
     *
     * The pose is represented as (x, y, z, rx, ry, rz).
     * x, y, z are the target position of the Tool Center Point (TCP) in the base coordinate system, in meters.
     * rx, ry, rz are the target orientation of the TCP in the base coordinate system, as ZYX Euler angles in radians.
     *
     * @return The current target pose, in the form (x, y, z, rx, ry, rz)
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getTargetTcpPose(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getTargetTcpPose() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTargetTcpPose","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.4173932217619493,-0.13250000000000012,0.43296496133045825,3.141577313781914,0.0,1.5707963267948963]}
     * \endenglish
     */
    std::vector<double> getTargetTcpPose();

    /**
     * \chinese
     * 获取工具端的位姿（不带TCP偏移）
     *
     * 位姿表示形式为(x,y,z,rx,ry,rz)。
     * 其中x、y、z是法兰盘中心在基坐标系下的目标位置，单位是m。
     * rx、ry、rz是法兰盘中心在基坐标系下的目标姿态，是ZYX欧拉角，单位是rad。
     *
     * @return 工具端的位姿,形式为(x,y,z,rx,ry,rz)
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getToolPose(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getToolPose() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolPose","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.41777820858878617,-0.13250000000000012,0.20928410288421018,3.141579231257899,0.0,1.5707963267948963]}
     * \endchinese
     * \english
     * Get the tool pose (without TCP offset)
     *
     * The pose is represented as (x, y, z, rx, ry, rz).
     * x, y, z are the target position of the flange center in the base coordinate system, in meters.
     * rx, ry, rz are the target orientation of the flange center in the base coordinate system, as ZYX Euler angles in radians.
     *
     * @return The tool pose, in the form (x, y, z, rx, ry, rz)
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getToolPose(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getToolPose() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolPose","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.41777820858878617,-0.13250000000000012,0.20928410288421018,3.141579231257899,0.0,1.5707963267948963]}
     * \endenglish
     */
    std::vector<double> getToolPose();

    /**
     * \chinese
     * 获取TCP速度
     *
     * @return TCP速度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getTcpSpeed(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getTcpSpeed() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpSpeed","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the TCP speed
     *
     * @return TCP speed
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getTcpSpeed(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getTcpSpeed() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpSpeed","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getTcpSpeed();

    /**
     * \chinese
     * 获取TCP的力/力矩
     *
     * @return TCP的力/力矩
     *
     * @par Python函数原型
     * getTcpForce(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getTcpForce() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpForce","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the TCP force/torque
     *
     * @return TCP force/torque
     *
     * @par Python function prototype
     * getTcpForce(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getTcpForce() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpForce","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getTcpForce();

    /**
     * \chinese
     * 获取肘部的位置
     *
     * @return 肘部的位置
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getElbowPosistion(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getElbowPosistion() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getElbowPosistion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.07355755887512408,-0.1325,0.43200874126125227,-1.5707963267948968,0.433006344376404,0.0]}
     * \endchinese
     * \english
     * Get the position of the elbow
     *
     * @return The position of the elbow
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getElbowPosistion(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getElbowPosistion() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getElbowPosistion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.07355755887512408,-0.1325,0.43200874126125227,-1.5707963267948968,0.433006344376404,0.0]}
     * \endenglish
     */
    std::vector<double> getElbowPosistion();

    /**
     * \chinese
     * 获取肘部速度
     *
     * @return 肘部速度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getElbowVelocity(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getElbowVelocity() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getElbowVelocity","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the elbow velocity
     *
     * @return Elbow velocity
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getElbowVelocity(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getElbowVelocity() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getElbowVelocity","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getElbowVelocity();

    /**
     * \chinese
     * 获取基座力/力矩
     *
     * @return 基座力/力矩
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getBaseForce(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getBaseForce() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getBaseForce","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the base force/torque
     *
     * @return Base force/torque
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getBaseForce(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getBaseForce() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getBaseForce","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getBaseForce();

    /**
     * \chinese
     * 获取上一次发送的TCP目标位姿
     *
     * @return TCP目标位姿
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getTcpTargetPose(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getTcpTargetPose() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpTargetPose","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.41777829240862013,-0.13250000000000012,0.2092832117232601,3.1415812372223217,0.0,1.5707963267948963]}
     * \endchinese
     * \english
     * Get the last sent TCP target pose
     *
     * @return TCP target pose
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getTcpTargetPose(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getTcpTargetPose() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpTargetPose","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.41777829240862013,-0.13250000000000012,0.2092832117232601,3.1415812372223217,0.0,1.5707963267948963]}
     * \endenglish
     */
    std::vector<double> getTcpTargetPose();

    /**
     * \chinese
     * 获取TCP目标速度
     *
     * @return TCP目标速度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getTcpTargetSpeed(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getTcpTargetSpeed() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpTargetSpeed","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the TCP target speed
     *
     * @return TCP target speed
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getTcpTargetSpeed(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getTcpTargetSpeed() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpTargetSpeed","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getTcpTargetSpeed();

    /**
     * \chinese
     * 获取TCP目标力/力矩
     *
     * @return TCP目标力/力矩
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getTcpTargetForce(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getTcpTargetForce() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpTargetForce","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the TCP target force/torque
     *
     * @return TCP target force/torque
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getTcpTargetForce(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getTcpTargetForce() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpTargetForce","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getTcpTargetForce();

    /**
     * \chinese
     * 获取机械臂关节标志
     *
     * @return 机械臂关节标志
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointState(self: pyaubo_sdk.RobotState) ->
     * List[arcs::common_interface::JointStateType]
     *
     * @par Lua函数原型
     * getJointState() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointState","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":["Running","Running","Running","Running","Running","Running"]}
     * \endchinese
     * \english
     * Get the joint state of the manipulator
     *
     * @return Joint state of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointState(self: pyaubo_sdk.RobotState) ->
     * List[arcs::common_interface::JointStateType]
     *
     * @par Lua function prototype
     * getJointState() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointState","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":["Running","Running","Running","Running","Running","Running"]}
     * \endenglish
     */
    std::vector<JointStateType> getJointState();

    /**
     * \chinese
     * 获取关节的伺服状态
     *
     * @return 关节的伺服状态
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointServoMode(self: pyaubo_sdk.RobotState) ->
     * List[arcs::common_interface::JointServoModeType]
     *
     * @par Lua函数原型
     * getJointServoMode() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointServoMode","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":["Position","Position","Position","Position","Position","Position"]}
     * \endchinese
     * \english
     * Get the servo state of the joints
     *
     * @return The servo state of the joints
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointServoMode(self: pyaubo_sdk.RobotState) ->
     * List[arcs::common_interface::JointServoModeType]
     *
     * @par Lua function prototype
     * getJointServoMode() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointServoMode","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":["Position","Position","Position","Position","Position","Position"]}
     * \endenglish
     */
    std::vector<JointServoModeType> getJointServoMode();

    /**
     * \chinese
     * 获取机械臂关节角度
     *
     * @return 机械臂关节角度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointPositions(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointPositions() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointPositions","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,-0.26199241371495835,1.7418102574563423,0.4330197667082982,1.5707963267948966,0.0]}
     * \endchinese
     * \english
     * Get the joint positions of the manipulator
     *
     * @return Joint positions of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointPositions(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointPositions() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointPositions","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,-0.26199241371495835,1.7418102574563423,0.4330197667082982,1.5707963267948966,0.0]}
     * \endenglish
     */
    std::vector<double> getJointPositions();

    /**
     * \chinese
     * 获取机械臂历史关节角度
     *
     * @param steps 步数
     * @return 机械臂历史关节角度
     * \endchinese
     * \english
     * Get the historical joint positions of the manipulator
     *
     * @param steps Number of steps
     * @return Historical joint positions of the manipulator
     * \endenglish
     */
    std::vector<double> getJointPositionsHistory(int steps);

    /**
     * \chinese
     * 获取机械臂关节速度
     *
     * @return 机械臂关节速度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointSpeeds(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointSpeeds() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointSpeeds","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the joint speeds of the manipulator
     *
     * @return Joint speeds of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointSpeeds(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointSpeeds() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointSpeeds","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getJointSpeeds();

    /**
     * \chinese
     * 获取机械臂关节加速度
     *
     * @return 机械臂关节加速度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointAccelerations(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointAccelerations() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointAccelerations","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the joint accelerations of the manipulator
     *
     * @return Joint accelerations of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointAccelerations(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointAccelerations() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointAccelerations","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getJointAccelerations();

    /**
     * \chinese
     * 获取机械臂关节力矩
     *
     * @return 机械臂关节力矩
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointTorqueSensors(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointTorqueSensors() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTorqueSensors","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,6275.367736816406,-7704.2816162109375,3586.9766235351563,503.0364990234375,1506.0882568359375]}
     * \endchinese
     * \english
     * Get the joint torques of the manipulator
     *
     * @return Joint torques of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointTorqueSensors(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointTorqueSensors() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTorqueSensors","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,6275.367736816406,-7704.2816162109375,3586.9766235351563,503.0364990234375,1506.0882568359375]}
     * \endenglish
     */
    std::vector<double> getJointTorqueSensors();

    /**
     * \chinese
     * 获取机械臂关节接触力矩（外力距）
     *
     * @return 机械臂关节接触力矩
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointContactTorques(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointContactTorques() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointContactTorques","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the joint contact torques (external torques) of the manipulator
     *
     * @return Joint contact torques of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointContactTorques(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointContactTorques() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointContactTorques","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getJointContactTorques();

    /**
     * \chinese
     * 获取底座力传感器读数
     *
     * @return 底座力传感器读数
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getBaseForceSensor(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getBaseForceSensor() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getBaseForceSensor","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the base force sensor readings
     *
     * @return Base force sensor readings
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getBaseForceSensor(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getBaseForceSensor() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getBaseForceSensor","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getBaseForceSensor();

    /**
     * \chinese
     * 获取TCP力传感器读数
     *
     * @return TCP力传感器读数
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getTcpForceSensors(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getTcpForceSensors() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpForceSensors","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the TCP force sensor readings
     *
     * @return TCP force sensor readings
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getTcpForceSensors(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getTcpForceSensors() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpForceSensors","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getTcpForceSensors();

    /**
     * \chinese
     * 获取机械臂关节电流
     *
     * @return 机械臂关节电流
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointCurrents(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointCurrents() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointCurrents","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,1.25885009765625,-1.5289306640625,0.71868896484375,0.1007080078125,0.3021240234375]}
     * \endchinese
     * \english
     * Get the joint currents of the manipulator
     *
     * @return Joint currents of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointCurrents(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointCurrents() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointCurrents","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,1.25885009765625,-1.5289306640625,0.71868896484375,0.1007080078125,0.3021240234375]}
     * \endenglish
     */
    std::vector<double> getJointCurrents();

    /**
     * \chinese
     * 获取机械臂关节电压
     *
     * @return 机械臂关节电压
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointVoltages(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointVoltages() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointVoltages","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[2.0,2.5,3.0,2.0,2.5,2.0]}
     * \endchinese
     * \english
     * Get the joint voltages of the manipulator
     *
     * @return Joint voltages of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointVoltages(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointVoltages() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointVoltages","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[2.0,2.5,3.0,2.0,2.5,2.0]}
     * \endenglish
     */
    std::vector<double> getJointVoltages();

    /**
     * \chinese
     * 获取机械臂关节温度
     *
     * @return 机械臂关节温度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointTemperatures(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointTemperatures() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTemperatures","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[38.0,38.0,38.0,39.0,38.0,39.0]}
     * \endchinese
     * \english
     * Get the joint temperatures of the manipulator
     *
     * @return Joint temperatures of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointTemperatures(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointTemperatures() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTemperatures","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[38.0,38.0,38.0,39.0,38.0,39.0]}
     * \endenglish
     */
    std::vector<double> getJointTemperatures();

    /**
     * \chinese
     * 获取关节全球唯一ID
     *
     * @return 关节全球唯一ID
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointUniqueIds(self: pyaubo_sdk.RobotState) -> List[str]
     *
     * @par Lua函数原型
     * getJointUniqueIds() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointUniqueIds","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":["00800020ffffffff31405153","00800020ffffffff3e3f5153","00800020ffffffff414b5153","00800020ffffffff31065153","00800020ffffffff41535153","00800020ffffffff41545153"]}
     * \endchinese
     * \english
     * Get the globally unique IDs of the joints
     *
     * @return Globally unique IDs of the joints
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointUniqueIds(self: pyaubo_sdk.RobotState) -> List[str]
     *
     * @par Lua function prototype
     * getJointUniqueIds() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointUniqueIds","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":["00800020ffffffff31405153","00800020ffffffff3e3f5153","00800020ffffffff414b5153","00800020ffffffff31065153","00800020ffffffff41535153","00800020ffffffff41545153"]}
     * \endenglish
     */
    std::vector<std::string> getJointUniqueIds();

    /**
     * \chinese
     * 获取关节固件版本
     *
     * @return 关节固件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointFirmwareVersions(self: pyaubo_sdk.RobotState) -> List[int]
     *
     * @par Lua函数原型
     * getJointFirmwareVersions() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointFirmwareVersions","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[1000010,1000010,1000010,1000010,1000010,1000010]}
     * \endchinese
     * \english
     * Get the joint firmware versions
     *
     * @return Joint firmware versions
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointFirmwareVersions(self: pyaubo_sdk.RobotState) -> List[int]
     *
     * @par Lua function prototype
     * getJointFirmwareVersions() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointFirmwareVersions","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[1000010,1000010,1000010,1000010,1000010,1000010]}
     * \endenglish
     */
    std::vector<int> getJointFirmwareVersions();

    /**
     * \chinese
     * 获取关节硬件版本
     *
     * @return 关节硬件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointHardwareVersions(self: pyaubo_sdk.RobotState) -> List[int]
     *
     * @par Lua函数原型
     * getJointHardwareVersions() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointHardwareVersions","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[1000000,1000000,1004000,1004000,1004000,1004000]}
     * \endchinese
     * \english
     * Get the joint hardware versions
     *
     * @return Joint hardware versions
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointHardwareVersions(self: pyaubo_sdk.RobotState) -> List[int]
     *
     * @par Lua function prototype
     * getJointHardwareVersions() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointHardwareVersions","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[1000000,1000000,1004000,1004000,1004000,1004000]}
     * \endenglish
     */
    std::vector<int> getJointHardwareVersions();

    /**
     * \chinese
     * 获取MasterBoard全球唯一ID
     *
     * @return MasterBoard全球唯一ID
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getMasterBoardUniqueId(self: pyaubo_sdk.RobotState) -> str
     *
     * @par Lua函数原型
     * getMasterBoardUniqueId() -> string
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMasterBoardUniqueId","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":"001e0044510f343037323637"}
     * \endchinese
     * \english
     * Get the globally unique ID of the MasterBoard
     *
     * @return Globally unique ID of the MasterBoard
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getMasterBoardUniqueId(self: pyaubo_sdk.RobotState) -> str
     *
     * @par Lua function prototype
     * getMasterBoardUniqueId() -> string
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMasterBoardUniqueId","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":"001e0044510f343037323637"}
     * \endenglish
     */
    std::string getMasterBoardUniqueId();

    /**
     * \chinese
     * 获取MasterBoard固件版本
     *
     * @return MasterBoard固件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getMasterBoardFirmwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getMasterBoardFirmwareVersion() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMasterBoardFirmwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":1000004}
     * \endchinese
     * \english
     * Get the MasterBoard firmware version
     *
     * @return MasterBoard firmware version
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getMasterBoardFirmwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getMasterBoardFirmwareVersion() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMasterBoardFirmwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":1000004}
     * \endenglish
     */
    int getMasterBoardFirmwareVersion();
    /**
     * \chinese
     * 获取MasterBoard硬件版本
     *
     * @return MasterBoard硬件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getMasterBoardHardwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getMasterBoardHardwareVersion() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMasterBoardHardwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":1000000}
     * \endchinese
     * \english
     * Get the MasterBoard hardware version
     *
     * @return MasterBoard hardware version
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getMasterBoardHardwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getMasterBoardHardwareVersion() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMasterBoardHardwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":1000000}
     * \endenglish
     */
    int getMasterBoardHardwareVersion();

    /**
     * \chinese
     * 获取SlaveBoard全球唯一ID
     *
     * @return SlaveBoard全球唯一ID
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getSlaveBoardUniqueId(self: pyaubo_sdk.RobotState) -> str
     *
     * @par Lua函数原型
     * getSlaveBoardUniqueId() -> string
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlaveBoardUniqueId","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":"736572630080000000000000"}
     * \endchinese
     * \english
     * Get the globally unique ID of the SlaveBoard
     *
     * @return Globally unique ID of the SlaveBoard
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getSlaveBoardUniqueId(self: pyaubo_sdk.RobotState) -> str
     *
     * @par Lua function prototype
     * getSlaveBoardUniqueId() -> string
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlaveBoardUniqueId","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":"736572630080000000000000"}
     * \endenglish
     */
    std::string getSlaveBoardUniqueId();

    /**
     * \chinese
     * 获取SlaveBoard固件版本
     *
     * @return SlaveBoard固件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getSlaveBoardFirmwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getSlaveBoardFirmwareVersion() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlaveBoardFirmwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":0}
     * \endchinese
     * \english
     * Get the SlaveBoard firmware version
     *
     * @return SlaveBoard firmware version
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getSlaveBoardFirmwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getSlaveBoardFirmwareVersion() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlaveBoardFirmwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":0}
     * \endenglish
     */
    int getSlaveBoardFirmwareVersion();

    /**
     * \chinese
     * 获取SlaveBoard硬件版本
     *
     * @return SlaveBoard硬件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getSlaveBoardHardwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getSlaveBoardHardwareVersion() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlaveBoardHardwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":6030098}
     * \endchinese
     * \english
     * Get the SlaveBoard hardware version
     *
     * @return SlaveBoard hardware version
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getSlaveBoardHardwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getSlaveBoardHardwareVersion() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlaveBoardHardwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":6030098}
     * \endenglish
     */
    int getSlaveBoardHardwareVersion();

    /**
     * \chinese
     * 获取工具端全球唯一ID
     *
     * @return 工具端全球唯一ID
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getToolUniqueId(self: pyaubo_sdk.RobotState) -> str
     *
     * @par Lua函数原型
     * getToolUniqueId() -> string
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolUniqueId","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":"397d4e5331541252314d3042"}
     * \endchinese
     * \english
     * Get the globally unique ID of the tool
     *
     * @return Globally unique ID of the tool
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getToolUniqueId(self: pyaubo_sdk.RobotState) -> str
     *
     * @par Lua function prototype
     * getToolUniqueId() -> string
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolUniqueId","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":"397d4e5331541252314d3042"}
     * \endenglish
     */
    std::string getToolUniqueId();

    /**
     * \chinese
     * 获取工具端固件版本
     *
     * @return 工具端固件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getToolFirmwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getToolFirmwareVersion() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolFirmwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":1001003}
     * \endchinese
     * \english
     * Get the tool firmware version
     *
     * @return Tool firmware version
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getToolFirmwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getToolFirmwareVersion() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolFirmwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":1001003}
     * \endenglish
     */
    int getToolFirmwareVersion();

    /**
     * \chinese
     * 获取工具端硬件版本
     *
     * @return 工具端硬件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getToolHardwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getToolHardwareVersion() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolHardwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":1000000}
     * \endchinese
     * \english
     * Get the tool hardware version
     *
     * @return Tool hardware version
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getToolHardwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getToolHardwareVersion() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolHardwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":1000000}
     * \endenglish
     */
    int getToolHardwareVersion();

    /**
     * \chinese
     * 获取末端通信模式
     *
     * @return 末端通信模式
     * 0: 表示无串口
     * 1: 表示只有串口
     * 2: 表示带力传感器和串口
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getToolCommMode(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getToolCommMode() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolCommMode","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":1}
     * \endchinese
     * \english
     * Get the tool communication mode
     *
     * @return Tool communication mode
     * 0: No serial port
     * 1: Serial port only
     * 2: With force sensor and serial port
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getToolCommMode(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getToolCommMode() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getToolCommMode","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":1}
     * \endenglish
     */
    int getToolCommMode();

    /**
     * \chinese
     * 获取底座全球唯一ID
     *
     * @return 底座全球唯一ID
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getPedestalUniqueId(self: pyaubo_sdk.RobotState) -> str
     *
     * @par Lua函数原型
     * getPedestalUniqueId() -> string
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getPedestalUniqueId","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":"205257533543065248544339"}
     * \endchinese
     * \english
     * Get the globally unique ID of the pedestal
     *
     * @return Globally unique ID of the pedestal
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getPedestalUniqueId(self: pyaubo_sdk.RobotState) -> str
     *
     * @par Lua function prototype
     * getPedestalUniqueId() -> string
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getPedestalUniqueId","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":"205257533543065248544339"}
     * \endenglish
     */
    std::string getPedestalUniqueId();

    /**
     * \chinese
     * 获取底座固件版本
     *
     * @return 底座固件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getPedestalFirmwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getPedestalFirmwareVersion() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getPedestalFirmwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":1000004}
     * \endchinese
     * \english
     * Get the pedestal firmware version
     *
     * @return Pedestal firmware version
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getPedestalFirmwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getPedestalFirmwareVersion() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getPedestalFirmwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":1000004}
     * \endenglish
     */
    int getPedestalFirmwareVersion();

    /**
     * \chinese
     * 获取底座硬件版本
     *
     * @return 底座硬件版本
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getPedestalHardwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua函数原型
     * getPedestalHardwareVersion() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getPedestalHardwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":1007000}
     * \endchinese
     * \english
     * Get the pedestal hardware version
     *
     * @return Pedestal hardware version
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getPedestalHardwareVersion(self: pyaubo_sdk.RobotState) -> int
     *
     * @par Lua function prototype
     * getPedestalHardwareVersion() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getPedestalHardwareVersion","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":1007000}
     * \endenglish
     */
    int getPedestalHardwareVersion();

    /**
     * \chinese
     * 获取机械臂关节目标位置角度
     *
     * @return 机械臂关节目标位置角度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointTargetPositions(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointTargetPositions() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetPositions","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,-0.2619944355631239,1.7418124015308052,0.4330219266665035,1.5707963267948966,0.0]}
     * \endchinese
     * \english
     * Get the target joint positions (angles) of the manipulator
     *
     * @return Target joint positions (angles) of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointTargetPositions(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointTargetPositions() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetPositions","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,-0.2619944355631239,1.7418124015308052,0.4330219266665035,1.5707963267948966,0.0]}
     * \endenglish
     */
    std::vector<double> getJointTargetPositions();

    /**
     * \chinese
     * 获取机械臂关节目标速度
     *
     * @return 机械臂关节目标速度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointTargetSpeeds(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointTargetSpeeds() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetSpeeds","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.00024227101509399773,0.0016521760307419697,0.0026521060731088397,0.0,0.0]}
     * \endchinese
     * \english
     * Get the target joint speeds of the manipulator
     *
     * @return Target joint speeds of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointTargetSpeeds(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointTargetSpeeds() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetSpeeds","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.00024227101509399773,0.0016521760307419697,0.0026521060731088397,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getJointTargetSpeeds();

    /**
     * \chinese
     * 获取机械臂关节目标加速度
     *
     * @return 机械臂关节目标加速度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointTargetAccelerations(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointTargetAccelerations() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetAccelerations","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,-0.6737932929246071,-12.610253240108449,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the target joint accelerations of the manipulator
     *
     * @return Target joint accelerations of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointTargetAccelerations(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointTargetAccelerations() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetAccelerations","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,-0.6737932929246071,-12.610253240108449,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getJointTargetAccelerations();

    /**
     * \chinese
     * 获取机械臂关节目标力矩
     *
     * @return 机械臂关节目标力矩
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointTargetTorques(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointTargetTorques() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetTorques","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the target joint torques of the manipulator
     *
     * @return Target joint torques of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointTargetTorques(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointTargetTorques() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetTorques","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getJointTargetTorques();

    /**
     * \chinese
     * 获取机械臂关节目标电流
     *
     * @return 机械臂关节目标电流
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getJointTargetCurrents(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua函数原型
     * getJointTargetCurrents() -> table
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetCurrents","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endchinese
     * \english
     * Get the target joint currents of the manipulator
     *
     * @return Target joint currents of the manipulator
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getJointTargetCurrents(self: pyaubo_sdk.RobotState) -> List[float]
     *
     * @par Lua function prototype
     * getJointTargetCurrents() -> table
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getJointTargetCurrents","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":[0.0,0.0,0.0,0.0,0.0,0.0]}
     * \endenglish
     */
    std::vector<double> getJointTargetCurrents();

    /**
     * \chinese
     * 获取控制柜温度
     *
     * @return 控制柜温度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getControlBoxTemperature(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua函数原型
     * getControlBoxTemperature() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getControlBoxTemperature","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":25.0}
     * \endchinese
     * \english
     * Get the control box temperature
     *
     * @return Control box temperature
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getControlBoxTemperature(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua function prototype
     * getControlBoxTemperature() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getControlBoxTemperature","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":25.0}
     * \endenglish
     */
    double getControlBoxTemperature();

    /**
     * \chinese
     * 获取控制柜湿度
     *
     * @return 控制柜湿度
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getControlBoxHumidity(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua函数原型
     * getControlBoxHumidity() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getControlBoxHumidity","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":20.0}
     * \endchinese
     * \english
     * Get the control box humidity
     *
     * @return Control box humidity
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getControlBoxHumidity(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua function prototype
     * getControlBoxHumidity() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getControlBoxHumidity","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":20.0}
     * \endenglish
     */
    double getControlBoxHumidity();

    /**
     * \chinese
     * 获取母线电压
     *
     * @return 母线电压
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getMainVoltage(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua函数原型
     * getMainVoltage() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMainVoltage","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":52.75}
     * \endchinese
     * \english
     * Get the main bus voltage
     *
     * @return Main bus voltage
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getMainVoltage(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua function prototype
     * getMainVoltage() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMainVoltage","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":52.75}
     * \endenglish
     */
    double getMainVoltage();

    /**
     * \chinese
     * 获取母线电流
     *
     * @return 母线电流
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getMainCurrent(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua函数原型
     * getMainCurrent() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMainCurrent","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":0.3204345703125}
     * \endchinese
     * \english
     * Get the main bus current
     *
     * @return Main bus current
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getMainCurrent(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua function prototype
     * getMainCurrent() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getMainCurrent","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":0.3204345703125}
     * \endenglish
     */
    double getMainCurrent();

    /**
     * \chinese
     * 获取机器人电压
     *
     * @return 机器人电压
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getRobotVoltage(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua函数原型
     * getRobotVoltage() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getRobotVoltage","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":52.75}
     * \endchinese
     * \english
     * Get the robot voltage
     *
     * @return Robot voltage
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getRobotVoltage(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua function prototype
     * getRobotVoltage() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getRobotVoltage","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":52.75}
     * \endenglish
     */
    double getRobotVoltage();

    /**
     * \chinese
     * 获取机器人电流
     *
     * @return 机器人电流
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python函数原型
     * getRobotCurrent(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua函数原型
     * getRobotCurrent() -> number
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getRobotCurrent","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":0.3204345703125}
     * \endchinese
     * \english
     * Get the robot current
     *
     * @return Robot current
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par Python function prototype
     * getRobotCurrent(self: pyaubo_sdk.RobotState) -> float
     *
     * @par Lua function prototype
     * getRobotCurrent() -> number
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getRobotCurrent","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":0.3204345703125}
     * \endenglish
     */
    double getRobotCurrent();

    /**
     * \chinese
     * 获取机器人缓速等级
     *
     * @return 机器人缓速等级
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlowDownLevel","params":[],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":0}
     * \endchinese
     * \english
     * Get the robot slow down level
     *
     * @return Robot slow down level
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlowDownLevel","params":[],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":0}
     * \endenglish
     */
    int getSlowDownLevel();

    /**
     * \chinese
     * 获取末端力传感器通信状态
     *
     * @param name 力传感器名称，与 selectTcpForceSensor 的参数一致
     * @return 通信正常返回 true;  反之返回 false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par JSON-RPC请求示例
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getTcpForceSensorStatus","params":["tool.KWR75A"],"id":1}
     *
     * @par JSON-RPC响应示例
     * {"id":1,"jsonrpc":"2.0","result":0}
     * \endchinese
     * \english
     * Get the communication status of the tool force sensor
     *
     * @param name  force sensor name, it is consistent with the parameters of
     * 'selectTcpForceSensor'
     * @return Returns true if communication is normal; otherwise returns false
     *
     * @throws arcs::common_interface::AuboException
     *
     * @par JSON-RPC request example
     * {"jsonrpc":"2.0","method":"rob1.RobotState.getSlowDownLevel","params":["tool.KWR75A"],"id":1}
     *
     * @par JSON-RPC response example
     * {"id":1,"jsonrpc":"2.0","result":0}
     * \endenglish
     */
    bool getTcpForceSensorStatus(const std::string &name);

protected:
    void *d_;
};
using RobotStatePtr = std::shared_ptr<RobotState>;
} // namespace common_interface
} // namespace arcs
#endif // AUBO_SDK_ROBOT_STATE_INTERFACE_H
