#pragma once
#include "Globe.h"

class MyButton{
public:
	MyButton();
	~MyButton();

	//�����ҵ���һ��Ԫ�أ���ӵ��ҵ������С���һ��ͬ���Ķ������
	void setMyParents(MyButton *buton);

	//�����ҵ���һ��Ԫ��(ֱ���ϼ�)
	void setMyselfParent(MyButton *buton);
	vector<MyButton *> myParents;
	MyButton * myselfParent;

	bool isMyParents(MyButton *buton);
	bool isMyselfParent(MyButton *buton);

	void setCurrentMoveEvent(int event);
	int moveEvent;

	typedef enum {
		UP,
		DOWN,
		LEFT,
		RIGHT
	} MOVE_TYPE;

	void setName(std::string name);
	std::string getName();
	bool isPress();
	void setPressed();
	void setSelect(bool is);
	bool isSelect();
	int getChangeFlag();
	void setChangeFlag(int flg);
	void resetChange();
	void reset();
	void setPressedRect(cocos2d::CCRect rect,cocos2d::CCNode *father);
	cocos2d::CCRect rect;
	int pressed[2];
	void init(int type);
	int type;
	std::string name;
#define MYBUTTON_TYPE_SPRITE 12

private:
	bool isPressed;
	bool isSelected;
	int changeSelectFlag;
};
