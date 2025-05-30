#ifndef _SCENE_H_
#define _SCENE_H_

#include "camera.h"
#include <graphics.h>

class Scene
{
public:
	Scene() = default;
	~Scene() = default;

	virtual void on_enter() {} // ÷ÿ÷√≥°æ∞◊¥Ã¨
	virtual void on_update(int delta) {}
	virtual void on_draw(const Camera& camera) {}
	virtual void on_input(const ExMessage& msg) {}
	virtual void on_exit() {} // ÷ÿ÷√≥°æ∞◊¥Ã¨

private:

};

#endif // !_SCENE_H_