#pragma once
#include "controller.h" // 引入Controller类的头文件
#include "motor.h"      // 引入Motor类的头文件

class System {
public:
    // 构造函数，接受一个Motor对象和一个Controller对象
    System(Motor& motor, Controller& controller);

    // 初始化系统
    void initialize();

    // 运行系统
    void run();

private:
    Motor& motor;         // 引用一个Motor对象
    Controller& controller; // 引用一个Controller对象
};
