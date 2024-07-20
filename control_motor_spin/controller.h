#pragma once
#include "Motor.h" // 引入Motor类的头文件

class Controller {
public:
    // 构造函数，接受一个Motor对象
    Controller(Motor& motor);

    // 初始化控制器
    void initialize();

    // 设置目标位置
    void setTargetPosition(double position);

    // 设置目标速度
    void setTargetTorque(double Torgue);

    // 设置阻抗控制参数
    void setImpedanceParameters(double stiffness, double damping, double mass);

    // 更新控制信号
    void updateControlSignal();

private:
    Motor& motor;              // 引用一个Motor对象
    double targetPosition;     // 目标位置
    double targetTorgue;     // 目标速度
    double stiffness;          // 阻抗控制中的刚度系数
    double damping;            // 阻抗控制中的阻尼系数
    double mass;               // 阻抗控制中的质量系数
};
