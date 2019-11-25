#pragma once
#include "Scene.h"
#include "Start.h"


class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	virtual void Initialize();

	Start* start;
	GameObject* background;

};
