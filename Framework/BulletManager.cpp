#include "stdafx.h"
#include "BulletManager.h"
#include "Scene.h"

BulletManager::BulletManager()
{
}

BulletManager::~BulletManager()
{
}

Bullet* BulletManager
::PushBackPlayerBullet(Bullet* b)
{
	Scene::GetCurrentScene().
		PushBackGameObject(b);
	playerBullet.push_back(b);
	return b;
}

void BulletManager::Destroy(Bullet* b)
{
	destroyed.push_back(b);
}

void BulletManager::Remove()
{
	for (auto& i : destroyed)
	{
		i->Destroy();
		playerBullet.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}

void BulletManager::LateUpdate()
{
	Remove();
}