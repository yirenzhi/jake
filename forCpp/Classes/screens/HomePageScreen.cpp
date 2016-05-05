#include "HomePageScreen.h"
#include "MyGameScreen.h"
#include "VariousScreen.h"
#include "GameInfoScreen.h"
#include "ManageScreen.h"
#include "HuodongScreen.h"
#include "HuodongInfoScreen.h"
#include "ZhuantiInfo.h"

bool HomePageScreen::init(){
	//deleteDir();
	setTilesName("首页");
	addBgAndTile();
	CCLog("init");

	NetHander *net = new NetHander();
	net->getHomePage();
	net->setCallBack(this);
	vecNet.push_back(net);

	////首页最大的推荐位
	//sprite.push_back(MySprite::create("screens/homepage/show0.png"));
	//sprite[0]->setPosition(ccp(300,400));
	//sprite[0]->setName("巴啦啦小魔仙");
	//this->addChild(sprite[0],4);

	////横着的两个活动位
	//for(int i = 0;i<2;i++){
	//	string temp[] = {
	//		"三国神将传",
	//		"开心宝贝"
	//	};
	//	string path = "screens/homepage/show"+Globe::intToString(i+1)+".png";
	//	sprite.push_back(MySprite::create(path.c_str()));
	//	sprite[1+i]->setPosition(ccp(640+i*335,505));
	//	sprite[1+i]->setName(temp[i]);
	//	this->addChild(sprite[1+i],2+i);
	//}
	////4个游戏推荐位
	//for(int i = 0;i<4;i++){
	//	string temp[] = {
	//		"冠军足球经理",
	//		"天天捕鱼",
	//		"铠甲勇士",
	//		"樱桃小丸子"
	//	};
	//	string path = "screens/homepage/show"+Globe::intToString(i+3)+".png";
	//	sprite.push_back(MySprite::create(path.c_str()));
	//	sprite[3+i]->setPosition(ccp(555+i*168,295));
	//	sprite[3+i]->setName(temp[i]);
	//	this->addChild(sprite[3+i],10+i);
	//}

	//4个功能按钮
	for(int i = 0;i<4;i++){
		string path = "screens/homepage/button"+Globe::intToString(i)+".png";
		buttonSprite[i] = MySprite::create(path.c_str());
		buttonSprite[i]->setPosition(ccp(265+i*250,115));
		this->addChild(buttonSprite[i],20);
	}

	//buttonSprite[1]->setSelect(true);
	stage = 0;
	delayFrm = 0;
	isShowBack = false;
    return Screen::init();
}

void HomePageScreen::back(){
	if(stage==0){
		stage = 1;
		delayFrm = 0;
		string get= Globe::makeJsonString("showPressBackAgain",Globe::GBKToUTF("请再按一次返回键退出"));
		Globe::callJava(get);
	}else if(stage==1){
		if(delayFrm>=20){
			exitGame();
		}
	}
}

void HomePageScreen::deleteDir(){
	string ablePath = MyFileUtils::getWritablePath();
	MyFileUtils::deleteDir(ablePath+"/"+Globe::gameIconSavePath);
	MyFileUtils::deleteDir(ablePath+"/"+Globe::gameShowSavePath);
	MyFileUtils::deleteDir(ablePath+"/"+Globe::huodongSavaPath);
	MyFileUtils::deleteDir(ablePath+"/"+Globe::homePageSavaPaht);
	MyFileUtils::deleteDir(ablePath+"/"+Globe::huodongDetailSavaPaht);
	MyFileUtils::deleteDir(ablePath+"/"+Globe::zhuantiDetailSavaPaht);
	MyFileUtils::deleteDir(ablePath+"/"+Globe::gameApkSavePath);
}

void HomePageScreen::exitGame(){
	CCLog("------exit-----");

	//北京联通的数码的盒子退出有问题，把删除文件夹去掉

	deleteDir();
	


	//清除正在下载的资源
	for(int i = 0;i<vecDownLoadRes.size();i++){
		if(!vecDownLoadRes[i]->isDownLoadSuccess){
			vecDownLoadRes[i]->down->close();
		}
		//delete vecDownLoadRes[i];
	}
	vecDownLoadRes.clear();



	string get= Globe::makeJsonString("exit","");
	Globe::callJava(get);
	CCLog("------exit end-----");
	CCDirector::sharedDirector()->end();
}

void HomePageScreen::update(float ft){

	if(isKeypressed(M_KEY_UP)
		||isKeypressed(M_KEY_DOWN)
		||isKeypressed(M_KEY_LEFT)
		||isKeypressed(M_KEY_RIGHT)
		||isKeypressed(M_KEY_OK)
		||isKeypressed(M_KEY_MENU)){
			if(stage==1){
				stage = 0;
			}
	}
	if(stage==1){
		if(delayFrm<10240){
			delayFrm++;
		}
	}
	Screen::update(ft);
	for(int i = 0;i<lenght(buttonSprite);i++){
		if(buttonSprite[i]->isPress()){
			switch(i){
			case 0:
				{
					SWITCHTO_CHILD_SCREEN(MyGameScreen);
				}
				break;
			case 1:
				{
					SWITCHTO_CHILD_SCREEN(VariousScreen);
				}
				break;
			case 2:
				{
					HuodongScreen::tileLayerX = 0;
					HuodongScreen::index = 0;
					SWITCHTO_CHILD_SCREEN(HuodongScreen);
				}
				break;
			case 3:
				{
					SWITCHTO_CHILD_SCREEN(ManageScreen);
				}
				break;
			}
			break;
		}
	}

	for(int i = 0;i<sprite.size();i++){
		if(sprite[i]->isPress()){
			if(sprite[i]->appType=="1"){//游戏
				GameInfoScreen::gameId = sprite[i]->appid;
				SWITCHTO_CHILD_SCREEN(GameInfoScreen);
			}else if(sprite[i]->appType=="2"){//活动
				HuodongInfoScreen::activityId = sprite[i]->appid;
				SWITCHTO_CHILD_SCREEN(HuodongInfoScreen);
			}else if(sprite[i]->appType=="3"){//专题
				ZhuantiInfo::zhuantiId = sprite[i]->appid;
				SWITCHTO_CHILD_SCREEN(ZhuantiInfo);
			}
			break;
		}
	}
	keyReset();
}

void HomePageScreen::call(string receive){
	//CCLog("start down");
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			Reader reader1;
			Value root1;
			reader1.parse(root["Description"].asString(),root1);
			for(int i = 0;i<root1.size();i++){
				string imageUrl = root1[i]["Image"].asString();
				string appid = root1[i]["ID"].asString();
				string locationID = Globe::intToString(root1[i]["LocationID"].asInt());
				string type = Globe::intToString(root1[i]["Type"].asInt());
				string name = root1[i]["Description"].asString().c_str();
				float x = root1[i]["X"].asInt();
				float y = root1[i]["Y"].asInt();
				MySprite *icon = MySprite::create("screens/public/laoding.png");
				if(locationID=="1"){
					icon->setDefaultFocus(true,this);
				}
				icon->setAddMode(1);
				icon->setOpacity(0);
				icon->setPosition(ccp(x,y));
				icon->setAppType(type);
				icon->setAppId(appid);
				icon->setName(name);
				sprite.push_back(icon);
				icon->getImageFromUrl(imageUrl,Globe::homePageSavaPaht+"/"+type+"/"+appid);
				vecDownLoadSprite.push_back(icon);
				this->addChild(icon,4);
			}
		}
	}

	//CCLog("install:%s",path.c_str());
	//string get= Globe::makeJsonString("install",path);
	//Globe::callJava(get);
}

void HomePageScreen::draw(){

}

void HomePageScreen::clear(){

}
