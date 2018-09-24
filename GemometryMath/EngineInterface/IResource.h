#ifndef IRESOURCE_FILE_H_
#define IRESOURCE_FILE_H_

#include"Platform.h"
struct ITask;

class IResourceManager;

typedef unsigned long long int ResourceHandle;

enum ResourceType
{
	Texture,
	Mesh,
	Shader,
	Material
};

struct IResourceResetCallBack
{
	virtual void OnResetCallBack() = 0;
};

class IResource
{
protected:
	KsString m_FileName;
	KsString m_GroupName;
	KsString m_ShortName;

	ResourceHandle m_Handle;
	uint32 m_Size;
	bool m_bIsLoad;
	IResourceManager* m_Manager;
	ResourceType m_Type;
	IResourceResetCallBack* m_CallBack;


protected:

	virtual bool LoadImpl() = 0;
	virtual bool UnLoadImpl() = 0;

public:
	IResource(ResourceType type, IResourceManager* creator, const KsString& name, ResourceHandle handle,
		const KsString& group = _T("none"))
	{
		m_Type = type;
		m_Manager = creator;
		m_FileName = name;
		m_Handle = handle;
		m_GroupName = group;
		m_bIsLoad = false;
		m_CallBack = NULL;


	}

	virtual ~IResource()
	{
		
	}
	virtual bool Load()
	{
		if (m_bIsLoad)
		{
			return true;
		}
		if (!LoadImpl())
		{
			return false;
		}
		m_bIsLoad = true;
		return true;
	}
	virtual void Reload()
	{
	
		UnLoad();
		Load();
	}
	virtual void UnLoad()
	{
		if (!m_bIsLoad)
		{
			return;
		}
		UnLoadImpl();
		m_bIsLoad = false;
	}
	virtual const KsString& GetName()
	{
		return m_FileName;
	}
	virtual const KsString& GetShortName()const
	{
		return m_ShortName;
	}

	virtual const KsString& GetGroupName()const
	{
		return m_GroupName;
	}
	virtual const ResourceHandle GetHandle()const
	{
		return m_Handle;
	}

	virtual ResourceType GetType()const{ return m_Type; }

	void BindResetCallBack(IResourceResetCallBack* callBack)
	{
		m_CallBack = callBack;
	}
	uint32 GetMemUsage()
	{
		return m_Size;
	}





};

#include"SharedPtr.h"
typedef SharedPtr<IResource> ResourcePtr;
#endif