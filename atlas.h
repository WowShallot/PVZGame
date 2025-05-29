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

	void load_from_file(LPCTSTR path_template, int num) //����ָ��·����ͼƬ������
	{
		img_list.clear();       //�����ͼƬ�����б�
		img_list.resize(num);   //���б��ȶ���Ϊָ����Сnum

		TCHAR path_file[256];
		for (int i = 0; i < num; i++)
		{
			_stprintf_s(path_file, path_template, i + 1);
			loadimage(&img_list[i], path_file);
		}
	}

	void clear()     //�������ͼ�����Ѽ��ص�ͼƬ����
	{
		img_list.clear();
	}

	int get_size()   //��ȡͼ����ͼƬ������
	{
		return (int)img_list.size();
	}

	IMAGE* get_image(int idx)  //δ����Animation����ͨ�����������ȡʵ����Ⱦ�Ķ���֡
	{
		if (idx < 0 || idx >= img_list.size())  //�ȼ�����������Ƿ���Ч
			return nullptr;                     //��Խ���򷵻ؿ�ָ��
		return &img_list[idx];                  //��֮���򷵻ض�Ӧ����ͼƬ����ĵ�ַ
	}

	void add_image(const IMAGE& img) //��ͼ����������е�ͼƬ����
	{
		img_list.push_back(img);
	}

private:
	vector<IMAGE> img_list; // ͼ������б�
};

#endif // !_ATLAS_H_
