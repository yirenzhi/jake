#pragma once
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8)
#include <curl/curl.h>
#include <curl/easy.h>

#include <stdio.h>
#include <vector>

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#endif
#endif

USING_NS_CC;
#define USING_STD using namespace std;
USING_STD;

class MyFileUtils{

public:
	MyFileUtils();
	~MyFileUtils();

	static std::string getWritablePath();
	static bool openOrCreateFile_(const char* pContentString, const std::string& pFileName);
	static bool mkDirM(const std::string& pDirName);
	static bool mkDir(const std::string& pDirName);
	static inline std::string convertPathFormatToUnixStyle(const std::string& path);
	static void deleteFile(string  dirPath);
	static void deleteDir(string pathToSave);
};