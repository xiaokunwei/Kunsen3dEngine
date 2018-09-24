#pragma once
#include "Platform.h"
#include "IResource.h"
#include<hash_map>
enum KS_RESOURCE_MANAGER_TYPE
{
	RESOURCE_MANAGER_TYPE_TETURE,
	RESOURCE_MANAGER_TYPE_MATERIAL,
	RESOURCE_MANAGER_TYPE_MESH,
	RESOURCE_MANAGER_TYPE_SHADER
};
typedef std::hash_map<KsString, ResourcePtr> KsResourceMap;
typedef std::map<ResourceHandle, ResourcePtr> KsResourceHandleMap;

class IResourceManager
{
protected:
	KsResourceMap m_mapResource;
	ResourceHandle m_hNextHandle;
	KsResourceHandleMap m_mapResourcesByHandle;

};