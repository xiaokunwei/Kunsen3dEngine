#include "stdafx.h"
#include "KsSystem.h"
#include"IRenderer.h"



KsSystem::KsSystem()
{
	m_EngineEnvironment->pSystemInfo = new SystemInfo();

	InitSystemInfo();

}


KsSystem::~KsSystem()
{
}

bool KsSystem::Init(ISystemInitInfo& sii)
{
	LogMessage(_T("initial system..."));
	std::vector<KsString> result;

#ifdef WIN32
	TCHAR renderdll[MAX_PATH] = _T("RenderGL330");
#endif
	if (!_tcsicmp(renderdll, _T("RendererD3D9")))
	{
		LOAD_MODULE_GLOBAL(m_moduleHandles.hRenderer, renderdgl330);
	}
	else
	{
		LOAD_MODULE_GLOBAL(m_moduleHandles.hRenderer, RenderGL330);
	}

	//-----------------------------------------------------------------
	// RenderSystem Initialize
	//------------------------------------
	if (m_moduleHandles.hRenderer)
	{
		m_hWnd = m_EngineEnvironment->pRenderer->Init(sii);

		if (m_hWnd == NULL)
		{
			LogError(_T("fatal error :renender"));
			return false;
		}
		LogMessage(_T("Render Initialized successfully"));
	}
	return true;
}

bool KsSystem::PostInit(HWND hwnd, ISystemInitInfo& initInfo)
{
	return true;
}
bool KsSystem::Destroy()
{
	return true;
}
bool KsSystem::Update()
{
	m_EngineEnvironment->pRenderer->StartRender();
	return	true;
}
bool KsSystem::PostUpdate()
{
	return true;
}
SystemGlobalEnvironment* KsSystem::GetEnvironment()
{
	return	m_EngineEnvironment;
}
void KsSystem::SetEditorHWND(HWND drawHwnd, HWND mainHwnd)
{

}
bool KsSystem::IsEditor()
{
	return false;	
}

bool KsSystem::LoadScenes(const TCHAR* filename, IProgressCallBack* callBack)
{
	return false;
}
bool KsSystem::SaveScene(const TCHAR* fileName)
{
	return	 false;
}
bool KsSystem::IsSceneEmpty()
{
	return false;
}
bool KsSystem::ReloadResources(uint8 type, const KsString& name)
{
	return false;
}
void KsSystem::UpdateProgress(int progress)
{
	
}
void KsSystem::CleanGarbage()
{

}
IResourceManager* KsSystem::GetTextureManager()
{
	return m_pTextureManager;
}
IResourceManager* KsSystem::GetMaterialManager()
{
	return m_pMaterialManager;
}
IResourceManager* KsSystem::GetMeshManager()
{
	return m_pMeshManager;
}
IResourceManager* KsSystem::GetShaderManager()
{
	return m_pShaderManager;
}
//IMeshLoader* KsSystem::GetObjMeshLoader()
//{
//	return m_pMeshLoader;
//}
HWND KsSystem::GetHWND()
{
	return m_hWnd;
}
void KsSystem::InitSystemInfo()
{
#ifdef WIN32
	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	m_EngineEnvironment->pSystemInfo->cpuCoreCount = siSysInfo.dwNumberOfProcessors;
	m_EngineEnvironment->pSystemInfo->mainThreadId = GetCurrentThreadId();
#else

#endif
}
