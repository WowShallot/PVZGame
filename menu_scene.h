#pragma once

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

	}
	
	void on_update() 
	{
		cout << "主菜单退出" << endl;
	}

private:

};