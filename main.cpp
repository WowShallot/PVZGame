#include <graphics.h>
#include "scene.h"
#include "menu_scene.h"


int main()
{
	ExMessage msg;
	const int FPS = 60;

	initgraph(1280, 720, EW_SHOWCONSOLE);//EW_SHOWCONSOLE��ʾ����̨����

	BeginBatchDraw();

	Scene* scene = new MenuScene();

	scene->on_enter();

	while (true)
	{
		DWORD frame_start_time = GetTickCount();

		//1.��ȡ����
		while (peekmessage(&msg)) 
		{
			scene->on_input(msg); 
		}

		//2.��������
		scene->on_update(); 

		cleardevice();

		//3.���ƻ���
		scene->on_draw(); 

		FlushBatchDraw();

		DWORD frame_end_time = GetTickCount();
		DWORD frame_delta_time = frame_end_time - frame_start_time;
		if (frame_delta_time < 1000 / FPS)
			Sleep(1000 / FPS - frame_delta_time);
	}

	EndBatchDraw();

	return 0;
}