#include "AppDelegate.h"
#include "screens/LoginScreen.h"
#include "screens/MyGameScreen.h"
#include "screens/HomePageScreen.h"
#include "screens/VariousScreen.h"
#include "screens/GameInfoScreen.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	//根据720P的大小来缩放
	pDirector->setOpenGLView(pEGLView);
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(1280,720,kResolutionExactFit);
	
    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);


	string stage = Globe::callJava(Globe::makeJsonString("getActivityStage",""));
	if(stage==""){//没保存过，说明是正常启动，
		//登陆页面
		// create a scene. it's an autorelease object
		CCScene *pScene = LoginScreen::createScene(false);
		pDirector->runWithScene(pScene);
	}else{//被非正常关闭，重启，直接跳转到那个页面
		CCLog("stage:::::%s",stage.c_str());
		int index = stage.find("%");
		int screenId = Globe::stringToInt(stage.substr(0,index));
		int gameId = Globe::stringToInt(stage.substr(index+1,stage.length()));
		CCLog("screenId:::::%d%d",screenId,gameId);
		NetHander::getInfo();
		if(screenId==Globe::MYGAME_SCREEN){
			CCScene *pScene = MyGameScreen::createScene(false);
			pDirector->runWithScene(pScene);
		}else if(screenId==Globe::GAMEINFO_SCREEN){
			GameInfoScreen::gameId = Globe::intToString(gameId);
			CCScene *pScene = GameInfoScreen::createScene(false);
			pDirector->runWithScene(pScene);
		}
	}

	

	//我的游戏页面
	/*CCScene *pScene = MyGameScreen::createScene();
	pDirector->runWithScene(pScene);*/

	//首页
	/*CCScene *pScene = VariousScreen::createScene(false);
	pDirector->runWithScene(pScene);*/
    // run
    

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
