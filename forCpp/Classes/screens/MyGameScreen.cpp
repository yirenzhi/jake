#include "MyGameScreen.h"
#include "HomePageScreen.h"
#include "AskOpenScreen.h"
#include "VariousScreen.h"
#include "GameInfoScreen.h"


MySprite* MyGameScreen::selectGame = NULL;
int MyGameScreen::selectIndex = 0;
int MyGameScreen::tileY = 0;
string MyGameScreen::allGamesStr = "";
bool MyGameScreen::init(){
	needSaveDefaultFocas = false;
	setTilesName("我的游戏");
	addBgAndTile();
	scrollvie = NULL;
	bt = NULL;
	selectGame = NULL;
	hasChange = false;
	stage = 0;

	string get1= Globe::makeJsonString("getInstalledApks","");
	allGamesStr = Globe::callJava(get1);
	if(allGamesStr==""){
		updateNoGames();
	}else{
		NetHander *net = new NetHander();
		net->getAllInstallApks(allGamesStr);
		net->setCallBack(this);
		vecNet.push_back(net);
	}
    return Screen::init();
}


void MyGameScreen::updateNoGames(){
	CCSprite *info = CCSprite::create("screens/mygame/info.png");
	info->setPosition(ccp(Globe::SW/2,Globe::SH/2+80));
	this->addChild(info,2);
	bt = MySprite::create("screens/mygame/bt0.png");
	bt->setPosition(ccp(Globe::SW/2,Globe::SH/2));
	this->addChild(bt,3);
	CCSprite *bt1 = CCSprite::create("screens/mygame/bt1.png");
	bt1->setPosition(ccp(bt->getContentSize().width/2,bt->getContentSize().height/2));
	bt->addChild(bt1,2);

	setFocus(bt);
}


void MyGameScreen::back(){
	SWITCHTO_FATHER_SCREEN(HomePageScreen);
}

void MyGameScreen::update(float ft){
	for(int i = 0;i<vectiles.size();i++){
		if(vectiles[i]->isPress()){
			selectGame = vectiles[i];
			selectIndex = i;
			tileY = tileLayer->getPositionY();
			NetHander *net = new NetHander();
			net->getNewVersion(MyGameScreen::selectGame->appid);
			net->setCallBack(this);
			vecNet.push_back(net);
			return;
		}
	}
	if(scrollvie){
		scrollvie->update();
	}

	if(bt){
		if(bt->isPress()){
			SWITCHTO_CHILD_SCREEN(VariousScreen);
		}
	}
	if(hasChange){//检车是否卸载过游戏
		string get1= Globe::makeJsonString("getInstalledApks","");
		string current = Globe::callJava(get1);
		if(allGamesStr!=current){
			allGamesStr = current;
			SWITCHTO_SCREEN(MyGameScreen);
		}
	}
	Screen::update(ft);
}

void MyGameScreen::draw(){

}

void MyGameScreen::clear(){

}

void MyGameScreen::call(string receive){
	stage++;
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			if(stage==1){
				Reader reader1;
				Value root1;
				reader1.parse(root["Description"].asString(),root1);
				myGames.clear();
				for(int i = 0;i<root1.size();i++){
					gameInfo info;
					info.appId = Globe::replaceStr(root1[i]["AppID"].toStyledString());
					//string name = root1[i]["Name"].asString();
					info.url = root1[i]["Icon"].asString();
					info.pkgName = root1[i]["PackageName"].asString();
					myGames.push_back(info);
				}

				int colNum = 4;
				int w = 230;
				int h = 300;
				int num = myGames.size();
			
				if(num==0){
					updateNoGames();
				}else{
					int linNum = num/colNum+(num%colNum==0?0:1);
					tileLayer = MyScrollview::create();
					tileLayer->setAnchorPoint(ccp(0,0));
					tileLayer->setShowRect(0,30,Globe::SW,630);
					tileLayer->setEveroneSize(CCSize(w,h));
					tileLayer->setWH(Globe::SW,linNum*h);
					if(tileY==0){
						tileLayer->setPosition(ccp(0,630));
					}else{
						tileLayer->setPosition(ccp(0,tileY));
					}
					int faW = 210;
					int faH = 265;
					for(int i = 0;i<num;i++){

						MySprite *temp = MySprite::create("screens/public/laoding.png");
						temp->setAddMode(2);
						float x = Globe::SW/2-((float)(colNum-1)/2)*w+(i%colNum)*w-30;
						int offset = (h - faH)/2;
						temp->setPosition(ccp(x,-offset-faH/2-(i/colNum)*h));
						temp->setFactRect(CCRectMake(temp->getPositionX()-faW/2,
								temp->getPositionY()-faH/2,faW,faH));
						float scanX = faW/temp->getContentSize().width;
						float scanY = faH/temp->getContentSize().height;
						temp->setScaleX(scanX);
						temp->setScaleY(scanY);
						temp->getImageFromUrl(myGames[i].url,"myGamesIcon/"+myGames[i].appId);
						vecDownLoadSprite.push_back(temp);
						temp->setFather(tileLayer);
						temp->setAppId(myGames[i].appId);
						temp->setPkgName(myGames[i].pkgName);
						addMySprite(temp);
						tileLayer->addChild(temp);
						vectiles.push_back(temp);
					}
					if(selectIndex==0){
						setFocus(vectiles[0]);
					}else{
						int index = 0;
						if(selectIndex<vectiles.size()){
							index = selectIndex;
							setFocus(vectiles[selectIndex]);
						}else{
							index = vectiles.size()-1;
							changeFocus(vectiles[index]);
						}
						vectiles[index]->setChangeFlag(1);
						hasSelectFocus = true;
						int x = vectiles[index]->getPositionX()+tileLayer->getPositionX();
						int y = vectiles[index]->getPositionY()+tileLayer->getPositionY();
						focus->setPosition(ccp(x,y));
					}
				
					this->addChild(tileLayer,10);
					scrollvie = new MyScrollviewThumbnail(tileLayer);
					scrollvie->setPosition(ccp(1120,650));
					scrollvie->setAnchorPoint(ccp(0,1));
					this->addChild(scrollvie,110);
					scrollvie->autorelease();
					scrollvie->update();
				}
			}
			else{
				string ver = hasInstallApk(MyGameScreen::selectGame->pkgName);
				string serVersion = "";
				Reader reader1;
				Value root1;
				reader1.parse(root["Description"].asString(),root1);
				for(int i = 0;i<root1.size();i++){
					if(Globe::replaceStr(root1[i]["AppID"].toStyledString())==MyGameScreen::selectGame->appid){
						serVersion = Globe::replaceStr(root1[i]["Version"].toStyledString());
						break;
					}
				}
				if(Globe::stringToInt(ver)>=Globe::stringToInt(serVersion)){
					//ADD_SCREEN(AskOpenScreen);
					string str = MyGameScreen::selectGame->pkgName+"|"+Globe::intToString(Globe::MYGAME_SCREEN)+"%";
					Globe::callJava(Globe::makeJsonString("openGame",str));
					hasChange = true;
					return;
				}
			}
		}
	}
	if(stage>1){
		string get= Globe::makeJsonString("showPressBackAgain",Globe::GBKToUTF("游戏更新啦，请更新到最新版本！"));
		Globe::callJava(get);
		GameInfoScreen::gameId = MyGameScreen::selectGame->appid;
		SWITCHTO_CHILD_SCREEN(GameInfoScreen);
	}
	//CCLog("install:%s",path.c_str());
	//string get= Globe::makeJsonString("install",path);
	//Globe::callJava(get);
}