#ifndef IGAME_FILE_H
#define IGAME_FILE_H

struct IGame
{
	virtual ~IGame(){}

	virtual bool OnInit() = 0;

	virtual bool OnDestroy() = 0;

	virtual bool OnUpdate() = 0;

	virtual bool OnLevelLoaded() = 0;
};
#endif