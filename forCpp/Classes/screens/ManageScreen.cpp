#include "ManageScreen.h"
#include "HomePageScreen.h"
#include "AboutScreen.h"
#include "UninstallScreen.h"
#include "JiankongScreen.h"
#include "ChaxunScreen.h"

bool ManageScreen::init(){
	setTilesName("管理");
	addBgAndTile();
	
	

	if(NetHander::bossId=="410"){//北京联通
		int w = 140;
		jiankong = MySprite::create("screens/manage/jiankong.png");
		jiankong->setPosition(ccp(Globe::SW/2-3*w,Globe::SH/2));
		this->addChild(jiankong,2);

		chaxun = MySprite::create("screens/manage/chaxun.png");
		chaxun->setPosition(ccp(Globe::SW/2-w,Globe::SH/2));
		this->addChild(chaxun,2);

		uninstall = MySprite::create("screens/manage/uninstall.png");
		uninstall->setPosition(ccp(Globe::SW/2+w,Globe::SH/2));
		this->addChild(uninstall,2);

		about = MySprite::create("screens/manage/about.png");
		about->setPosition(ccp(Globe::SW/2+3*w,Globe::SH/2));
		this->addChild(about,2);
		setFocus(jiankong);
	}else{
		jiankong = NULL;
		chaxun = NULL;
		uninstall = MySprite::create("screens/manage/uninstall.png");
		uninstall->setPosition(ccp(Globe::SW/2-150,Globe::SH/2));
		this->addChild(uninstall,2);

		about = MySprite::create("screens/manage/about.png");
		about->setPosition(ccp(Globe::SW/2+150,Globe::SH/2));
		this->addChild(about,2);
		setFocus(uninstall);
	}
	
	
    return Screen::init();
}

void ManageScreen::back(){
	SWITCHTO_FATHER_SCREEN(HomePageScreen);
}

void ManageScreen::update(float ft){
	

	if(uninstall->isPress()){
		SWITCHTO_CHILD_SCREEN(UninstallScreen);
	}else if(about->isPress()){
		SWITCHTO_CHILD_SCREEN(AboutScreen);
	}

	if(jiankong!=NULL){
		if(jiankong->isPress()){
			SWITCHTO_CHILD_SCREEN(JiankongScreen);
		}
	}

	if(chaxun!=NULL){
		if(chaxun->isPress()){
			SWITCHTO_CHILD_SCREEN(ChaxunScreen);
		}
	}
	Screen::update(ft);
}

void ManageScreen::draw(){

}

void ManageScreen::clear(){

}