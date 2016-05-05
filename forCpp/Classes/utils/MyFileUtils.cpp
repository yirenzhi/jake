#include "MyFileUtils.h"


MyFileUtils::MyFileUtils(){

}
MyFileUtils::~MyFileUtils(){

}

std::string MyFileUtils::getWritablePath() 

{ 

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32) 

    return CCFileUtils::sharedFileUtils()->getWritablePath(); 

#else 

    char full_path[MAX_PATH + 1]; 

    ::GetModuleFileNameA(NULL, full_path,MAX_PATH + 1); 

    std::string ret((char*)full_path); 

    // remove xxx.exe 

    ret =  ret.substr(0, ret.rfind("\\") + 1); 

    ret = convertPathFormatToUnixStyle(ret); 

    return ret; 

#endif 

}


bool MyFileUtils::openOrCreateFile_(const char* pContentString, const std::string& pFileName) 

{ 

    std::string fn=convertPathFormatToUnixStyle(pFileName); 

    int np=fn.rfind('/'); 

    if(np!=std::string::npos) 

        if(!mkDirM(fn.substr(0,np))) 

            return false; 

   

    std::string path = getWritablePath()+fn; 

    FILE* file = fopen(path.c_str(), "w");   

    if (file) 

    {   

        //fputs(pContentString, file);   

        fclose(file);  

        //CCLog("save file [%s]",path.c_str());   

        return true; 

    } 

    else 

        //CCLog("fail to save file [%s]!",path.c_str()); 

    return false; 

} 

//检测各级文件夹，不存在则创建 

bool MyFileUtils::mkDirM(const std::string& pDirName) 

{ 

    std::string path = getWritablePath(); 

    int np=pDirName.find('/',0); 

    while(np!=std::string::npos) 

    { 

        if(!mkDir(path+pDirName.substr(0,np))) 

            return false; 

        np=pDirName.find('/',np+1); 

    } 

    return mkDir(path+pDirName); 

} 

   

//创建文件夹 

bool MyFileUtils::mkDir(const std::string& pDirName) 

{ 

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32) 

    mode_t processMask = umask(0);
    int ret = mkdir(pDirName.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
    umask(processMask);
    if (ret != 0 && (errno != EEXIST))
    {
        return false;
    }
    
    return true;

#else 

    if ((GetFileAttributesA(pDirName.c_str())) == INVALID_FILE_ATTRIBUTES) 

    { 

        if(!CreateDirectoryA(pDirName.c_str(), 0)) 

        { 

            //CCLog("fail to create dir [%s]",pDirName.c_str()); 

            return false; 

        } 

        //CCLog("create dir [%s]",pDirName.c_str()); 

    } 

#endif 

       

    return true; 

} 

//路径格式转为UnixStyle，"c:\xxx.txt" --> "c:/xxx.txt" 

    inline std::string MyFileUtils::convertPathFormatToUnixStyle(const std::string& path) 

    {  

        std::string ret = path; int len = ret.length(); 

        for (int i = 0; i < len; ++i)  

        {  

            if (ret[i] == '\\')  

            {  

                ret[i] = '/';  

            }  

        }  

        return ret; 

    }

void MyFileUtils::deleteFile(string pathToSave)
{
	
	FILE *file = fopen(pathToSave.c_str(), "r");
	if(file){
		//CCLog("delete:%s",pathToSave.c_str());
		fclose(file);
		unlink(pathToSave.c_str());
	}
}

void MyFileUtils::deleteDir(string pathToSave)
{
    // Remove downloaded files
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
    string command = "rm -r ";
    // Path may include space.
    command += "\"" + pathToSave + "\"";
    system(command.c_str());
#else
    string command = "rd /s /q ";
    // Path may include space.
    command += "\"" + pathToSave + "\"";
    system(command.c_str());
#endif
}


