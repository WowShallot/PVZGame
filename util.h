#ifndef _UTIL_H_
#define _UTIL_H_

#include <graphics.h>

inline void flip_image(IMAGE* src, IMAGE* dst) //src--翻转前的原图片， dst--翻转后的目标图片
{
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src); //GetImageBuffer对图片的像素数据进行操作
	DWORD* dst_buffer = GetImageBuffer(dst);
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int idx_src = y * w + x;
			int idx_dst = y * w + (w - x - 1);
			dst_buffer[idx_dst] = src_buffer[idx_src];
		}
	}
}

#endif // !_UTIL_H_
