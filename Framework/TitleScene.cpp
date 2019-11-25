#include "stdafx.h"
#include "TitleScene.h"


TitleScene::TitleScene()
{
	
}


TitleScene::~TitleScene()
{
}
void TitleScene::Initialize()
{
	background
		= PushBackGameObject(
			new GameObject(L"resources/titleScene.png", Vector2(600.0f, 450.0f)));

	start = (Start*)PushBackGameObject(new Start());
	
}
