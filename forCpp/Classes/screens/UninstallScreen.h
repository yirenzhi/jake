#include "..\common\Screen.h"

class UninstallScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(UninstallScreen,Globe::MYGAME_SCREEN);

public:

	CREATE_FUNC(UninstallScreen);
	CREATE_SCENE(UninstallScreen);

	vector <MySprite*> vectiles;

	MyScrollview *tileLayer;
	MyScrollviewThumbnail *scrollvie;

	struct gameInfo{
		string appId;
		string url;
		string name;
		string pkgName;
	};
	vector <gameInfo> myGames;

	static MySprite * selectGame;
	static int selectIndex;
	static int tileY;

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