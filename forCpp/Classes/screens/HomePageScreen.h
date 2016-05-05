#include "..\common\Screen.h"


class HomePageScreen : public Screen,Callback{
	CREATE_CONSTRUCOR(HomePageScreen,Globe::HOMEPAGE_SCREEN);

public:

	CREATE_FUNC(HomePageScreen);
	CREATE_SCENE(HomePageScreen);

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);

	void call(string receive);

	static void deleteDir();

	vector<MySprite *>sprite;
	MySprite *buttonSprite[4];
	void exitGame();

	int stage;
	int delayFrm;
};