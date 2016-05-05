#include "..\common\Screen.h"

class AskOpenScreen:public Screen{
	CREATE_CONSTRUCOR(AskOpenScreen,Globe::ASKOPEN_SCREEN);

public:

	CREATE_FUNC(AskOpenScreen);
	CREATE_SCENE(AskOpenScreen);

	MySprite *bt0;
	MySprite *bt1;

	CCLayer *zhezhao;
	int stage;
	int stageFrm;
	//static string testString;

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);
};