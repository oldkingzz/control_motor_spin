#include <iostream>
#include "motor.h"
#include "controller.h"

int main() {
    // 创建一个Motor对象
    Motor motor;

    // 创建一个Controller对象，并传入Motor对象
    Controller controller(motor);

    // 初始化控制器
    controller.initialize();

    // 设置目标位置和速度
    controller.setTargetPosition(10.0);  // 设置目标位置为10.0
    controller.setTargetTorque(1.0);   // 设置目标速度为1.0

    // 设置阻抗控制参数
    controller.setImpedanceParameters(500.0, 10.0, 5.0);  // 设置刚度、阻尼和质量系数

    // 模拟控制循环
    for (int i = 0; i < 100; ++i) {
        controller.updateControlSignal();  // 更新控制信号
        // 这里可以添加一些延时，以模拟实际的控制周期
    }

    return 0;
}
