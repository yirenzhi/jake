#include "ZhuantiInfo.h"
#include "HomePageScreen.h"
#include "HuodongScreen.h"
#include "GameInfoScreen.h"

string ZhuantiInfo::zhuantiId ="";
int ZhuantiInfo::tileLayerX = 0;
int ZhuantiInfo::index = 0;
bool ZhuantiInfo::init(){
	setTilesName("专题");
	addBgAndTile();
	hasAdd = false;
	icon = NULL;

	NetHander *net = new NetHander();
	net->getZhuanquDetail(zhuantiId);
	net->setCallBack(this);
	vecNet.push_back(net);

	needSaveDefaultFocas = false;
	
	isShowBack = false;
    return Screen::init();
}



void ZhuantiInfo::update(float ft){
	for(int i = 0;i<vectiles.size();i++){
		if(vectiles[i]->isPress()){
			tileLayerX = tileLayer->getPositionX();
			index = i;
			GameInfoScreen::gameId = vectiles[i]->appid;
			SWITCHTO_CHILD_SCREEN(GameInfoScreen);
		}
	}
	//下载完了
	if(icon){
		if(icon->isShow&&!hasAdd){
			hasAdd = true;
			loadIcon();
		}
	}
	

	Screen::update(ft);
}

void ZhuantiInfo::draw(){

}

void ZhuantiInfo::clear(){

}

void ZhuantiInfo::back(){
	if(hasTileName("活动")){
		SWITCHTO_FATHER_SCREEN(HuodongScreen);
	}else{
		SWITCHTO_FATHER_SCREEN(HomePageScreen);
	}
}

void ZhuantiInfo::loadIcon(){
	int startX = 200;
	int colNum = 1;
	int w = 200;
	int h = 300;
	int num = vecIconInfo.size();
	tileLayer = MyScrollview::create();
	tileLayer->setTouchType(MyScrollview::LEFT_RIGHT);
	tileLayer->setAnchorPoint(ccp(0,0));
	tileLayer->setShowRect(startX,0,Globe::SW-startX,Globe::SH);
	tileLayer->setEveroneSize(CCSize(w,h));
	tileLayer->setWH(num*w,h);
	
	for(int i = 0;i<num;i++){
		string id = Globe::replaceStr(vecIconInfo[i].appid);
		MySprite *icon = MySprite::create("screens/public/laoding.png");
		if(i==num/2){
			icon->setDefaultFocus(true,this);
		}
				
		icon->setAddMode(2);
		icon->setOpacity(0);
		float x = w/2+i*w;
		icon->setPosition(ccp(x,240));
		icon->setAppId(id);
		icon->setName(vecIconInfo[i].name);
		icon->setSelectScale(1.1);
		icon->setFather(tileLayer);
		int faW = 180;
		int faH = 265;
		float scanX = faW/icon->getContentSize().width;
		float scanY = faH/icon->getContentSize().height;
		icon->setScaleX(scanX);
		icon->setScaleY(scanY);
		icon->setFactRect(CCRectMake(icon->getPositionX()-faW/2,
		icon->getPositionY()-faH/2,faW,faH));
		icon->getImageFromUrl(vecIconInfo[i].url,Globe::zhuantiDetailSavaPaht+"/"+id);
		vecDownLoadSprite.push_back(icon);
		addMySprite(icon);
		tileLayer->addChild(icon);
		vectiles.push_back(icon);
	}
			
	int offsetX = Globe::SW/2-(vectiles[0]->rect.origin.x+vectiles[0]->rect.size.width/2+(num-1)*w/2);
	if(tileLayerX!=0){
		tileLayer->setPosition(ccp(tileLayerX,0));
	}else{
		tileLayer->setPosition(ccp(offsetX,0));
	}
	if(index>num-1){//回到上次的焦点
		index = num-1;
	}
	if(index>0){//回到上次的焦点
		changeFocus(vectiles[index]);
	}
			
	this->addChild(tileLayer,10);
}

void ZhuantiInfo::call(string receive){
	bool get = false;
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			Reader reader1;
			Value root1;  
			reader1.parse(root["Description"].asString(), root1);
			string url = root1["Image"].asString();

			icon = MySprite::create("screens/public/laoding.png");
			icon->setAddMode(2);
			icon->setOpacity(0);
			icon->setPosition(ccp(Globe::SW/2,Globe::SH/2));
			float scanX = Globe::SW/icon->getContentSize().width;
			float scanY = Globe::SH/icon->getContentSize().height;
			icon->setScaleX(scanX);
			icon->setScaleY(scanY);
	
			icon->getImageFromUrl(url,Globe::zhuantiDetailSavaPaht+"/"+zhuantiId);
			vecDownLoadSprite.push_back(icon);
			this->addChildNoButton(icon,3);

			

			Reader reader2;
			Value root2;  
			reader2.parse(root1["Apps"].toStyledString(), root2);
			if(root2.size()==0){
				get = false;
			}else{
				get = true;
			}
			for(int i = 0;i<root2.size();i++){
				iconInfo in;
				in.appid = Globe::replaceStr(root2[i]["AppID"].toStyledString());
				in.name = root2[i]["AppName"].asString();
				in.url = root2[i]["AppIcon"].asString();
				vecIconInfo.push_back(in);
			}

			

		}
	}
	if(!get){
		CCLabelTTF *word1 = CCLabelTTF::create("type","Marker Felt",40);
		ccColor3B cc3b = {255,255,255};
		word1->setAnchorPoint(ccp(0.5,0.5));
		word1->setColor(cc3b);
		word1->setString(Globe::GBKToUTF("敬请期待！").c_str());
		word1->setPosition(ccp(Globe::SW/2,Globe::SH/2));
		this->addChild(word1,20);
	
	}
}