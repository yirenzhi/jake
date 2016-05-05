#pragma once
#include "Globe.h"
#include "MySprite.h"
#include "MyScrollview.h"
#include "DownloadResTemplate.h"
#include "MyScrollviewThumbnail.h"
#include "..\net\download\DownloadObject.h"
#include "..\net\NetHander.h"
#include "..\net\download\Download.h"
#include "..\net\Callback.h"
#include <map>

class MySprite;
class Screen : public CCLayer
{
public:

	Screen(void);
	~Screen(void);

	

	int keyBuff;
	bool canClearKeycode;
	bool isKeypressed(int keycode);
	void keyReset();
	int gcFrm;

	CCSprite *backSprite;
	CCRenderTexture* getCurrentRenderTexture();

	//当前界面的截图
	static CCRenderTexture *currentCanvas;
	
	CCSprite *focus;
	bool needSaveDefaultFocas;
	bool hasSelectFocus;

	int testNumberKey;

	virtual bool init(void);
	virtual void draw(void);
	virtual void update(float dt);
	virtual void clear(void);
	virtual void back(void);

	void setFatherScreen(Screen *layer);

	
	
	void setFocus(MySprite *sprite);
	bool isShowSwitchBack;
	int switchFrm;

	float showScale;
	Screen *father;
	vector <MyButton *> vecButtons;
	void addCanTouchPoint(MyButton *button);
	static vector <string> vecTitlesName;
	static map <int,CCRect> hasPressedFocus;
	CCRect focusRectBuf;
	void addBgAndTile();
	string tileName;
	int screenId;
	int frm;
	CCLayerColor* creatLayerColor(float w,float h,float alph);

	const static int M_KEY_UP = 1 << 24;
	const static int M_KEY_DOWN = 1 << 23;
	const static int M_KEY_LEFT = 1 << 22;
	const static int M_KEY_RIGHT = 1 << 21;
	const static int M_KEY_OK = 1 << 20;
	const static int M_KEY_SOFT_R = 1 << 19;// right soft key
	const static int M_KEY_MENU = 1 << 18;// right soft key
	const static int M_KEY_0 = 1<<17;
	const static int M_KEY_1 = 1<<16;
	const static int M_KEY_2 = 1<<15;
	const static int M_KEY_3 = 1<<14;
	const static int M_KEY_4 = 1<<13;
	const static int M_KEY_5 = 1<<12;
	const static int M_KEY_6 = 1<<11;
	const static int M_KEY_7 = 1<<10;
	const static int M_KEY_8 = 1<<9;
	const static int M_KEY_9 = 1<<8;

	void addMySprite(MySprite * child);

	void addChild(MySprite * child);
    
    void addChild(MySprite * child, int zOrder);

	void addChildNoButton(MySprite * child, int zOrder);
   
    void addChild(MySprite* child, int zOrder, int tag);

	void addChild(CCNode * child);
    
    void addChild(CCNode * child, int zOrder);
   
    void addChild(CCNode* child, int zOrder, int tag);

	void removeChild(MySprite *child);
	void removeChild(CCNode *child);

	static void clearDownload();
	void changeFocus(MySprite *sprite);

	static void install(string path,string pkgName);
	static void unInstall(string pkgname);
	static string hasInstallApk(string pkgname);
	static string currDownloadApkPath;
	//测试用
	static vector <string>vecHasInstallApk;

	//static bool isDownloadingRes(string saveName);
	//static void removeDownloading(string saveName);
	//static vector <string>vecLoaingRes;

	bool isShowBack;
	bool hasPressedFocusBuf();

	void removeAllChildren();
	void removeTilesName(string name);
	void setTilesName(string name);
	bool hasTileName(string name);
	MyButton * getFocusButton();
	vector <NetHander *>vecNet;

	static DownloadResTemplate* getResDownTemplate(string saveName);
	static vector <DownloadResTemplate *>vecDownLoadRes;
	static vector <MySprite *>vecDownLoadSprite;
private:
	void keyBackClicked();
	void keyMenuClicked();
	void keyArrowClicked(int arrow);  
	void keyEnterClicked();  

	void keyBackReleased();
	void keyMenuReleased();
	void keyArrowReleased(int arrow);  
	void keyEnterReleased();  


	void setScaleEnd();
	
	MyButton * getNearBotton(MyButton *in,int way);
	float getNearQuanzhi(MyButton *btIn,MyButton *btAr,int way,bool isAll);
	int getChonghe(int x1,int x2,int x3,int x4);
	
	void getLogoCallback(string receive);

	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	
};