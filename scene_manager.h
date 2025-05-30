#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "scene.h"
#include "camera.h"

extern Scene* menu_scene;//ͨ��extern�ؼ���
extern Scene* game_scene;//��ȡ��������ȫ��ָ�������
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

	void set_current_scene(Scene* scene)//���õ�ǰ�ĳ���
	{
		current_scene = scene;
		current_scene->on_enter(); //ȷ��������ִ����������
	}

	void switch_to(SceneType type) // ת����ǰ����
	{
		current_scene->on_exit();  //�����˳���ǰ����
		switch (type)              //Ȼ���ҵ��³���
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
		current_scene->on_enter();  //�����ת���³���
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