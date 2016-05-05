#include "..\common\Screen.h"

class ChaxunScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(ChaxunScreen,Globe::CHAXUN_SCREEN);

public:

	CREATE_FUNC(ChaxunScreen);
	CREATE_SCENE(ChaxunScreen);
	
	//每页显示数目
#define NUM_PAGE 7
	//struct jilu{
	//	string jine;//金额
	//	string gameName;
	//	string proName;
	//	string time;
	//};

	//vector <jilu*> vecJilu;

	CCLabelTTF *wordGameName[NUM_PAGE];
	CCLabelTTF *wordProName[NUM_PAGE];
	CCLabelTTF *wordMoney[NUM_PAGE];
	CCLabelTTF *wordTime[NUM_PAGE];
	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);

	int pageNum;
	int pageIndex;


	CCLabelTTF *pageLabel;


	bool isChaxuning;
	void chaxun();
	void chaxunEnd();
	void clearWord();

	//上次按的是不是下一页，保存一下。便于设置默认焦点
	bool isNextBuf;
	MySprite * addBt(string pngPath,int x);

	MySprite *btLastPage;
	MySprite *btNextPage;
	MySprite *btCancle;

	void call(string receive);
};