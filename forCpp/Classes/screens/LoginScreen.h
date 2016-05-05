#include "..\common\Screen.h"


class LoginScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(LoginScreen,Globe::LOGIN_SCREEN);

public:

	CREATE_FUNC(LoginScreen);
	CREATE_SCENE(LoginScreen);

	void menuCloseCallback(CCObject* pSender);

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);

	static int stage;


	void call(string receive);


	CCSprite* dian[5];
	int dianOptin[5];
	bool isTurn;

	MySprite* downSprite;
	int frm;
	int showFrm;
	static bool hasGetDownloadUrl;
	MySprite *icon;
};