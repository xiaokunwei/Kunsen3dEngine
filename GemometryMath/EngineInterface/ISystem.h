#ifndef ISYSTEM_FILE_H
#define ISYSTEM_FILE_H

#include "Platform.h"


struct ISystem;
struct IInputManager;
struct IRenderer;
struct I3DEngine;

struct IGameFrameWork;
class IResourceManager;
struct IMeshLoader;
struct ITaskDispathcher;
struct IResFileManager;
struct SystemInfo
{
	TCHAR gpuDesc[255];
	TCHAR cpuDesc[255];

	uint32 gpuVendorID;
	uint32 cpuVenderID;

	uint32 cpuCoreCount;
	thread_id mainThreadId;

};

struct UNIQUE_IFACE SystemGlobalEnvironment
{
	ISystem* pSystem;

	IInputManager* pInputManager;

	IRenderer* pRenderer;

	I3DEngine* p3DEngine;

	SystemInfo* pSystemInfo;

	IResFileManager* pFileSystem;
	ITaskDispathcher* pCommonTaskDispatcher;

	IGameFrameWork* p_Game;

	void* pReserved0;
	void* pReserved1;
	void* pReserved2;


};

extern SystemGlobalEnvironment* m_EngineEnvironment;

void LogMessage(const TCHAR*, ...);
inline void LogMessage(const TCHAR* format, ...)
{

}
void LogInput(const TCHAR*, ...);
inline void LogInput(const TCHAR* format, ...)
{

}
void LogWarning(const TCHAR*, ...);
inline void LogWarning(const TCHAR*, ...)
{

}
void LogError(const TCHAR*, ...);
inline void LogError(const TCHAR* format, ...)
{

}
struct IProgressCallBack
{
	virtual void OnUpdateProgress(int progress) = 0;
	virtual void OnInitProgress(const TCHAR* progressText) = 0;
};

struct ISystemInitInfo
{
	HINSTANCE hInstance;
	IProgressCallBack* pProgressCallBack;
	int fWidth;
	int fHeight;
	void* appPtr;

#ifdef OS_ANDROID
	void* nativeWindowPTR;
	android_app* android_states;
#endif

	ISystemInitInfo(){
		hInstance = NULL;
		pProgressCallBack = NULL;
		fWidth = 0;
		fHeight = 0;
		appPtr = NULL;
#ifdef OS_ANDROID
		nativeWindowPTR = 0;
		android_states = 0;
#endif
	}
};

struct ISystem
{
public:
	virtual ~ISystem(){}

	virtual bool Init(ISystemInitInfo& initInfo) = 0;

	virtual bool PostInit(HWND hWnd, ISystemInitInfo& initInfo) = 0;

	virtual bool Destroy() = 0;

	virtual bool Update() = 0;

	virtual bool PostUpdate() = 0;

	virtual SystemGlobalEnvironment* GetEnvironment() = 0;

	virtual void SetEditorHWND(HWND drawHwnd, HWND mainHwnd) = 0;

	virtual bool IsEditor() = 0;

	virtual bool LoadScenes(const TCHAR* fileName, IProgressCallBack* pCallback) = 0;

	virtual bool SaveScene(const TCHAR* filename) = 0;

	virtual bool IsSceneEmpty() = 0;

	virtual bool ReloadResources(uint8 type, const KsString& name) = 0;

	virtual void UpdateProgress(int progress) = 0;

	virtual void CleanGarbage() = 0;

	virtual IResourceManager* GetTextureManager() = 0;

	virtual IResourceManager* GetMaterialManager() = 0;

	virtual IResourceManager* GetMeshManager() = 0;

	virtual IResourceManager* GetShaderManager() = 0;

	//virtual IMeshLoader* GetObjMeshLoader();

	virtual HWND GetHWND() = 0;
};
#endif