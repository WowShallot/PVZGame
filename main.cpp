#include <graphics.h>
#include "scene.h"
#include "menu_scene.h"
#include "game_scene.h"
#include "scene_manager.h"
#include "selector_sccene.h"
#include "util.h"
#include "atlas.h"

Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* selector_scene = nullptr;

SceneManager scene_manager;

void flip_atlas(Atlas& src, Atlas& dst);//用于图集翻转的函数


int main()
{
	ExMessage msg;
	const int FPS = 60;

	initgraph(1280, 720, EW_SHOWCONSOLE);//EW_SHOWCONSOLE显示控制台窗口

	BeginBatchDraw();

	menu_scene = new MenuScene();
	game_scene = new GameScene();
	selector_scene = new SelectorScene();

	scene_manager.set_current_scene(menu_scene);

	while (true)
	{
		DWORD frame_start_time = GetTickCount();

		//1.读取数据
		while (peekmessage(&msg)) 
		{
			scene_manager.on_input(msg);
		}

		//2.处理数据
		scene_manager.on_update();

		cleardevice();

		//3.绘制画面
		scene_manager.on_draw();

		FlushBatchDraw();

		DWORD frame_end_time = GetTickCount();
		DWORD frame_delta_time = frame_end_time - frame_start_time;
		if (frame_delta_time < 1000 / FPS)
			Sleep(1000 / FPS - frame_delta_time);
	}

	EndBatchDraw();

	return 0;
}

void flip_atlas(Atlas& src, Atlas& dst)
{
	dst.clear();   //首先清空了目标图集中已有的图片，避免目标图集重复使用时出现问题                   
	for (int i = 0; i < src.get_size(); i++) 
	{
		IMAGE img_flpipped;
		flip_image(src.get_image(i), &img_flpipped);//对原图集中的每一张图片都进行flip_image操作
		dst.add_image(img_flpipped);//通过add_image将翻转后的图片添加到目标图集
	}
}