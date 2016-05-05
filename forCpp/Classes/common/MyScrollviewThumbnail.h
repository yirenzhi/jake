#pragma once
#include "Globe.h"
#include "MyScrollview.h"

class MyScrollviewThumbnail : public CCNode{
public:
	MyScrollviewThumbnail(MyScrollview *tileLayer);
	~MyScrollviewThumbnail();
	//缩略条的区域背景
	CCSprite * bg;
	//缩略条
	CCSprite * point;
	MyScrollview *tileLayer;
	

	void update();


};