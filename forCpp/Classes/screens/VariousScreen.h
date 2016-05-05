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
	//ÿ������Ľӿ��Ƿ������ɣ�Ҫ������ɲ����������һ��
	bool isGetInfoEnd;
	//����Ϸ����ҳ�������ʱ��Ҫ�ص��ոս�ȥ��ʱ���ICONͼ��
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