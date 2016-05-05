//
//  CurlDown.h
//  muli_download
//
//  Created by vin on 14-3-24.
//
//

#ifndef __muli_download__CurlDown__
#define __muli_download__CurlDown__

#include <iostream>
#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "../cocos2dx/platform/third_party/win32/pthread/pthread.h"
#include "../cocos2dx/platform/third_party/win32/curl/curl.h"
#include "io.h"
#else
#include "curl/curl.h"
#include "../external/emscripten/system/include/sys/io.h"
#endif
#include <stdio.h>
using namespace std;
USING_NS_CC;

class CurlDownDelegate;

class CurlDown{
private:
	string mFileName; // �����ļ�����
	
public:
	~CurlDown();
	CurlDown();
	CurlDown(string downUrl, string filePath);
	bool isStop;
	string mFilePath; // ���ش洢��ַ
	double mFileLenth; // �����ļ���С
	string mDownloadUrl; // ����URL
	long timeout; // ����ʱʱ�� Ϊ�˲����� ���ó�ʱʱ��Ϊ2�� ����Ƿ���ʽ�汾 ��Ϊ20�볬ʱʱ��
	bool download(); // ���ط���
	long getDownloadFileLenth(); // �����ļ���С����
	void downloadControler(); // ���ؿ��Ʒ���
	long getLocalFileLength(); // ��ǰ�����ļ���С
	void setStopDown();// ֹͣ����
	void setPauseDown();
	void setDelegate(CurlDownDelegate * delegate);
	CurlDownDelegate *mDelegate;

	bool isPause;

	enum ErrorCode
	{
		// Error caused by creating a file to store downloaded data
		kCreateFile,
		/** Error caused by network
		-- network unavaivable
		-- timeout
		-- ...
		*/
		kNetwork,
		/** There is not a new version
		*/
		kNoNewVersion,
		/** Error caused in uncompressing stage
		-- can not open zip file
		-- can not read file global information
		-- can not read file information
		-- can not create a directory
		-- ...
		*/
		kUncompress,
	};
};

class CurlDownDelegate
{
public:
	/* @brief Call back function for error
	@param errorCode Type of error
	*/
	virtual void onError(CurlDown::ErrorCode errorCode) {};
	/** @brief Call back function for recording downloading percent
	@param percent How much percent downloaded
	@warn This call back function just for recording downloading percent.
	AssetsManager will do some other thing after downloading, you should
	write code in onSuccess() after downloading.
	*/
	virtual void onProgress(double percent, void *delegate, string filefullPath) {};
	/** @brief Call back function for success
	*/
	virtual void onSuccess(string filefullPath) {};
};

#endif /* defined(__muli_download__CurlDown__) */
