#pragma once
#include "Globe.h"
#include "MyScrollview.h"

class MyScrollviewThumbnail : public CCNode{
public:
	MyScrollviewThumbnail(MyScrollview *tileLayer);
	~MyScrollviewThumbnail();
	//�����������򱳾�
	CCSprite * bg;
	//������
	CCSprite * point;
	MyScrollview *tileLayer;
	

	void update();


};