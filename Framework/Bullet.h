#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
class Bullet :
	public GameObject
{
public:
	Bullet(const wchar_t* path,
		float speed, float speedRate,
		float angle, float angleRate,
		float damage);
	~Bullet();
	float speed;
	float speedRate;
	float angle;
	float angleRate;
	float damage;

	CircleCollider* col;

	virtual void Update();
	virtual void Move();
	virtual void Destroy();
};

