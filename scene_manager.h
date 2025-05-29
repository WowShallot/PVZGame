#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "scene.h"


class SceneManager
{
public:
	enum class SceneType
	{
		Menu,
		Game
	};

public:
	SceneManager() = default;
	~SceneManager() = default;

	void set_current_state(Scene* scene)//设置当前的场景
	{
		current_scene = scene;
		current_scene->on_enter(); //确保场景的执行流程完整
	}

	void switch_to(SceneType type) // 转换当前场景
	{
		current_scene->on_exit();  //首先退出当前场景
		switch (type)              //然后找到新场景
		{
		case SceneType::Menu:
			break;
		case SceneType::Game:
			break;
		default:
			break;
		}
		current_scene->on_enter();  //最后跳转至新场景
	}

private:
	Scene* current_scene = nullptr;
};

#endif // !_SCENE_MANAGER_H_