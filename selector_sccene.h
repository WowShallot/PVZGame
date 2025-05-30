#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include "scene.h"
#include "scene_manager.h"
#include "animation.h"
 
extern IMAGE img_VS;
extern IMAGE img_1P;
extern IMAGE img_2P;
extern IMAGE img_1P_desc;
extern IMAGE img_2P_desc;
extern IMAGE img_gravestone_left;
extern IMAGE img_gravestone_right;
extern IMAGE img_selector_tip;
extern IMAGE img_selector_background;
extern IMAGE img_1P_selector_btn_idle_left;
extern IMAGE img_1P_selector_btn_idle_right;
extern IMAGE img_1P_selector_btn_down_left;
extern IMAGE img_1P_selector_btn_down_right;
extern IMAGE img_2P_selector_btn_idle_left;
extern IMAGE img_2P_selector_btn_idle_right;
extern IMAGE img_2P_selector_btn_down_left;
extern IMAGE img_2P_selector_btn_down_right;
extern IMAGE img_peashooter_selector_background_left;
extern IMAGE img_peashooter_selector_background_right;
extern IMAGE img_sunflower_selector_background_left;
extern IMAGE img_sunflower_selector_background_right;

extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_right;

extern IMAGE img_avatar_peashooter;
extern IMAGE img_avatar_sunflower;

extern SceneManager scene_manager;

class SelectorScene : public Scene
{
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void on_enter() 
	{
		animation_peashooter.set_atlas(&atlas_peashooter_idle_right);
		animation_sunflower.set_atlas(&atlas_sunflower_idle_right);
		animation_peashooter.set_interval(100);
		animation_sunflower.set_interval(100);

		static const int OFFSET_X = 50;

		pos_img_VS.x = (getwidth() - img_VS.getwidth()) / 2;
		pos_img_VS.y = (getheight() - img_VS.getheight()) / 2;
		pos_img_tip.x = (getwidth() - img_selector_tip.getwidth()) / 2;
		pos_img_tip.y = getheight() - 125;
		pos_img_1P.x = (getwidth() / 2 - img_1P.getwidth()) / 2 - OFFSET_X;
		pos_img_1P.y = 35;
		pos_img_2P.x = getwidth() / 2 +(getwidth() / 2 - img_2P.getwidth()) / 2 + OFFSET_X;
		pos_img_2P.y = pos_img_1P.y;
		pos_img_1P_desc.x = (getwidth() / 2 - img_1P_desc.getwidth()) / 2 - OFFSET_X;
		pos_img_1P_desc.y = getheight() - 150;
		pos_img_2P_desc.x = getwidth() / 2 + (getwidth() / 2 - img_2P_desc.getwidth()) / 2 + OFFSET_X;
		pos_img_2P_desc.y = pos_img_1P_desc.y;
		pos_img_1P_gravestone.x = (getwidth() / 2 - img_gravestone_right.getwidth()) / 2 - OFFSET_X;
		pos_img_1P_gravestone.y = pos_img_1P.y + img_1P.getheight() + 35;
		pos_img_2P_gravestone.x = getwidth() / 2 + (getwidth() / 2 - img_gravestone_left.getwidth()) / 2 + OFFSET_X;
		pos_img_2P_gravestone.y = pos_img_1P_gravestone.y;
		pos_animation_1P.x = (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 - OFFSET_X;
		pos_animation_1P.y = pos_img_1P_gravestone.y + 20;
		pos_animation_2P.x = getwidth() / 2 + (getwidth() / 2 -atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 + OFFSET_X;
		pos_animation_2P.y = pos_animation_1P.y;
		pos_img_1P_name.y = pos_animation_1P.y + 155;
		pos_img_2P_name.y = pos_img_1P_name.y;
		pos_1P_selector_btn_left.x = pos_img_1P_gravestone.x - img_1P_selector_btn_idle_left.getwidth();
		pos_1P_selector_btn_left.y = pos_img_1P_gravestone.y + (img_gravestone_right.getheight() - img_1P_selector_btn_idle_left.getheight()) / 2;
		pos_1P_selector_btn_right.x = pos_img_1P_gravestone.x + img_gravestone_right.getwidth();
		pos_1P_selector_btn_right.y = pos_1P_selector_btn_left.y;
		pos_2P_selector_btn_left.x = pos_img_2P_gravestone.x - img_2P_selector_btn_idle_left.getwidth();
		pos_2P_selector_btn_left.y = pos_1P_selector_btn_left.y;
		pos_2P_selector_btn_right.x = pos_img_2P_gravestone.x + img_gravestone_left.getwidth();
		pos_2P_selector_btn_right.y = pos_1P_selector_btn_left.y;
	} 

	void on_update(int delta) 
	{

	}

	void on_draw(const Camera& camera)
	{
		putimage(0, 0, &img_selector_background);

		putimage_alpha(pos_img_VS.x, pos_img_VS.y, &img_VS);

		putimage_alpha(pos_img_1P.x, pos_img_1P.y, &img_1P);
		putimage_alpha(pos_img_2P.x, pos_img_2P.y, &img_2P);
		putimage_alpha(pos_img_1P_gravestone.x, pos_img_1P_gravestone.y, &img_gravestone_right);
		putimage_alpha(pos_img_2P_gravestone.x, pos_img_2P_gravestone.y, &img_gravestone_left);

		putimage_alpha(pos_img_1P_desc.x, pos_img_1P_desc.y, &img_1P_desc);
		putimage_alpha(pos_img_2P_desc.x, pos_img_2P_desc.y, &img_2P_desc);

		putimage_alpha(pos_img_tip.x, pos_img_tip.y, &img_selector_tip);
	}

	void on_input(const ExMessage& msg)
	{

	}

	void on_exit() 
	{

	}


private:
	POINT pos_img_VS = { 0 };						// VS ������ͼƬλ��
	POINT pos_img_tip = { 0 };						// ��ʾ��Ϣ�ı�ͼƬλ��			
	POINT pos_img_1P = { 0 };						// 1P �ı�ͼƬλ��
	POINT pos_img_2P = { 0 };						// 2P �ı�ͼƬλ��
	POINT pos_img_1P_desc = { 0 };					// 1P ��λ����ͼƬλ��
	POINT pos_img_2P_desc = { 0 };					// 2P ��λ����ͼƬλ��
	POINT pos_img_1P_name = { 0 };					// 1P ��ɫ����ͼƬλ��
	POINT pos_img_2P_name = { 0 };					// 2P ��ɫ����ͼƬλ��
	POINT pos_animation_1P = { 0 };					// 1P ��ɫ����λ��
	POINT pos_animation_2P = { 0 };					// 2P ��ɫ����λ��
	POINT pos_img_1P_gravestone = { 0 };			// 1P Ĺ��ͼƬλ��
	POINT pos_img_2P_gravestone = { 0 };			// 2P Ĺ��ͼƬλ��
	POINT pos_1P_selector_btn_left = { 0 };			// 1P �����л���ťλ��
	POINT pos_1P_selector_btn_right = { 0 };		// 1P �����л���ťλ��
	POINT pos_2P_selector_btn_left = { 0 };			// 2P �����л���ťλ��        
	POINT pos_2P_selector_btn_right = { 0 };		// 2P �����л���ťλ��        

	Animation animation_peashooter;					// �����ֶ���
	Animation animation_sunflower;					// ���տ�����
};

#endif // !_SELECTOR_SCENE_H_