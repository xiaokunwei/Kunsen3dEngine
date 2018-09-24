#ifndef RENDERGL330_FILE_H
#define RENDERGL330_FILE_H
#include"Prerequisites.h"
#include"DeviceRenderContext.h"
class RendererGL :public IRenderer
{
public:
	RendererGL();
	~RendererGL();

	virtual HWND Init(ISystemInitInfo& sii);

	virtual void Destroy();

	virtual IRenderSequence* SwapRenderSequence();

	virtual IRenderSequence* GetRenderSequence();

	virtual void CleanRenderSequence();

	virtual bool StartRender();

	virtual bool EndRender();

	virtual void SkipOnFrame(int frameCount = 1);

	virtual void SetSunDir(const KunSen::Vec3f& lightDir);

	virtual uint32 GetScreenHeight(bool forceOrigin = false);

	virtual uint32 GetScreenWidth(bool forceOrigin = false);

	virtual void SetCurrContent(HWND hWnd, uint32 posx, uint32 posy, uint32 width, uint32 height, bool fullscreen = false);

	virtual HWND GetWindowHwnd();

	virtual ERenderAPI GetRenderAPI();

	virtual bool FullScreenMode();


private:

	uint32 m_ScreenWidth;
	uint32 m_ScreenHeight;

	IDviceRenderContext* m_pDeviceContext;
	GLint m_backBufferFBO;

	GLuint m_rtFBO;
	GLuint m_drtFBO;

	HWND m_hWnd;

	GLuint vbo;
	GLuint vao;

	GLuint shaderProgram;


};

RendererGL* GetRenderer();
#endif

