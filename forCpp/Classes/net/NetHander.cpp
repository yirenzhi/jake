#include "NetHander.h"


string NetHander::version = "1.0";
string NetHander::mac = "09-20150819020-01";
string NetHander::bossId = "410";
//string NetHander::serverUrl = "http://61.50.252.76:8700/OTTGameHall/";
string NetHander::serverUrl = "http://api1.tvsdk.cn/OTTGameHall/";
string NetHander::key = "36DDA110-6F01-4C12-9840-33DAEC6A12FC";
NetHander::NetHander():isClose(false),callback(NULL){
	getNetString = "";
}

NetHander::~NetHander(){
	callback = NULL;
}

void NetHander::getInfo(){
	string ver = Globe::callJava(Globe::makeJsonString("getVersion",""));
	if(ver!=""){
		version = ver;
	}

	string ma = Globe::callJava(Globe::makeJsonString("getMac",""));
	if(ma!=""){
		mac = ma;
	}

	string bosid = Globe::callJava(Globe::makeJsonString("getBossId",""));
	if(bosid!=""){
		bossId = bosid;
	}

	string url = Globe::callJava(Globe::makeJsonString("getServerUrl",""));
	if(url!=""){
		serverUrl = url;
	}

	string hkey = Globe::callJava(Globe::makeJsonString("getHttpKey",""));
	if(hkey!=""){
		key = hkey;
	}

}



void NetHander::setCallBack(Callback *back){
	callback = back;
}

void NetHander::getLogo(){
	name = "getlogo.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getHomePage(){
	name = "GetHomePage.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getCategory(){
	name = "getCategory.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getCategoryDetail(string id){
	name = "GetCategoryDetail.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "CategoryID", id);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);
	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getAppDetail(string id){
	name = "GetAppDetail.ashx";
	string url = serverUrl+name;
	url = put(url, "AppID", id);
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);
	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getApkDownloadUrl(string id){
	name = "GetDownloadUrl.ashx";
	string url = serverUrl+name;
	url = put(url, "AppID", id);
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);
	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getRecommendApp(){
	name = "GetRecommendApp.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);
	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getAllInstallApks(string allPkgName){
	name = "GetSJAppInfo.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "PackageNames", allPkgName);
	url = put(url, "Version", version);

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getNewVersion(string appId){
	name = "GetAppUpdate.ashx";
	string url = serverUrl+name;
	url = put(url, "AppIDs", appId);
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getAcitivity(int num){
	name = "GetActivityPage.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "Count", Globe::intToString(num));
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getAcitivityDetail(string id){
	name = "GetActivityDetail.ashx";
	string url = serverUrl+name;
	url = put(url, "ActivityID", id);
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getZhuanquDetail(string id){
	name = "GetZoneDetail.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "MacAddress", mac);
	url = put(url, "Version", version);
	url = put(url, "ZoneID", id);

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getUserPassword(){
	name = "GetUserPassword.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "ManySDK_GameID", "tvg100001");
	url = put(url, "ManySDK_UserID", mac);
	

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::getXiaofeijilu(int index,int pageSize){
	name = "GetUserOrders.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "C_3rd_UserID", mac);
	url = put(url, "ManySDK_GameID", "tvg100001");
	url = put(url, "page", Globe::intToString(index));
	url = put(url, "pagesize", Globe::intToString(pageSize));
	

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}

void NetHander::setUserPassword(string oldPassword,string passWord){
	name = "SetUserPassword.ashx";
	string url = serverUrl+name;
	url = put(url, "BossID", bossId);
	url = put(url, "ManySDK_GameID", "tvg100001");
	url = put(url, "ManySDK_UserID", mac);
	url = put(url, "OldPassword", oldPassword);
	url = put(url, "Password", passWord);
	

	sign += key;
	sign = md5(sign);
	url+="&sign="+sign;
	CCLog("httpUrl:%s",url.c_str());
	doSend(url);
}


void NetHander::doSend(string url){
	CCHttpRequest* request = new CCHttpRequest();
	request->setUrl((url+"&sj=0").c_str());//设置请求地址  
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, callfuncND_selector(NetHander::callbackSend));//请求完的回调函数  
    //request->setRequestData("HelloWorld",strlen("HelloWorld"));//请求的数据
	request->setTag(name.c_str());
	CCHttpClient::getInstance()->setTimeoutForConnect(20);
	CCHttpClient::getInstance()->setTimeoutForRead(20);
	CCHttpClient::getInstance()->send(request);//发送请求 
    request->release();//释放
	getNetString = "";
}

void NetHander::close(){
	this->autorelease();
	isClose = true;
}

void NetHander::callbackSend(CCNode *node,void *data){
	CCLog("callbackSend:%x",this);
	CCHttpResponse *response = (CCHttpResponse*)data;  
	if (!response)  
    {  
        return;  
    }
	if(isClose){
		return;
	}
	//获取一些其他参数
	if(true){
		int s=response->getHttpRequest()->getRequestType();
		if(s!=0){
			CCLog("request type %d",s); 
		}
		
		int statusCode = response->getResponseCode();
		if(statusCode!=200){
			CCLog("response code: %d", statusCode);  
		}
		
		if (!response->isSucceed())
		{  
			CCLog("response failed");  
			CCLog("error buffer: %s", response->getErrorBuffer());  
			if(callback){
				callback->call("");
			}
			return;  
		}  
	}

    std::vector<char> *buffer = response->getResponseData(); 

	std::string temp(buffer->begin(),buffer->end());
    CCLog("httpReceived:[%s]|%s",response->getHttpRequest()->getTag(),temp.c_str());
	getNetString = temp;
	if(callback){
		callback->call(temp);
	}
}

string NetHander::put(string url,string key,string value){
	if(url.find("?")==-1){
		sign = "";
		sign = sign + value;
		url = url + ("?" + key + "=" +  value);
	}else{
		sign = sign + value;
		url = url + ("&" + key + "=" +  value);
	}
	return url;
}









