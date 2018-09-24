// GameFrameWork.cpp : 定义 DLL 应用程序的导出函数。
//


#include"GameFrameWork.h"

GameFrameWork::GameFrameWork()
{
	m_pFuncGameStart = NULL;
	m_pFuncGameEnd = NULL;
	m_pGame = NULL;
}
bool GameFrameWork::Init(ISystemInitInfo& sii)
{
	
	return m_EngineEnvironment->pSystem->Init(sii);
}
bool GameFrameWork::PostInit(HWND hwnd, ISystemInitInfo& sii)
{
	m_EngineEnvironment->pSystem->PostInit(hwnd, sii);

	return true;
}

void GameFrameWork::Run()
{
#ifdef WIN32
	for (;;)
	{
		MSG msg;

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message != WM_QUIT)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				break;
			}
		}
		else
		{
			if (!Update())
			{
				// need to clean the message loop (WM_QUIT might cause problems in the case of a restart)
				// another message loop might have WM_QUIT already so we cannot rely only on this 
				while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				break;
			}
		}
	}
#endif
}
bool GameFrameWork::Destroy()
{
	//m_EngineEnvironment->pSystem->Destroy();
	return true;
}
bool GameFrameWork::Update()
{
	m_EngineEnvironment->pSystem->Update();
	return true;
}
bool GameFrameWork::InitGame(const TCHAR* dllname)
{
	LogMessage(_T("load game..."));
	
	return true;
}
bool GameFrameWork::DestroyGame(bool defered)
{
	return true;
}

void GameFrameWork::LoadLevel(const TCHAR* filename)
{

}
void GameFrameWork::OnLevelLoaded()
{

}
void GameFrameWork::MarkClose()
{

}

SystemGlobalEnvironment* GameFrameWork::GetEnvironment()
{
	return m_EngineEnvironment;
}