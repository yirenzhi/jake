#include "..\common\Screen.h"

class ZhuantiInfo:public Screen,Callback{
	CREATE_CONSTRUCOR(ZhuantiInfo,Globe::ZHUANTI_SCREEN);

public:

	CREATE_FUNC(ZhuantiInfo);
	CREATE_SCENE(ZhuantiInfo);


	vector <MySprite*> vectiles;

	MyScrollview *tileLayer;
	static int tileLayerX;
	static int index;

	
	struct iconInfo{
		string appid;
		string name;
		string url;
	};
	vector<iconInfo>vecIconInfo;
	MySprite *icon;

	static string zhuantiId;

	void loadIcon();
	bool hasAdd;

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);
	void call(string receive);
};