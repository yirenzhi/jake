#include "..\common\Screen.h"

class AboutScreen:public Screen{
	CREATE_CONSTRUCOR(AboutScreen,Globe::ABOUT_SCREEN);

public:

	CREATE_FUNC(AboutScreen);
	CREATE_SCENE(AboutScreen);


	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);
};