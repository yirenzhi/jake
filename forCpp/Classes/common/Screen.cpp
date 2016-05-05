#include "Screen.h"

string Screen::currDownloadApkPath = "";
vector <string>Screen::vecTitlesName;
CCRenderTexture *Screen::currentCanvas = NULL;
map<int,CCRect> Screen::hasPressedFocus;
vector <MySprite *>Screen::vecDownLoadSprite;
vector <DownloadResTemplate *>Screen::vecDownLoadRes;
vector <string>Screen::vecHasInstallApk;
Screen::Screen(){
	needSaveDefaultFocas = true;
}

Screen::~Screen(void){
	
}


bool Screen::init(){
	testNumberKey = 0;
	frm = 0;
	gcFrm = 0;
	switchFrm = 0;
	isShowSwitchBack = true;
	backSprite = NULL;
	if(currentCanvas){//当前是父窗口,子窗口已经屏幕截图了
		CCSprite *sprite = CCSprite::createWithTexture(currentCanvas->getSprite()->getTexture());
		sprite->setFlipY(true);
		sprite->setAnchorPoint(ccp(0.5,0.5));
		sprite->setPosition(ccp(Globe::SW/2,Globe::SH/2));
		CCActionInterval * fadout = CCFadeOut::create(0.2);
		CCActionInterval * scanto = CCScaleTo::create(0.3,0,0);
		CCActionInterval * spaw = CCSpawn::create(fadout,scanto,NULL);
		sprite->runAction(spaw);
		addChild(sprite,220);
	}
	this->keyBuff = 0;
	this->setKeypadEnabled(true);
	hasSelectFocus = false;
	focus = CCSprite::create("screens/public/foucs.png");
	this->addChild(focus,200);
	focus->setPosition(ccp(-1000,-1000));

	if(isShowBack){
		backSprite = CCSprite::create("screens/public/back.png");
		backSprite->setAnchorPoint(ccp(1,0));
		backSprite->setPosition(ccp(Globe::SW-30,30));
		this->addChild(backSprite,150);
	}
	keyReset();
	scheduleUpdate();
	return true;
}



void Screen::addBgAndTile(){
	isShowBack = true;
	CCSprite* pSprite1 = CCSprite::create("screens/public/bg.png");
	pSprite1->setPosition(ccp(Globe::SW/2, Globe::SH/2));
	this->addChild(pSprite1, 1);
	
	
	int fontSize = 22;
	int startX = 1188;
	for(int i = 0;i<vecTitlesName.size();i++){
		string name = "";
		if(i==0){
			name = vecTitlesName[i];
		}else{
			name = vecTitlesName[i]+"<-";
		}
		string shouyeStr = Globe::GBKToUTF(name.c_str());
		CCLabelTTF *word1 = CCLabelTTF::create("type","Marker Felt",fontSize);
		this->addChild(word1,180);
		ccColor3B cc3b = {255,255,255};
		word1->setColor(cc3b);
		word1->setAnchorPoint(ccp(1,0.5));
		word1->setString(shouyeStr.c_str());
		word1->setPosition(ccp(startX,690));

		float width = word1->boundingBox().size.width;
		startX-=width;

		if(i==vecTitlesName.size()-1){//最后一个名称
			CCSprite *spriteWord = CCSprite::create("screens/public/wordBg.png");
			spriteWord->setScaleX((width/40));
			spriteWord->setPosition(ccp(startX+width/2-(i==0?0:fontSize/2),690));
			this->addChild(spriteWord,1);
		}
	}
	
}

void Screen::setFatherScreen(Screen *layer){
	this->father = layer;
}


void Screen::draw(){
	
}

MyButton * Screen::getFocusButton(){
	for(int i = 0;i<vecButtons.size();i++){
		if(vecButtons[i]->isSelect()){
			return vecButtons[i];
		}
	}
	if(vecButtons.size()>0){
		return vecButtons[0];
	}else{
		return NULL;
	}
}

float Screen::getNearQuanzhi(MyButton *btIn,MyButton *btAr,int way,bool isAll){
	float quanzhi = 0;
	if(!btIn->isMyParents(btAr)||isAll){//是否是他的上一级
		CCRect rect1 = btIn->rect;
		CCRect rect2 = btAr->rect;
		CCPoint p1 = ccp(rect1.getMidX()-rect1.size.width/2,rect1.getMidY()+rect1.size.height/2);
		CCPoint p2 = ccp(rect1.getMidX()+rect1.size.width/2,rect1.getMidY()+rect1.size.height/2);
		CCPoint p3 = ccp(rect1.getMidX()-rect1.size.width/2,rect1.getMidY()-rect1.size.height/2);
		CCPoint p4 = ccp(rect1.getMidX()+rect1.size.width/2,rect1.getMidY()-rect1.size.height/2);

		CCPoint pe1 = ccp(rect2.getMidX()-rect2.size.width/2,rect2.getMidY()+rect2.size.height/2);
		CCPoint pe2 = ccp(rect2.getMidX()+rect2.size.width/2,rect2.getMidY()+rect2.size.height/2);
		CCPoint pe3 = ccp(rect2.getMidX()-rect2.size.width/2,rect2.getMidY()-rect2.size.height/2);
		CCPoint pe4 = ccp(rect2.getMidX()+rect2.size.width/2,rect2.getMidY()-rect2.size.height/2);
		if(way==0){
			int chonghe = getChonghe(p1.x,p2.x,pe1.x,pe2.x);
			if(chonghe!=0&&rect2.getMidY()>rect1.getMidY()){
				int juli = pe3.y-p1.y;
				quanzhi = (float)chonghe*(rect1.getMidX()>rect2.getMidX()?2:1)/juli;
			}
		}else if(way==1){
			int chonghe = getChonghe(p1.x,p2.x,pe1.x,pe2.x);
			if(chonghe!=0&&rect2.getMidY()<rect1.getMidY()){
				int juli = p3.y-pe1.y;
				quanzhi = (float)chonghe*(rect1.getMidX()>rect2.getMidX()?2:1)/juli;
			}
		}else if(way==2){
			int chonghe = getChonghe(p3.y,p1.y,pe3.y,pe1.y);
			if(chonghe!=0&&rect2.getMidX()<rect1.getMidX()){
				int juli = p1.x-pe2.x;
				quanzhi = (float)chonghe*(rect1.getMidY()<rect2.getMidY()?2:1)/juli;
			}
		}else if(way==3){
			int chonghe = getChonghe(p3.y,p1.y,pe3.y,pe1.y);
			if(chonghe!=0&&rect2.getMidX()>rect1.getMidX()){
				int juli = pe1.x-p2.x;
				quanzhi = (float)chonghe*(rect1.getMidY()<rect2.getMidY()?2:1)/juli;
			}
		}
		if(quanzhi==0){//没重合部分
			float tem = 1;
			if(way==0){
				if(pe1.y>p1.y&&Globe::abs(rect2.getMidY()-rect1.getMidY())>2){
					int juli = Globe::abs(rect1.getMidX()-rect2.getMidX())+Globe::abs(rect1.getMidY()-rect2.getMidY());
					quanzhi = tem/juli;
				}
			}else if(way==1){
				if(pe3.y<p3.y&&Globe::abs(rect2.getMidY()-rect1.getMidY())>2){
					int juli = Globe::abs(rect1.getMidX()-rect2.getMidX())+Globe::abs(rect1.getMidY()-rect2.getMidY());
					quanzhi = tem/juli;
				}
			}else if(way==2){
				if(pe1.x<p1.x&&Globe::abs(rect2.getMidX()-rect1.getMidX())>2){
					int juli = Globe::abs(rect1.getMidX()-rect2.getMidX())+Globe::abs(rect1.getMidY()-rect2.getMidY());
					quanzhi = tem/juli;
				}
			}else if(way==3){
				if(pe2.x>p2.x&&Globe::abs(rect2.getMidX()-rect1.getMidX())>2){
					int juli = Globe::abs(rect1.getMidX()-rect2.getMidX())+Globe::abs(rect1.getMidY()-rect2.getMidY());
					quanzhi = tem/juli;
				}
			}
		}
	}
	return quanzhi;
}

int Screen::getChonghe(int x1,int x2,int x3,int x4){
	int ret = 0;
	if(x3<x1){
		if(x4<x1){
		}else if(x4>x2){
			ret = x2-x1;
		}else{
			ret = x4-x1;
		}
	}else if(x3<x2){
		if(x4<x2){
			ret = x4-x3;
		}else{
			ret = x2-x3;
		}
	}else{
		ret = 0;
	}
	return ret;
}

MyButton * Screen::getNearBotton(MyButton *in,int way){
	MyButton *nearButton = in;
	float quanzhi = 0;
	int index = 0;
	for(int i = 0;i<vecButtons.size();i++){
		if(vecButtons[i]->type==MYBUTTON_TYPE_SPRITE&&in->type==MYBUTTON_TYPE_SPRITE){
			MySprite *sp = (MySprite *)vecButtons[i];
			MySprite *insprite = (MySprite *)in;
			if(in==vecButtons[i]){
					continue;
			}
			if(!insprite->hasDownload&&insprite->addMode==1){
					continue;
			}
			if(!sp->hasDownload&&sp->addMode==1){
				continue;
			}
			float cur = getNearQuanzhi(in,vecButtons[i],way,false);
			//CCLog("cur:vecButtons[%d]:,%f,%f,%f",i,vecButtons[i]->rect.origin.x,vecButtons[i]->rect.origin.y,cur);
			if(cur>quanzhi){
				index = i;
				quanzhi = cur;
			}
		}
	}
	//说明有取到过
	if(quanzhi!=0){
		//CCLog("getNear:%d,%f",index,quanzhi);
		return vecButtons[index];
	}else{
		for(int i = 0;i<vecButtons.size();i++){
			if(vecButtons[i]->type==MYBUTTON_TYPE_SPRITE&&in->type==MYBUTTON_TYPE_SPRITE){
				MySprite *sp = (MySprite *)vecButtons[i];
				MySprite *insprite = (MySprite *)in;
				if(in==vecButtons[i]){
					continue;
				}
				if(!insprite->hasDownload&&insprite->addMode==1){
					continue;
				}
				if(!sp->hasDownload&&sp->addMode==1){
					continue;
				}
				float cur = getNearQuanzhi(in,vecButtons[i],way,true);
				//CCLog("cur:vecButtons[%d]:,%f,%f,%f",i,vecButtons[i]->rect.origin.x,vecButtons[i]->rect.origin.y,cur);
				if(cur>quanzhi){
					quanzhi = cur;
				}
			}
		}
		if(quanzhi!=0){
			if(in->myselfParent){
				return in->myselfParent;
			}
		}
	}
	return nearButton;
}

void Screen::update(float ft){
	if(gcFrm<200){
		gcFrm++;
	}else{
		gcFrm = 0;
		Globe::callJava(Globe::makeJsonString("gc",""));
	}
	
	for(int i = 0;i<vecDownLoadSprite.size();i++){//下载完成的图片通知显示
	if(!vecDownLoadSprite[i]->isShow){
			DownloadResTemplate *templateApk = getResDownTemplate(vecDownLoadSprite[i]->saveName);
			if(templateApk){
				if(templateApk->isDownLoadSuccess){
					templateApk->isNotice = true;
					vecDownLoadSprite[i]->downloadEnd(templateApk->fullPath);
				}
			}
		}
	}
	for(int i = 0;i<vecDownLoadRes.size();i++){//下载完成apk通知安装
		if(vecDownLoadRes[i]->isDownLoadSuccess&&!vecDownLoadRes[i]->isNotice){//下载完了并且没有通知安装过
			if(vecDownLoadRes[i]->isApk){
				vecDownLoadRes[i]->isNotice = true;
				//currDownloadApkPath = vecDownLoadRes[i]->pkgName;
				//install(vecDownLoadRes[i]->fullPath,vecDownLoadRes[i]->pkgName);
				break;
			}
		}else if(vecDownLoadRes[i]->isDownLoadSuccess&&vecDownLoadRes[i]->isNotice){//下载完了，也通知安装了,检测是否安装完了
			if(vecDownLoadRes[i]->isApk){
				string has = hasInstallApk(vecDownLoadRes[i]->pkgName);
				if(has!=""&&has==vecDownLoadRes[i]->version){//已经安装好了，删除文件
					MyFileUtils::deleteFile(vecDownLoadRes[i]->fullPath);
					vecDownLoadRes.erase(vecDownLoadRes.begin()+i);
					break;
				}
			}else{
				if(!vecDownLoadRes[i]->isDownLoadSuccess){
					vecDownLoadRes[i]->down->close();
				}
				delete vecDownLoadRes[i];
				vecDownLoadRes.erase(vecDownLoadRes.begin()+i);
			}
		}
	}

	if(switchFrm<50){
		switchFrm++;
		if(switchFrm>15){
			isShowSwitchBack = false;
		}
	}
	if(isKeypressed(M_KEY_SOFT_R)){
		back();
	}
	

	MyButton * current = getFocusButton();
	if(!current){
		return;
	}
	for(int i = 0;i<vecButtons.size();i++){
		if(vecButtons[i]->type==MYBUTTON_TYPE_SPRITE){
			MySprite *sprite = (MySprite *)vecButtons[i];
			sprite->setPressedRect(sprite->getFactRect(),sprite->father);
		}
	}
	if(isKeypressed(M_KEY_UP)){
		MyButton * nearButton = getNearBotton(current,0);
		if(current!=nearButton){
			current->setSelect(false);
			nearButton->setCurrentMoveEvent(MyButton::UP);
			nearButton->setSelect(true);
		}
		keyReset();
	}else if(isKeypressed(M_KEY_DOWN)){
		MyButton * nearButton = getNearBotton(current,1);
		if(current!=nearButton){
			current->setSelect(false);
			nearButton->setCurrentMoveEvent(MyButton::DOWN);
			nearButton->setSelect(true);
		}
		keyReset();
	}else if(isKeypressed(M_KEY_LEFT)){
		MyButton * nearButton = getNearBotton(current,2);
		if(current!=nearButton){
			current->setSelect(false);
			nearButton->setCurrentMoveEvent(MyButton::LEFT);
			nearButton->setSelect(true);
		}
		keyReset();
	}else if(isKeypressed(M_KEY_RIGHT)){
		MyButton * nearButton = getNearBotton(current,3);
		if(current!=nearButton){
			current->setSelect(false);
			nearButton->setCurrentMoveEvent(MyButton::RIGHT);
			nearButton->setSelect(true);
		}
		keyReset();
	}else if(isKeypressed(M_KEY_OK)){
		current->setPressed();
		keyReset();
	}

	float time = 0.12;
	for(int i = 0;i<vecButtons.size();i++){
		if(vecButtons[i]->type==MYBUTTON_TYPE_SPRITE){
			MySprite *sprite = (MySprite *)vecButtons[i];
			float scanFlagX = sprite->selectScale*sprite->initScalX;
			float scanFlagY = sprite->selectScale*sprite->initScalY;
			if(sprite->getChangeFlag()==1){
				if(!hasSelectFocus){
					float scx = sprite->rect.size.width/360;
					float scy = sprite->rect.size.height/360;
					focus->setPosition(ccp(sprite->rect.getMidX(),sprite->rect.getMidY()));
					focus->setScaleX(scx*sprite->selectScale);
					focus->setScaleY(scy*sprite->selectScale);
					hasSelectFocus = true;
					sprite->setScaleX(scanFlagX);
					sprite->setScaleY(scanFlagY);
				}else{
					focus->stopAllActions();
					
					//focus->setScale(1/scanFlag);
					float scx = sprite->rect.size.width/360;
					float scy = sprite->rect.size.height/360;
					float endX = sprite->rect.getMidX();
					float endY = sprite->rect.getMidY();

					if(sprite->father){//scrollview里面的
						sprite->father->stopAllActions();
						int x = sprite->rect.origin.x+sprite->rect.size.width/2;
						int y = sprite->rect.origin.y+sprite->rect.size.height/2;
						if(sprite->father->touchType==MyScrollview::UP_DOWN){//上下模式
							int dyDown = y-sprite->father->everoneSize.height/2;//最下面边的坐标Y
							int dyUp = y+sprite->father->everoneSize.height/2;//最上面边的坐标Y
							if(dyDown<sprite->father->startY){//最下一条边到了屏幕外
								sprite->father->doMoveUpDown(sprite->father->startY-dyDown);
								endY = sprite->father->startY+sprite->father->everoneSize.height/2;
							}else if(dyUp>sprite->father->endY){//最上一条边到了屏幕外
								sprite->father->doMoveUpDown(-(dyUp-sprite->father->endY));
								endY = sprite->father->endY-sprite->father->everoneSize.height/2;
							}
						}else if(sprite->father->touchType==MyScrollview::LEFT_RIGHT){//上下模式
							
							int dxLeft = x-sprite->father->everoneSize.width/2;//最左面边的坐标X
							int dxRight = x+sprite->father->everoneSize.width/2;//最右面边的坐标X
							int maxX = Globe::SW/2+200;
							int minX = Globe::SW/2-200;
							if(dxLeft<minX){//最下一条边到了屏幕外
								sprite->father->doMoveLeftRight(minX-dxLeft);
								endX = minX+sprite->father->everoneSize.width/2;
							}else if(dxRight>maxX){//最上一条边到了屏幕外
								sprite->father->doMoveLeftRight(-(dxRight-maxX));
								endX = maxX-sprite->father->everoneSize.width/2;
							}
						}
					}
					CCActionInterval * scato = CCScaleTo::create(time,scx,scy);
					CCActionInterval * moveto = CCMoveTo::create(time,ccp(endX,endY));
					CCActionInterval * scato2 = CCScaleTo::create(time,scx*sprite->selectScale,scy*sprite->selectScale);
					CCFiniteTimeAction * spawn =CCSpawn::create(scato,moveto,NULL);

					/*CCActionInterval * tinto1 = CCScaleTo ::create(0.5,2);
					CCActionInterval * tinto2 = CCScaleTo ::create(0.5,1);
					CCFiniteTimeAction * seq2= CCSequence::create(tinto1,tinto2,NULL);  
					CCActionInterval * repeatForever =CCRepeatForever::create((CCActionInterval* )seq2);  */
					CCFiniteTimeAction * seq1= CCSequence::create(spawn,scato2,NULL);
					focus->runAction(seq1);

					CCActionInterval * delay = CCDelayTime::create(time);
					CCActionInterval * scanto1 = CCScaleTo::create(time,scanFlagX,scanFlagY);
					CCFiniteTimeAction * seq= CCSequence::create(delay,scanto1,NULL);  
					sprite->runAction(seq);
					

				}
				sprite->setFoucs(true);
				focus->setZOrder(sprite->getZOrder()+1);
			}else if(sprite->getChangeFlag()==2){
				sprite->stopAllActions();
				sprite->setFoucs(false);
				CCActionInterval * scanto = CCScaleTo::create(time,sprite->initScalX,sprite->initScalY);
				sprite->runAction(scanto);
			}
		}
	}
}



void Screen::addCanTouchPoint(MyButton *button){
	vecButtons.push_back(button);
}

void Screen::clear(){
	for(int i = 0;i<vecNet.size();i++){
		vecNet[i]->close();
	}
	vecNet.clear();
}



//void Screen::removeDownloading(string saveName){
//	for(int i = 0;i<vecLoaingRes.size();i++){
//		if(vecLoaingRes[i]==saveName){
//			vecLoaingRes.erase(vecLoaingRes.begin()+i);
//			break;
//		}
//	}
//}
//
//bool Screen::isDownloadingRes(string saveName){
//	for(int i = 0;i<vecLoaingRes.size();i++){
//		if(vecLoaingRes[i]==saveName){
//			return true;
//		}
//	}
//	return false;
//}


DownloadResTemplate* Screen::getResDownTemplate(string saveName){
	for(int i = 0;i<vecDownLoadRes.size();i++){
		if(vecDownLoadRes[i]->savePathName==saveName){
			return vecDownLoadRes[i];
		}
	}
	return NULL;
}

void Screen::clearDownload(){
	//for(int i = 0;i<vecDownLoadRes.size();i++){
	//	if(!vecDownLoadRes[i]->isDownLoadSuccess){
	//		vecDownLoadRes[i]->down->close();
	//	}
	//}
	vecDownLoadSprite.clear();
}


void Screen::keyBackClicked(){
	if(CCScene::isShowSwitch){
		return;
	}
	Screen::keyBuff = Screen::keyBuff|M_KEY_SOFT_R;
}

void Screen::keyMenuClicked(){
	if(CCScene::isShowSwitch){
		return;
	}
	Screen::keyBuff = Screen::keyBuff|M_KEY_MENU;
}

void Screen::keyArrowClicked(int arrow){
	testNumberKey = arrow;
	if(CCScene::isShowSwitch){
		return;
	}
	testNumberKey+=1000;
	if (arrow == kTypeLeftArrowClicked)  
	{  
		// 左方向键按下
		Screen::keyBuff = Screen::keyBuff|M_KEY_LEFT;
	}  
	else if (arrow == kTypeRightArrowClicked)  
	{  
		// 右方向键按下
		Screen::keyBuff = Screen::keyBuff|M_KEY_RIGHT;
	}  

	if (arrow == kTypeUpArrowClicked)  
	{  
		// 上方向键按下  
		Screen::keyBuff = Screen::keyBuff|M_KEY_UP;
	}  
	else if (arrow == kTypeDownArrowClicked)  
	{  
		// 下方向键按下  
		Screen::keyBuff = Screen::keyBuff|M_KEY_DOWN;
	} 

	if (arrow == kType0ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_0;
	} 
	else if (arrow == kType1ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_1;
	} 
	else if (arrow == kType2ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_2;
	} 
	else if (arrow == kType3ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_3;
	} 
	else if (arrow == kType4ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_4;
	} 
	else if (arrow == kType5ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_5;
	} 
	else if (arrow == kType6ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_6;
	} 
	else if (arrow == kType7ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_7;
	} 
	else if (arrow == kType8ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_8;
	} 
	else if (arrow == kType9ArrowClicked)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff|M_KEY_9;
	} 
}

void Screen::keyEnterClicked()  
{  
	// Enter键按下  
	if(CCScene::isShowSwitch){
		return;
	}
	Screen::keyBuff = Screen::keyBuff|M_KEY_OK;
}  


void Screen::keyBackReleased(){
	if(CCScene::isShowSwitch){
		return;
	}
	Screen::keyBuff = Screen::keyBuff&(~M_KEY_SOFT_R);

}

void Screen::keyMenuReleased(){
	if(CCScene::isShowSwitch){
		return;
	}
	Screen::keyBuff = Screen::keyBuff&(~M_KEY_MENU);
}

void Screen::keyArrowReleased(int arrow){
	if(CCScene::isShowSwitch){
		return;
	}
	if (arrow == kTypeLeftArrowReleased)  
	{  
		// 左方向键松开
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_LEFT);
	}  
	else if (arrow == kTypeRightArrowReleased)  
	{  
		// 右方向键松开
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_RIGHT);
	}  

	if (arrow == kTypeUpArrowReleased)  
	{  
		// 上方向键松开  
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_UP);
	}  
	else if (arrow == kTypeDownArrowReleased)  
	{  
		// 下方向键松开  
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_DOWN);
	}  

	if (arrow == kType0ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_0);
	} 
	else if (arrow == kType1ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_1);
	} 
	else if (arrow == kType2ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_2);
	} 
	else if (arrow == kType3ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_3);
	} 
	else if (arrow == kType4ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_4);
	} 
	else if (arrow == kType5ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_5);
	} 
	else if (arrow == kType6ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_6);
	} 
	else if (arrow == kType7ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_7);
	} 
	else if (arrow == kType8ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_8);
	} 
	else if (arrow == kType9ArrowReleased)  
	{  
		// 数字键0
		Screen::keyBuff = Screen::keyBuff&(~M_KEY_9);
	} 
}

void Screen::keyEnterReleased()  
{  
	if(CCScene::isShowSwitch){
		return;
	}
	// Enter键松开  
	Screen::keyBuff = Screen::keyBuff&(~M_KEY_OK);
}  

bool Screen::isKeypressed(int key){
	if(CCScene::isShowSwitch){
		return false;
	}
	if(isKeypadEnabled()){
		if((Screen::keyBuff & key) == key){
			Screen::canClearKeycode = true;
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
	
}

void Screen::keyReset() {
	if(Screen::canClearKeycode){
		Screen::keyBuff = 0;
		Screen::canClearKeycode = false;
	}
}




/************************************************************************/
/* alph 0到255之间                                                                     */
/************************************************************************/
CCLayerColor* Screen::creatLayerColor(float w,float h,float alph){
	CCLayerColor* layerColor = CCLayerColor::create();  

	layerColor->setColor(ccc3(0, 0, 0));  

	layerColor->setOpacity(alph);  

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();  

	layerColor->setContentSize(CCSizeMake(w, h));
	return layerColor;
}

CCRenderTexture* Screen::getCurrentRenderTexture(){
	CCSize size = CCDirector::sharedDirector()->getWinSize();  

	CCRenderTexture* renderTexture = CCRenderTexture::create(size.width, size.height);  
	renderTexture->retain();  
	CCScene *s = CCDirector::sharedDirector()->getRunningScene();  

	renderTexture->begin();  
	s->visit();  
	renderTexture->end();
	return renderTexture;
}


void Screen::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
	//CCLayer::ccTouchesBegan(pTouches,pEvent);
	if(CCScene::isShowSwitch||isShowSwitchBack){
		return;
	}
	CCPoint point = convertTouchToNodeSpace((CCTouch*)pTouches->anyObject());
	for(int i = 0;i<vecButtons.size();i++){
		if(Globe::rectContainsPoint(vecButtons[i]->rect,point)){
			vecButtons[i]->pressed[0] = 1;
		}
	}
}

void Screen::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){
	//CCLayer::ccTouchesMoved(pTouches,pEvent);
	if(CCScene::isShowSwitch||isShowSwitchBack){
		return;
	}
}

void Screen::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent){
	//CCLayer::ccTouchesEnded(pTouches,pEvent);
	if(CCScene::isShowSwitch||isShowSwitchBack){
		return;
	}
	CCPoint point = convertTouchToNodeSpace((CCTouch*)pTouches->anyObject());
	for(int i = 0;i<vecButtons.size();i++){
		if(Globe::rectContainsPoint(vecButtons[i]->rect,point)){
			vecButtons[i]->pressed[1] = 1;
		}
	}

	if(backSprite){
		if(Globe::rectContainsPoint(backSprite->boundingBox(),point)){
			back();
		}
	}

}

void Screen::back(){

}

void Screen::addChild(MySprite * child){
	CCLayer::addChild(child);
	addMySprite(child);
}
    
void Screen::addChild(MySprite * child, int zOrder){
	CCLayer::addChild(child,zOrder);
	child->zBur = zOrder;
	addMySprite(child);
}

void Screen::addChildNoButton(MySprite * child, int zOrder){
	CCLayer::addChild(child,zOrder);
	child->zBur = zOrder;
}
   
void Screen::addChild(MySprite* child, int zOrder, int tag){
	CCLayer::addChild(child,zOrder,tag);
	child->zBur = zOrder;
	addMySprite(child);
}

void Screen::addMySprite(MySprite * child){
	//MyButton *buton = (MyButton *)child;
	addCanTouchPoint(child);
	CCRect ret = child->getFactRect();
	child->setPressedRect(ret,child->father);
	if(hasPressedFocusBuf()){
		if(focusRectBuf.equals(child->rect)){
			for(int i = 0;i<vecButtons.size();i++){
				vecButtons[i]->setSelect(false);
			}
			child->setSelect(true);
		}
	}
}

void Screen::removeChild(MySprite *child){
	for(int i = 0;i<vecButtons.size();i++){
		MyButton *bu = child;
		if(bu==vecButtons[i]){
			vecButtons.erase(vecButtons.begin()+i);
			break;
		}
	}
	CCLayer::removeChild(child);
}

void Screen::removeChild(CCNode *child){
	CCLayer::removeChild(child);
}

void Screen::setFocus(MySprite *sprite){
	if(!hasPressedFocusBuf()||!needSaveDefaultFocas){
		sprite->setSelect(true);
	}
}

void Screen::changeFocus(MySprite *sprite){
	for(int i = 0;i<vecButtons.size();i++){
		vecButtons[i]->setSelect(false);
	}
	sprite->setSelect(true);
}

bool Screen::hasPressedFocusBuf(){
	return !focusRectBuf.equals(CCRectMake(0,0,0,0));
}

void Screen::removeAllChildren(){
	CCLayer::removeAllChildren();
	vecButtons.clear();
}

void Screen::addChild(CCNode * child){
	CCLayer::addChild(child);
}
    
void Screen::addChild(CCNode * child, int zOrder){
	CCLayer::addChild(child,zOrder);
}
   
void Screen::addChild(CCNode* child, int zOrder, int tag){
	CCLayer::addChild(child,zOrder,tag);
}

void Screen::removeTilesName(string name){
	for(int i = 0;i<vecTitlesName.size();i++){
		if(vecTitlesName[i]==name){
			vecTitlesName.erase(i+vecTitlesName.begin());
			break;
		}
	}
}

bool Screen::hasTileName(string name){
	bool has = false;
	for(int i = 0;i<vecTitlesName.size();i++){
		if(vecTitlesName[i]==name){
			has = true;
			break;
		}
	}
	return has;
}

void Screen::setTilesName(string name){
	this->tileName = name;
	bool has = hasTileName(name);
	if(!has){
		vecTitlesName.push_back(name);
	}
}

void Screen::install(string path,string pkgName){
	vecHasInstallApk.push_back(pkgName);
	Globe::callJava(Globe::makeJsonString("install",path));
}
void Screen::unInstall(string pkgname){
	for(int i = 0;i<vecHasInstallApk.size();i++){
		if(vecHasInstallApk[i]==pkgname){
			vecHasInstallApk.erase(vecHasInstallApk.begin()+i);
			break;
		}
	}
	Globe::callJava(Globe::makeJsonString("unInstall",pkgname));
}

string Screen::hasInstallApk(string pkgname){

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	for(int i = 0;i<vecHasInstallApk.size();i++){
		if(vecHasInstallApk[i]==pkgname){
			return "";
		}
	}
	return "";
#endif

	string get= Globe::makeJsonString("isInstallApk",pkgname);
	string has = Globe::callJava(get);
	return has;
}
