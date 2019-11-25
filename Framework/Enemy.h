#pragma once
#include "GameObject.h"
#include "BulletManager.h"
#include "CircleCollider.h"
class Enemy :
	public GameObject
{
public:
	Enemy(const wchar_t* path,
		BulletManager* bm);
	~Enemy();

	float hp;
	float transferTime;
	float timer;
	float delay = 5.0f;
	float aimX;
	float aimY;

	bool canMove;
	bool dead;

	virtual void Update();

	void Hit(float damage);
	void Move(float x, float y);
	
	CircleCollider* col;
	BulletManager* bm;
};

