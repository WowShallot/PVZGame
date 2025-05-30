#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>
using namespace std;

class Timer
{
public:
	Timer() = default;
	~Timer() = default;

	//重置计时器状态，重新开始计时
	void restart()
	{
		pass_time = 0;
		shotted = false;
	}

	//设置计时器等待时间
	void set_wait_time(int val)
	{
		wait_time = val;
	}

	//是否单次触发
	void set_one_shot(bool flag)
	{
		one_shot = flag;
	}

	//设置回调函数
	void set_callback(function<void()> callback)
	{
		this->callback = callback;
	}

	//计时器的暂停
	void pause()
	{
		paused = true;
	}

	//计时器的恢复运行
	void resume()
	{
		paused = false;
	}


	//
	void on_update(int delta)
	{
		if (paused) //检查计时器是否处于暂停状态
			return;

		pass_time += delta; //累加帧更新实际过去的时间
		if (pass_time >= wait_time) //将 计时器启动以来已过去的时间 与 期望到达的时间wait_time 进行比较
		{
			//若超时，则尝试触发计时器的回调
			if ((!one_shot || (one_shot && !shotted)) && callback) //检查计时器是否能被触发
				//（不是单次触发 或 单词触发但没有被触发过）同时 检查callback是否有效
				callback();
			shotted = true; //设置计时器的触发状态为true
			pass_time = 0;  //重置已经度过的时间
		}
	}

private:
	int pass_time = 0;		   // 已过时间
	int wait_time = 0;		   // 等待时间
	bool paused = false;	   // 是否暂停
	bool shotted = false;	   // 是否触发
	bool one_shot = false;	   // 单次触发
	function<void()> callback; // 触发回调
};

#endif // !_TIMER_H_