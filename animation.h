#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "atlas.h"
#include "util.h"

#include <graphics.h>
#include <functional>

using namespace std;

class Animation
{
public:
	Animation() = default;
	~Animation() = default;

	//1.用于动画的基础设置和获取工具
	// 用于重置动画状态，在动画需要从头播放时使用
	void reset()						
	{
		timer = 0;
		idx_frame = 0;
	}

	// 设置动画所使用的图集
	void set_atlas(Atlas* new_atlas)	
	{ 
		reset();            // 避免重复设置时出现帧索引越界的情况
		atlas = new_atlas;
	}

	// 设置动画是否循环播放
	void set_loop(bool flag)			
	{
		is_loop = flag;
	}

	// 设置动画帧间隔
	void set_interval(int ms)			
	{
		interval = ms;
	}

	//动画在播放时 帧索引 的推进是自动进行的
	//不需要外部使用 set 进行设置

	// 获取当前 帧索引
	int get_idx_frame()					
	{
		return idx_frame;
	}

	// 获取当前 帧图片
	IMAGE* get_frame()					
	{
		return atlas->get_image(idx_frame);
	}

	// 检查动画是否播放结束
	bool check_finished()				
	{
		if (is_loop)       //当动画被设置为循环播放时
			return false;  //返回false表示不会结束播放
		return (idx_frame == atlas->get_size() - 1); //反之，则检查当前 帧索引 是否已经到达图集的尾部
	}

	//2.定义回调函数，用于死亡动画播放结束后再删除对象
	//将传入的函数对象保存到对象本身的callback中
	void set_callback(function<void()> callback)
	{
		this->callback = callback;
	}

	//3.动画更新和渲染逻辑
	//动画更新
	void on_update(int delta)
	{
		timer += delta;			//每次更新时累加计时器的值
		if (timer >= interval)  //检查计时器是否超过帧间隔
		{
			timer = 0;          //超过帧间隔，计时器归零
			idx_frame++;		//超过帧间隔，则累加帧索引
			if (idx_frame >= atlas->get_size()) //检查动画是否播放到图集尾部
			{
				idx_frame = is_loop ? 0 : atlas->get_size() - 1;
				//根据是否循环播放，设置动画 帧索引 是从头开始 还是保持在图集最后一张图片位置上
				if (!is_loop && callback)   //如果帧索引到达了图集的尾部，且动画没有设置循环播放并且回调函数存在
					callback();				//则执行回调函数的逻辑
			}
		}
	}

	//动画渲染，设置透明度
	void on_draw(int x, int y) const  //const 表示常量成员函数，不会修改类的任何成员变量，即不会修改对象的状态
	{
		putimage_alpha(x, y, atlas->get_image(idx_frame));
	}

	


private:
	int timer = 0;          // 计时器
	int interval = 0;		// 帧间隔
	int idx_frame = 0;		// 帧索引
	bool is_loop = true;	// 是否循环	
	Atlas* atlas = nullptr; // atlas图集指针
	function<void()> callback; //function类型的函数对象 <void()>表示函数对象中存储的函数返回类型为void并且无参数

};

#endif // !_ANIMATION_H_
