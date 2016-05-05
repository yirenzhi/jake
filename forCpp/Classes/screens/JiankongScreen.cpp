#include "JiankongScreen.h"
#include "ManageScreen.h"

string JiankongScreen::password = "";
bool JiankongScreen::init(){
	setTilesName("家长监控");
	
	addBgAndTile();
	needSaveDefaultFocas = false;
	setTingFrm = 0;
	frm = 0;
	inputOld = "";
	inputNew = "";
	inputAgain = "";
	isSeting = false;

	selectIndex = 0;
	isFristSet = false;
	hasGetPassWord = false;
	
	NetHander *net = new NetHander();
	net->getUserPassword();
	net->setCallBack(this);
	vecNet.push_back(net);

	
	CCSprite *tile = CCSprite::create("screens/jiankong/tile.png");
	tile->setAnchorPoint(ccp(0.5,0.5));
	tile->setPosition(ccp(Globe::SW/2,600));
	this->addChild(tile,2);




	isSetEnd = false;
	kuang = NULL;

    return Screen::init();
}



void JiankongScreen::update(float ft){
	if(switchFrm<50){
		switchFrm++;
		if(switchFrm>15){
			isShowSwitchBack = false;
		}
	}
	if(!hasGetPassWord){
		return;
	}
	if(isSetEnd){
		setTingFrm++;
		if(setTingFrm>=120){
			back();
		}
		return;
	}
	frm++;
	frm%=10240;
	if(isFristSet){
		if(isKeypressed(M_KEY_UP)){
			selectIndex--;
			if(selectIndex<0){
				selectIndex = 0;
			}
			if(selectIndex!=2){
				btOk->setSelect(false);
				btCancle->setSelect(false);
				focus->setZOrder(0);
				focus->setPosition(ccp(btOk->getPositionX(),btOk->getPositionY()));
			}
		}else if(isKeypressed(M_KEY_DOWN)){
			selectIndex++;
			if(selectIndex>2){
				selectIndex = 2;
			}
			if(selectIndex==2){
				setFocus(btOk);
			}
			if(selectIndex!=2){
				btOk->setSelect(false);
				btCancle->setSelect(false);
				focus->setZOrder(0);
				focus->setPosition(ccp(btOk->getPositionX(),btOk->getPositionY()));
			}
		}

		if(selectIndex==2){
			if(btOk->isPress()){
				if(inputNew!=inputAgain){
					showInfo("密码和重复密码不相同，请重新输入");
					inputNew = "";
					inputAgain = "";
				}else if(inputNew.length()==0){
					showInfo("请输入6位数字密码");
				}else if(inputNew.length()!=6){
					showInfo("请输入6位数字密码");
					inputNew = "";
					inputAgain = "";
				}else{
					setTongsuo(inputNew);
				}
			}else if(btCancle->isPress()){
				back();
			}
			Screen::update(ft);
		}else{
			if(isKeypressed(M_KEY_LEFT)){
				if(selectIndex==0){
					if(inputNew.length()>0){
						inputNew = inputNew.substr(0,inputNew.length()-1);
					}
				}else if(selectIndex==1){
					if(inputAgain.length()>0){
						inputAgain = inputAgain.substr(0,inputAgain.length()-1);
					}
				}
			}
		}
		
		string temp[] = {"0","1","2","3","4","5","6","7","8","9"};
		int key[] = {M_KEY_0,M_KEY_1,M_KEY_2,M_KEY_3,M_KEY_4,M_KEY_5,M_KEY_6,M_KEY_7,M_KEY_8,M_KEY_9};
		for(int i = 0;i<10;i++){
			//if(isKeypressed(key[i])){//在某个盒子数字键不响应，没时间调试了，改成如下方法
			if(testNumberKey==1008+i||testNumberKey==8+i){
				if(selectIndex==0&&inputNew.length()<8){
					inputNew+=temp[i];
				}else if(selectIndex==1&&inputAgain.length()<8){
					inputAgain+=temp[i];
				}
				showInfo("");
				testNumberKey = 0;
				break;
			}
		}
		//把字符串转换成“*”
		string newo = "";
		for(int i = 0;i<inputNew.length();i++){
			newo+="*";
		}
		newPassword->setString(newo.c_str());
		string agin = "";
		for(int i = 0;i<inputAgain.length();i++){
			agin+="*";
		}
		againPassword->setString(agin.c_str());

		
		
	}else{
		if(isKeypressed(M_KEY_UP)){
			selectIndex--;
			if(selectIndex<0){
				selectIndex = 0;
			}
			if(selectIndex!=3){
				btOk->setSelect(false);
				btCancle->setSelect(false);
				focus->setZOrder(0);
				focus->setPosition(ccp(btOk->getPositionX(),btOk->getPositionY()));
			}
		}else if(isKeypressed(M_KEY_DOWN)){
			selectIndex++;
			if(selectIndex>3){
				selectIndex = 3;
			}
			if(selectIndex==3){
				setFocus(btOk);
			}
			if(selectIndex!=3){
				btOk->setSelect(false);
				btCancle->setSelect(false);
				focus->setZOrder(0);
				focus->setPosition(ccp(btOk->getPositionX(),btOk->getPositionY()));
			}
		}

		if(selectIndex==3){
			if(btOk->isPress()){
				if(password!=inputOld){
					showInfo("旧密码输入错误");
					inputOld = "";
				}else if(inputNew!=inputAgain){
					showInfo("新密码和重复密码不相同，请重新输入");
					inputNew = "";
					inputAgain = "";
				}else if(inputNew.length()==0){
					setTongsuo(inputNew);
				}else if(inputNew.length()!=6){
					showInfo("请输入6位数字密码");
					inputNew = "";
					inputAgain = "";
				}else{
					setTongsuo(inputNew);
				}
			}else if(btCancle->isPress()){
				back();
			}
			Screen::update(ft);
		}else{
			if(isKeypressed(M_KEY_LEFT)){
				if(selectIndex==0){
					if(inputOld.length()>0){
						inputOld = inputOld.substr(0,inputOld.length()-1);
					}
				}else if(selectIndex==1){
					if(inputNew.length()>0){
						inputNew = inputNew.substr(0,inputNew.length()-1);
					}
				}else if(selectIndex==2){
					if(inputAgain.length()>0){
						inputAgain = inputAgain.substr(0,inputAgain.length()-1);
					}
				}
			}
		}
		
		string temp[] = {"0","1","2","3","4","5","6","7","8","9"};
		int key[] = {M_KEY_0,M_KEY_1,M_KEY_2,M_KEY_3,M_KEY_4,M_KEY_5,M_KEY_6,M_KEY_7,M_KEY_8,M_KEY_9};
		for(int i = 0;i<10;i++){
			//if(isKeypressed(key[i])){
			if(testNumberKey==1008+i||testNumberKey==8+i){
				if(selectIndex==0&&inputOld.length()<8){
					inputOld+=temp[i];
				}else if(selectIndex==1&&inputNew.length()<8){
					inputNew+=temp[i];
				}else if(selectIndex==2&&inputAgain.length()<8){
					inputAgain+=temp[i];
				}
				testNumberKey = 0;
				showInfo("");
				break;
			}
		}
		//把字符串转换成“*”
		string old = "";
		for(int i = 0;i<inputOld.length();i++){
			old+="*";
		}
		oldPassword->setString(old.c_str());
		string newo = "";
		for(int i = 0;i<inputNew.length();i++){
			newo+="*";
		}
		newPassword->setString(newo.c_str());
		string agin = "";
		for(int i = 0;i<inputAgain.length();i++){
			agin+="*";
		}
		againPassword->setString(agin.c_str());
	}
	updateGuangbiao();
	
	keyReset();
	
}

void JiankongScreen::setTongsuo(string info){
	NetHander *net = new NetHander();
	net->setUserPassword(password,info);
	net->setCallBack(this);
	vecNet.push_back(net);
	isSeting = true;
}

void JiankongScreen::showInfo(string showInfo){
	messageInfo->setString(Globe::GBKToUTF(showInfo.c_str()).c_str());
	CCActionInterval *blin = CCBlink::create(1,4);
	CCActionInterval *fadin = CCFadeIn::create(0.1);
	CCActionInterval *seq = CCSequence::create(blin,fadin,NULL);
	messageInfo->runAction(seq);
}

void JiankongScreen::updateGuangbiao(){
	if(isFristSet){
		guangbiao->setOpacity((frm/6)%2==0&&selectIndex<2?100:0);

		if(selectIndex==0){
			guangbiao->setPosition(ccp(newPassword->getContentSize().width+newPassword->getPositionX(),newPassword->getPositionY()));
		}else if(selectIndex==1){
			guangbiao->setPosition(ccp(againPassword->getContentSize().width+againPassword->getPositionX(),againPassword->getPositionY()));
		}
	}else{
		guangbiao->setOpacity((frm/6)%2==0&&selectIndex<3?100:0);
		if(selectIndex==0){
			guangbiao->setPosition(ccp(oldPassword->getContentSize().width+oldPassword->getPositionX(),oldPassword->getPositionY()));
		}else if(selectIndex==1){
			guangbiao->setPosition(ccp(newPassword->getContentSize().width+newPassword->getPositionX(),newPassword->getPositionY()));
		}else if(selectIndex==2){
			guangbiao->setPosition(ccp(againPassword->getContentSize().width+againPassword->getPositionX(),againPassword->getPositionY()));
		}
	}
}

void JiankongScreen::draw(){

}

void JiankongScreen::clear(){

}

void JiankongScreen::back(){
	SWITCHTO_FATHER_SCREEN(ManageScreen);
}

void JiankongScreen::updateInput(){
	hasGetPassWord = true;
	if(password==""){
		isFristSet = true;
		kuang = CCSprite::create("screens/jiankong/show0.png");
		kuang->setAnchorPoint(ccp(0.5,0.5));
		kuang->setPosition(ccp(Globe::SW/2,Globe::SH/2-50));
		this->addChild(kuang,2);

		ccColor3B cc3bInfo = {75,203,255};
		//提示文字1
		CCLabelTTF *info = CCLabelTTF::create("type","Marker Felt",25);
		info->setAnchorPoint(ccp(0.5,0.5));
		info->setColor(cc3bInfo);
		info->setString(Globe::GBKToUTF("请设置您的童锁密码").c_str());
		info->setPosition(ccp(Globe::SW/2,540));
		this->addChild(info,2);

		ccColor3B cc3bInfo1 = {0,0,0};
				

		//新密码
		newPassword = CCLabelTTF::create("type","Marker Felt",25);
		newPassword->setAnchorPoint(ccp(0,1));
		newPassword->setColor(cc3bInfo1);
		newPassword->setString("");
		newPassword->setPosition(ccp(Globe::SW/2-30,345));
		this->addChild(newPassword,2);

		//新密码
		againPassword = CCLabelTTF::create("type","Marker Felt",25);
		againPassword->setAnchorPoint(ccp(0,1));
		againPassword->setColor(cc3bInfo1);
		againPassword->setString("");
		againPassword->setPosition(ccp(Globe::SW/2-30,280));
		this->addChild(againPassword,2);

		guangbiao = CCLabelTTF::create("type","Marker Felt",25);
		guangbiao->setAnchorPoint(ccp(0,1));
		guangbiao->setColor(cc3bInfo1);
		guangbiao->setString("|");
		guangbiao->setPosition(ccp(Globe::SW/2-30,345));
		this->addChild(guangbiao,2);

		btOk = MySprite::create("screens/jiankong/bt.png");
		btOk->setPosition(ccp(Globe::SW/2-130,150));
		CCSprite *ok = CCSprite::create("screens/jiankong/b0.png");
		ok->setAnchorPoint(ccp(0.5,0.5));
		ok->setPosition(ccp(btOk->getContentSize().width/2,btOk->getContentSize().height/2));
		btOk->addChild(ok,1);
		btOk->setSelectScale(1);
		this->addChild(btOk,2);

		btCancle = MySprite::create("screens/jiankong/bt.png");
		btCancle->setPosition(ccp(Globe::SW/2+130,150));
		CCSprite *can = CCSprite::create("screens/jiankong/b1.png");
		can->setAnchorPoint(ccp(0.5,0.5));
		can->setPosition(ccp(btCancle->getContentSize().width/2,btCancle->getContentSize().height/2));
		btCancle->addChild(can,1);
		btCancle->setSelectScale(1);
		this->addChild(btCancle,2);

		ccColor3B cc3bInfo2 = {255,255,255};
		//提示文字1
		messageInfo = CCLabelTTF::create("type","Marker Felt",25);
		messageInfo->setAnchorPoint(ccp(0.5,0.5));
		messageInfo->setColor(cc3bInfo2);
		messageInfo->setString("");
		messageInfo->setPosition(ccp(Globe::SW/2,450));
		this->addChild(messageInfo,2);


	}
	else{
		isFristSet = false;
		kuang = CCSprite::create("screens/jiankong/show1.png");
		kuang->setAnchorPoint(ccp(0.5,0.5));
		kuang->setPosition(ccp(Globe::SW/2,Globe::SH/2-50));
		this->addChild(kuang,2);

		ccColor3B cc3bInfo = {75,203,255};
		//提示文字1
		CCLabelTTF *info = CCLabelTTF::create("type","Marker Felt",25);
		info->setAnchorPoint(ccp(0.5,0.5));
		info->setColor(cc3bInfo);
		info->setString(Globe::GBKToUTF("输入旧密码后，再输入新密码，即可修改童锁密码").c_str());
		info->setPosition(ccp(Globe::SW/2,540));
		this->addChild(info,2);

		//提示文字2
		CCLabelTTF *info1 = CCLabelTTF::create("type","Marker Felt",25);
		info1->setAnchorPoint(ccp(0.5,0.5));
		info1->setColor(cc3bInfo);
		info1->setString(Globe::GBKToUTF("密码仅支持6位数字，新密码位空代表取消童锁。请谨慎修改，便于记忆。").c_str());
		info1->setPosition(ccp(Globe::SW/2,505));
		this->addChild(info1,2);


		ccColor3B cc3bInfo1 = {0,0,0};
		//旧密码
		oldPassword = CCLabelTTF::create("type","Marker Felt",25);
		oldPassword->setAnchorPoint(ccp(0,1));
		oldPassword->setColor(cc3bInfo1);
		oldPassword->setString("");
		oldPassword->setPosition(ccp(Globe::SW/2-30,376));
		this->addChild(oldPassword,2);

		//新密码
		newPassword = CCLabelTTF::create("type","Marker Felt",25);
		newPassword->setAnchorPoint(ccp(0,1));
		newPassword->setColor(cc3bInfo1);
		newPassword->setString("");
		newPassword->setPosition(ccp(Globe::SW/2-30,315));
		this->addChild(newPassword,2);

		//新密码
		againPassword = CCLabelTTF::create("type","Marker Felt",25);
		againPassword->setAnchorPoint(ccp(0,1));
		againPassword->setColor(cc3bInfo1);
		againPassword->setString("");
		againPassword->setPosition(ccp(Globe::SW/2-30,255));
		this->addChild(againPassword,2);

		guangbiao = CCLabelTTF::create("type","Marker Felt",25);
		guangbiao->setAnchorPoint(ccp(0,1));
		guangbiao->setColor(cc3bInfo1);
		guangbiao->setString("|");
		guangbiao->setPosition(ccp(Globe::SW/2-30,375));
		this->addChild(guangbiao,2);

		btOk = MySprite::create("screens/jiankong/bt.png");
		btOk->setPosition(ccp(Globe::SW/2-130,150));
		CCSprite *ok = CCSprite::create("screens/jiankong/b0.png");
		ok->setAnchorPoint(ccp(0.5,0.5));
		ok->setPosition(ccp(btOk->getContentSize().width/2,btOk->getContentSize().height/2));
		btOk->addChild(ok,1);
		btOk->setSelectScale(1);
		this->addChild(btOk,2);

		btCancle = MySprite::create("screens/jiankong/bt.png");
		btCancle->setPosition(ccp(Globe::SW/2+130,150));
		CCSprite *can = CCSprite::create("screens/jiankong/b1.png");
		can->setAnchorPoint(ccp(0.5,0.5));
		can->setPosition(ccp(btCancle->getContentSize().width/2,btCancle->getContentSize().height/2));
		btCancle->addChild(can,1);
		btCancle->setSelectScale(1);
		this->addChild(btCancle,2);

		ccColor3B cc3bInfo2 = {255,255,255};
		//提示文字1
		messageInfo = CCLabelTTF::create("type","Marker Felt",25);
		messageInfo->setAnchorPoint(ccp(0.5,0.5));
		messageInfo->setColor(cc3bInfo2);
		messageInfo->setString("");
		messageInfo->setPosition(ccp(Globe::SW/2,450));
		this->addChild(messageInfo,2);
	}
}

void JiankongScreen::call(string receive){
	bool get = false;
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			if(!isSeting){//获取到password以后
				password = root["Description"].asString();
				updateInput();
			}else{//设置password结果
				isSetEnd = true;
				string result = root["Description"].asString();
				if(result=="success"){
					setTingFrm = 0;
					showInfo("设置成功");
				}else{
					setTingFrm = 0;
					showInfo("设置失败，请重试!("+result+")");
				}
				password = inputNew;
			}
		}else{
			if(isSeting){
				isSetEnd = true;
				setTingFrm = 0;
				showInfo("设置失败，请重试!");
			}
		}
	}
}