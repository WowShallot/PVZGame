#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector2.h"

class Camera
{
public:
	Camera() = default;
	~Camera() = default;

	//���������λ�õĳ�������
	const Vector2& get_position() const
	{
		return position;
	}

	//�������λ�ù���
	void reset()
	{
		position.x = 0;
		position.y = 0;
	}

	void on_update(int delta)
	{

	}

private:
	Vector2 position;
};


#endif // !_CAMERA_H_
