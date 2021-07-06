#include "DXUT.h"
#include "Bullet.h"

void Bullet::Awake()
{
	tf->ac<CSpriteRenderer>()->Init(SPRITE("Bullet"), SortingLayer::Default, RenderMode::Default);
	tf->ac<CCollider>();
}

void Bullet::Start()
{
}

void Bullet::Update()
{
	if (tf->m_vPos.x > WINSIZEX || tf->m_vPos.x < 0 || tf->m_vPos.y > WINSIZEY || tf->m_vPos.y < 0)
	{
		tf->go->Destroy();
	}

	tf->m_vPos.x += cosf(bulletDir * PI / 180) * bulletSpeed;
	tf->m_vPos.y += -sinf(bulletDir * PI / 180) * bulletSpeed;
}

void Bullet::LateUpdate()
{
}

void Bullet::OnRender()
{
}

void Bullet::OnDestroy()
{
}

void Bullet::OnCollisionEnter(CObject* _pObj)
{
}

void Bullet::OnCollisionStay(CObject* _pObj)
{
}

void Bullet::OnCollisionExit(CObject* _pObj)
{
}

void Bullet::Init(float _dir)
{
	tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
	bulletDir = _dir + 90;
	bulletSpeed = 3;
}

void Bullet::Init(float _dir, Vec2 _pos)
{
	tf->m_vPos = _pos;
	bulletDir = _dir + 90;
	bulletSpeed = 3;
}

void Bullet::Init(float _dir, float _speed)
{
	tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
	bulletDir = _dir + 90;
	bulletSpeed = _speed;
}

void Bullet::Init(float _dir, float _speed, Vec2 _pos)
{
	tf->m_vPos = _pos;
	bulletDir = _dir + 90;
	bulletSpeed = _speed;
}
