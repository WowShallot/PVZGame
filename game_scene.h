#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include <iostream>
#include "scene.h"
#include "scene_manager.h"

using namespace std;

extern SceneManager scene_manager;

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

	void on_draw(int delta)
	{
		outtextxy(10, 10, _T("��Ϸ���ڻ�ͼ����"));
	}

	void on_input(const ExMessage& msg)
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}
	}

	void on_exit()
	{
		cout << "��Ϸ�����˳�" << endl;
	}

private:

};


#endif // !_GAME_SCENE_H_