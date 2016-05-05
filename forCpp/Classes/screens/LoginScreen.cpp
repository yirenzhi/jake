#include "LoginScreen.h"
#include "HomePageScreen.h"
#include "MyGameScreen.h"

bool LoginScreen::hasGetDownloadUrl = false;
int LoginScreen::stage = 0;
bool LoginScreen::init(){
	stage = 0;
	icon = NULL;
	hasGetDownloadUrl = false;
	isTurn = false;
    
    // add "HelloWorld" splash screen"
    downSprite = MySprite::create("screens/login/bg.png");
	downSprite->setPosition(ccp(Globe::SW/2, Globe::SH/2));
    // add the sprite as a child to this layer
    this->addChild(downSprite, 1);

	CCSprite* pSprite1 = CCSprite::create("screens/login/info0.png");
	pSprite1->setPosition(ccp(Globe::SW/2, Globe::SH/2+30));
	pSprite1->setAnchorPoint(ccp(0.5,0));

    this->addChild(pSprite1, 2);

	CCSprite* pSprite2 = CCSprite::create("screens/login/info1.png");
	pSprite2->setPosition(ccp(Globe::SW/2, Globe::SH/2-30));
	pSprite2->setAnchorPoint(ccp(0.5,1));
    this->addChild(pSprite2, 2);
	
	int num = lenght(dian);
	int w = 40;
	float time = 3;
	for(int i = 0;i<num;i++){
		dianOptin[i] =(num-i)*250/num;
		dian[i] = CCSprite::create("screens/login/dian.png");
		int start = ((float)(num-1)/2)*w;
		dian[i]->setPosition(ccp(Globe::SW/2-start+i*w, Globe::SH/2));
		dian[i]->setOpacity(dianOptin[i]);
		dian[i]->setScale(0.5+((float)dianOptin[i]/2)/250);
		this->addChild(dian[i], 3);
	}

	NetHander::getInfo();
	frm = 0;
	showFrm = 0;

	isShowBack = false;
    return Screen::init();
}

void LoginScreen::update(float ft){
	//CCdelaytime CCRepeat不用一起用。。
	if(stage==1){//结束了，跳转页面
		string ablePath = MyFileUtils::getWritablePath();
		MyFileUtils::deleteDir(ablePath+"logo");
		//HomePageScreen::deleteDir();
		SWITCHTO_FATHER_SCREEN(HomePageScreen);
		//SWITCHTO_FATHER_SCREEN(MyGameScreen);
		return;
	}
	frm++;
	if(frm==30){

		NetHander *net = new NetHander();
		net->getLogo();
		Callback *call = (Callback *)this;
		net->setCallBack(call);
		vecNet.push_back(net);
		//net->autorelease();
	}else if(frm>=600){//10秒之后
		if(!hasGetDownloadUrl){
			CCLog("hasGetDownloadUrl stage 1");
			stage = 1;
		}
	}else if(frm>=6000){
		stage = 1;
	}

	if(!isTurn){
		for(int i = 0;i<lenght(dian);i++){
			dianOptin[i]+=10;
			dianOptin[i]%=500;
			int temp = dianOptin[i]>=250?(500-dianOptin[i]):dianOptin[i];
			dian[i]->setOpacity(temp);
			dian[i]->setScale(0.5+((float)temp/2)/250);
		}
		if(icon){
			if(icon->hasDownload){
				if(icon->showTime<0){
					if(isKeypressed(M_KEY_OK)){
						downSprite->setPressed();
					}
				}else{
					showFrm++;
					if(showFrm>=icon->showTime*60){
						downSprite->setPressed();
					}
				}

				if(downSprite->isPress()){
					CCLog("pressed stage 1");
					stage = 1;
				}
			}
		}
		
	}
	Screen::update(ft);
}

void LoginScreen::back(){

}

void LoginScreen::draw(){

}

void LoginScreen::clear(){

}

void LoginScreen::call(string receive){
	CCLog("receive------%s",receive.c_str());
	if(receive == ""){
		hasGetDownloadUrl = false;
		stage = 1;
		return;
	}
	CCLog("receive no null");
	string imgUrl = "";
	double time = 0;
	string name = "";
	string folder = "";
	Reader reader;  
		Value root;  
		if (reader.parse(receive, root)){
			if(root["Result"].asInt()==0){
				Reader reader1;
				Value root1;
				reader1.parse(root["Description"].asString(), root1);
				imgUrl = root1["Logo"].asString();
				time = root1["ShowTime"].asDouble();
				if(imgUrl==""){
					hasGetDownloadUrl = false;
					stage = 1;
				}else{
					hasGetDownloadUrl = true;
					name = imgUrl.substr(imgUrl.find_last_of("/")+1,imgUrl.length());
					folder = "logo";
					
					icon = MySprite::create("screens/public/laoding.png");
					
					icon->setAddMode(1);
					icon->setOpacity(0);
					icon->setPosition(ccp(Globe::SW/2,Globe::SH/2));
					
					icon->setName(name);
					icon->getImageFromUrl(imgUrl,folder);
					vecDownLoadSprite.push_back(icon);
					this->addChild(icon,4);
				}
			}else{
				hasGetDownloadUrl = false;
				stage = 1;
			}
		}
}


void LoginScreen::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}