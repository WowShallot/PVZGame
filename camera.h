#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector2.h"
#include "timer.h"

class Camera
{
public:
	Camera()
	{
		timer_shake.set_one_shot(true); //���õ��δ���
		timer_shake.set_callback([&]()  //���ûص����� ȡ������״̬ �� ���������λ��
			{
				is_shaking = false;
				reset();
			});
	}
	~Camera() = default;

	//���������������ʼ����������
	//               ����ǿ��    ��������ʱ��
	void shake(float strength, int duration)
	{
		is_shaking = true;
		shaking_strength = strength;
		//���ý�������״̬�Ķ�ʱ��
		timer_shake.set_wait_time(duration);//�ȴ�ʱ��Ϊ��������ʱ��
		timer_shake.restart();              //���¿�ʼ��ʱ
	}
	//���������λ�õĳ�������
	const Vector2& get_position() const
	{
		return position;
	}

	//�������λ�ù���
	void reset()
	{
		position.x = 0;
		position.y = 0;
	}

	void on_update(int delta)
	{
		timer_shake.on_update(delta);

		if (is_shaking) //����������ڶ������������λ�õ�x��yֵ��2����ǿ��Ϊ�뾶��Բ�����ȡֵ
		{
			position.x = (-50 + rand() % 100) / 50.0f * shaking_strength;
			position.y = (-50 + rand() % 100) / 50.0f * shaking_strength;
		}
	}

private:
	Vector2 position;			// �����λ��
	Timer timer_shake;			// �����������ʱ��
	bool is_shaking = false;	// ������Ƿ����ڶ���
	float shaking_strength = 0; // �������������
};


#endif // !_CAMERA_H_
