#include "CurDown.h"
#include "Download.h"


CurlDown::~CurlDown(){
	mFileLenth = 0;
}
CurlDown::CurlDown() :isStop(false),isPause(false), mDownloadUrl(""), timeout(1){ // test timeout 2 seconds. if release timeout 20 seconds
	mFileLenth = 0;
	mFilePath = "";
	//pthread_mutex_init(&g_downloadMutex_1, NULL);
}
CurlDown::CurlDown(string downUrl, string filePath) : mFileLenth(0), isPause(false),isStop(false), mDownloadUrl(downUrl), timeout(1), mFilePath(filePath){  // test timeout 2 seconds. if release timeout 20 seconds
	mDownloadUrl = downUrl;
	//pthread_mutex_init(&g_downloadMutex_1, NULL);
}

void CurlDown::setDelegate(CurlDownDelegate * delegate) {
	//pthread_mutex_lock(&g_downloadMutex_1);
	mDelegate = delegate;
	//pthread_mutex_unlock(&g_downloadMutex_1);
}


#pragma mark- ���Ʒ���
void CurlDown::downloadControler() {
	mFileLenth = getDownloadFileLenth(); // ��ȡԶ���ļ���С
	if (mFileLenth <= 0) {
		//cout << "download file fail..." << endl;
		mDelegate->onError(kNetwork);
		return;
	}
	//vector<string> searchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();
	//vector<string>::iterator iter = searchPaths.begin();
	//Download *down = (Download *)mDelegate;
	//int end = down->saveName.rfind("/");
	//string temp = down->saveName.substr(0,down->saveName.rfind("/")+1);
	//string ablePath = MyFileUtils::getWritablePath()+temp;
	//searchPaths.insert(iter, ablePath);
	//CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);

	
	bool ret = false;
	while (true){ // ѭ������ ÿ30��������� ����������
		if(!isPause){
			ret = download(); //ֱ������ ���ж����߳�
		}else{
			ret = false;
		}
		if (isStop) { // �������ֹͣ break
			break;
		}
		
		if (ret){ //�������
			break;
		}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		Sleep(0.1);
#else
		//usleep(1);
#endif
	}
	if(isStop){
		delete this;
		delete mDelegate;
	}else{
		if (ret) {
			mDelegate->onSuccess(mFilePath);
		}
		else {
			mDelegate->onError(kUncompress);
		}
	}
	
}

void CurlDown::setStopDown(){
	//pthread_mutex_lock(&g_downloadMutex_1);
	isStop = true;
	//pthread_mutex_unlock(&g_downloadMutex_1);
}

void CurlDown::setPauseDown(){
	//pthread_mutex_lock(&g_downloadMutex_1);
	isPause = true;
	//pthread_mutex_unlock(&g_downloadMutex_1);
}

#pragma mark �����ļ�д�뱾�ػص�����
static size_t my_write_func(void *ptr, size_t size, size_t nmemb, void *userdata) {
	FILE *fp = (FILE*)userdata;
	size_t written = fwrite(ptr, size, nmemb, fp);
	return written;
}
#pragma mark ���ؽ��Ⱥ��� - ÿ�����ش�С �����ܵĴ�С
static int my_progress_func(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded) {
	//    double curpercent = nowDownloaded / totalToDownload *100;//2001619
	//    if (totalToDownload == 0) {
	//        return 0;
	//    }
	//    CCLog("nowDd:%d; totalDown:%d; downProgress:%.2f%%",(int)nowDownloaded,(int)totalToDownload,curpercent);
	// ������ֵ ����ע�͵�������������Ͳ�׼ȷ��
	CurlDown* curlDown = (CurlDown*)ptr;
	if (!curlDown || curlDown->mFileLenth == 0 || nowDownloaded == 0) return 0;
	double nowDown = (curlDown->mFileLenth - totalToDownload + nowDownloaded);
	double curpercent = nowDown / curlDown->mFileLenth * 100; // 2001619

	curlDown->mDelegate->onProgress(curpercent, ptr, curlDown->mFilePath);
	//    CCLog("nowDd:%d; totalDown:%d; downProgress:%.2f%%",(int)(curlDown->mFileLenth - totalToDownload + nowDownloaded),(int)curlDown->mFileLenth , curpercent);
	return 0;
}

//fopen�����������£�
//fopen�����ļ���������ʹ���ļ���ʽ������
//r��ֻ����
//w��ֻд��
//r+�������д��
//w+�������д��
//a�����ı��ļ�ĩ������ݣ�
//a+�����ı��ļ�ĩ������ݣ��������
//rb��ֻ���������ļ���
//wb��ֻд�������ļ���
//rb+��ֻ���������ļ�������д��
//wb+��ֻд�������ļ����������
//ab����������ļ�ĩ������ݣ�
//ab+����������ļ�ĩ������ݣ��������
long CurlDown::getLocalFileLength() {
	FILE *fp = fopen(mFilePath.c_str(), "r");
	fseek(fp, 0, SEEK_END);
	long length = ftell(fp);
	fclose(fp);
	return length;
}

#pragma mark ��������
bool CurlDown::download() {
	CCLog("downloading...");
	FILE *fp = NULL;
	if (access(mFilePath.c_str(), 0) == 0) { // �Զ�������ʽ׷��
		fp = fopen(mFilePath.c_str(), "ab+");
	}
	else { // ������д
		fp = fopen(mFilePath.c_str(), "wb+");
	}

	if (fp == NULL) {// ����ļ���ʼ��ʧ�ܽ��з���
		return false;
	}

	// ��ȡ�����ļ����ش�С
	long localFileLenth = getLocalFileLength(); //�Ѿ����صĴ�С
	CURL *handle = curl_easy_init();
	std::string packageUrl = mDownloadUrl; //���ص�ַ+�����ļ���
	curl_easy_setopt(handle, CURLOPT_URL, packageUrl.c_str()); // http://curl.haxx.se/libcurl/c/fopen.html
	curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1L);
	curl_easy_setopt(handle, CURLOPT_TIMEOUT, timeout);
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, my_write_func);   //д�ļ��ص�����
	curl_easy_setopt(handle, CURLOPT_WRITEDATA, fp); // д���ļ�����
	curl_easy_setopt(handle, CURLOPT_RESUME_FROM, localFileLenth);  // �ӱ��ش�Сλ�ý�����������
	//curl_easy_setopt(handle, CURLOPT_RESUME_FROM_LARGE, localFileLenth); // ��
	curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0L);

	curl_easy_setopt(handle, CURLOPT_PROGRESSFUNCTION, my_progress_func); //���ؽ��Ȼص�����
	curl_easy_setopt(handle, CURLOPT_PROGRESSDATA, this); // ���뱾�����

	CURLcode res = curl_easy_perform(handle);
	curl_easy_cleanup(handle);
	fclose(fp);
	return res == CURLE_OK;
}

/* �õ�Զ���ļ��Ĵ�С, Ҫ���ص��ļ���С */ // �ο����Ǹ����� ��ȡ������С
long CurlDown::getDownloadFileLenth(){
	//	double filesize = 0.0;
	CURL *handle = curl_easy_init();
	//    http://curl.haxx.se/libcurl/c/ftpgetinfo.html
	//    curl_easy_setopt(curl, CURLOPT_URL, ftpurl);
	//    /* No download if the file */
	//    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
	//    /* Ask for filetime */
	//    curl_easy_setopt(curl, CURLOPT_FILETIME, 1L);
	//    /* No header output: TODO 14.1 http-style HEAD output for ftp */
	//    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, throw_away);
	//    curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
	//    /* Switch on full protocol/debug output */
	//    /* curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); */

	curl_easy_setopt(handle, CURLOPT_URL, mDownloadUrl.c_str());
	/* No download if the file */
	curl_easy_setopt(handle, CURLOPT_NOBODY, 1L);
	curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1L);//����ܹؼ��������٣���Ȼ���߳�curl�ͻ����ˣ�����ʱ��
	/* Ask for filetime */
	curl_easy_setopt(handle, CURLOPT_HEADER, 0L); // 0 ����ӡ��־ 1��ӡ��־

	if (curl_easy_perform(handle) == CURLE_OK) {
		curl_easy_getinfo(handle, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &mFileLenth);
		//printf("filesize : %0.0f bytes\n", mFileLenth);
	}
	else {
		mFileLenth = -1;
	}
	return mFileLenth;
}