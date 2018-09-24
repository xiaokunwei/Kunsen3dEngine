#ifndef RENDERER_FILE_H
#define RENDERER_FILE_H

#include"Platform.h"
#include"..\Include\Math\Vec3f.h"

class IResourceManager;

struct IAuxRenderer;

struct IRenderSequence;
struct IParticleProxy;

struct RenderLight
{
	KunSen::Vec3f m_Pos;
	KunSen::Vec3f m_Dir;
	KunSen::Vec3f m_Diffuse;
	KunSen::Vec3f m_Specular;
	float m_HDRPower;
	float m_Radius;
	
	RenderLight()
	{
		m_Pos = KunSen::Vec3f(0, 0, 0);
		m_Dir = KunSen::Vec3f(0, 0, 1);
		m_Diffuse = KunSen::Vec3f(1, 1, 1);
		m_Specular = KunSen::Vec3f(1, 1, 1);

		m_HDRPower = 1;
		m_Radius = 5;
	}
};

typedef std::list<RenderLight> RenderLightList;


enum  ERenderAPI
{
	D3D9,
	D3D11,
	OPENGL,
	OPENGLES,
};

struct IRenderer
{
public:
	virtual ~IRenderer(){}

	//virtual IResourceManager* GetResourceManager(BYTE type) = 0;

	virtual HWND Init(struct ISystemInitInfo& sii) = 0;

	virtual void Destroy() = 0;

	//virtual IParticleProxy* CreateGPUParticleProxy() = 0;

	//virtual void DestroyGPUParticleProxy(IParticleProxy*) = 0;

	virtual IRenderSequence* SwapRenderSequence() = 0;

	virtual IRenderSequence* GetRenderSequence() = 0;

	virtual void CleanRenderSequence() = 0;

	virtual bool StartRender() = 0;

	virtual bool EndRender() = 0;

	virtual void SkipOnFrame(int frameCount = 1) = 0;

	virtual void SetSunDir(const KunSen::Vec3f& lightDir) = 0;

	virtual uint32 GetScreenHeight(bool forceOrigin = false) = 0;

	virtual uint32 GetScreenWidth(bool forceOrigin = false) = 0;

	virtual void SetCurrContent(HWND hWnd, uint32 posx, uint32 posy, uint32 width, uint32 height, bool fullscreen = false) = 0;

	virtual HWND GetWindowHwnd() = 0;

	virtual ERenderAPI GetRenderAPI() = 0;

	virtual bool FullScreenMode(){ return true; }


	
};
#endif // !RENDERER_FILE_H
