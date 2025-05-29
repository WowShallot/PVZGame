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
		cout << "�������˵�" << endl;
	}

	void on_update() 
	{
		cout << "���˵���������..." << endl;
	}

	void on_draw() 
	{
		outtextxy(10, 10, _T("���˵���ͼ����"));
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
		cout << "���˵��˳�" << endl;
	}

private:

};

#endif // !_MENU_SCENE_H_