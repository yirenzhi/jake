#pragma once
#include "MyButton.h"
#include "MyScrollview.h"
#include "Globe.h"
#include "Screen.h"
#include "..\net\download\DownloadObject.h"
#include "..\net\download\Download.h"

class Screen;
class MySprite : public CCSprite, public MyButton,public DownloadObject{
public:
	MySprite();
	~MySprite();
	
	bool isShow;
	void downloadEnd(string path);

	

	void showDownLoad();
	
	void setFather(MyScrollview *node);
	//当前被选中
	void setFoucs(bool is);
	void setSelectScale(float scale);
	static MySprite* create(const char *pszFileName);
	void getImageFromUrl(string url,string savepath);

	MyScrollview *father;
	float selectScale;
	int zBur;


	float initScalX,initScalY;
	
	string fullPaht;
	string saveName;
	CCRect factRect;
	void setFactRect(CCRect rect);
	CCRect getFactRect();

	void setAppId(string id);
	void setPkgName(string name);
	void setAppType(string type);

	void setAddMode(int mode);
	bool hasDownload;
	void downloadEndCallBack(CCNode *node);
	int addMode;
	void setDefaultFocus(bool is,Screen *screen);
	bool isDefaultFocus;

	string pkgName;
	string appid;
	string appType;
	Screen *fatherScreen;
	bool hasGetUrlImage;
	Download *down;
	int cutY;
	void setCutY(int cut);
	float showScanX,showScanY;
	void setShowScanXY(float sx,float sy);
	bool isClear;
private:
	void setTheDefaultFocus();
	bool replaceTexture2D(string path);
	CCSprite* layerColor;
	CCLabelTTF *word1;
};