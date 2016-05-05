#pragma once
#include "Globe.h"


class MyScrollview : public CCLayer{
public:
	MyScrollview();
	~MyScrollview();

	//ÿ��Ԫ�صĿ�Ⱥ͸߶�,������������
	CCSize everoneSize;
	void setEveroneSize(CCSize size);

	void doMoveUpDown(int distanse);
	void doMoveLeftRight(int distanse);

	int startX;
	int startY;
	int endX;
	int endY;
	float arriveTime;

	typedef enum {
		UP_DOWN,
		LEFT_RIGHT
	} TOUCH_TYPE;


	void setTouchType(int type);
	void setWH(int width,int height);

	static MyScrollview *create(void);
	void setShowRect(int sx,int sy,int ex,int ey);
	void visit(void);
	CCPoint startTouchPoint;

	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	void setPosition(CCPoint point);
	void reset();
	int initX,initY;
	int touchType;
	int w,h;
};