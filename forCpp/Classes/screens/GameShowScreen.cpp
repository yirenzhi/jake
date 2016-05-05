#include "GameShowScreen.h"
#include "GameInfoScreen.h"


bool GameShowScreen::init(){
	isShowBack = false;

	icon = MySprite::create("screens/public/laoding.png");
	icon->setAddMode(2);
	icon->setOpacity(0);
	float scanX = Globe::SW/icon->getContentSize().width;
	float scanY = Globe::SH/icon->getContentSize().height;
	icon->setScaleX(scanX);
	icon->setScaleY(scanY);
	icon->setPosition(ccp(Globe::SW/2,Globe::SH/2));
	
	icon->getImageFromUrl(
		GameInfoScreen::infoGame[GameInfoScreen::selectShowIconIndex]->fromUrl,
		GameInfoScreen::infoGame[GameInfoScreen::selectShowIconIndex]->inTheFolder);
	vecDownLoadSprite.push_back(icon);
	this->addChildNoButton(icon,3);
	

    return Screen::init();
}


void GameShowScreen::update(float ft){
	
	if(isKeypressed(M_KEY_UP)||isKeypressed(M_KEY_DOWN)){
		CCLog("pressed");
		if(isKeypressed(M_KEY_UP)){
			GameInfoScreen::selectShowIconIndex--;
		}else if(isKeypressed(M_KEY_DOWN)){
			GameInfoScreen::selectShowIconIndex++;
		}
		GameInfoScreen::selectShowIconIndex = ((GameInfoScreen::selectShowIconIndex+3)%3);
		this->removeChild(icon);

		icon = MySprite::create("screens/public/laoding.png");
		icon->setAddMode(2);
		icon->setOpacity(0);
		float scanX = Globe::SW/icon->getContentSize().width;
		float scanY = Globe::SH/icon->getContentSize().height;
		icon->setScaleX(scanX);
		icon->setScaleY(scanY);
		icon->setPosition(ccp(Globe::SW/2,Globe::SH/2));
	
		icon->getImageFromUrl(
			GameInfoScreen::infoGame[GameInfoScreen::selectShowIconIndex]->fromUrl,
			GameInfoScreen::infoGame[GameInfoScreen::selectShowIconIndex]->inTheFolder);
		vecDownLoadSprite.push_back(icon);
		this->addChildNoButton(icon,3);
	}
	
	Screen::update(ft);
	keyReset();
}

void GameShowScreen::draw(){

}

void GameShowScreen::clear(){

}

void GameShowScreen::back(){
	DELECT_SCREEN();
}