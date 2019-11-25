#pragma once
#include "GameObject.h"
#include "Bullet.h"
class BulletManager :
	public GameObject
{
public:
	BulletManager();
	~BulletManager();

	std::list<Bullet*> playerBullet;
	Bullet* PushBackPlayerBullet(Bullet* p);
	void Destroy(Bullet* b);

	virtual void LateUpdate();

private:
	std::list<Bullet*> destroyed;
	void Remove();
};

