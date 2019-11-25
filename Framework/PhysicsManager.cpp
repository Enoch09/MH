#include "stdafx.h"
#include "PhysicsManager.h"


PhysicsManager::PhysicsManager(Player* p, EnemyManager* em, BulletManager* bm)
:player(p), em(em), bm(bm)
{
}


PhysicsManager::~PhysicsManager()
{
}
void PhysicsManager::LateUpdate()
{
	if (!bm || !em || !player)
		return;
	for (auto& i : bm->playerBullet)
	{

		for (auto& j : em->enemyList)
		{
			if (i->col->Intersected(*j->col))
			{
				em->Hit(j, i->damage);
				bm->Destroy(i);
			}
		}
	}
}
