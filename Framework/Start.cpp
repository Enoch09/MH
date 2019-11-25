#include "stdafx.h"
#include "Start.h"
#include "InputManager.h"
#include "Scene.h"


Start::Start()
{
	
}


Start::~Start()
{
}

void Start::Update() {
	if (InputManager::GetKeyState(VK_SPACE))
		Scene::ChangeScene(new GameScene());
}