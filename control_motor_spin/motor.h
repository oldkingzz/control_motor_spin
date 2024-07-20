#pragma once

#include <string>
#include <iostream>

class Motor {
public:
    // 构造函数，接受电机ID和CAN接口名称
    Motor() = default;
    Motor(int id, const std::string& canInterface) ;

    // 初始化电机
    void initialize();

    // 读取电机位置
    double readPosition();

    // 读取电机扭矩
    double readTorque();

    // 发送控制信号
    void sendControlSignal(double position, double velocity);

private:
    int motorId; // 电机ID
    std::string canInterface; // CAN接口名称

    // 私有方法：打开CAN接口
    void openCanInterface();

    // 私有方法：关闭CAN接口
    void closeCanInterface();

    // 私有方法：发送CAN消息
    void sendCanMessage(const std::string& message);

    // 私有方法：接收CAN消息
    std::string receiveCanMessage();
};

