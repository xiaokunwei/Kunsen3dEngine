#pragma once
#include "Platform.h"
#include "IResource.h"

enum ETextureFormat
{

	eTF_RGB4,
	eTF_RGB5,
	eTF_RGB8,
	eTF_RGB10,
	eTF_RGB12,
	eTF_RGB16,
	eTF_RGBA2,
	eTF_RGBA4,
	eTF_RGB5_A1,
	eTF_RGBA8,
	eTF_RGB10_A2,
	eTF_RGBA12,
	eTF_RGBA16,

	eTF_A8,
	eTF_R8,

	eTF_RGBA32F,
	eTF_RGB32F,
	eTF_RGBA16F,
	eTF_RGB16F,

	eTF_RG16F,

	eTF_R32F,
	eTF_R16F,

	eTF_DXT5,
	eTF_DXT3,
	eTF_DXT1,

	eTF_NULL,
	eTF_INTZ,

	eTF_UnKnown,
};

class ITexture :public IResource
{
public:
	ITexture(IResourceManager* creator, const KsString& name, ResourceHandle handle,
		const KsString& group = _T("none")) :IResource(Texture, creator, name, handle, group)
	{

	}
	virtual ~ITexture() {}

	virtual Apply(uint32 channel, uint8 filter) = 0;

	virtual uint32 GetHeight() = 0;

	virtual uint32 GetWidth() = 0;

	virtual uint32 GetMipLevel() = 0;

	virtual void OnReset() = 0;

	virtual void OnLost() = 0;

	virtual void UnLock() {}

	virtual bool Dynamic() { return false; }

	virtual bool Sizable() { return false; }

	virtual void CalcMemUsage() {}


};
class KsTexturePtr :public SharedPtr<ITexture>
{
public:
	KsTexturePtr() :SharedPtr<ITexture>() {}
	KsTexturePtr(ITexture* rep) :SharedPtr<ITexture>(rep) {}
	KsTexturePtr(const KsTexturePtr& r) :SharedPtr<ITexture>(r) {}
	KsTexturePtr(const KsTexturePtr& r) :SharedPtr<ITexture>()
	{
		pRep = static_cast<ITexture*>(r.GetPointer());
		pUseCount = r.UseCountPointer();
		if (pUseCount)
		{
			++(*pUseCount);
		}
	}
	KsTexturePtr& operator=(const KsTexturePtr& r)
	{
		if (pRep == static_cast<ITexture*>(r.GetPointer()))
			return *this;

		Release();

		{
			pRep = static_cast<ITexture*>(r.GetPointer());
			pUseCount = r.UseCountPointer();
			if (pUseCount)
			{
				++(*pUseCount);
			}
		}
	}



};