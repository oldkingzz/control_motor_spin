#pragma once
#include "Motor.h" // ����Motor���ͷ�ļ�

class Controller {
public:
    // ���캯��������һ��Motor����
    Controller(Motor& motor);

    // ��ʼ��������
    void initialize();

    // ����Ŀ��λ��
    void setTargetPosition(double position);

    // ����Ŀ���ٶ�
    void setTargetTorque(double Torgue);

    // �����迹���Ʋ���
    void setImpedanceParameters(double stiffness, double damping, double mass);

    // ���¿����ź�
    void updateControlSignal();

private:
    Motor& motor;              // ����һ��Motor����
    double targetPosition;     // Ŀ��λ��
    double targetTorgue;     // Ŀ���ٶ�
    double stiffness;          // �迹�����еĸն�ϵ��
    double damping;            // �迹�����е�����ϵ��
    double mass;               // �迹�����е�����ϵ��
};
