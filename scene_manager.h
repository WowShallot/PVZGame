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

	void set_current_state(Scene* scene)//���õ�ǰ�ĳ���
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
			break;
		case SceneType::Game:
			break;
		default:
			break;
		}
		current_scene->on_enter();  //�����ת���³���
	}

private:
	Scene* current_scene = nullptr;
};

#endif // !_SCENE_MANAGER_H_