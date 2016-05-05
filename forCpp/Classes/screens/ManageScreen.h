#include "..\common\Screen.h"

class ManageScreen:public Screen{
	CREATE_CONSTRUCOR(ManageScreen,Globe::MANAGE_SCREEN);

public:

	CREATE_FUNC(ManageScreen);
	CREATE_SCENE(ManageScreen);

	MySprite * uninstall;
	MySprite * about;
	MySprite * jiankong;
	MySprite * chaxun;

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);
};