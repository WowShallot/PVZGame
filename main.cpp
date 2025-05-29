#include <graphics.h>
#include "scene.h"
#include "menu_scene.h"


int main()
{
	ExMessage msg;
	const int FPS = 60;

	initgraph(1280, 720, EW_SHOWCONSOLE);//EW_SHOWCONSOLE显示控制台窗口

	BeginBatchDraw();

	Scene* scene = new MenuScene();

	scene->on_enter();

	while (true)
	{
		DWORD frame_start_time = GetTickCount();

		//1.读取数据
		while (peekmessage(&msg)) 
		{
			scene->on_input(msg); 
		}

		//2.处理数据
		scene->on_update(); 

		cleardevice();

		//3.绘制画面
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