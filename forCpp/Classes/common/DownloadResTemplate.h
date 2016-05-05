#include "Globe.h"
#include "..\net\download\Download.h"

class DownloadResTemplate{
public:
	DownloadResTemplate();
	~DownloadResTemplate();

	bool isDownLoadSuccess;
	string savePathName;
	Download *down;
	string fullPath;
	string pkgName;
	bool isApk;
	bool isNotice;
	string version;//版本号，如果是下载的一个更新的APK包，则保存一下版本号，删除文件的时候，除了判断有没有安装这个应用外，还要判断当前应用的版本号是不是这个apk包的版本号
};