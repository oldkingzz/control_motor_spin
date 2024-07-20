#include <iostream>
#include "motor.h"
#include "controller.h"

int main() {
    // ����һ��Motor����
    Motor motor;

    // ����һ��Controller���󣬲�����Motor����
    Controller controller(motor);

    // ��ʼ��������
    controller.initialize();

    // ����Ŀ��λ�ú��ٶ�
    controller.setTargetPosition(10.0);  // ����Ŀ��λ��Ϊ10.0
    controller.setTargetTorque(1.0);   // ����Ŀ���ٶ�Ϊ1.0

    // �����迹���Ʋ���
    controller.setImpedanceParameters(500.0, 10.0, 5.0);  // ���øնȡ����������ϵ��

    // ģ�����ѭ��
    for (int i = 0; i < 100; ++i) {
        controller.updateControlSignal();  // ���¿����ź�
        // ����������һЩ��ʱ����ģ��ʵ�ʵĿ�������
    }

    return 0;
}
