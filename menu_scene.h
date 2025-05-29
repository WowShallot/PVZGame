#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include <iostream>
#include "scene.h"
#include "scene_manager.h"

using namespace std;

extern SceneManager scene_manager;

class MenuScene : public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		cout << "进入主菜单" << endl;
	}

	void on_update() 
	{
		cout << "主菜单正在运行..." << endl;
	}

	void on_draw() 
	{
		outtextxy(10, 10, _T("主菜单绘图内容"));
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

};

#endif // !_MENU_SCENE_H_