#pragma once

#include <string>
#include <iostream>

class Motor {
public:
    // ���캯�������ܵ��ID��CAN�ӿ�����
    Motor() = default;
    Motor(int id, const std::string& canInterface) ;

    // ��ʼ�����
    void initialize();

    // ��ȡ���λ��
    double readPosition();

    // ��ȡ���Ť��
    double readTorque();

    // ���Ϳ����ź�
    void sendControlSignal(double position, double velocity);

private:
    int motorId; // ���ID
    std::string canInterface; // CAN�ӿ�����

    // ˽�з�������CAN�ӿ�
    void openCanInterface();

    // ˽�з������ر�CAN�ӿ�
    void closeCanInterface();

    // ˽�з���������CAN��Ϣ
    void sendCanMessage(const std::string& message);

    // ˽�з���������CAN��Ϣ
    std::string receiveCanMessage();
};

