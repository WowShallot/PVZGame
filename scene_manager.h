#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "scene.h"
#include "camera.h"

extern Scene* menu_scene;//通过extern关键字
extern Scene* game_scene;//获取到这两个全局指针的引用
extern Scene* selector_scene;

class SceneManager
{
public:
	enum class SceneType
	{
		Menu,
		Game,
		Selector
	};

public:
	SceneManager() = default;
	~SceneManager() = default;

	void set_current_scene(Scene* scene)//设置当前的场景
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
			current_scene = menu_scene;
			break;
		case SceneType::Game:
			current_scene = game_scene;
			break;
		case SceneType::Selector:
			current_scene = selector_scene;
		default:
			break;
		}
		current_scene->on_enter();  //最后跳转至新场景
	}

	void on_update(int delta)
	{
		current_scene->on_update(delta);
	}

	void on_draw(const Camera& camera)
	{
		current_scene->on_draw(camera);
	}

	void on_input(const ExMessage& msg)
	{
		current_scene->on_input(msg);
	}

private:
	Scene* current_scene = nullptr;
};

#endif // !_SCENE_MANAGER_H_