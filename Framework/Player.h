#pragma once
#include "GameObject.h"
#include "BulletManager.h"	//��Ŭ��� ����
class Player :
	public GameObject
{
public:
	Player(const wchar_t* path,
		BulletManager* bm);
	~Player();

	float moveSpeed;	//�̵� �ӵ�
	virtual void Update();	//������Ʈ ó��

	BulletManager* bm;		//�Ѿ� �Ŵ���
	void WShoot();			//�Ѿ� �߻�
	void AShoot();
	void SShoot();
	void DShoot();
	void CreateBullet(float speed, float angle);
};