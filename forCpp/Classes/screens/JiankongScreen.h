#include "..\common\Screen.h"

class JiankongScreen:public Screen,Callback{
	CREATE_CONSTRUCOR(JiankongScreen,Globe::JIANKONG_SCREEN);

public:

	CREATE_FUNC(JiankongScreen);
	CREATE_SCENE(JiankongScreen);

	MySprite *btOk;
	MySprite *btCancle;
	CCSprite *kuang;

	bool init(void);
	void draw(void);
	void update(float dt);
	void clear(void);
	void back(void);
	void updateGuangbiao(void);
	void showInfo(string info);
	void setTongsuo(string info);
	void updateInput();
	
	int setTingFrm;

	int selectIndex;
	bool isFristSet;

	bool hasGetPassWord;
	CCLabelTTF *oldPassword;
	CCLabelTTF *newPassword;
	CCLabelTTF *againPassword;

	CCLabelTTF *messageInfo;

	CCLabelTTF *guangbiao;
	int frm;

	string inputOld;
	string inputNew;
	string inputAgain;

	bool isSeting;
	bool isSetEnd;

	static string password;
	void call(string receive);
};