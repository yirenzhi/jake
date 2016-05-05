#include "..\common\Screen.h"

class VariousScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(VariousScreen,Globe::VARIOUS_SCREEN);

public:

	CREATE_FUNC(VariousScreen);
	CREATE_SCENE(VariousScreen);

	
	vector <MySprite *> spriteTile;
	vector <MySprite *> tiles;

	void initTils(int index);

	MyScrollview *tileLayer;
	MyScrollviewThumbnail *scrollvie;


	
	int currentIndex;
	//每个分类的接口是否调用完成，要调用完成才允许调用下一个
	bool isGetInfoEnd;
	//从游戏详情页面回来的时候，要回到刚刚进去的时候的ICON图标
	static bool isComeBack;
	static int tileIndex;
	static int layerY;
	static int iconIndex;
	bool mustRefresh;
	void refresh();
	

	typedef struct
	{
		string id;
		string name;
	}cateGory; 

	void getVariousInfo(int index);

	vector <cateGory> cateGorys;
	void call(string receive);
	int callStage;

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);
};