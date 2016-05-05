#include "ChaxunScreen.h"
#include "ManageScreen.h"


bool ChaxunScreen::init(){
	setTilesName("消费查询");
	addBgAndTile();

	pageNum = 0;
	pageIndex = 0;
	
	
	btLastPage = NULL;
	btNextPage = NULL;
	btCancle = NULL;

	pageLabel = NULL;

	CCSprite *bg = CCSprite::create("screens/chaxun/bg.png");
	bg->setPosition(ccp(Globe::SW/2,Globe::SH/2));
	bg->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(bg,1);

	ccColor3B cc3bInfo = {75,203,255};
	for(int i = 0;i<NUM_PAGE;i++){
		wordGameName[i] = CCLabelTTF::create("type","Marker Felt",20);
		wordGameName[i]->setAnchorPoint(ccp(0.5,1));
		wordGameName[i]->setColor(cc3bInfo);
		wordGameName[i]->setString("");
		wordGameName[i]->setPosition(ccp(750,500-i*42));
		this->addChild(wordGameName[i],2);

		wordProName[i] = CCLabelTTF::create("type","Marker Felt",20);
		wordProName[i]->setAnchorPoint(ccp(0.5,1));
		wordProName[i]->setColor(cc3bInfo);
		wordProName[i]->setString("");
		wordProName[i]->setPosition(ccp(535,500-i*42));
		this->addChild(wordProName[i],2);

		wordMoney[i] = CCLabelTTF::create("type","Marker Felt",20);
		wordMoney[i]->setAnchorPoint(ccp(0.5,1));
		wordMoney[i]->setColor(cc3bInfo);
		wordMoney[i]->setString("");
		wordMoney[i]->setPosition(ccp(320,500-i*42));
		this->addChild(wordMoney[i],2);

		wordTime[i] = CCLabelTTF::create("type","Marker Felt",20);
		wordTime[i]->setAnchorPoint(ccp(0.5,1));
		wordTime[i]->setColor(cc3bInfo);
		wordTime[i]->setString("");
		wordTime[i]->setPosition(ccp(980,500-i*42));
		this->addChild(wordTime[i],2);
	}
	chaxun();
	isNextBuf = false;
    return Screen::init();
}


void ChaxunScreen::chaxun(){
	isChaxuning = true;
	NetHander *net = new NetHander();
	net->getXiaofeijilu(pageIndex+1,NUM_PAGE);
	net->setCallBack(this);
	vecNet.push_back(net);
}

void ChaxunScreen::update(float ft){
	if(isChaxuning){
		Screen::update(ft);
		return;
	}

	if(btNextPage!=NULL){
		if(btNextPage->isPress()){
			isNextBuf = true;
			pageIndex++;
			clearWord();
			chaxun();
		}
	}

	if(btLastPage!=NULL){
		if(btLastPage->isPress()){
			isNextBuf = false;
			pageIndex--;
			clearWord();
			chaxun();
		}
	}

	if(btCancle!=NULL){
		if(btCancle->isPress()){
			back();
		}
	}


	
	Screen::update(ft);
}

void ChaxunScreen::draw(){

}

void ChaxunScreen::clear(){

}

void ChaxunScreen::back(){
	SWITCHTO_FATHER_SCREEN(ManageScreen);
}

void ChaxunScreen::call(string receive){
	isChaxuning = false;
	bool get = false;
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			Reader reader1;
			Value root1;
			reader1.parse(root["Description"].asString(),root1);
			int count = root1["Count"].asInt();
			if(count==0){
				ccColor3B cc3bInfo = {75,203,255};
				CCLabelTTF *show = CCLabelTTF::create("type","Marker Felt",20);
				show->setAnchorPoint(ccp(0.5,1));
				show->setColor(cc3bInfo);
				show->setString(Globe::GBKToUTF("当前没有消费记录").c_str());
				show->setPosition(ccp(Globe::SW/2,500));
				this->addChild(show,2);
				return;
			}
			if(count%NUM_PAGE==0){
				pageNum = (count/NUM_PAGE);
			}else{
				pageNum = (count/NUM_PAGE)+1;
			}
			Reader reader2;
			Value root2;
			reader2.parse(root1["Records"].toStyledString(),root2);
			
			for(int i = 0;i<root2.size();i++){
				string gameName = root2[i]["GameName"].asString();
				string money = root2[i]["Money"].asString();
				string name = root2[i]["Name"].asString();
				string time = root2[i]["UpdateTime"].asString();
				wordGameName[i]->setString(gameName.c_str());
				wordProName[i]->setString(name.c_str());
				wordMoney[i]->setString(money.c_str());
				wordTime[i]->setString(time.c_str());
			}
			chaxunEnd();
		}
	}
}

void ChaxunScreen::clearWord(){
	for(int i = 0;i<NUM_PAGE;i++){
		wordGameName[i]->setString("");
		wordProName[i]->setString("");
		wordMoney[i]->setString("");
		wordTime[i]->setString("");
	}
}

void ChaxunScreen::chaxunEnd(){
	if(btLastPage!=NULL){
		this->removeChild(btLastPage);
		btLastPage = NULL;
	}
	if(btNextPage!=NULL){
		this->removeChild(btNextPage);
		btNextPage = NULL;
	}
	if(btCancle!=NULL){
		this->removeChild(btCancle);
		btCancle = NULL;
	}
	if(pageLabel==NULL){
		//新密码
		ccColor3B cc3bInfo = {75,203,255};
		pageLabel = CCLabelTTF::create("type","Marker Felt",20);
		pageLabel->setAnchorPoint(ccp(0,1));
		pageLabel->setColor(cc3bInfo);
		string temp = "共"+Globe::intToString(pageIndex+1)+"/"+Globe::intToString(pageNum);
		pageLabel->setString(Globe::GBKToUTF(temp.c_str()).c_str());
		pageLabel->setPosition(ccp(Globe::SW-200,600));
		this->addChild(pageLabel,2);
	}else{
		string temp = "共"+Globe::intToString(pageIndex+1)+"/"+Globe::intToString(pageNum);
		pageLabel->setString(Globe::GBKToUTF(temp.c_str()).c_str());
	}

	
	int offsetW = 120;
	if(pageIndex==0){//第一页
		if(pageNum>1){//有下一页
			btCancle = addBt("screens/jiankong/b1.png",Globe::SW/2-offsetW);
			btNextPage = addBt("screens/chaxun/b1.png",Globe::SW/2+offsetW);
			setFocus(btNextPage);
		}else{//只有一页
			btCancle = addBt("screens/jiankong/b1.png",Globe::SW/2);
			setFocus(btCancle);
		}
	}else if(pageIndex==pageNum-1){//最后一页
		btLastPage = addBt("screens/chaxun/b0.png",Globe::SW/2-offsetW);
		btCancle = addBt("screens/jiankong/b1.png",Globe::SW/2+offsetW);
		setFocus(btLastPage);
	}else{
		btLastPage = addBt("screens/chaxun/b0.png",Globe::SW/2-2*offsetW);
		btCancle = addBt("screens/jiankong/b1.png",Globe::SW/2);
		btNextPage = addBt("screens/chaxun/b1.png",Globe::SW/2+2*offsetW);
		if(isNextBuf){
			setFocus(btNextPage);
		}else{
			setFocus(btLastPage);
		}
		
	}
}

MySprite* ChaxunScreen::addBt(string pngPath,int x){
	int y = 150;

	MySprite *sprite = MySprite::create("screens/jiankong/bt.png");
	sprite->setPosition(ccp(x,y));
	CCSprite *ok = CCSprite::create(pngPath.c_str());
	ok->setAnchorPoint(ccp(0.5,0.5));
	ok->setPosition(ccp(sprite->getContentSize().width/2,sprite->getContentSize().height/2));
	sprite->addChild(ok,1);
	sprite->setSelectScale(1);
	this->addChild(sprite,2);
	return sprite;
}