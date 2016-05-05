#include "..\common\Screen.h"

class GameInfoScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(GameInfoScreen,Globe::GAMEINFO_SCREEN);

public:

	CREATE_FUNC(GameInfoScreen);
	CREATE_SCENE(GameInfoScreen);


	static string gameId;
	string apkDownloadUrl;

	int callStage;

	int tuijian;
	string gameName;
	string gameInfo;
	string downNum;
	string filesize;
	string version;
	string versionCode;
	string about;
	string control;
	string iconPath;
	string packageName;

	bool hasInstall;

	

	struct tuijianGameDetail{
		string tjGameId;
		string tjInfo;
		int tjGrade;
		string tjIcon;
		string tjName;
	};


	
	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);

	void updateGetApk(Value value);
	void updateVersion(Value value);
	void updateGetGameInfo(Value value);
	void updateGetTuijian(Value value);

	

	void showGameInfo();
	void call(string receive);
	string getApkSavePathName(string url);

	float getJindu();

	void addDakaiXiezaiSprite();
	void addInstallSprite();

	DownloadResTemplate *templateApk;
	int installingFrm;


	bool isNoticeInstallApk;
	//下载完了以后通知自动安装过
	bool hasInstallEndNotice;
	MySprite *dakai;
	MySprite *xiezai;
	MySprite *install;

	CCSprite *jindu;
	CCLabelTTF *word;

	CCSprite *anzhuang;

	MySprite *tuijianGame[3];
	static vector <MySprite *> infoGame;
	static int selectShowIconIndex;


};