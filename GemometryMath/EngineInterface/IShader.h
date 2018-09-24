#pragma once
#include"Platform.h"
#include "IResource.h"
#include "ITexture.h"
#include "Math/Vec2f.h"
#include "Math/Vec3f.h"
#include "Math/Vec4f.h"

enum EShaderInternalTechnique
{
	eSIT_General = 0,

	eSIT_Zpass_DL,

	eSIT_ShadowPass,

	eSIT_Zpass_DS,

	eSIT_ReflGenPass,

	eSIT_FastCubeGen,

	eSIT_Count,
};
struct ShaderMacro
{
	KsString m_name;
	KsString m_value;
	KsString m_desc;

	bool m_active;
	bool m_hidden;

	ShaderMacro()
	{
		m_active = false;
		m_hidden = false;
	}
};

enum eSystemShaderMacro
{
	eSSM_Skinned = 1 << 31,
	eSSM_Forward = 1 << 30,
	eSSM_LowProfile = 1 << 29,
	eSSM_DefaultProfile = 1 << 28,
	eSSM_HigheProfile = 1 << 27,
	eSSM_Zpass = 1 << 26,
};

typedef std::map<uint32, ShaderMacro> ShaderMacros;

class IShader :public IResource
{
public:
	IShader(IResourceManager* creator, const KsString& name, ResourceHandle handle,
		const KsString& group = _T("none")) :IResource(eRT_Shader, creator, name, handle, group) {}

	virtual ~IShader() {}

	virtual uint32 GetDefaultRenderLayer() = 0;

	virtual OnReset() = 0;

	virtual OnLost() = 0;

	virtual void SetTechniqueByName(LPCSTR name) = 0;

	virtual void SetTechnique(const char* hTech) = 0;

	virtual const char* GetTechniqueByName(LPCSTR name) = 0;

	virtual void SetValue(const char* hParam, const void* data, uint32 bytes) = 0;

	virtual void SetFloat(const char* hParam, float data) = 0;

	virtual void SetFloat2(const char* hParam, const KunSen::Vec2f& data) = 0;

	virtual void SetFloat3(const char* hParam, const KunSen::Vec3f& data) = 0;

	virtual void SetFloat4(const char* hParam, const KunSen::Vec4f& data) = 0;

	virtual void Begin(uint32* pPasses, DWORD flag) = 0;

	virtual void BeginPass(uint32 uPass) = 0;

	virtual void Commit() = 0;

	virtual void EndPass() = 0;

	virtual void End() = 0;


};


class KsShaderPtr :public SharedPtr<IShader>
{
public:
	KsShaderPtr() :SharedPtr<IShader>() {}

	explicit KsShaderPtr(IShader* rep) :SharedPtr<IShader>(rep) {}

	KsShaderPtr(const KsShaderPtr& r) :SharedPtr<IShader>(r) {}

	KsShaderPtr(const ResourcePtr& r) :SharedPtr<IShader>()
	{
		{
			pRep = static_cast<IShader*>(r.GetPointer());
			pUseCount = r.UseCountPointer();
			if (pUseCount)
			{
				++(*pUseCount);
			}
		}
	}

	KsShaderPtr& operator=(const KsShaderPtr& r)
	{
		if (pRep == static_cast<IShader*>(r.GetPointer()))
			return *this;

		Release();
		{
			pRep = static_cast<IShader*>(r.GetPointer());
			pUseCount = r.UseCountPointer();
			if (pUseCount)
			{
				++(*pUseCount);
			}
		}
	}





};