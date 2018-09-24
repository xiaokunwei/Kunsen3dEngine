// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include"Platform.h"
#include"PlatformImpl.h"
#include"KsSystem.h"

KsSystem* g_System = NULL;

extern "C" DLL_EXPORT ISystem* ModuleInitialize()
{
	m_EngineEnvironment = new SystemGlobalEnvironment;
	memset(m_EngineEnvironment, 0, sizeof(SystemGlobalEnvironment));
	g_System = new KsSystem();
	m_EngineEnvironment->pSystem = g_System;

	return g_System;
}
extern "C" void DLL_EXPORT ModelUnload()
{

}