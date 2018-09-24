// dllmain.cpp : 定义 DLL 应用程序的入口点。


#include"Prequesities.h"
#include"GameFrameWork.h"
#include"PlatformImpl.h"



GameFrameWork* g_GameFrameWork;

typedef ISystem* (*GET_SYSTEM)();

typedef void(*DESTROY_END)();

GET_SYSTEM pFunStart;
DESTROY_END pFuncEnd;
HINSTANCE hHandle;

extern "C" DLL_EXPORT IGameFrameWork* ModuleInitialize()
{
	hHandle = 0;
	KsOpenModule(hHandle, _T("EngineSystem"));

	pFunStart = (GET_SYSTEM)DLL_GETSYM(hHandle, "ModuleInitialize");
	pFuncEnd = (DESTROY_END)DLL_GETSYM(hHandle, "ModelUnload");
	ISystem* system = pFunStart();

	SystemGlobalEnvironment* m_Env = system->GetEnvironment();

	if (m_Env)
	{
		m_EngineEnvironment = m_Env;
		g_GameFrameWork = new GameFrameWork();
		m_EngineEnvironment->p_Game = g_GameFrameWork;
	}

	return g_GameFrameWork;
}

extern "C" void DLL_EXPORT ModelUnload()
{
	delete g_GameFrameWork;

	pFuncEnd();
	DLL_FREE(hHandle);
}

