#ifndef IGAMEFRAMEWORK_FILE_H
#define IGAMEFRAMEWORK_FILE_H
#include<Windows.h>
struct SystemGlobalEnvironment;

struct ISystemInitInfo;


struct IGameFrameWork
{
	virtual ~IGameFrameWork(){}

	virtual bool Init(ISystemInitInfo& sii) = 0;

	virtual bool PostInit(HWND hWnd,ISystemInitInfo& sii) = 0;

	virtual void Run() = 0;

	virtual bool Destroy() = 0;

	virtual bool Update() = 0;

	virtual bool InitGame(const TCHAR* dllName) = 0;

	virtual bool DestroyGame(bool defered = true) = 0;

	virtual void LoadLevel(const TCHAR* filename) = 0;

	virtual void OnLevelLoaded() = 0;

	virtual void MarkClose() = 0;

	virtual SystemGlobalEnvironment* GetEnvironment() = 0;

};

#endif