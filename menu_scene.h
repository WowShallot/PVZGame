#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include "scene.h"
#include <iostream>
using namespace std;

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

	}
	
	void on_exit() 
	{
		cout << "���˵��˳�" << endl;
	}

private:

};

#endif // !_MENU_SCENE_H_