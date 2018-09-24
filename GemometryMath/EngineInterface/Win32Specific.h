#ifndef WIN32SPECIFIC_FILE_H
#define WIN32SPECIFIC_FILE_H

#ifndef _M_X64
#define _CPU_X86
#define _CPU_SSE
#endif

#ifndef _AFXDLL
#include<Windows.h>
#endif

typedef signed char				int8;
typedef signed short			int16;
typedef signed int				int32;
typedef signed __int64			int64;
typedef unsigned char			uint8;
typedef unsigned char			BYTE;
typedef unsigned short			uint16;
typedef unsigned int			uint32;
typedef unsigned __int64		uint64;
typedef float					f32;
typedef double					f64;
typedef double					real;  //biggest float-type on this machine

typedef unsigned long			DWORD;  //biggest float-type on this machine

#if defined(_WIN64)
typedef __int64 INT_PTR, *PINT_PTR;
typedef unsigned __int64 UINT_PTR, *PUINT_PTR;

typedef __int64 LONG_PTR, *PLONG_PTR;
typedef unsigned __int64 ULONG_PTR, *PULONG_PTR;

typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;

typedef __int64 gk_ptr_type;
#else
typedef int gk_ptr_type;

typedef __w64 int INT_PTR, *PINT_PTR;
typedef __w64 unsigned int UINT_PTR, *PUINT_PTR;

typedef __w64 long LONG_PTR, *PLONG_PTR;
typedef __w64 unsigned long ULONG_PTR, *PULONG_PTR;

typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;
#endif

typedef void *THREAD_HANDLE;
typedef void *EVENT_HANDLE;

#if defined(DEBUG) || defined(_DEBUG)
#ifndef V
#define V(x)           { hr = (x); if( FAILED(hr) ) { /*DXUTTrace( __FILE__, (DWORD)__LINE__, hr, L#x, true )*/; } }
#endif
#ifndef V_RETURN
#define V_RETURN(x)    { hr = (x); if( FAILED(hr) ) { return hr/*DXUTTrace( __FILE__, (DWORD)__LINE__, hr, L#x, true )*/; } }
#endif
#else
#ifndef V
#define V(x)           { hr = (x); }
#endif
#ifndef V_RETURN
#define V_RETURN(x)    { hr = (x); if( FAILED(hr) ) { return hr; } }
#endif
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)			{ if(p) { delete (p);		(p)=NULL; } }
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)	{ if(p) { delete [] (p);		(p)=NULL; } }
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)			{ if(p) { (p)->Release();	(p)=NULL; } }
#endif

#ifndef SAFE_release
#define SAFE_release(p)			{ if(p) { (p)->release();	(p)=NULL; } }
#endif

//#ifdef _DEBUG
#define ILINE inline
//#else
//#define ILINE inline
//#endif
#include<tchar.h>

#include "io.h"
#include <dos.h>
#endif // !WIN32SPECIFIC_FILE_H
