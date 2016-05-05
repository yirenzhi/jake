#include "UninstallScreen.h"
#include "ManageScreen.h"
#include "VariousScreen.h"

MySprite* UninstallScreen::selectGame = NULL;
int UninstallScreen::selectIndex = 0;
int UninstallScreen::tileY = 0;
string UninstallScreen::allGamesStr = "";
bool UninstallScreen::init(){
	needSaveDefaultFocas = false;
	setTilesName("卸载游戏");
	addBgAndTile();
	scrollvie = NULL;
	bt = NULL;
	selectGame = NULL;
	hasChange = false;

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


void UninstallScreen::updateNoGames(){
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


void UninstallScreen::back(){
	SWITCHTO_FATHER_SCREEN(ManageScreen);
}

void UninstallScreen::update(float ft){
	for(int i = 0;i<vectiles.size();i++){
		if(vectiles[i]->isPress()){
			selectGame = vectiles[i];
			selectIndex = i;
			tileY = tileLayer->getPositionY();
			hasChange = true;
			Screen::unInstall(selectGame->pkgName);
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
	if(hasChange){
		string get1= Globe::makeJsonString("getInstalledApks","");
		string current = Globe::callJava(get1);
		if(allGamesStr!=current){
			allGamesStr = current;
			SWITCHTO_SCREEN(UninstallScreen);
		}
		
	}
	Screen::update(ft);
}

void UninstallScreen::draw(){

}

void UninstallScreen::clear(){

}

void UninstallScreen::call(string receive){
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			Reader reader1;
			Value root1;
			reader1.parse(root["Description"].asString(),root1);
			myGames.clear();
			for(int i = 0;i<root1.size();i++){
				gameInfo info;
				info.appId = Globe::replaceStr(root1[i]["AppID"].toStyledString());
				info.name = root1[i]["Name"].asString();
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


					MySprite *icon = MySprite::create("screens/public/laoding.png");
					float x = Globe::SW/2-((float)(colNum-1)/2)*w+(i%colNum)*w-30;
					int offset = (h - icon->factRect.size.height)/2;
					int faW = 176;
					int faH = 225;
					//添加游戏名字
					CCLabelTTF *word1 = CCLabelTTF::create("type","Marker Felt",28);
					ccColor3B cc3b = {255,255,255};
					word1->setAnchorPoint(ccp(0.5,0.5));
					word1->setColor(cc3b);
					word1->setString(myGames[i].name.c_str());
					word1->setPosition(ccp(icon->getContentSize().width/2,25));
					icon->addChild(word1,2);
					float scanX = faW/icon->getContentSize().width;
					float scanY = faH/icon->getContentSize().height;
					icon->setScaleX(scanX);
					icon->setScaleY(scanY);
					icon->setPosition(ccp(x,-offset-icon->factRect.size.height/2-(i/colNum)*h));
					icon->setFactRect(CCRectMake(icon->getPositionX()-faW/2,
						icon->getPositionY()-faH/2,faW,faH));
					icon->setPkgName(myGames[i].pkgName);
					icon->setAddMode(2);
					icon->setCutY(40);
					icon->setShowScanXY(0.9,0.9);
					icon->getImageFromUrl(myGames[i].url,"myGamesIcon/"+myGames[i].appId);
					vecDownLoadSprite.push_back(icon);
					icon->setFather(tileLayer);
					icon->setAppId(myGames[i].appId);
					icon->setPkgName(myGames[i].pkgName);

					/*MySprite *temp = MySprite::create("screens/public/laoding.png");
					temp->setAddMode(2);
					float x = Globe::SW/2-((float)(colNum-1)/2)*w+(i%colNum)*w-30;
					int offset = (h - faH)/2;
					temp->setPosition(ccp(x,-offset-faH/2-(i/colNum)*h));
					temp->setFactRect(CCRectMake(temp->getPositionX()-faW/2,
							temp->getPositionY()-faH/2,faW,faH));
					float scanX = faW/temp->getContentSize().width;
					float scanY = faH/temp->getContentSize().height;
					temp->setScaleX(scanX);
					temp->setScaleY(scanY);*/
					


					addMySprite(icon);
					tileLayer->addChild(icon);
					vectiles.push_back(icon);
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
	}

	//CCLog("install:%s",path.c_str());
	//string get= Globe::makeJsonString("install",path);
	//Globe::callJava(get);
}