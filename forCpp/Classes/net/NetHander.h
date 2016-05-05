#pragma once
#include "../common/Globe.h"
#include "cocos-ext.h"
#include "../utils/MD5.h"
#include "../json/json.h"
#include <string>
#include <locale.h> 
#include "Callback.h"

using namespace Json;



USING_NS_CC_EXT;  
#pragma comment(lib,"pthreadVCE2.lib")


class NetHander : public CCNode{
public:
	NetHander();
	~NetHander();
	
	Callback *callback;
	void setCallBack(Callback *back);
	void getLogo();
	void getHomePage();
	void getCategory();
	void getCategoryDetail(string id);
	void getAppDetail(string id);
	void getRecommendApp();
	void getApkDownloadUrl(string id);
	void getAllInstallApks(string allPkgName);
	void getNewVersion(string appId);
	void getAcitivity(int appId);
	void getAcitivityDetail(string id);
	void getZhuanquDetail(string id);
	void getUserPassword();
	void setUserPassword(string oldPassword,string passWord);
	void getXiaofeijilu(int index,int pagesize);

	string getNetString;
	string name;

	static string version;
	static string mac;
	static string bossId;
	static string serverUrl;
	static string key;
	static void getInfo();
	void close();
	
private:
	
	
	string sign;

	bool isClose;

	void doSend(string url);
	void callbackSend(CCNode *node,void *data);
	string put(string url,string key,string value);
	
};