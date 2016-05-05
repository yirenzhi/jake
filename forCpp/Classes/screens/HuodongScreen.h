#include "..\common\Screen.h"

class HuodongScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(HuodongScreen,Globe::HUODONG_SCREEN);

public:

	CREATE_FUNC(HuodongScreen);
	CREATE_SCENE(HuodongScreen);


	vector <MySprite*> vectiles;

	MyScrollview *tileLayer;
	static int tileLayerX;
	static int index;

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);
	void call(string receive);
};