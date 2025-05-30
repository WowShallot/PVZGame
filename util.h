#ifndef _UTIL_H_
#define _UTIL_H_

#include <graphics.h>

#pragma comment(lib, "MSIMG32.LIB") // ��Ҫ������ӿ��ļ������ӣ���putimage_alpha�������

inline void putimage_alpha(const Camera& camera, int dst_x, int dst_y, IMAGE* img)  // ����ͼƬ��͸����
{
	int w = img->getwidth();
	int h = img->getheight();
	const Vector2& pos_camera = camera.get_position();
	AlphaBlend(GetImageHDC(GetWorkingImage()), (int)(dst_x - pos_camera.x), (int)(dst_y - pos_camera.x), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

inline void flip_image(IMAGE* src, IMAGE* dst) //src--��תǰ��ԭͼƬ�� dst--��ת���Ŀ��ͼƬ
{
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src); //GetImageBuffer��ͼƬ���������ݽ��в���
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
