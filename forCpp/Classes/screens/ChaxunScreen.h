#include "..\common\Screen.h"

class ChaxunScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(ChaxunScreen,Globe::CHAXUN_SCREEN);

public:

	CREATE_FUNC(ChaxunScreen);
	CREATE_SCENE(ChaxunScreen);
	
	//ÿҳ��ʾ��Ŀ
#define NUM_PAGE 7
	//struct jilu{
	//	string jine;//���
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

	//�ϴΰ����ǲ�����һҳ������һ�¡���������Ĭ�Ͻ���
	bool isNextBuf;
	MySprite * addBt(string pngPath,int x);

	MySprite *btLastPage;
	MySprite *btNextPage;
	MySprite *btCancle;

	void call(string receive);
};