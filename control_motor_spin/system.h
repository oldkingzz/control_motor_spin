#pragma once
#include "controller.h" // ����Controller���ͷ�ļ�
#include "motor.h"      // ����Motor���ͷ�ļ�

class System {
public:
    // ���캯��������һ��Motor�����һ��Controller����
    System(Motor& motor, Controller& controller);

    // ��ʼ��ϵͳ
    void initialize();

    // ����ϵͳ
    void run();

private:
    Motor& motor;         // ����һ��Motor����
    Controller& controller; // ����һ��Controller����
};
