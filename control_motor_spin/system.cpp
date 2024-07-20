#include "system.h" // 包含System类的头文件
#include <iostream> // 引入iostream库，用于输入输出操作

// 构造函数，初始化Motor和Controller引用
System::System(Motor& motor, Controller& controller)
    : motor(motor), controller(controller) {}

// 初始化系统
void System::initialize() {
    motor.initialize();       // 初始化电机
    controller.initialize();  // 初始化控制器
    std::cout << "System initialized." << std::endl; // 输出系统初始化完成的信息
}

// 运行系统
void System::run() {
    // 示例代码：设置目标位置和速度
    controller.setTargetPosition(10.0); // 设置目标位置为10.0
    controller.setTargetTorque(5.0);  // 设置目标速度为5.0

    // 更新控制信号
    controller.updateControlSignal(); // 调用控制器的updateControlSignal方法更新控制信号

    // 读取并输出当前电机状态
    double currentPosition = motor.readPosition(); // 获取当前电机位置
    double currentTorque = motor.readTorque();     // 获取当前电机扭矩
    std::cout << "Current position: " << currentPosition << std::endl; // 输出当前电机位置
    std::cout << "Current torque: " << currentTorque << std::endl;     // 输出当前电机扭矩
}
