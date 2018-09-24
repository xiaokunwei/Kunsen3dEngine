#pragma once
#include"Prerequister.h"


struct ModuleHandle
{
	HINSTANCE hInputLayer;
	HINSTANCE hRenderer;
	HINSTANCE h3DEngine;
	HINSTANCE hFont;

};
class KsSystem :public ISystem
{
public:
	KsSystem();
	~KsSystem();

	virtual bool Init(ISystemInitInfo& initInfo);
	virtual bool PostInit(HWND hWnd, ISystemInitInfo& initInfo);

	virtual bool Destroy();

	virtual bool Update();

	virtual bool PostUpdate();

	virtual SystemGlobalEnvironment* GetEnvironment();

	virtual void SetEditorHWND(HWND drawHwnd, HWND mainHwnd);

	virtual bool IsEditor();

	virtual bool LoadScenes(const TCHAR* fileName, IProgressCallBack* pCallback);

	virtual bool SaveScene(const TCHAR* filename);

	virtual bool IsSceneEmpty();

	virtual bool ReloadResources(uint8 type, const KsString& name);

	virtual void UpdateProgress(int progress) ;

	virtual void CleanGarbage();

	virtual IResourceManager* GetTextureManager();

	virtual IResourceManager* GetMaterialManager() ;

	virtual IResourceManager* GetMeshManager();

	virtual IResourceManager* GetShaderManager();

//	virtual IMeshLoader* GetObjMeshLoader();

	virtual HWND GetHWND();

protected:

	void InitSystemInfo();

	ModuleHandle m_moduleHandles;
	HWND m_hWnd;

	IResourceManager* m_pTextureManager;
	IResourceManager* m_pMeshManager;
	IResourceManager* m_pMaterialManager;
	IResourceManager* m_pShaderManager;
	IMeshLoader* m_pMeshLoader;
};

