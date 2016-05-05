#include "MySprite.h"


MySprite::MySprite(){
	MyButton::init(MYBUTTON_TYPE_SPRITE);
	setFather(NULL);
	setSelectScale(1.1);
	addMode = 0;
	isDefaultFocus = false;
	hasDownload = true;
	factRect = CCRectMake(0,0,0,0);
	initScalX = 1;
	initScalY = 1;
	showScanX = 1;
	showScanY = 1;
	hasGetUrlImage = false;
	down = NULL;
	fullPaht = "";
	saveName = "";
	isShow = false;
	cutY = 0;
}


MySprite::~MySprite(){

}

void MySprite::setSelectScale(float scale){
	this->selectScale = scale;
}

void MySprite::setFoucs(bool is){
	if(is){
		/*CCSprite *sprite = CCSprite::create("screens/public/foucs.png");
		float x = boundingBox().size.width/2;
		float y = boundingBox().size.height/2;
		sprite->setPosition(ccp(x,y));
		sprite->setAnchorPoint(ccp(0.5,0.5));
		this->addChild(sprite,this->getZOrder()+1);*/
		if(name!=""){
			int fontSize = 5+(rect.size.width+rect.size.height)/25;

			layerColor = CCSprite::create("screens/public/zhezhao.png");
			float scx = rect.size.width/layerColor->boundingBox().size.width;
			float scy = fontSize*1.8/layerColor->boundingBox().size.height;
			layerColor->setScaleX(scx/initScalX);
			layerColor->setScaleY(scy);
			
			layerColor->setOpacity(0);
			layerColor->setPosition(ccp(0,0));
			layerColor->setAnchorPoint(ccp(0,0));

			CCActionInterval *fain1 = CCFadeIn::create(0.5);
			layerColor->runAction(fain1);
			addChild(layerColor,201);
			//layerColor->stopAllActions();

			
			//layerColor->runAction(fain);

			string shouyeStr = name.c_str();
			
			word1 = CCLabelTTF::create("type","Marker Felt",fontSize);
			this->addChild(word1,201);
			ccColor3B cc3b = {255,255,255};
			word1->setAnchorPoint(ccp(0,0));
			word1->setColor(cc3b);
			word1->setString(shouyeStr.c_str());
			word1->setPosition(ccp(5+rect.size.width/30,5+fontSize/4));
			word1->stopAllActions();
			CCActionInterval *fain2 = CCFadeIn::create(0.5);
			word1->runAction(fain2);
		}
		zBur = this->getZOrder();
		this->setZOrder(200);
	}else{
		if(name!=""){
			removeChild(layerColor,false);
			removeChild(word1,false);
		}
		this->setZOrder(zBur);
	}
	resetChange();
}

MySprite* MySprite::create(const char *pszFileName)
{
    MySprite *pobSprite = new MySprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

//bool MySprite::hasDownLoaded(string url,string savepath){
//	string name = url.substr(url.find_last_of("/")+1,url.length());
//	string saveName = savepath+"/"+name;
//	string ablePath = MyFileUtils::getWritablePath();
//	string fullPaht = ablePath+saveName;
//	FILE *file = fopen(fullPaht.c_str(), "r");
//	if(file){
//
//	}else{
//
//	}
//}


void MySprite::getImageFromUrl(string url,string savepath)
{
	hasGetUrlImage = true;
	this->fromUrl = url;
	string name = url.substr(url.find_last_of("/")+1,url.length());
	this->inTheFolder = savepath;
	saveName = savepath+"/"+name;
	string ablePath = MyFileUtils::getWritablePath();
	this->fullPaht = ablePath+saveName;
	if(!replaceTexture2D(fullPaht)){
		hasDownload = false;
		DownloadResTemplate *templateApk = Screen::getResDownTemplate(saveName);
		if(!templateApk){//没下载过
			templateApk = new DownloadResTemplate();
			templateApk->down = new Download(url,saveName);
			templateApk->savePathName = saveName;
			templateApk->fullPath = ablePath+saveName;
			templateApk->down->start();
			templateApk->isApk = false;
			Screen::vecDownLoadRes.push_back(templateApk);
		}
		//down->autorelease();
	}else{
		isShow = true;
		if(isDefaultFocus){
			setTheDefaultFocus();
		}
	}
}


void MySprite::setTheDefaultFocus(){
	if(!fatherScreen->hasPressedFocusBuf()){
		for(int i = 0;i<fatherScreen->vecButtons.size();i++){
			fatherScreen->vecButtons[i]->setSelect(false);
		}
		this->setSelect(true);
	}
}


void MySprite::setCutY(int cut){
	cutY = cut;
}

void MySprite::setFather(MyScrollview *node){
	this->father = node;
}

void MySprite::downloadEnd(string path){
	this->saveDir = path;
	showDownLoad();
}

void MySprite::showDownLoad(){
	isShow = true;
	replaceTexture2D(this->saveDir);
	
	if(isDefaultFocus){
		setTheDefaultFocus();
	}
}

bool MySprite::replaceTexture2D(string path){
	CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(path.c_str());
	if(!texture){
		return false;
	}
	if(addMode == 0){//默认下载的图片与原图片大小相等
		this->setTexture(texture);
		this->setOpacity(255);
		if(!hasDownload){
			this->setOpacity(0);
			CCActionInterval *fadin = CCFadeIn::create(0.5);
			CCCallFuncN * funcall= CCCallFuncN::create(this, callfuncN_selector(MySprite::downloadEndCallBack));
			CCActionInterval *seq = CCSequence::create(fadin,funcall,NULL);
			this->runAction(seq);
		}
	}else if(addMode == 1){//如果下载之前不知道要下载的图片多大
		CCSize size = texture->getContentSize();
		this->setContentSize(size);
		CCRect rect1 = CCRectMake(0,0,size.width,size.height);
		
		this->setTexture(texture);
		this->setTextureRect(rect1, false, rect1.size);
		this->setOpacity(255);
		if(!hasDownload){
			this->setOpacity(0);
			CCActionInterval *fadin = CCFadeIn::create(0.5);
			CCCallFuncN * funcall= CCCallFuncN::create(this, callfuncN_selector(MySprite::downloadEndCallBack));
			CCActionInterval *seq = CCSequence::create(fadin,funcall,NULL);
			this->runAction(seq);
		}
	}if(addMode == 2){//把下载的图片贴在默认的图片上
		float w = this->getContentSize().width;
		float h = this->getContentSize().height;
		CCSprite *sp = CCSprite::createWithTexture(texture);
		sp->setAnchorPoint(ccp(0,1));
		float temp = (1-showScanX)/2;
		sp->setPosition(ccp(w*temp,h-temp*w));
		float sx = w/sp->boundingBox().size.width;
		float sy = (h-cutY)/sp->boundingBox().size.height;
		sp->setScaleX(sx*showScanX);
		sp->setScaleY(sy*showScanY);
		this->addChild(sp,10);
		this->setOpacity(255);
		if(!hasDownload){
			sp->setOpacity(0);
			CCActionInterval *fadin = CCFadeIn::create(1);
			CCCallFuncN * funcall= CCCallFuncN::create(this, callfuncN_selector(MySprite::downloadEndCallBack));
			CCActionInterval *seq = CCSequence::create(fadin,funcall,NULL);
			sp->runAction(seq);
		}
	}
	return true;
}

void MySprite::setShowScanXY(float sx,float sy){
	this->showScanX = sx;
	this->showScanY = sy;
}

void MySprite::setFactRect(CCRect rect){
	initScalX = rect.size.width/this->getContentSize().width;
	initScalY = rect.size.height/this->getContentSize().height;
	this->factRect = rect;
}

CCRect MySprite::getFactRect(){
	if(factRect.equals(CCRectMake(0,0,0,0))){
		float w = this->getContentSize().width;
		float h = this->getContentSize().height;
		return CCRectMake(
			this->boundingBox().getMidX()-w/2,
			this->boundingBox().getMidY()-h/2,
			w,h
		);
	}else{
		return factRect;
	}
}

void MySprite::downloadEndCallBack(CCNode *node){
	hasDownload = true;
}

void MySprite::setAddMode(int mode){
	addMode = mode;
}
void MySprite::setDefaultFocus(bool is,Screen *screen){
	isDefaultFocus = is;
	fatherScreen = screen;
}


void MySprite::setAppId(string id){
	this->appid = id;
}

void MySprite::setPkgName(string name){
	this->pkgName = name;
}

void MySprite::setAppType(string type){
	this->appType = type;
}
