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
	string version;//�汾�ţ���������ص�һ�����µ�APK�����򱣴�һ�°汾�ţ�ɾ���ļ���ʱ�򣬳����ж���û�а�װ���Ӧ���⣬��Ҫ�жϵ�ǰӦ�õİ汾���ǲ������apk���İ汾��
};