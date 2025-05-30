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
		cout << "进入游戏局内场景" << endl;
	}

	void on_update()
	{
		cout << "游戏正在运行..." << endl;
	}

	void on_draw(int delta)
	{
		outtextxy(10, 10, _T("游戏局内绘图内容"));
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
		cout << "游戏局内退出" << endl;
	}

private:

};


#endif // !_GAME_SCENE_H_