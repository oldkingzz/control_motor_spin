#include "Controller.h" // ����Controller���ͷ�ļ�
#include <iostream> // ����iostream�⣬���������������

// ���캯������ʼ��Motor����
Controller::Controller(Motor& motor)
    : motor(motor), targetPosition(0.0), targetTorgue(0.0), stiffness(1.0), damping(0.1), mass(1.0) {}

// ��ʼ��������
void Controller::initialize() {
    motor.initialize(); // ��ʼ�����
    // ������ʼ������
    std::cout << "Controller initialized." << std::endl; // �����������ʼ����ɵ���Ϣ
}

// ����Ŀ��λ��
void Controller::setTargetPosition(double position) {
    targetPosition = position; // ����Ŀ��λ��
    std::cout << "Target position set to " << targetPosition << std::endl; // ����趨��Ŀ��λ��
}

// ����Ŀ���ٶ�
void Controller::setTargetTorque(double Torque) {
    targetTorgue = Torque; // ����Ŀ���ٶ�
    std::cout << "Target velocity set to " << targetTorgue << std::endl; // ����趨��Ŀ���ٶ�
}

// �����迹���Ʋ���
void Controller::setImpedanceParameters(double stiffness, double damping, double mass) {
    this->stiffness = stiffness; // ���øն�ϵ��
    this->damping = damping;     // ��������ϵ��
    this->mass = mass;           // ��������ϵ��
    std::cout << "Impedance parameters set: stiffness=" << stiffness
        << ", damping=" << damping << ", mass=" << mass << std::endl; // ����趨���迹����
}

// ���¿����ź�
void Controller::updateControlSignal() {
    // ��ȡ��ǰ���λ��
    double currentPosition = motor.readPosition(); // ����Motor���readPosition������ȡ��ǰ���λ��
    // ��ȡ��ǰ����ٶ�
    double currentTorgue = motor.readTorque(); // ����Motor���readVelocity������ȡ��ǰ����ٶ�

    // ����λ�����
    double positionError = targetPosition - currentPosition; // ����Ŀ��λ���뵱ǰ���λ��֮������
    // �����ٶ����
    double TorgueError = targetTorgue - currentTorgue; // ����Ŀ���ٶ��뵱ǰ����ٶ�֮������

    // �迹���ƹ�ʽ��F = Kp * positionError + Kd * velocityError
    double forceCommand = stiffness * positionError + damping * TorgueError; // �������������

    // ���Ϳ����źŵ����
    motor.sendControlSignal(targetPosition, forceCommand); // ����Motor���sendControlSignal�������Ϳ����ź�

    // ������º�Ŀ����ź���Ϣ
    std::cout << "Control signal updated: position=" << targetPosition
        << ", force=" << forceCommand << std::endl;
}
