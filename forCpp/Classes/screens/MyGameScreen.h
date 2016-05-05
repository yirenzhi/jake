#include "..\common\Screen.h"

class MyGameScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(MyGameScreen,Globe::MYGAME_SCREEN);

public:

	CREATE_FUNC(MyGameScreen);
	CREATE_SCENE(MyGameScreen);

	vector <MySprite*> vectiles;

	MyScrollview *tileLayer;
	MyScrollviewThumbnail *scrollvie;

	struct gameInfo{
		string appId;
		string url;
		string pkgName;
	};
	vector <gameInfo> myGames;

	static MySprite * selectGame;
	static int selectIndex;
	static int tileY;
	int stage;

	MySprite *bt;

	bool hasChange;
	void updateNoGames();

	static string allGamesStr;

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);

	void call(string receive);
};