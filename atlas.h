#ifndef _ATLAS_H_
#define _ATLAS_H_

#include <vector>
#include <graphics.h>
using namespace std;

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	void load_from_file(LPCTSTR path_template, int num) //加载指定路径的图片到类中
	{
		img_list.clear();       //先清空图片对象列表
		img_list.resize(num);   //将列表长度定义为指定大小num

		TCHAR path_file[256];
		for (int i = 0; i < num; i++)
		{
			_stprintf_s(path_file, path_template, i + 1);
			loadimage(&img_list[i], path_file);
		}
	}

	void clear()     //用于清空图集中已加载的图片对象
	{
		img_list.clear();
	}

	int get_size()   //获取图集中图片的数量
	{
		return (int)img_list.size();
	}

	IMAGE* get_image(int idx)  //未来在Animation类中通过这个方法获取实际渲染的动画帧
	{
		if (idx < 0 || idx >= img_list.size())  //先检查索引参数是否有效
			return nullptr;                     //若越界则返回空指针
		return &img_list[idx];                  //反之，则返回对应索引图片对象的地址
	}

	void add_image(const IMAGE& img) //向图集中添加已有的图片对象
	{
		img_list.push_back(img);
	}

private:
	vector<IMAGE> img_list; // 图像对象列表
};

#endif // !_ATLAS_H_
