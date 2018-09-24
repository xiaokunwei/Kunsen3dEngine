#ifndef I3DENGINE_H_
#define I3DENGINE_H_

struct ICamera;


#include<string>
struct IGameObject;

struct ITimeOfDay;

struct ITerrianSystem;

struct Renderable;

#include "Math/Vec3f.h"

struct I3DEngine
{
public:
	virtual ~I3DEngine(){}

	virtual void Init() = 0;

	virtual void Destroy() = 0;

	virtual ICamera* CreateCamera(const std::string& name) = 0;

	virtual ICamera* GetCamera(const std::string& name) const = 0;

	virtual bool HasCamera(const std::string& name)const = 0;

	virtual void DestroyCamera(const std::string& name) = 0;

	virtual void DestroyAllCamera(const std::string& name) = 0;

	virtual void SetMainCamera(ICamera* cam) = 0;

	virtual ICamera* GetMainCamera() = 0;

	virtual ICamera* GetRenderingCamera(ICamera* cam) = 0;

	virtual void RemoveRenderLayer(const std::string& meshName) = 0;

	virtual void DestroyAllLayer() = 0;

	virtual  ITerrianSystem* CreateTerrian() = 0;

	virtual void DestroyTerrain(ITerrianSystem* terrian) = 0;

	virtual void DestroyTerrainSync(ITerrianSystem* terrain) = 0;

	virtual ITerrianSystem* GetTerrain() = 0;



};

#endif