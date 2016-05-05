#include "AboutScreen.h"
#include "ManageScreen.h"


bool AboutScreen::init(){
	setTilesName("��������");
	addBgAndTile();
	
	CCSprite *spt = CCSprite::create("screens/about/bg.png");
	spt->setPosition(ccp(Globe::SW/2,Globe::SH/2));
	this->addChild(spt,2);


	ccColor3B cc3bCur = {178,116,227};
	CCLabelTTF *curr = CCLabelTTF::create("type","Marker Felt",18);
	curr->setAnchorPoint(ccp(0.5,0.5));
	curr->setColor(cc3bCur);
	curr->setString(Globe::GBKToUTF(("��ǰ�汾��"+NetHander::version+"  1280*720  320 sw360dp").c_str()).c_str());
	curr->setPosition(ccp(408,442));
	this->addChild(curr,2);
		
	CCLabelTTF *curr1 = CCLabelTTF::create("type","Marker Felt",18);
	curr1->setAnchorPoint(ccp(0.5,0.5));
	curr1->setColor(cc3bCur);
	curr1->setString(Globe::GBKToUTF("00000028-Play-SmartTV-1280*720").c_str());
	curr1->setPosition(ccp(408,413));
	this->addChild(curr1,2);

	//��˾���
	ccColor3B cc3bW = {255,255,255};
	string temp = "       ʥ������רע�ڻ���������Ϸ�Ŀ�������Ӫ�ͷ��У�ּ��ͨ�������նˣ�Ϊ�û��ṩ���ƵĻ����������֣�����һ��ȫ�µ��������ʽ���ṩ���ֶ����Ĳ��컯��Ʒ����������û��ձ�����Ҫ��";
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
	curr2->setString(Globe::GBKToUTF("��ҿͷ�ͨ����ͨ���ٷ���ά����ͷ�ȡ����ϵ").c_str());
	curr2->setPosition(ccp(160,165));
	this->addChild(curr2,2);

	CCLabelTTF *curr3 = CCLabelTTF::create("type","Marker Felt",18);
	curr3->setAnchorPoint(ccp(0,0.5));
	curr3->setColor(cc3bW);
	curr3->setString(Globe::GBKToUTF("ʥ����Ϸ������http:\/\/www.holyblade.com\/").c_str());
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