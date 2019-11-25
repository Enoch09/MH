#include "stdafx.h"
#include "GameScene.h"
#include "PhysicsManager.h"


GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	background
		= PushBackGameObject(
		new GameObject(L"resources/Elder'sRecess.png", Vector2(600.0f, 450.0f)));
	
	BulletManager* bm
		=(BulletManager*)
		PushBackGameObject(
			new BulletManager());
	player = 
		(Player*)PushBackGameObject(
		new Player(
			L"resources/player/Nergigante.png",
			bm));
	player->transform->SetPosition(600.0f, 450.0f);
	EnemyManager* em = (EnemyManager*)PushBackGameObject(
		new EnemyManager());
	PhysicsManager* pm = (PhysicsManager*)PushBackGameObject(
		new PhysicsManager(player, em, bm));

	Enemy* Namielle = em->PushBackEnemy(new Enemy(L"resources/Enemy/Namielle.png", bm));
	Namielle->transform->SetPosition(500.0f, 100.0f);

	Enemy* VaalHazak = em->PushBackEnemy(new Enemy(L"resources/Enemy/VaalHazak.png", bm));
	VaalHazak->transform->SetPosition(800.0f, 100.0f);

	Enemy* Bazelgeuse = em->PushBackEnemy(new Enemy(L"resources/Enemy/Bazelgeuse.png", bm));
	Bazelgeuse->transform->SetPosition(600.0f, 800.0f);
	if (Namielle->dead && VaalHazak->dead && Bazelgeuse->dead) {
		Enemy* Xenojiiva = em->PushBackEnemy(new Enemy(L"resources/Enemy/Xenojiiva.png", bm));
		Xenojiiva->transform->SetPosition(600.0f, 450.0f);
	}
}