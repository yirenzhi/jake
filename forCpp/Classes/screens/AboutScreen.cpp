#include "AboutScreen.h"
#include "ManageScreen.h"


bool AboutScreen::init(){
	setTilesName("关于我们");
	addBgAndTile();
	
	CCSprite *spt = CCSprite::create("screens/about/bg.png");
	spt->setPosition(ccp(Globe::SW/2,Globe::SH/2));
	this->addChild(spt,2);


	ccColor3B cc3bCur = {178,116,227};
	CCLabelTTF *curr = CCLabelTTF::create("type","Marker Felt",18);
	curr->setAnchorPoint(ccp(0.5,0.5));
	curr->setColor(cc3bCur);
	curr->setString(Globe::GBKToUTF(("当前版本："+NetHander::version+"  1280*720  320 sw360dp").c_str()).c_str());
	curr->setPosition(ccp(408,442));
	this->addChild(curr,2);
		
	CCLabelTTF *curr1 = CCLabelTTF::create("type","Marker Felt",18);
	curr1->setAnchorPoint(ccp(0.5,0.5));
	curr1->setColor(cc3bCur);
	curr1->setString(Globe::GBKToUTF("00000028-Play-SmartTV-1280*720").c_str());
	curr1->setPosition(ccp(408,413));
	this->addChild(curr1,2);

	//公司简介
	ccColor3B cc3bW = {255,255,255};
	string temp = "       圣剑网络专注于互动电视游戏的开发、运营和发行，旨在通过电视终端，为用户提供完善的互动电视娱乐，创造一种全新的娱乐生活方式，提供多种多样的差异化产品，满足各类用户普遍娱乐要求。";
	string inf = Globe::GBKToUTF(temp.c_str());
	CCLabelTTF *info = Globe::horizontalSpacingANDverticalSpacing(inf,"Marker Felt",18,0,8,470,cc3bW);
	//info->setAnchorPoint(ccp(0,0.5));
	//info->setColor(cc3bInfo);
	//info->setString(Globe::GBKToUTF(gameInfo.c_str()).c_str());
	info->setPosition(ccp(160,340));
	//info->setHorizontalAlignment(kCCTextAlignmentLeft);
	//info->setDimensions(CCSize(480,120));
	this->addChild(info,2);


	CCLabelTTF *curr2 = CCLabelTTF::create("type","Marker Felt",18);
	curr2->setAnchorPoint(ccp(0,0.5));
	curr2->setColor(cc3bW);
	curr2->setString(Globe::GBKToUTF("玩家客服通道：通过官方二维码与客服取得联系").c_str());
	curr2->setPosition(ccp(160,165));
	this->addChild(curr2,2);

	CCLabelTTF *curr3 = CCLabelTTF::create("type","Marker Felt",18);
	curr3->setAnchorPoint(ccp(0,0.5));
	curr3->setColor(cc3bW);
	curr3->setString(Globe::GBKToUTF("圣剑游戏官网：http:\/\/www.holyblade.com\/").c_str());
	curr3->setPosition(ccp(160,135));
	this->addChild(curr3,2);

    return Screen::init();
}



void AboutScreen::update(float ft){
	
	Screen::update(ft);
}

void AboutScreen::draw(){

}

void AboutScreen::clear(){

}

void AboutScreen::back(){
	SWITCHTO_FATHER_SCREEN(ManageScreen);
}