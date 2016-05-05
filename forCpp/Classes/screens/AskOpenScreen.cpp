#include "AskOpenScreen.h"
#include "GameInfoScreen.h"
#include "MyGameScreen.h"


//string AskOpenScreen::testString = "com.holyblade.kjys|com.holyblade.kjysa|com.holyblade.kjysk|com.holyblade.kjysj|com.holyblade.kjysi|com.holyblade.kjysh|com.holyblade.kjysg|com.holyblade.kjysf|com.holyblade.kjyse|com.holyblade.kjysd|com.holyblade.kjysc|com.holyblade.kjysb|";
bool AskOpenScreen::init(){
	
	/*zhezhao = creatLayerColor(Globe::SW,Globe::SH,180);
	this->addChild(zhezhao,1);*/
	stageFrm = 0;

	stage = 0;
	int offset = 90;
	bt0 = MySprite::create("screens/askopen/bt.png");
	CCSprite *btw0 = CCSprite::create("screens/askopen/btw0.png");
	btw0->setAnchorPoint(ccp(0.5,0.5));
	btw0->setPosition(ccp(bt0->boundingBox().size.width/2,bt0->boundingBox().size.height/2));
	bt0->addChild(btw0,1);
	bt0->setPosition(ccp(Globe::SW/2-150,Globe::SH/2-125-offset));
	bt0->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(bt0,2);


	bt1 = MySprite::create("screens/askopen/bt.png");
	CCSprite *btw1 = CCSprite::create("screens/askopen/btw1.png");
	btw1->setAnchorPoint(ccp(0.5,0.5));
	btw1->setPosition(ccp(bt1->boundingBox().size.width/2,bt1->boundingBox().size.height/2));
	bt1->addChild(btw1,1);
	bt1->setPosition(ccp(Globe::SW/2+150,Globe::SH/2-125-offset));
	bt1->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(bt1,2);



	MySprite *temp = MySprite::create("screens/public/laoding.png");
	temp->setAddMode(2);
	temp->setAnchorPoint(ccp(0.5,0));
	temp->setPosition(ccp(Globe::SW/2,Globe::SH/2-offset));
	temp->setScale(1.4);
	temp->getImageFromUrl(MyGameScreen::selectGame->fromUrl,"myGamesIcon/"+MyGameScreen::selectGame->appid);
	vecDownLoadSprite.push_back(temp);
	addMySprite(temp);

	this->addChild(temp,2);

	CCSprite *info = CCSprite::create("screens/askopen/info.png");
	info->setAnchorPoint(ccp(0.5,0));
	info->setPosition(ccp(Globe::SW/2,Globe::SH/2-40-offset));
	this->addChild(info,2);
	setFocus(bt0);


	
    return Screen::init();
}



void AskOpenScreen::update(float ft){
	if(stage==1){
		stageFrm++;
		if(stageFrm==5){
			DELECT_SCREEN();
			string str = MyGameScreen::selectGame->pkgName+"|"+Globe::intToString(Globe::MYGAME_SCREEN)+"%";
			Globe::callJava(Globe::makeJsonString("openGame",str));
		}
		return;
	}else if(stage==2){
		stageFrm++;
		if(stageFrm==5){
			DELECT_SCREEN();
			Screen::unInstall(MyGameScreen::selectGame->pkgName);
		}
		return;
	}
	if(bt0->isPress()){
		
		//this->removeChild(zhezhao);
		stage = 1;
		stageFrm = 0;
		
	}else if(bt1->isPress()){
		//this->removeChild(zhezhao);
		stage = 2;
		stageFrm = 0;
		
	}


	Screen::update(ft);
}

void AskOpenScreen::draw(){

}

void AskOpenScreen::clear(){

}

void AskOpenScreen::back(){
	DELECT_SCREEN();
}
