#include "MyButton.h"

MyButton::MyButton(){
	name = "";
	this->isPressed = false;
	myselfParent = NULL;
}

MyButton::~MyButton(){

}

void MyButton::setChangeFlag(int flg){
	changeSelectFlag = flg;
}

bool MyButton::isPress(){
	if(isPressed){
		MyButton::reset();
		return true;
	}
	if(pressed[0]==1&&pressed[1]==1){
		MyButton::reset();
		return true;
	}
	//判断完一次以后就重置
	
	return false;
}

void MyButton::setPressed(){
	isPressed = true;
} 

void MyButton::setPressedRect(cocos2d::CCRect rect,cocos2d::CCNode *father){
	if(father){
		this->rect = CCRectMake(father->boundingBox().origin.x+rect.origin.x,
						father->boundingBox().origin.y+rect.origin.y,
						rect.size.width,
						rect.size.height
		);
	}else{
		this->rect = rect;
	}
}

void MyButton::init(int type){
	this->type = type;
	pressed[0] = -1;
	pressed[1] = -1;
	isSelected = false;
	isPressed = false;
	changeSelectFlag = 0;
}

void MyButton::reset(){
	pressed[0] = -1;
	pressed[1] = -1;
	isPressed = false;
	changeSelectFlag = 0;
}

void MyButton::setCurrentMoveEvent(int event){
	this->moveEvent = event;
}

void MyButton::setSelect(bool is){
	if(isSelected&&is){
		return;
	}
	if(!isSelected&&is){//以前没选中，现在选中了
		changeSelectFlag = 1;
	}else if(isSelected&&!is){
		changeSelectFlag = 2;
	}else{
		changeSelectFlag = 0;
	}
	isSelected = is;
}

int MyButton::getChangeFlag(){
	return changeSelectFlag;
}

bool MyButton::isSelect(){
	return isSelected;
}

void MyButton::resetChange(){
	changeSelectFlag = 0;
}

void MyButton::setName(string name){
	this->name = name;
}
string MyButton::getName(){
	return name;
}

void MyButton::setMyParents(MyButton *buton){
	myParents.push_back(buton);
}

void MyButton::setMyselfParent(MyButton *buton){
	myselfParent = buton;
}

bool MyButton::isMyParents(MyButton *buton){
	for(int i = 0;i<myParents.size();i++){
		if(buton==myParents[i]){
			return true;
		}
	}
	return false;
}

bool MyButton::isMyselfParent(MyButton *buton){
	if(buton==myselfParent){
		return true;
	}
	return false;
}
