#include "GameInfoScreen.h"
#include "HomePageScreen.h"
#include "MyGameScreen.h"
#include "VariousScreen.h"
#include "GameShowScreen.h"
#include "HuodongScreen.h"
#include "ZhuantiInfo.h"

string GameInfoScreen::gameId = "";
int GameInfoScreen::selectShowIconIndex = 0;
vector <MySprite *> GameInfoScreen::infoGame;
bool GameInfoScreen::init(){
	//getInfo();
	isNoticeInstallApk = false;
	hasInstallEndNotice = false;
	installingFrm = 0;
	templateApk = NULL;
	needSaveDefaultFocas = false;
	dakai = NULL;
	xiezai = NULL;
	install = NULL;
	jindu = NULL;
	hasInstall = false;
	setTilesName("游戏详情");
	addBgAndTile();
	callStage = 0;
	versionCode = "";
	for(int i = 0;i<lenght(tuijianGame);i++){
		tuijianGame[i] = NULL;
	}

	infoGame.clear();
	CCLog("gameId:::%s",gameId.c_str());
	NetHander *net = new NetHander();
	net->getApkDownloadUrl(gameId);
	net->setCallBack(this);
	vecNet.push_back(net);


	ccColor3B cc3bInfo = {75,203,255};
	

	word = NULL;
	
	
	


	//推荐游戏
	CCSprite *tuijianBg = CCSprite::create("screens/gameInfo/tuijianBg.png");
	tuijianBg->setPosition(ccp(955,620));
	tuijianBg->setAnchorPoint(ccp(0,1));
	this->addChild(tuijianBg,4);

	CCSprite *tuijian = CCSprite::create("screens/gameInfo/tuijian.png");
	tuijian->setPosition(ccp(962,610));
	tuijian->setAnchorPoint(ccp(0,1));
	this->addChild(tuijian,4);

	

    return Screen::init();
}


void GameInfoScreen::showGameInfo(){
	//icon
	//游戏名称
	int startY = 585;
	int startX = 165;
	CCSprite *tile = CCSprite::create("screens/gameInfo/tile.png");
	tile->setPosition(ccp(startX,startY));
	tile->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(tile,1);
	CCLabelTTF *word1 = CCLabelTTF::create("type","Marker Felt",40);
	ccColor3B cc3b = {255,255,255};
	word1->setAnchorPoint(ccp(0.5,0.5));
	word1->setColor(cc3b);
	word1->setString(gameName.c_str());
	word1->setPosition(ccp(startX,startY));
	this->addChild(word1,2);
	
	//游戏详情介绍背景
	CCSprite *infoBg = CCSprite::create("screens/gameInfo/infobg.png");
	infoBg->setPosition(ccp(300,300));
	infoBg->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(infoBg,2);

	MySprite *icon = MySprite::create("screens/public/laoding.png");
	icon->setAddMode(2);
	icon->setOpacity(0);
	icon->setPosition(ccp(150,425));
	float scanX = 165/icon->getContentSize().width;
	float scanY = 165/icon->getContentSize().height;
	icon->setScaleX(scanX);
	icon->setScaleY(scanY);
	
	icon->getImageFromUrl(iconPath,Globe::gameIconSavePath+"/"+gameId);
	vecDownLoadSprite.push_back(icon);
	this->addChildNoButton(icon,3);

	//信息
	int infoY = 495;
	int infoH = 35;
	ccColor3B cc3bInfo = {75,203,255};
	//推荐指数
	CCLabelTTF *wordTuijian = CCLabelTTF::create("type","Marker Felt",20);
	wordTuijian->setAnchorPoint(ccp(0,0.5));
	wordTuijian->setColor(cc3bInfo);
	wordTuijian->setString(Globe::GBKToUTF("推荐指数：").c_str());
	wordTuijian->setPosition(ccp(250,infoY));
	this->addChild(wordTuijian,2);

	for(int i = 0;i<tuijian;i++){
		CCSprite *tui = CCSprite::create("screens/gameInfo/xingxing.png");
		tui->setPosition(ccp(350+i*25,infoY));
		tui->setAnchorPoint(ccp(0.5,0.5));
		this->addChild(tui,2);
	}
	//下载次数
	CCLabelTTF *download = CCLabelTTF::create("type","Marker Felt",20);
	download->setAnchorPoint(ccp(0,0.5));
	download->setColor(cc3bInfo);
	download->setString((Globe::GBKToUTF("下载次数：")+downNum).c_str());
	download->setPosition(ccp(250,infoY-infoH));
	this->addChild(download,2);
	//文件大小
	CCLabelTTF *file = CCLabelTTF::create("type","Marker Felt",20);
	file->setAnchorPoint(ccp(0,0.5));
	file->setColor(cc3bInfo);
	file->setString((Globe::GBKToUTF("文件大小：")+filesize+Globe::GBKToUTF("MB")).c_str());
	file->setPosition(ccp(250,infoY-2*infoH));
	this->addChild(file,2);
	//版本号
	CCLabelTTF *banben = CCLabelTTF::create("type","Marker Felt",20);
	banben->setAnchorPoint(ccp(0,0.5));
	banben->setColor(cc3bInfo);
	banben->setString((Globe::GBKToUTF("版本号：")+version).c_str());
	banben->setPosition(ccp(250,infoY-3*infoH));
	this->addChild(banben,2);

	//开发商
	CCLabelTTF *kaifa = CCLabelTTF::create("type","Marker Felt",20);
	kaifa->setAnchorPoint(ccp(0,0.5));
	kaifa->setColor(cc3bInfo);
	kaifa->setString((Globe::GBKToUTF("开发商：")+about).c_str());
	kaifa->setPosition(ccp(250,infoY-4*infoH));
	this->addChild(kaifa,2);

	//游戏描述信息
	string inf = gameInfo;
	CCLabelTTF *info = Globe::horizontalSpacingANDverticalSpacing(inf,"Marker Felt",14,0,2,480,cc3bInfo);
	info->setPosition(ccp(65,320));
	this->addChild(info,2);

	//CCLabelTTF *info = CCLabelTTF::create("type","Marker Felt",15);
	//info->setAnchorPoint(ccp(0,1));
	//info->setColor(cc3bInfo);
	//info->setString(inf.c_str());
	//info->setHorizontalAlignment(kCCTextAlignmentLeft);
	//info->setDimensions(CCSize(480,120));
	//info->setPosition(ccp(65,320));
	//this->addChild(info,2);

	

	//遥控器和手柄
	CCSprite *yaokong = CCSprite::create("screens/gameInfo/yaokong.png");
	yaokong->setPosition(ccp(170,185));
	this->addChild(yaokong,3);
	CCSprite *the = CCSprite::create("screens/gameInfo/sele.png");
	the->setPosition(ccp(140,185));
	this->addChild(the,3);

	CCSprite *shoubing = CCSprite::create("screens/gameInfo/shoubing.png");
	shoubing->setPosition(ccp(420,185));
	this->addChild(shoubing,3);
}

void GameInfoScreen::call(string receive){
	callStage++;
	Reader reader;
	Value root;  
	if (reader.parse(receive, root)){
		if(root["Result"].asInt()==0){
			if(callStage==1){//获取到网络下载地址
				updateGetApk(root);
			}
			/*else if(callStage==2){
				updateVersion(root);
			}*/
			else if(callStage==2){//获取应用详情和3个游戏截图等
				updateGetGameInfo(root);
			}
			else if(callStage==3){//获取推荐位游戏信息
				updateGetTuijian(root);
			}
		}
	}
}

void GameInfoScreen::updateGetApk(Value value){
	apkDownloadUrl = value["Description"].asString();

	/*NetHander *net = new NetHander();
	net->getNewVersion(gameId);
	net->setCallBack(this);
	vecNet.push_back(net);*/

	NetHander *net = new NetHander();
	net->getAppDetail(gameId);
	net->setCallBack(this);
	vecNet.push_back(net);

}

	
void GameInfoScreen::updateVersion(Value value){
	string ver = hasInstallApk(packageName);
	Reader reader1;
	Value root1;
	reader1.parse(value["Description"].asString(),root1);
	for(int i = 0;i<root1.size();i++){
		if(Globe::replaceStr(root1[i]["AppID"].toStyledString())==gameId){
			string version = Globe::replaceStr(root1[i]["Version"].toStyledString());
			CCLog("version:%s|%s",version.c_str(),ver.c_str());
			if(ver!=""){
				if(Globe::stringToInt(version)<Globe::stringToInt(ver)){//有版本更新
					apkDownloadUrl = root1[i]["DownloadUrl"].asString();
				}
			}
			
			break;
		}
	}

	NetHander *net = new NetHander();
	net->getAppDetail(gameId);
	net->setCallBack(this);
	vecNet.push_back(net);

}

float GameInfoScreen::getJindu(){
	string save = getApkSavePathName(apkDownloadUrl);
	DownloadResTemplate *templateApk = getResDownTemplate(save);
	if(templateApk){
		if(templateApk->isDownLoadSuccess){
			return 100.0f;
		}else{
			return templateApk->down->jindu;
		}
	}else{
		return 0;
	}
}

void GameInfoScreen::updateGetGameInfo(Value root){
	Reader reader1;
	Value root1;
	reader1.parse(root["Description"].asString(),root1);
	gameInfo = root1["Description"].asString();
	downNum = Globe::intToString(root1["DownloadTime"].asInt());
	tuijian = Globe::stringToInt(root1["Grade"].toStyledString());
	iconPath = root1["Icon"].asString();
	gameName =  root1["Name"].asString();
	packageName = root1["PackageName"].asString();
	about = root1["Publisher"].asString();
	filesize = Globe::floatToString(root1["Size"].asDouble());
	versionCode = Globe::intToString(root1["VersionCode"].asInt());
	version =  root1["VersionName"].asString();
	showGameInfo();

	string has = hasInstallApk(packageName);
	if(has!=""&&Globe::stringToInt(has)>=Globe::stringToInt(versionCode)){//已经安装过,并且没有最新版

		hasInstall = true;
		//打开和卸载按钮
		dakai = MySprite::create("screens/gameInfo/select0.png");
		dakai->setPosition(ccp(170,120));
		this->addChild(dakai,3);
		xiezai = MySprite::create("screens/gameInfo/select1.png");
		xiezai->setPosition(ccp(420,120));
		this->addChild(xiezai,3);
		changeFocus(dakai);
	}else{
		hasInstall = false;
		install = MySprite::create("screens/gameInfo/bbt.png");
		install->setSelectScale(1);
		install->setPosition(ccp(300,120));
		this->addChild(install,3);
		changeFocus(install);

		if(has==""){//没有安装过
			anzhuang = CCSprite::create("screens/gameInfo/install.png");
		}else{
			anzhuang = CCSprite::create("screens/gameInfo/update.png");
		}
		
		anzhuang->setAnchorPoint(ccp(0.5,0.5));
		anzhuang->setPosition(ccp(install->getContentSize().width/2,install->getContentSize().height/2));
		install->addChild(anzhuang,5);

		
		
		jindu = CCSprite::create("screens/gameInfo/bbs.png");
		float sx = install->getContentSize().width/jindu->getContentSize().width;
		float sy = install->getContentSize().height/jindu->getContentSize().height;
		jindu->setScaleX(sx*getJindu()/100);
		jindu->setScaleY(sy);
		jindu->setAnchorPoint(ccp(0,0.5));
		jindu->setPosition(ccp(0,install->getContentSize().height/2));
		install->addChild(jindu,4);
	}
	string ScreenShots = root1["ScreenShots"].toStyledString();
	vector<string> vecShowIcon;
	Reader reader2;
	Value root2;
	reader2.parse(ScreenShots,root2);
	for(int i = 0;i<root2.size();i++){
		vecShowIcon.push_back(root2[i].asString());
	}
			
	//3张图片介绍
	for(int i = 0;i<vecShowIcon.size();i++){
		/*string path = "screens/gameInfo/t"+Globe::intToString(gameId)+"_"+Globe::intToString(i)+".png";
		infoGame[i] = MySprite::create(path.c_str());
		infoGame[i]->setPosition(ccp(760,530-186*i));
		this->addChild(infoGame[i],4);*/

		int faW = 318;
		int faH = 180;
		
		MySprite *temp = MySprite::create("screens/public/laoding.png");
		temp->setAddMode(2);
		//infoGame[i]->setOpacity(0);
		temp->setPosition(ccp(760,530-186*i));
		temp->setFactRect(CCRectMake(temp->getPositionX()-faW/2,
				temp->getPositionY()-faH/2,faW,faH));
		float scanX = faW/temp->getContentSize().width;
		float scanY = faH/temp->getContentSize().height;
		temp->setScaleX(scanX);
		temp->setScaleY(scanY);
		temp->getImageFromUrl(vecShowIcon[i],Globe::gameShowSavePath+"/"+gameId+"/"+Globe::intToString(i));
		vecDownLoadSprite.push_back(temp);
		this->addChild(temp,3);
		infoGame.push_back(temp);
	}
				

	NetHander *net = new NetHander();
	net->getRecommendApp();
	net->setCallBack(this);
	vecNet.push_back(net);
}


void GameInfoScreen::updateGetTuijian(Value root){
	string games = root["Description"].asString();
	Reader reader1;
	Value root1;
	reader1.parse(games,root1);

	vector <tuijianGameDetail> allTj;
	vector <tuijianGameDetail> overTj;
	//取到所有的推荐游戏
	for(int i = 0;i<root1.size();i++){
		Reader reader2;
		Value root2;
		reader2.parse(root1[i].toStyledString(),root2);
		tuijianGameDetail tem;
		tem.tjGameId = Globe::replaceStr(root2["AppID"].toStyledString());
		tem.tjInfo = root2["Description"].asString();
		tem.tjGrade = Globe::stringToInt(root2["Grade"].toStyledString());
		tem.tjIcon = root2["Icon"].asString();
		tem.tjName = root2["Name"].asString();
		allTj.push_back(tem);
	}
	if(allTj.size()>3){
		//从中取3个（不包含本身）
		//先去除掉本身的
		for(int i = 0;i<allTj.size();i++){
			if(allTj[i].tjGameId==gameId){
				allTj.erase(allTj.begin()+i);
				i--;
			}
		}
		if(allTj.size()<3){
			overTj = allTj;
		}else{
			for(int i = 0;i<3;i++){
			int rand = Globe::getRandom(allTj.size());
			overTj.push_back(allTj[rand]);
			allTj.erase(allTj.begin()+rand);
			}
		}
	}else{
		overTj = allTj;
	}
	for(int i = 0;i<overTj.size();i++){
		tuijianGame[i] = MySprite::create("screens/gameInfo/gameBg.png");
		MySprite *icon = MySprite::create("screens/public/laoding.png");
		icon->setAddMode(2);
		icon->setOpacity(0);
		icon->setPosition(ccp(0,0));
		float scanX = 150/icon->getContentSize().width;
		float scanY = 150/icon->getContentSize().height;
		icon->setScaleX(scanX);
		icon->setScaleY(scanY);
		icon->getImageFromUrl(overTj[i].tjIcon,Globe::gameIconSavePath+"/"+gameId);
		vecDownLoadSprite.push_back(icon);
					
		icon->setPosition(ccp(0,0));
		icon->setAnchorPoint(ccp(0,0));
		tuijianGame[i]->setAppId(overTj[i].tjGameId);
		tuijianGame[i]->addChild(icon,10);

		ccColor3B cc3bInfo = {75,203,255};
		CCLabelTTF *Tname = CCLabelTTF::create("type","Marker Felt",16);
		Tname->setAnchorPoint(ccp(0,0.5));
		Tname->setColor(cc3bInfo);
		Tname->setString(overTj[i].tjName.c_str());
		Tname->setPosition(ccp(150,130));
		tuijianGame[i]->addChild(Tname,10);
		for(int j = 0;j<overTj[i].tjGrade;j++){
			CCSprite *tx = CCSprite::create("screens/gameInfo/xingxing.png");
			tx->setPosition(ccp(162+j*20,105));
			tx->setScale(0.8);
			tuijianGame[i]->addChild(tx,10);
		}
		CCLabelTTF *info = CCLabelTTF::create("type","Marker Felt",12);
		info->setAnchorPoint(ccp(0,1));
		info->setColor(cc3bInfo);
		info->setString(overTj[i].tjInfo.c_str());
		info->setPosition(ccp(152,95));
		info->setHorizontalAlignment(kCCTextAlignmentLeft);
		info->setDimensions(CCSize(110,90));
		tuijianGame[i]->addChild(info,12);


		tuijianGame[i]->setPosition(ccp(1100,495-i*165));
		tuijianGame[i]->setAnchorPoint(ccp(0.5,0.5));
		this->addChild(tuijianGame[i],5);
	}
}




void GameInfoScreen::update(float ft){
	/*if(templateApk!=NULL){
		if(currDownloadApkPath==templateApk->pkgName){
			installingFrm++;
			if(installingFrm==200){
				Screen::install(templateApk->fullPath,templateApk->pkgName);
				currDownloadApkPath = "";
				installingFrm = 0;
			}
			return;
		}
	}*/
	if(isNoticeInstallApk){
		if(!hasInstallEndNotice){
			hasInstallEndNotice = true;
			Screen::install(templateApk->fullPath,templateApk->pkgName);
		}
	}
	
	if(dakai&&xiezai){
		if(dakai){
			if(dakai->isPress()){
				string str = packageName+"|"+Globe::intToString(screenId)+"%"+GameInfoScreen::gameId;
				Globe::callJava(Globe::makeJsonString("openGame",str));
			}
		}
		if(xiezai){
			if(xiezai->isPress()){
				hasInstallEndNotice = false;
				isNoticeInstallApk = false;
				Screen::unInstall(packageName);
			}
		}
		if(hasInstall){
			string has = hasInstallApk(packageName);
			if(has==""){//如果已经安装了，变成没安装，说明卸载掉了
				hasInstall = false;
				
				addInstallSprite();
			}
		}
	}
	else if(install){
		string save = getApkSavePathName(apkDownloadUrl);
		templateApk = getResDownTemplate(save);
		if(install->isPress()){
			if(!templateApk){//没下载过
				hasInstallEndNotice = false;
				isNoticeInstallApk = false;
				templateApk = new DownloadResTemplate();
				templateApk->down = new Download(apkDownloadUrl,save);
				templateApk->savePathName = save;
				string ablePath = MyFileUtils::getWritablePath();
				templateApk->fullPath = ablePath+save;
				templateApk->down->start();
				templateApk->isApk = true;
				templateApk->pkgName = packageName;
				templateApk->version = versionCode;
				vecDownLoadRes.push_back(templateApk);
				
			}else{
				if(!templateApk->isDownLoadSuccess){//没下载完
					templateApk->down->pause();
				}
				else{//下载完了,安装
					//Globe::sleep(2000);
					Screen::install(templateApk->fullPath,templateApk->pkgName);
				}
			}
		}
		//进度条变化
		if(jindu){
			float sx = install->getContentSize().width/jindu->getContentSize().width;
			float ji = getJindu();
			jindu->setScaleX(sx*ji/100);
			if(templateApk){
				if(!word){
					anzhuang->setOpacity(0);
					word = CCLabelTTF::create("type","Marker Felt",15);
					ccColor3B cc3b = {255,255,255};
					word->setAnchorPoint(ccp(1,0));
					word->setColor(cc3b);
					string sho = ("下载中："+Globe::floatToString(getJindu())+"%,按确认键暂停");
					word->setString(sho.c_str());
					word->setPosition(ccp(install->getContentSize().width-10,10));
					install->addChild(word,100);
				}
				if(!templateApk->isDownLoadSuccess){
					if(templateApk->down){
						if(templateApk->down->clsCurDown){
							if(templateApk->down->clsCurDown->isPause){
								if(word){
									string sho = ("已暂停,请按确认键继续");
									word->setString(Globe::GBKToUTF(sho.c_str()).c_str());
								}
							}else{
								if(word){
									string sho = ("下载中："+Globe::floatToString(getJindu())+"%,按确认键暂停");
									word->setString(Globe::GBKToUTF(sho.c_str()).c_str());
								}
							}
						}
					}
				}else{
					if(templateApk->isNotice){
						string sho = ("下载完成，请按确认键安装");
						word->setString(Globe::GBKToUTF(sho.c_str()).c_str());
						isNoticeInstallApk = true;
					}
				}
			}
		}
		if(!hasInstall){//没有安装过，变成已经安装完成了
			string has = hasInstallApk(packageName);
			if(has!=""&&has==versionCode){
				hasInstall = true;
				
				//打开和卸载按钮
				addDakaiXiezaiSprite();
			}
		}
	}
	
	for(int i = 0;i<lenght(tuijianGame);i++){
		if(tuijianGame[i]){
			if(tuijianGame[i]->isPress()){
				GameInfoScreen::gameId = tuijianGame[i]->appid;
				removeTilesName(tileName);
				SWITCHTO_CHILD_SCREEN(GameInfoScreen);
			}
		}
	}

	for(int i = 0;i<infoGame.size();i++){
		if(infoGame[i]){
			if(infoGame[i]->isPress()){
				selectShowIconIndex = i;
				ADD_SCREEN(GameShowScreen);
			}
		}
	}
	Screen::update(ft);
}

void GameInfoScreen::addDakaiXiezaiSprite(){
	word = NULL;
	this->removeChild(install);
	install = NULL;
	dakai = MySprite::create("screens/gameInfo/select0.png");
	dakai->setPosition(ccp(170,120));
	this->addChild(dakai,3);
	xiezai = MySprite::create("screens/gameInfo/select1.png");
	xiezai->setPosition(ccp(420,120));
	this->addChild(xiezai,3);
	changeFocus(dakai);
}

void GameInfoScreen::addInstallSprite(){
	this->removeChild(dakai);
	this->removeChild(xiezai);
	dakai = NULL;
	xiezai = NULL;
	install = MySprite::create("screens/gameInfo/bbt.png");
	install->setSelectScale(1);
	install->setPosition(ccp(300,120));
	changeFocus(install);
	anzhuang = CCSprite::create("screens/gameInfo/install.png");
	anzhuang->setAnchorPoint(ccp(0.5,0.5));
	anzhuang->setPosition(ccp(300,120));
	this->addChild(anzhuang,215);

		
	jindu = CCSprite::create("screens/gameInfo/bbs.png");
	float sx = install->getContentSize().width/jindu->getContentSize().width;
	float sy = install->getContentSize().height/jindu->getContentSize().height;
	jindu->setScaleX(sx*getJindu()/100);
	jindu->setScaleY(sy);
	jindu->setAnchorPoint(ccp(0,0.5));
	jindu->setPosition(ccp(0,install->getContentSize().height/2));
	install->addChild(jindu,4);
	this->addChild(install,3);
}

string GameInfoScreen::getApkSavePathName(string url){
	string name = url.substr(url.find_last_of("/")+1,url.length());
	return Globe::gameApkSavePath+"/"+gameId+"/"+name;
}

void GameInfoScreen::draw(){
	
}

void GameInfoScreen::clear(){
	
}

void GameInfoScreen::back(){
	if(hasTileName("分类")){
		SWITCHTO_FATHER_SCREEN(VariousScreen);
	}else if(hasTileName("我的游戏")){
		SWITCHTO_FATHER_SCREEN(MyGameScreen);
	}else if(hasTileName("专题")){
		SWITCHTO_FATHER_SCREEN(ZhuantiInfo);
	}else if(hasTileName("活动")){
		SWITCHTO_FATHER_SCREEN(HuodongScreen);
	}
	else{
		SWITCHTO_FATHER_SCREEN(HomePageScreen);
	}
		
}