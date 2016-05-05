#include "HuodongInfoScreen.h"
#include "HuodongScreen.h"
#include "GameInfoScreen.h"
#include "HomePageScreen.h"

string HuodongInfoScreen::activityId = "";
bool HuodongInfoScreen::init(){
	appId = "";
	NetHander *net = new NetHander();
	net->getAcitivityDetail(activityId);
	net->setCallBack(this);
	vecNet.push_back(net);
	bt = NULL;
	icon = NULL;

	isShowBack = false;
    return Screen::init();
}



void HuodongInfoScreen::update(float ft){
	if(icon){
		if(icon->isShow){
			if(!bt){
				bt = MySprite::create("screens/huodongInfo/bt.png");
				bt->setPosition(ccp(Globe::SW/2,60));
				this->addChild(bt,5);
				bt->setSelect(true);
			}else{
				if(bt->isPress()){
					GameInfoScreen::gameId = appId;
					SWITCHTO_CHILD_SCREEN(GameInfoScreen);
				}
			}
		}
	}
	
	Screen::update(ft);
}

void HuodongInfoScreen::draw(){

}

void HuodongInfoScreen::clear(){

}

void HuodongInfoScreen::back(){
	if(hasTileName("活动")){
		SWITCHTO_FATHER_SCREEN(HuodongScreen);
	}else{
		SWITCHTO_FATHER_SCREEN(HomePageScreen);
	}
}

void HuodongInfoScreen::call(string receive){
	bool get = false;
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			Reader reader1;
			Value root1;  
			reader1.parse(root["Description"].asString(), root1);
			
			appId = Globe::replaceStr(root1["AppID"].toStyledString());
			string imgUrl = root1["Image"].asString();
			if(imgUrl!=""){
				get = true;
			}
			icon = MySprite::create("screens/public/laoding.png");
			icon->setAddMode(2);
			icon->setOpacity(0);
			icon->setPosition(ccp(Globe::SW/2,Globe::SH/2));
			float scanX = Globe::SW/icon->getContentSize().width;
			float scanY = Globe::SH/icon->getContentSize().height;
			icon->setScaleX(scanX);
			icon->setScaleY(scanY);
	
			icon->getImageFromUrl(imgUrl,Globe::huodongDetailSavaPaht+"/"+activityId);
			vecDownLoadSprite.push_back(icon);
			this->addChildNoButton(icon,3);
		}
	}
	if(!get){
		CCLabelTTF *word1 = CCLabelTTF::create("type","Marker Felt",40);
		ccColor3B cc3b = {255,255,255};
		word1->setAnchorPoint(ccp(0.5,0.5));
		word1->setColor(cc3b);
		word1->setString(Globe::GBKToUTF("活动还没开始吧。").c_str());
		word1->setPosition(ccp(Globe::SW/2,Globe::SH/2));
		this->addChild(word1,20);
	
	}
}