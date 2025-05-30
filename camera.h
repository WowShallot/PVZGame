#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector2.h"

class Camera
{
public:
	Camera() = default;
	~Camera() = default;

	//返回摄像机位置的常量引用
	const Vector2& get_position() const
	{
		return position;
	}

	//将摄像机位置归零
	void reset()
	{
		position.x = 0;
		position.y = 0;
	}

	void on_update(int delta)
	{
		const Vector2 speed = { -0.35f, 0 }; //给摄像机一个水平向左的速度
		position += speed * (float)delta;    //让摄像机随着时间逐渐向左移动
	}

private:
	Vector2 position;
};


#endif // !_CAMERA_H_
