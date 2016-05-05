#include "..\common\Screen.h"

class GameShowScreen:public Screen{
	CREATE_CONSTRUCOR(GameShowScreen,Globe::GAMESHOW_SCREEN);

public:

	CREATE_FUNC(GameShowScreen);
	CREATE_SCENE(GameShowScreen);
	MySprite *icon;

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);
};