// dllmain.cpp : 定义 DLL 应用程序的入口点。

#include"Prerequisites.h"

#include"PlatformImpl.h"

#ifdef RENDERAPI_GL330
#include <glo/glo_impl.hpp>
#endif

#include"RendererGL330.h"
RendererGL* g_RenderModule;

extern "C" void DLL_EXPORT ModuleInitialize(SystemGlobalEnvironment* pEnv)
{
	if (pEnv)
	{
		m_EngineEnvironment = pEnv;
		g_RenderModule = new RendererGL();
		pEnv->pRenderer = g_RenderModule;

	}
}
extern "C" void DLL_EXPORT ModuleUnload()
{
	delete g_RenderModule;
}
