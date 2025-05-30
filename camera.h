#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector2.h"
#include "timer.h"

class Camera
{
public:
	Camera()
	{
		timer_shake.set_one_shot(true); //设置单次触发
		timer_shake.set_callback([&]()  //设置回调函数 取消抖动状态 并 重置摄像机位置
			{
				is_shaking = false;
				reset();
			});
	}
	~Camera() = default;

	//用于设置摄像机开始抖动的属性
	//               抖动强度    抖动持续时间
	void shake(float strength, int duration)
	{
		is_shaking = true;
		shaking_strength = strength;
		//设置结束抖动状态的定时器
		timer_shake.set_wait_time(duration);//等待时间为抖动持续时间
		timer_shake.restart();              //重新开始计时
	}
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
		timer_shake.on_update(delta);

		if (is_shaking) //若摄像机正在抖动，则将摄像机位置的x、y值在2抖动强度为半径的圆内随机取值
		{
			position.x = (-50 + rand() % 100) / 50.0f * shaking_strength;
			position.y = (-50 + rand() % 100) / 50.0f * shaking_strength;
		}
	}

private:
	Vector2 position;			// 摄像机位置
	Timer timer_shake;			// 摄像机抖动定时器
	bool is_shaking = false;	// 摄像机是否正在抖动
	float shaking_strength = 0; // 摄像机抖动幅度
};


#endif // !_CAMERA_H_
