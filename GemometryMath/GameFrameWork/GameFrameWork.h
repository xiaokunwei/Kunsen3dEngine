#ifndef GAMEFRAMEWORK_FILE_H
#define GAMEFRAMEWORK_FILE_H
#include"Prequesities.h"
#include"IGameFrameWork.h"

struct IGame;

struct SystemGlobalEnvironment;

typedef IGame* (*GET_GAMEDLL)(SystemGlobalEnvironment*);

typedef void(*DESTROY_GAMEDLL)();

class GameFrameWork :public IGameFrameWork
{
public:

	GameFrameWork();

	virtual ~GameFrameWork(){}

	virtual bool Init(ISystemInitInfo& sii);

	virtual bool PostInit(HWND hWnd, ISystemInitInfo& sii);

	virtual void Run();

	virtual bool Destroy();

	virtual bool Update();

	virtual bool InitGame(const TCHAR* dllName);

	virtual bool DestroyGame(bool defered = true);

	virtual void LoadLevel(const TCHAR* filename);

	virtual void OnLevelLoaded();

	virtual void MarkClose();

	virtual SystemGlobalEnvironment* GetEnvironment();

private:
	GET_GAMEDLL  m_pFuncGameStart;
	DESTROY_GAMEDLL m_pFuncGameEnd;

	HINSTANCE m_handleGame;

	IGame* m_pGame;
};

#endif