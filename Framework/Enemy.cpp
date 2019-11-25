#include "stdafx.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "TimeManager.h"


Enemy::Enemy(const wchar_t* path,
	BulletManager* bm)
	:GameObject(path), bm(bm),
	hp(10.0f),transferTime(3.0f)
{
	col = new CircleCollider(
		*transform, renderer->GetWidth()*0.5f);
	
	
	timer = 0.0f;
	canMove = false;
	dead = false;
	aimX = 0.0f;
	aimY = 0.0f;
	srand((unsigned int)time(NULL));
}
Enemy::~Enemy()
{
	SAFE_DELETE(col);
}
void Enemy::Hit(float damage)
{
	hp -= damage;
	std::cout << "hp가 " << hp << "남았어요" << std::endl;
}
void Enemy::Update()
 {
	
	if (hp <= 0) {
		dead = true;
	}
	else {
		if (timer > delay) {
			aimX = (rand() % 1200)*1.0f;
			aimY = (rand() % 900)*1.0f;
			canMove = true;
			timer = 0.0f;
		}


		if (canMove)
			Move(aimX, aimY);
		if (aimX > transform->position.x && aimY > transform->position.y)
			canMove = false;

		timer += TimeManager::GetDeltaTime();
	}
}
void Enemy::Move(float x, float y)
{
	float speedX = (x - transform->position.x)/transferTime;
	float speedY = (y - transform->position.y)/transferTime;
	if (x < transform->position.x&&y<transform->position.y) {
		transform->position.x += speedX * TimeManager::GetDeltaTime();//-
		transform->position.y += speedY * TimeManager::GetDeltaTime();//-
	}
	else if (x > transform->position.x&&y < transform->position.y) {
		transform->position.x += speedX * TimeManager::GetDeltaTime();
		transform->position.y += speedY * TimeManager::GetDeltaTime();//-
	}
	else if (x < transform->position.x&&y > transform->position.y) {	
		transform->position.x += speedX * TimeManager::GetDeltaTime();//-
		transform->position.y += speedY * TimeManager::GetDeltaTime();
	}
	else if (x > transform->position.x&&y > transform->position.y) {
		transform->position.x += speedX * TimeManager::GetDeltaTime();
		transform->position.y += speedY * TimeManager::GetDeltaTime();
		
	}
}
