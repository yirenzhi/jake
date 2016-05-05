#include "..\common\Screen.h"

class HuodongInfoScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(HuodongInfoScreen,Globe::HUODONGINFO_SCREEN);

public:

	CREATE_FUNC(HuodongInfoScreen);
	CREATE_SCENE(HuodongInfoScreen);

	static string activityId;
	string appId;
	MySprite *icon;
	MySprite *bt;
	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);

	void call(string receive);
};