#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"


Player::Player(const wchar_t* path,
		BulletManager* bm)
:GameObject(path), bm(bm)
{
	moveSpeed = 3.0f;
}

void Player::Update()
{

	if (!(transform->position.x > 1200)) {
		if (InputManager::GetKeyState(VK_RIGHT))
			transform->position.x += moveSpeed;
	}
	if (transform->position.x > 0) {
		if (InputManager::GetKeyState(VK_LEFT))
			transform->position.x -= moveSpeed;
	}
	if (transform->position.y > 0) {
		if (InputManager::GetKeyState(VK_UP))
			transform->position.y -= moveSpeed;
	}
	if (!(transform->position.y > 900)) {
		if (InputManager::GetKeyState(VK_DOWN))
			transform->position.y += moveSpeed;
	}
	
	
	
	if (InputManager::GetKeyDown(0x57))
	{
		WShoot();
	}
	if (InputManager::GetKeyDown(0x41))
	{
		AShoot();
	}
	if (InputManager::GetKeyDown(0x53))
	{
		SShoot();
	}
	if (InputManager::GetKeyDown(0x44))
	{
		DShoot();
	}
}


Player::~Player()
{
}


void Player::WShoot()
{
	for (float i = 0.72f; i <= 0.78f; i += 0.03f)
	{
		CreateBullet(300.0f, i);//i
	}
}
void Player::AShoot()
{
	for (float i = 0.47f; i <= 0.53f; i += 0.03f)
	{
		CreateBullet(300.0f, i);//i
	}
}
void Player::SShoot()
{
	for (float i = 0.22f; i <= 0.28f; i += 0.03f)
	{
		CreateBullet(300.0f, i);//i
	}
}
void Player::DShoot()
{
	for (float i = 0.97f; i <= 1.03f; i += 0.03f)
	{
		CreateBullet(300.0f, i);//i
	}
}
void Player::CreateBullet(float speed, float angle)
{
	Bullet* b = bm->PushBackPlayerBullet(
		new Bullet(L"bone-2.png", speed,
		1.0f, angle, 0.0f, 1.0f)
		);
	b->transform->position
		= transform->position;
	//b->transform->SetScale(0.1f, 0.1f);
}