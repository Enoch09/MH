#pragma once
#include "GameObject.h"
#include "BulletManager.h"	//인클루드 ㄱㄱ
class Player :
	public GameObject
{
public:
	Player(const wchar_t* path,
		BulletManager* bm);
	~Player();

	float moveSpeed;	//이동 속도
	virtual void Update();	//업데이트 처리

	BulletManager* bm;		//총알 매니저
	void WShoot();			//총알 발사
	void AShoot();
	void SShoot();
	void DShoot();
	void CreateBullet(float speed, float angle);
};