#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>
using namespace std;

class Timer
{
public:
	Timer() = default;
	~Timer() = default;

	//���ü�ʱ��״̬�����¿�ʼ��ʱ
	void restart()
	{
		pass_time = 0;
		shotted = false;
	}

	//���ü�ʱ���ȴ�ʱ��
	void set_wait_time(int val)
	{
		wait_time = val;
	}

	//�Ƿ񵥴δ���
	void set_one_shot(bool flag)
	{
		one_shot = flag;
	}

	//���ûص�����
	void set_callback(function<void()> callback)
	{
		this->callback = callback;
	}

	//��ʱ������ͣ
	void pause()
	{
		paused = true;
	}

	//��ʱ���Ļָ�����
	void resume()
	{
		paused = false;
	}


	//
	void on_update(int delta)
	{
		if (paused) //����ʱ���Ƿ�����ͣ״̬
			return;

		pass_time += delta; //�ۼ�֡����ʵ�ʹ�ȥ��ʱ��
		if (pass_time >= wait_time) //�� ��ʱ�����������ѹ�ȥ��ʱ�� �� ���������ʱ��wait_time ���бȽ�
		{
			//����ʱ�����Դ�����ʱ���Ļص�
			if ((!one_shot || (one_shot && !shotted)) && callback) //����ʱ���Ƿ��ܱ�����
				//�����ǵ��δ��� �� ���ʴ�����û�б���������ͬʱ ���callback�Ƿ���Ч
				callback();
			shotted = true; //���ü�ʱ���Ĵ���״̬Ϊtrue
			pass_time = 0;  //�����Ѿ��ȹ���ʱ��
		}
	}

private:
	int pass_time = 0;		   // �ѹ�ʱ��
	int wait_time = 0;		   // �ȴ�ʱ��
	bool paused = false;	   // �Ƿ���ͣ
	bool shotted = false;	   // �Ƿ񴥷�
	bool one_shot = false;	   // ���δ���
	function<void()> callback; // �����ص�
};

#endif // !_TIMER_H_