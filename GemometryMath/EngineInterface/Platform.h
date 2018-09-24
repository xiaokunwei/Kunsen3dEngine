#pragma once
#ifndef WINVER                  // Specifies that the minimum required platform is Windows Vista.
#define WINVER 0x0600           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0600     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS          // Specifies that the minimum required platform is Windows 98.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE                       // Specifies that the minimum required platform is Internet Explorer 7.0.
#define _WIN32_IE 0x0700        // Change this to the appropriate value to target other versions of IE.
#endif

#ifndef PLATFORM_FILE_H
#define PLATFORM_FILE_H

// disable type conversion warnings
#pragma warning(disable:4244)
#pragma warning(disable:4305)

#if defined(__GNUG__)
# define COMPILER_GCC
#elif defined(_MSC_VER)
# define COMPILER_MSVC
// i don't care about your debug symbol issues...
# pragma warning(disable:4786)
#else
# error "Could not determine compiler"
#endif
#define BIT(x) (1<<(x))
#define SIMPLE_THREAD_STACK_SIZE_KB (32)

#if defined(WIN32)
#include"Win32Specific.h"
#endif
#if defined(LINUX)
#endif

#if defined(COMPILER_GCC)
#define DLL_EXPORT __attribute__ ((visibility("default")))
#define DLL_IMPORT __attribute__ ((visibility("default")))

#define DLL_OPEN(a) dlopen(a, RTLD_LAZY | RTLD_GLOBAL)
#define DLL_GETSYM(a,b) dlsym(a,b)
#define DLL_FREE(a) dlclose(a)

#define DLL_PREFIX _T("/data/app-lib/com.kkstudio.gkLauncherUniverse-1/lib")
#define DLL_PREFIX_2 _T("/data/app-lib/com.kkstudio.gkLauncherUniverse-2/lib")
#define DLL_SUFFIX _T(".so")
#else

#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)

#define DLL_OPEN(a) LoadLibraryEx(a,NULL,LOAD_WITH_ALTERED_SEARCH_PATH);
#define DLL_GETSYM(a,b) GetProcAddress(a,b)
#define DLL_FREE(a) FreeLibrary(a)

#define DLL_PREFIX _T("")
#define DLL_PREFIX_2 _T("")
#define DLL_SUFFIX _T(".dll")

#endif


#ifndef UNIQUE_IFACE
#define UNIQUE_IFACE
#endif // !UNIQUE_IFACE

#include<tchar.h>
///////////////////////////////////
// Module Init

struct SystemGlobalEnvironment;
extern SystemGlobalEnvironment* m_EngineEnvironment;

// log declare
extern void LogMessage(const TCHAR *, ...);
extern void LogInput(const TCHAR*, ...);
extern void LogWarning(const TCHAR*, ...);
extern void LogError(const TCHAR*, ...);


typedef void(*MODULE_START)(SystemGlobalEnvironment*);
typedef void(*MODULE_END)(void);

// module accessing func

void KsLoadModule(HINSTANCE&, const TCHAR*);
void KsOpenModule(HINSTANCE&, const TCHAR*);
void KsFreeModule(HINSTANCE&);

inline void KsLoadModule(HINSTANCE& handle, const TCHAR* moduleName)
{
	// load input dll [7/20/2011 Kaiming-Desktop]
	// cat .dll or .so
	LogMessage(_T("loading lib[ %s ]..."), moduleName);
	TCHAR finalModuleName[MAX_PATH];

	bool load_ok = false;

	for (int i = 0; i < 2; ++i)
	{
		if (i == 0)
		{
			_tcscpy(finalModuleName, DLL_PREFIX);
		}
		else
		{
			_tcscpy(finalModuleName, DLL_PREFIX_2);
		}
		_tcscat(finalModuleName, moduleName);
		_tcscat(finalModuleName, DLL_SUFFIX);


		handle = DLL_OPEN(finalModuleName);
		if (handle)
		{
			LogMessage(_T("lib[ %s ] entry calling..."), moduleName);
			MODULE_START pFunc = (MODULE_START)DLL_GETSYM(handle, "ModuleInitialize");
			if (pFunc)
			{
				pFunc(m_EngineEnvironment);
				load_ok = true;
				break;
			}
		}
	}

	if (!load_ok)
	{
		LogError(_T("loading lib[ %s ] failed."), moduleName);
#ifdef OS_ANDROID
		gkLogError(_T("dlerr: %s"), dlerror());
#endif
	}
}
inline void KsFreeModule(HINSTANCE&handle)
{
	if (handle)
	{
		MODULE_END pFunc = (MODULE_END)DLL_GETSYM(handle, "KsModuleUnLoad");
		pFunc();
		DLL_FREE(handle);
	}
}

inline void KsOpenModule(HINSTANCE& handle, const TCHAR*moduleName)
{
	LogMessage(_T("loading lib[%s]..."), moduleName);
	TCHAR finalModuleName[MAX_PATH];

	bool load_ok = false;

	for (int i = 0; i < 2; ++i)
	{
		if (i == 0)
		{
			_tcscpy(finalModuleName, DLL_PREFIX);
		}
		else
		{
			_tcscpy(finalModuleName, DLL_PREFIX_2);
		}
		_tcscat(finalModuleName, moduleName);
		_tcscat(finalModuleName, DLL_SUFFIX);

		handle = DLL_OPEN(finalModuleName);
		if (handle)
		{
			LogMessage(_T("loading lib[ %s ] successed."), moduleName);
			load_ok = true;
			break;
		}
	}

	if (!load_ok)
	{
		LogMessage(_T("loading lib[ %s ] failed."), moduleName);
	}
}

//////////////////////////////////////////////////////////////////////////
// static library define

#ifdef _STATIC_LIB
#define LOAD_MODULE_GLOBAL( a, b )		gkLoadStaticModule_##b(gEnv);a = (HINSTANCE)1;
#define UNLOAD_MODULE_GLOBAL( a, b )	gkFreeStaticModule_##b();a = (HINSTANCE)0;	
#else
#define LOAD_MODULE_GLOBAL( a, b )		KsLoadModule( a, _T(#b) )
#define UNLOAD_MODULE_GLOBAL( a, b )	KsFreeModule( a )
#endif
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<algorithm>
#include<functional>
#include<string>
#include<queue>

#if defined( UNICODE ) || defined( _UNICODE )
#	define KsString std::wstring
#	define KsStringStream std::wstringstream
#	define KsOStringStream std::wostringstream
#	define KsIfstream wifstream
#else
#	define KsString std::string
#	define KsStringStream std::stringstream
#	define KsOStringStream std::ostringstream
#	define KsIfstream ifstream
#endif

#ifdef WIN32
typedef uint32 thread_id;
#else
typedef pthread_t thread_id
#endif

#endif