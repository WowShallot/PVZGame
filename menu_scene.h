#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include <iostream>
#include "scene.h"
#include "scene_manager.h"
#include "animation.h"
#include "atlas.h"
#include "camera.h"
#include "timer.h"

using namespace std;

extern Atlas atlas_peashooter_run_right;

extern SceneManager scene_manager;

class MenuScene : public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);  //设置图集
		animation_peashooter_run_right.set_interval(75);						//设置帧间隔
		animation_peashooter_run_right.set_loop(true);							//设置循环

		timer.set_wait_time(1000);  //设置计时器在一秒后输出 Shot！字符串；并让其可多次触发
		timer.set_one_shot(false);
		timer.set_callback([]()
			{
				cout << "Shot!" << endl;
			});

	}

	void on_update(int delta) 
	{
		timer.on_update(delta);
		camera.on_update(delta);
		animation_peashooter_run_right.on_update(delta);
	}

	void on_draw() 
	{
		const Vector2& pos_camera = camera.get_position();
		animation_peashooter_run_right.on_draw((int)(100 - pos_camera.x), (int)(100 - pos_camera.y));
	}

	void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}
	
	void on_exit() 
	{
		cout << "主菜单退出" << endl;
	}

private:
	Timer timer;
	Camera camera;
	Animation animation_peashooter_run_right;

};

#endif // !_MENU_SCENE_H_