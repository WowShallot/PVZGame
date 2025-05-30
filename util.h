#ifndef _UTIL_H_
#define _UTIL_H_

#include <graphics.h>

#pragma comment(lib, "MSIMG32.LIB") // 不要忘记添加库文件的链接，与putimage_alpha定义相关

inline void putimage_alpha(const Camera& camera, int dst_x, int dst_y, IMAGE* img)  // 设置图片带透明度
{
	int w = img->getwidth();
	int h = img->getheight();
	const Vector2& pos_camera = camera.get_position();
	AlphaBlend(GetImageHDC(GetWorkingImage()), (int)(dst_x - pos_camera.x), (int)(dst_y - pos_camera.x), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

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
