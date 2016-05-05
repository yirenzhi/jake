#pragma once
#include "cocos2d.h"
#include "CCDirector.h"
#include "SimpleAudioEngine.h"
#include "JniHelper.h"
#include "jni.h"
#include "../json/json.h"
#include <iostream>  
#include "cocos-ext.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "iconv/include/iconv.h"
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "iconv\iconv.h"
#endif
#pragma comment(lib,"libiconv.lib")


//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//#include "Psapi.h"
//#pragma comment(lib,"Psapi.lib")
//#endif 

#define USING_STD using namespace std;

#define TOUCH_TGA 998

USING_NS_CC;
USING_STD;
USING_NS_CC_EXT;

/************************************************************************/
/* 开启内存泄露检测功能                                                                     */
/************************************************************************/
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)  
#include "vld.h"  
#endif 

/************************************************************************/
/* 调试模式的一些开关                                                                     */
/************************************************************************/
//#define GAME_ATTACK_TEST




#define CREATE_SCENE(__TYPE__) \
	static CCScene* createScene(bool is) \
{ \
	__TYPE__ *layer = __TYPE__::create();\
	CCScene *scene = CCScene::create();\
	scene->isShowSwitch = is;\
	scene->addChild(layer);\
	return scene;\
}


#define SWITCHTO_FATHER_SCREEN(__TYPE__) \
	removeTilesName(tileName);\
	if(needSaveDefaultFocas){\
		MyButton * current = getFocusButton();\
		if(current!=NULL){\
			hasPressedFocus[screenId] = current->rect;\
		}\
	}\
	currentCanvas = getCurrentRenderTexture();\
	Screen::clearDownload();\
	CCScene *scene = __TYPE__::createScene(false);\
	CCDirector::sharedDirector()->replaceScene(scene);\

#define SWITCHTO_CHILD_SCREEN(__TYPE__) \
	currentCanvas = NULL;\
	if(needSaveDefaultFocas){\
		MyButton * current = getFocusButton();\
		if(current!=NULL){\
			hasPressedFocus[screenId] = current->rect;\
		}\
	}\
	Screen::clearDownload();\
	CCScene *scene = __TYPE__::createScene(true);\
	CCScene::isShowSwitch = true;\
	CCDirector::sharedDirector()->replaceScene( CCTransitionCrossFade::create(0.3, scene));\
	//currentCanvas = getCurrentRenderTexture();\
	//CCScene *scene = __TYPE__::createScene();\
	//CCDirector::sharedDirector()->replaceScene(scene);\

#define SWITCHTO_SCREEN(__TYPE__) \
	currentCanvas = NULL;\
	removeTilesName(tileName);\
	Screen::clearDownload();\
	CCScene *scene = __TYPE__::createScene(false);\
	CCDirector::sharedDirector()->replaceScene(scene);\

#define ADD_SCREEN(__TYPE__){\
	currentCanvas = NULL;\
	focus->setOpacity(0);\
	Screen::clearDownload();\
	__TYPE__ *layer = __TYPE__::create();\
	layer->setFatherScreen(this);\
	this->addChild(layer,200);\
	this->setKeypadEnabled(false);\
	this->setTouchEnabled(false);\
	layer->setKeypadEnabled(true);\
	layer->setTouchEnabled(true);\
}

#define DELECT_SCREEN(){\
	Screen::clearDownload();\
	father->focus->setOpacity(255);\
	father->removeChild(this);\
	father->setKeypadEnabled(true);\
	father->setTouchEnabled(true);\
}


#define lenght(__TYPE__) sizeof(__TYPE__) / sizeof(__TYPE__[0])

#define CREATE_CONSTRUCOR(__TYPE__,id) \
	__TYPE__(){\
	this->screenId = id;\
	if(hasPressedFocus.find(id)!=hasPressedFocus.end()){\
		focusRectBuf = hasPressedFocus[id];\
	}\
this->setKeypadEnabled(true);\
this->setTouchEnabled(true);}\
	~__TYPE__(){\
Screen::clear();\
clear();}\

//typedef void (*HttpCallback)(string);
//#define httpCallback_selector(_SELECTOR) (HttpCallback)(&_SELECTOR)
 
using namespace CocosDenshion;

class Globe{

public:
	Globe();
	~Globe();


	typedef enum {
		ABOUT_SCREEN,
		ASKOPEN_SCREEN,
		GAMEINFO_SCREEN,
		GAMESHOW_SCREEN,
		HOMEPAGE_SCREEN,
		HUODONGINFO_SCREEN,
		HUODONG_SCREEN,
		LOGIN_SCREEN,
		MANAGE_SCREEN,
		MYGAME_SCREEN,
		UNINSTALL_SCREEN,
		VARIOUS_SCREEN,
		ZHUANTI_SCREEN,
		JIANKONG_SCREEN,
		CHAXUN_SCREEN,
	} SCREEN_ID;

	//static CCSpriteBatchNode* creatNumSprite(int num,string ddr);
	const static int SW = 1280;
	const static int SH = 720;
	static string intToString(int a);
	static int stringToInt(string a);
	static string floatToString(float f);
	static string intArrayToString(int *a,int lenght);
	static float abs(float a);

	static int getRandom(int end);

	static long getCurrentTime();

	static string replaceStr(string str);

	static float get02Float(float a);
	static string gameIconSavePath;
	static string gameShowSavePath;
	static string huodongSavaPath;
	static string gameApkSavePath;
	static string homePageSavaPaht;
	static string huodongDetailSavaPaht;
	static string zhuantiDetailSavaPaht;
	


	static bool rectContainsPoint(CCRect rect,CCPoint p);
	static CCActionInterval *moveForBeser(CCPoint p1,CCPoint p2,CCPoint air,float time);
	static void playBgSound(string sddr,bool isLoop);
	static void playEffect(string sddr);
	static void setSound(bool is);
	static bool isPlaySound;
	static void closeBgSound();
	static bool rectContainsTiles(CCRect rect,CCPoint p);
	static string callJava(string inr);
	static void sleep(long time);
	static void showMemoryLog();
	static string makeJsonString(string order,string info);

	static std::string UTFToGBK(const char *inbuf);
	static std::string GBKToUTF(const char *inbuf);

	static CCLabelTTF* horizontalSpacingANDverticalSpacing(string _string, const char *fontName, float fontSize, float horizontalSpacing, float verticalSpacing, float lineWidth,ccColor3B color);
private:
	static int code_convert(const char *from_charset, const char *to_charset, const char *inbuf, size_t inlen, char *outbuf, size_t outlen);

};



