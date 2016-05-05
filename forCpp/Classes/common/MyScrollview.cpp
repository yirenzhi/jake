#include "MyScrollview.h"

MyScrollview::MyScrollview(){
	setShowRect(0,0,Globe::SW,Globe::SH);
	setTouchType(UP_DOWN);
	
	arriveTime = 0.3;
}
MyScrollview::~MyScrollview(){

}

MyScrollview *MyScrollview::create()
{
	MyScrollview * pRet = new MyScrollview();
    if (pRet && pRet->init())
    {
		pRet->setTouchEnabled(true);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

void MyScrollview::setTouchType(int type){
	this->touchType = type;
}

void MyScrollview::setEveroneSize(CCSize size){
	this->everoneSize = size;
}

void MyScrollview::setPosition(CCPoint point){
	initX = point.x;
	initY = point.y;
	CCLayer::setPosition(point);
}

void MyScrollview::reset(){
	this->setPosition(ccp(initX,initY));
}

void MyScrollview::doMoveUpDown(int distanse){
	CCActionInterval *move = CCMoveBy::create(arriveTime,ccp(0,distanse));
	runAction(move);
}
void MyScrollview::doMoveLeftRight(int distanse){
	CCActionInterval *move = CCMoveBy::create(arriveTime,ccp(distanse,0));
	runAction(move);
}


void MyScrollview::setShowRect(int sx,int sy,int ex,int ey){
	startX = sx;
	startY = sy;
	endX = ex;
	endY = ey;
}

void MyScrollview::setWH(int width,int height){
	this->w = width;
	this->h = height;
}

void MyScrollview::visit(void)
{

	glEnable(GL_SCISSOR_TEST);

	//CCPoint selfPos = this->getPosition();

	//CCSize selfContentSize = this->getContentSize();
	int x = startX;
	int y = startY;
	int w = endX-startX;
	int h = endY-startY;

	if(touchType==UP_DOWN){
		y = 0;
		h = endY;
	}


	float scaleX = CCEGLView::sharedOpenGLView()->getScaleX();
	float scaleY = CCEGLView::sharedOpenGLView()->getScaleY();

	CCRect viewPortRect = CCEGLView::sharedOpenGLView()->getViewPortRect();

	glScissor(x *scaleX + viewPortRect.origin.x ,
	y * scaleY + viewPortRect.origin.y ,
	w*scaleX,
	h*scaleY);

	CCNode::visit();//显示父类的内容
	glDisable(GL_SCISSOR_TEST);
}

void MyScrollview::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
	startTouchPoint = convertTouchToNodeSpace((CCTouch*)pTouches->anyObject());
	
}

void MyScrollview::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){
	CCPoint point = convertTouchToNodeSpace((CCTouch*)pTouches->anyObject());
	if(touchType==UP_DOWN){
		int temp = point.y-startTouchPoint.y;
		int endY = getPositionY()+temp;
		setPosition(ccp(getPositionX(),endY));
	}else if(touchType==LEFT_RIGHT){
		int temp = point.x-startTouchPoint.x;
		setPosition(ccp(getPositionX()+temp,getPositionY()));
	}
}

void MyScrollview::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent){

}




