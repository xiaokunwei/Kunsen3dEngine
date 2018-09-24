// RenderEngine.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include"Platform.h"

#ifdef WIN32
#include"IGameFrameWork.h"
#include"ISystem.h"
#include"PlatformImpl.h"

typedef IGameFrameWork* (*GET_SYSTEM)();
typedef void(*DESTORY_END)();

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int{
	HINSTANCE hHandle = 0;
	KsOpenModule(hHandle, _T("GameFrameWork"));
	GET_SYSTEM pFuncStart = (GET_SYSTEM)DLL_GETSYM(hHandle, ("ModuleInitialize"));
	IGameFrameWork* game = pFuncStart();

	int width = 1280;
	int height = 720;
	ISystemInitInfo sii;
	sii.fWidth = width;
	sii.fHeight = height;

	if (!(game->Init(sii)))
	{
		return 0;
	}
	game->PostInit(NULL, sii);
	game->InitGame(NULL);

	game->Run();

	game->DestroyGame(false);
	game->Destroy();
	KsFreeModule(hHandle);

	return 0;

}
#endif
