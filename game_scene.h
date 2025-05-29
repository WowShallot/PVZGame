#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include <iostream>
using namespace std;

class GameScene : public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter()
	{
		cout << "������Ϸ���ڳ���" << endl;
	}

	void on_update()
	{
		cout << "��Ϸ��������..." << endl;
	}

	void on_draw()
	{
		outtextxy(10, 10, _T("��Ϸ���ڻ�ͼ����"));
	}

	void on_input(const ExMessage& msg)
	{

	}

	void on_exit()
	{
		cout << "��Ϸ�����˳�" << endl;
	}

private:

};


#endif // !_GAME_SCENE_H_