#include "VariousScreen.h"
#include "HomePageScreen.h"
#include "GameInfoScreen.h"
#include "MyGameScreen.h"
#include "UninstallScreen.h"

bool VariousScreen::isComeBack = false;
int VariousScreen::tileIndex = 0;
int VariousScreen::layerY = 0;
int VariousScreen::iconIndex = 0;
bool VariousScreen::init(){
	setTilesName("分类");
	addBgAndTile();
	needSaveDefaultFocas = false;
	currentIndex = 0;
	callStage = 0;
	isGetInfoEnd = false;
	mustRefresh = false;



	tileLayer = MyScrollview::create();
	tileLayer->setAnchorPoint(ccp(0,0));
	tileLayer->setShowRect(0,30,Globe::SW,630);
	tileLayer->setPosition(ccp(80,630));
	//initTils(0);
	

	
	this->addChild(tileLayer,10);

	scrollvie = new MyScrollviewThumbnail(tileLayer);
	scrollvie->setPosition(ccp(1120,650));
	scrollvie->setAnchorPoint(ccp(0,1));
	this->addChild(scrollvie,110);
	scrollvie->autorelease();
	scrollvie->update();
	
    return Screen::init();
}


void VariousScreen::call(string receive){

	callStage++;
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			Reader reader1;
			Value root1;
			reader1.parse(root["Description"].asString(),root1);
			if(callStage==1){//先获取分类
				for(int i = 0;i<root1.size();i++){
					cateGory cate;
					cate.id = Globe::intToString(root1[i]["ID"].asInt());
					cate.name = root1[i]["Name"].asString();
					cateGorys.push_back(cate);
				}
				if(cateGorys.size()>0){
					for(int i = 0;i<cateGorys.size();i++){
						string path = "screens/various/v"+Globe::intToString(i%3)+".png";
						MySprite *sptep = MySprite::create(path.c_str());
						sptep->setAnchorPoint(ccp(0.5,0.5));
						sptep->setSelectScale(1.3);
						sptep->setPosition(ccp(160,575-i*80));
						//添加文字
						CCLabelTTF *word1 = CCLabelTTF::create("type","Marker Felt",25);
						ccColor3B cc3b = {255,255,255};
						word1->setAnchorPoint(ccp(0.5,0.5));
						word1->setColor(cc3b);
						word1->setString(cateGorys[i].name.c_str());
						word1->setPosition(ccp(sptep->getContentSize().width/2,sptep->getContentSize().height/2));
						sptep->addChild(word1,2);
						spriteTile.push_back(sptep);
						this->addChild(spriteTile[i],1);
					}
					if(isComeBack){
						getVariousInfo(tileIndex);
						//setFocus(spriteTile[tileIndex]);
					}else{
						setFocus(spriteTile[0]);
						getVariousInfo(0);
					}
				}
			}
			else{
				isGetInfoEnd = true;
				int colNum = 4;
				int w = 200;
				int h = 250;
				int num = root1.size();
				int linNum = num/colNum+(num%colNum==0?0:1);
				tileLayer->setEveroneSize(CCSize(w,h));
				tileLayer->setWH(Globe::SW,linNum*h);
				for(int i = 0;i<root1.size();i++){
					string imageUrl = root1[i]["Icon"].asString();
					string appid = Globe::intToString(root1[i]["AppID"].asInt());
					string name = root1[i]["Name"].asString();
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
					word1->setString(name.c_str());
					word1->setPosition(ccp(icon->getContentSize().width/2,25));
					icon->addChild(word1,2);


					float scanX = faW/icon->getContentSize().width;
					float scanY = faH/icon->getContentSize().height;
					icon->setScaleX(scanX);
					icon->setScaleY(scanY);
					icon->setPosition(ccp(x,-offset-icon->factRect.size.height/2-(i/colNum)*h));
					icon->setFactRect(CCRectMake(icon->getPositionX()-faW/2,
						icon->getPositionY()-faH/2,faW,faH));
					icon->setAppId(appid);
					icon->setAddMode(2);
					icon->setCutY(40);
					icon->setShowScanXY(0.9,0.9);
					//icon->setName(name);

					int maxY = -(tileLayer->getPositionY()-tileLayer->endY);
					int minY = -(tileLayer->getPositionY()-tileLayer->startY);
					int topY = icon->factRect.origin.y+icon->factRect.size.height;
					int bottomY = icon->factRect.origin.y;
					string path = Globe::gameIconSavePath+"/"+appid;
					if(topY>minY&&
						bottomY<maxY){
						icon->getImageFromUrl(imageUrl,path);
					}else{
						icon->fromUrl = imageUrl;
						icon->inTheFolder = path;
					}

					/*string path = Globe::gameIconSavePath+"/"+appid;
					icon->getImageFromUrl(imageUrl,path);*/

					vecDownLoadSprite.push_back(icon);
					icon->setFather(tileLayer);
					addMySprite(icon);
					tileLayer->addChild(icon);
					for(int i = 0;i<spriteTile.size();i++){
						icon->setMyParents(spriteTile[i]);
					}
					icon->setMyselfParent(spriteTile[currentIndex]);
					tiles.push_back(icon);
				}
				if(isComeBack){
					isComeBack = false;
					mustRefresh = true;
					tileLayer->setPositionY(layerY);
					if(iconIndex<tiles.size()){
						changeFocus(tiles[iconIndex]);
					}
				}
			}
		}
	}
}


void VariousScreen::getVariousInfo(int index){
	tileLayer->reset();
	tiles.clear();
	//获取分类详情
	isGetInfoEnd = false;
	vecButtons.clear();
	NetHander *net = new NetHander();
	net->getCategoryDetail(cateGorys[index].id);
	net->setCallBack(this);
	vecNet.push_back(net);
	//net->autorelease();
	currentIndex = index;
	for(int i = 0;i<spriteTile.size();i++){
		vecButtons.push_back(spriteTile[i]);
	}
	for(int i = 0;i<spriteTile.size();i++){
		if(i==currentIndex){//当前选中的
			spriteTile[i]->setScale(1.3);
			spriteTile[i]->setOpacity(255);
		}else{
			spriteTile[i]->setScale(1);
			spriteTile[i]->setOpacity(100);
		}
	}
}

void VariousScreen::initTils(int index){
	
	
}

void VariousScreen::back(){
	if(hasTileName("我的游戏")){
		SWITCHTO_FATHER_SCREEN(MyGameScreen);
	}else if(hasTileName("卸载游戏")){
		SWITCHTO_FATHER_SCREEN(UninstallScreen);
	}else{
		SWITCHTO_FATHER_SCREEN(HomePageScreen);
	}
}

void VariousScreen::update(float ft){
	if(!CCScene::isShowSwitch&&!isShowSwitchBack){
		if(frm<10){
		frm++;
		if(frm==2){
			NetHander *net = new NetHander();
			net->getCategory();
			net->setCallBack(this);
			vecNet.push_back(net);
		}
		}
	}
	for(int i = 0;i<spriteTile.size();i++){
		if(i==currentIndex){//当前选中的
			spriteTile[i]->setScale(1.3);
			spriteTile[i]->setOpacity(255);
		}
	}
	//当前页面的图标图片刷新下载
	if(isKeypressed(M_KEY_UP)||isKeypressed(M_KEY_DOWN)||mustRefresh){
		refresh();
	}
	
	for(int i = 0;i<spriteTile.size();i++){
		if(spriteTile[i]->isPress()){//按下了
			if(i!=currentIndex&&isGetInfoEnd){
				tileLayer->removeAllChildren();
				vecDownLoadSprite.clear();
				getVariousInfo(i);
				break;
			}
		}
	}

	for(int i = 0;i<tiles.size();i++){
		if(tiles[i]->isPress()){
			GameInfoScreen::gameId = tiles[i]->appid;
			isComeBack = true;
			tileIndex = currentIndex;
			layerY = tileLayer->getPositionY();
			iconIndex = i;
			SWITCHTO_CHILD_SCREEN(GameInfoScreen);
		}
	}
	
	
	scrollvie->update();

	Screen::update(ft);
}

void VariousScreen::refresh(){
	mustRefresh = false;
	for(int i = 0;i<tiles.size();i++){
		int maxY = -(tileLayer->getPositionY()-tileLayer->endY)+tileLayer->everoneSize.height;
		int minY = -(tileLayer->getPositionY()-tileLayer->startY)-tileLayer->everoneSize.height;
		int topY = tiles[i]->factRect.origin.y+tiles[i]->factRect.size.height;
		int bottomY = tiles[i]->factRect.origin.y;
		if(topY>minY&&bottomY<maxY){
			if(!tiles[i]->hasGetUrlImage){
				tiles[i]->getImageFromUrl(tiles[i]->fromUrl,tiles[i]->inTheFolder);
				vecDownLoadSprite.push_back(tiles[i]);
			}
		}
	}
}

void VariousScreen::draw(){

}

void VariousScreen::clear(){

}