#include "Controller.h" // 包含Controller类的头文件
#include <iostream> // 引入iostream库，用于输入输出操作

// 构造函数，初始化Motor引用
Controller::Controller(Motor& motor)
    : motor(motor), targetPosition(0.0), targetTorgue(0.0), stiffness(1.0), damping(0.1), mass(1.0) {}

// 初始化控制器
void Controller::initialize() {
    motor.initialize(); // 初始化电机
    // 其他初始化操作
    std::cout << "Controller initialized." << std::endl; // 输出控制器初始化完成的信息
}

// 设置目标位置
void Controller::setTargetPosition(double position) {
    targetPosition = position; // 设置目标位置
    std::cout << "Target position set to " << targetPosition << std::endl; // 输出设定的目标位置
}

// 设置目标速度
void Controller::setTargetTorque(double Torque) {
    targetTorgue = Torque; // 设置目标速度
    std::cout << "Target velocity set to " << targetTorgue << std::endl; // 输出设定的目标速度
}

// 设置阻抗控制参数
void Controller::setImpedanceParameters(double stiffness, double damping, double mass) {
    this->stiffness = stiffness; // 设置刚度系数
    this->damping = damping;     // 设置阻尼系数
    this->mass = mass;           // 设置质量系数
    std::cout << "Impedance parameters set: stiffness=" << stiffness
        << ", damping=" << damping << ", mass=" << mass << std::endl; // 输出设定的阻抗参数
}

// 更新控制信号
void Controller::updateControlSignal() {
    // 读取当前电机位置
    double currentPosition = motor.readPosition(); // 调用Motor类的readPosition方法获取当前电机位置
    // 读取当前电机速度
    double currentTorgue = motor.readTorque(); // 调用Motor类的readVelocity方法获取当前电机速度

    // 计算位置误差
    double positionError = targetPosition - currentPosition; // 计算目标位置与当前电机位置之间的误差
    // 计算速度误差
    double TorgueError = targetTorgue - currentTorgue; // 计算目标速度与当前电机速度之间的误差

    // 阻抗控制公式：F = Kp * positionError + Kd * velocityError
    double forceCommand = stiffness * positionError + damping * TorgueError; // 计算控制力命令

    // 发送控制信号到电机
    motor.sendControlSignal(targetPosition, forceCommand); // 调用Motor类的sendControlSignal方法发送控制信号

    // 输出更新后的控制信号信息
    std::cout << "Control signal updated: position=" << targetPosition
        << ", force=" << forceCommand << std::endl;
}
