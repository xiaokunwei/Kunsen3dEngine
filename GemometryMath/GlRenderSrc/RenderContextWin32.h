#ifndef RENDERCONTEXTWIN32_FILE_H
#define RENDERCONTEXTWIN32_FILE_H
#include"Prerequisites.h"

#include"DeviceRenderContext.h"

/* Entry points */
typedef int (APIENTRY * PFNWGLSWAPINTERVALEXTPROC) (int);

/* Entry points */
typedef const char *(APIENTRY * PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC);

/* Entry points */
typedef const char *(APIENTRY * PFNWGLGETEXTENSIONSSTRINGEXTPROC)(void);

/* Entry points */
typedef BOOL(WINAPI * PFNWGLGETPIXELFORMATATTRIBIVARBPROC) (HDC, int, int, UINT, const int *, int *);

/* Entry points */
typedef HGLRC(WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC, HGLRC, const int *);
typedef const GLubyte * (APIENTRY *PFNGLGETSTRINGIPROC) (GLenum, GLuint);

#define WGL_CONTEXT_MAJOR_VERSION_ARB          0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB          0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB            0x2093
#define WGL_CONTEXT_FLAGS_ARB                  0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB           0x9126

/* Bits for WGL_CONTEXT_FLAGS_ARB */
#define WGL_CONTEXT_DEBUG_BIT_ARB              0x0001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x0002

/* Bits for WGL_CONTEXT_PROFILE_MASK_ARB */
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002


class DeviceRenderContext :public IDviceRenderContext
{
public:
	DeviceRenderContext();
	~DeviceRenderContext();

	virtual HWND InitDevice(ISystemInitInfo& sii);

	virtual bool DestroyDevice();
	

	virtual void SwapBuffer();
	virtual void MakeThreadContext(bool close = false);

	virtual void ResizeBackBuffer(int width, int height);

private:



	bool SetWindow(int width, int height, bool fullScreen, HWND hwnd);
	HWND								m_hWnd;
	DWORD							m_dwWindowStyle;
	HINSTANCE							m_hInst;

	HGLRC							m_mainContext;
	HDC								m_dc;

	PFNWGLSWAPINTERVALEXTPROC SwapIntervalEXT;


};
#endif
