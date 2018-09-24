#ifndef DEVICERENDERCONTEXT_FILE_H
#define DEVICERENDERCONTEXT_FILE_H
#include"Prerequisites.h"
struct IDviceRenderContext
{
public:
	virtual ~IDviceRenderContext(){}
	virtual HWND InitDevice(ISystemInitInfo& sii) = 0;

	virtual bool DestroyDevice() = 0;
	virtual void StartRender(){}
	virtual void EndRender() {}

	virtual void SwapBuffer() = 0;

	virtual void MakeThreadContext(bool close = false) = 0;

	virtual void ResizeBackBuffer(int width, int height) = 0;
 
};
#endif