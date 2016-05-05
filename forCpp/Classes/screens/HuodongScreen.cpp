#include "HuodongScreen.h"
#include "HomePageScreen.h"
#include "HuodongInfoScreen.h"
#include "ZhuantiInfo.h"

int HuodongScreen::tileLayerX = 0;
int HuodongScreen::index = 0;
bool HuodongScreen::init(){
	setTilesName("活动");
	addBgAndTile();

	NetHander *net = new NetHander();
	net->getAcitivity(10);
	net->setCallBack(this);
	vecNet.push_back(net);
	needSaveDefaultFocas = false;
	

    return Screen::init();
}



void HuodongScreen::update(float ft){
	
	for(int i = 0;i<vectiles.size();i++){
		if(vectiles[i]->isPress()){
			tileLayerX = tileLayer->getPositionX();
			index = i;
			if(vectiles[i]->appType=="2"){//活动
				HuodongInfoScreen::activityId = vectiles[i]->appid;
				SWITCHTO_CHILD_SCREEN(HuodongInfoScreen);
			}else if(vectiles[i]->appType=="3"){//专区
				ZhuantiInfo::tileLayerX = 0;
				ZhuantiInfo::index = 0;
				ZhuantiInfo::zhuantiId = vectiles[i]->appid;
				SWITCHTO_CHILD_SCREEN(ZhuantiInfo);
			}
		}
	}

	Screen::update(ft);
}

void HuodongScreen::draw(){

}

void HuodongScreen::clear(){

}

void HuodongScreen::back(){
	SWITCHTO_FATHER_SCREEN(HomePageScreen);
}

void HuodongScreen::call(string receive){
	bool get = false;
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			Reader reader1;
			Value root1;  
			reader1.parse(root["Description"].asString(), root1);
			if(root1.size()==0){
				get = false;
			}else{
				get = true;
			}
			if(get){
				int colNum = 1;
				int w = 350;
				int h = 300;
				int num = root1.size();
				tileLayer = MyScrollview::create();
				tileLayer->setTouchType(MyScrollview::LEFT_RIGHT);
				tileLayer->setAnchorPoint(ccp(0,0));
				tileLayer->setShowRect(0,0,Globe::SW,Globe::SH);
				tileLayer->setEveroneSize(CCSize(w,h));
				tileLayer->setWH(num*w,h);
	
				for(int i = 0;i<num;i++){
					string id = root1[i]["ID"].asString();
					MySprite *icon = MySprite::create("screens/public/laoding.png");
					if(i==0){
						icon->setDefaultFocus(true,this);
					}
					icon->setAddMode(1);
					icon->setOpacity(0);
					float x = w/2+i*w;
					icon->setPosition(ccp(x,Globe::SH/2));
					icon->setAppType(Globe::intToString(root1[i]["Type"].asInt()));
					icon->setAppId(id);
					icon->setName(root1[i]["Description"].asString());
					icon->setSelectScale(1.3);
					icon->setFather(tileLayer);
				
					icon->getImageFromUrl(root1[i]["Image"].asString(),Globe::huodongSavaPath+"/"+id);
					vecDownLoadSprite.push_back(icon);
					addMySprite(icon);
					tileLayer->addChild(icon);
					vectiles.push_back(icon);
				}
	
				int offsetX = Globe::SW/2-(vectiles[0]->rect.origin.x+vectiles[0]->rect.size.width/2);
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

			
				CCLayer *cu = creatLayerColor(tileLayer->w+Globe::SW,Globe::SH,80);
				cu->setPosition(ccp(-Globe::SW/2,0));
				tileLayer->addChild(cu,100);
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