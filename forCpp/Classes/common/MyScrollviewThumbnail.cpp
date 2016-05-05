#include "MyScrollviewThumbnail.h"

MyScrollviewThumbnail::MyScrollviewThumbnail(MyScrollview *tileLayer){
	this->tileLayer = tileLayer;
	bg = CCSprite::create("screens/public/viewBg.png");
	bg->setPosition(ccp(0,0));
	bg->setAnchorPoint(ccp(0,1));
	this->addChild(bg,220);


	point = CCSprite::create("screens/public/view.png");
	this->addChild(point,220);
	
}

MyScrollviewThumbnail::~MyScrollviewThumbnail(){

}

void MyScrollviewThumbnail::update(){
	float h = Globe::abs(tileLayer->h);
	float layerY = ((tileLayer->startY+tileLayer->endY)/2)-tileLayer->getPositionY();
	float showH = tileLayer->endY-tileLayer->startY;
	float xyPercent = layerY/h;
	float whPercent = showH/h;
	if(whPercent>1){
		whPercent = 1;
		xyPercent = -0.5;
	}

	float scan = bg->getContentSize().height/point->getContentSize().height;
	point->setScaleY(scan*whPercent);
	float x = bg->getContentSize().width/2;
	float y = bg->getContentSize().height*xyPercent;
	point->setAnchorPoint(ccp(0.5,0.5));
	point->setPosition(ccp(x,y));

}

