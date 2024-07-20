#include "system.h" // ����System���ͷ�ļ�
#include <iostream> // ����iostream�⣬���������������

// ���캯������ʼ��Motor��Controller����
System::System(Motor& motor, Controller& controller)
    : motor(motor), controller(controller) {}

// ��ʼ��ϵͳ
void System::initialize() {
    motor.initialize();       // ��ʼ�����
    controller.initialize();  // ��ʼ��������
    std::cout << "System initialized." << std::endl; // ���ϵͳ��ʼ����ɵ���Ϣ
}

// ����ϵͳ
void System::run() {
    // ʾ�����룺����Ŀ��λ�ú��ٶ�
    controller.setTargetPosition(10.0); // ����Ŀ��λ��Ϊ10.0
    controller.setTargetTorque(5.0);  // ����Ŀ���ٶ�Ϊ5.0

    // ���¿����ź�
    controller.updateControlSignal(); // ���ÿ�������updateControlSignal�������¿����ź�

    // ��ȡ�������ǰ���״̬
    double currentPosition = motor.readPosition(); // ��ȡ��ǰ���λ��
    double currentTorque = motor.readTorque();     // ��ȡ��ǰ���Ť��
    std::cout << "Current position: " << currentPosition << std::endl; // �����ǰ���λ��
    std::cout << "Current torque: " << currentTorque << std::endl;     // �����ǰ���Ť��
}
