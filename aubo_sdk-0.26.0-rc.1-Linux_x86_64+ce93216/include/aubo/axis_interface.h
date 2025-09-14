/** @file axes.h
 *  @brief 外部轴接口
 */
#ifndef AUBO_SDK_AXIS_INTERFACE_H
#define AUBO_SDK_AXIS_INTERFACE_H

#include <aubo/sync_move.h>
#include <aubo/trace.h>

namespace arcs {
namespace common_interface {

/**
 * \~chinese 外部轴API接口 
 * \~english External axis API interface
 */
class ARCS_ABI_EXPORT AxisInterface
{
public:
    AxisInterface();
    virtual ~AxisInterface();

    /**
     * \~chinese 通电
     * \~english Power on
     * @return
     */
    int poweronExtAxis();

    /**
     * \~chinese 断电
     * \~english Power off
     * @return
     */
    int poweroffExtAxis();

    /**
     * \~chinese 使能
     * \~english Enable
     * @return
     */
    int enableExtAxis();

    /**
     * \~chinese 设置外部轴的安装位姿(相对于世界坐标系)
     * \~chinese @param pose
     * \~english Set mounting pose of external axis (wrt world frame)
     * \~english @param pose

     * @return
     */
    int setExtAxisMountingPose(const std::vector<double> &pose);

    /**
     * \chinese 运动到指定点， 旋转或者平移
     * 
     * @param pos
     * @param v
     * @param a
     * @param duration
     * @return
     * \endchinese
     *
     * \english move to pos, rotation or linear
     * 
     * @param pos
     * @param v
     * @param a
     * @param duration
     * @return
     * \endenglish
     */
    int moveExtJoint(double pos, double v, double a, double duration);

    /**
     * \chinese
     * 制定目标运动速度
     *
     * @param v
     * @param a
     * @param duration
     * @return
     * \endchinese
     *
     * \english
     * Set target speed, acceleration and duration
     * @param v
     * @param a
     * @param duration
     * @return
     * \endenglish
     */
    int speedExtJoint(double v, double a, double duration);

    int stopExtJoint(double a);

    /**
     * \~chinese 获取外部轴的类型 0代表是旋转 1代表平移
     * \~english Get external axis type: 0 for rotation, 1 for linear
     * @return
     */
    int getExtAxisType();

    /**
     * \chinese
     * 获取当前外部轴的状态
     *
     * @return 当前外部轴的状态
     * \endchinese
     * 
     * \english
     * Get external axis status
     *
     * @return Current exteral axis status
     * \endenglish
     */
    AxisModeType getAxisModeType();

    /**
     * \chinese
     * 获取外部轴安装位姿
     *
     * @return 外部轴安装位姿
     * \endchinese
     * 
     * \english
     * Get external axis mounting pose
     *
     * @return External axis pose
     * \endenglish
     */
    std::vector<double> getExtAxisMountingPose();

    /**
     * \chinese
     * 获取相对于安装坐标系的位姿，外部轴可能为变位机或者导轨
     *
     * @return 相对于安装坐标系的位姿
     * \endchinese
     *
     * \english
     * Get pose wrt mounting coordinate system, axis can be positioner or linear rail
     *
     * @return Pose wrt mounting coordinate system
     * \endenglish
     */
    std::vector<double> getExtAxisPose();

    /**
     * \chinese 
     * 获取外部轴位置
     *
     * @return 外部轴位置
     * \endchinese
     * 
     * \english
     * Get external axis position
     *
     * @return External axis position
     * \endenglish
     */
    double getExtAxisPosition();

    /**
     * \chinese
     * 获取外部轴运行速度
     *
     * @return 外部轴运行速度
     * \endchinese
     * 
     * \english
     * Get external axis speed
     *
     * @return External axis speed
     * \endenglish
     */
    double getExtAxisVelocity();

    /**
     * \chinese
     * 获取外部轴运行加速度
     *
     * @return 外部轴运行加速度
     * \endchinese
     *
     * \english
     * Get external axis acceleration
     *
     * @return External axis acceleration
     * \endenglish
     */
    double getExtAxisAcceleration();

    /**
     * \chinese
     * 获取外部轴电流
     *
     * @return 外部轴电流
     * \endchinese
     *
     * \english
     * Get external axis current
     *
     * @return External axis current
     * \endenglish
     */
    double getExtAxisCurrent();

    /**
     * \chinese
     * 获取外部轴温度
     *
     * @return 外部轴温度
     * \endchinese
     *
     * \english
     * Get external axis temperature
     *
     * @return External axis temperature
     * \endenglish
     */
    double getExtAxisTemperature();

    /**
     * \chinese
     * 获取外部轴电压
     *
     * @return 外部轴电压
     * \endchinese
     *
     * \english
     * Get external axis voltage
     *
     * @return External axis voltage
     * \endenglish
     */
    double getExtAxisBusVoltage();

    /**
     * \chinese
     * 获取外部轴电流
     *
     * @return 外部轴电流
     * \endchinese
     *
     * \english
     * Get external axis current
     *
     * @return external axis current
     * \endenglish
     */
    double getExtAxisBusCurrent();

    /**
     * \chinese
     * 获取外部轴最大位置
     *
     * @return 外部轴最大位置
     * \endchinese
     *
     * \english
     * Get external axis max position
     *
     * @return External axis max position
     * \endenglish
     */
    double getExtAxisMaxPosition();

    /**
     * \chinese
     * 获取外部轴最小位置
     *
     * @return 外部轴最小位置
     * \endchinese
     *
     * \english
     * Get external axis min position
     *
     * @return External axis min position
     * \endenglish
     */
    double getExtMinPosition();

    /**
     * \chinese
     * 获取外部轴最大速度
     *
     * @return 外部轴最大速度
     * \endchinese
     *
     * \english
     * Get external axis max speed
     *
     * @return External axis max speed
     * \endenglish
     */
    double getExtAxisMaxVelocity();

    /**
     * \chinese
     * 获取外部轴最大加速度
     *
     * @return 外部轴最大加速度
     * \endchinese
     *
     * \english
     * Get external axis max acceleration
     *
     * @return External axis max acceleration
     * \endenglish
     */
    double getExtAxisMaxAcceleration();

    /**
     * \chinese
     * 跟踪另一个外部轴的运动(禁止运动过程中使用)
     *
     * @param target_name 目标的外部轴名字
     * @param phase 相位差
     * @param err 跟踪运行的最大误差
     * @return
     * \endchinese
     *
     * \english
     * Follow motion of another external axis （not to be used during motion）
     *
     * @param target_name name of target axis
     * @param phase phase difference
     * @param err max error when following motion
     * @return
     * \endenglish
     */
    int followAnotherAxis(const std::string &target_name, double phase,
                          double err);

    /**
     * \~chinese @brief stopFollowAnotherAxis(禁止运动过程中使用)
     * \~english @brief stopFollowAnotherAxis(not to be used during motion)
     * @return
     */
    int stopFollowAnotherAxis();

protected:
    void *d_;
};
using AxisInterfacePtr = std::shared_ptr<AxisInterface>;

} // namespace common_interface
} // namespace arcs

#endif // AUBO_SDK_AXIS_INTERFACE_H
