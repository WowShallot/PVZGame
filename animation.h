#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "atlas.h"
#include "util.h"

#include <graphics.h>
#include <functional>

using namespace std;

class Animation
{
public:
	Animation() = default;
	~Animation() = default;

	//1.���ڶ����Ļ������úͻ�ȡ����
	// �������ö���״̬���ڶ�����Ҫ��ͷ����ʱʹ��
	void reset()						
	{
		timer = 0;
		idx_frame = 0;
	}

	// ���ö�����ʹ�õ�ͼ��
	void set_atlas(Atlas* new_atlas)	
	{ 
		reset();            // �����ظ�����ʱ����֡����Խ������
		atlas = new_atlas;
	}

	// ���ö����Ƿ�ѭ������
	void set_loop(bool flag)			
	{
		is_loop = flag;
	}

	// ���ö���֡���
	void set_interval(int ms)			
	{
		interval = ms;
	}

	//�����ڲ���ʱ ֡���� ���ƽ����Զ����е�
	//����Ҫ�ⲿʹ�� set ��������

	// ��ȡ��ǰ ֡����
	int get_idx_frame()					
	{
		return idx_frame;
	}

	// ��ȡ��ǰ ֡ͼƬ
	IMAGE* get_frame()					
	{
		return atlas->get_image(idx_frame);
	}

	// ��鶯���Ƿ񲥷Ž���
	bool check_finished()				
	{
		if (is_loop)       //������������Ϊѭ������ʱ
			return false;  //����false��ʾ�����������
		return (idx_frame == atlas->get_size() - 1); //��֮�����鵱ǰ ֡���� �Ƿ��Ѿ�����ͼ����β��
	}

	//2.����ص����������������������Ž�������ɾ������
	//������ĺ������󱣴浽�������callback��
	void set_callback(function<void()> callback)
	{
		this->callback = callback;
	}

	//3.�������º���Ⱦ�߼�
	//��������
	void on_update(int delta)
	{
		timer += delta;			//ÿ�θ���ʱ�ۼӼ�ʱ����ֵ
		if (timer >= interval)  //����ʱ���Ƿ񳬹�֡���
		{
			timer = 0;          //����֡�������ʱ������
			idx_frame++;		//����֡��������ۼ�֡����
			if (idx_frame >= atlas->get_size()) //��鶯���Ƿ񲥷ŵ�ͼ��β��
			{
				idx_frame = is_loop ? 0 : atlas->get_size() - 1;
				//�����Ƿ�ѭ�����ţ����ö��� ֡���� �Ǵ�ͷ��ʼ ���Ǳ�����ͼ�����һ��ͼƬλ����
				if (!is_loop && callback)   //���֡����������ͼ����β�����Ҷ���û������ѭ�����Ų��һص���������
					callback();				//��ִ�лص��������߼�
			}
		}
	}

	//������Ⱦ������͸����
	void on_draw(int x, int y) const  //const ��ʾ������Ա�����������޸�����κγ�Ա�������������޸Ķ����״̬
	{
		putimage_alpha(x, y, atlas->get_image(idx_frame));
	}

	


private:
	int timer = 0;          // ��ʱ��
	int interval = 0;		// ֡���
	int idx_frame = 0;		// ֡����
	bool is_loop = true;	// �Ƿ�ѭ��	
	Atlas* atlas = nullptr; // atlasͼ��ָ��
	function<void()> callback; //function���͵ĺ������� <void()>��ʾ���������д洢�ĺ�����������Ϊvoid�����޲���

};

#endif // !_ANIMATION_H_
