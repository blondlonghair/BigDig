#include "DXUT.h"
#include "Bullet2.h"

void Bullet2::Awake()
{
	tf->ac<CSpriteRenderer>()->Init(SPRITE("Bullet2"), SortingLayer::Default, RenderMode::Default);
	tf->ac<CCollider>();
}

void Bullet2::Start()
{
}

void Bullet2::Update()
{
	if (tf->m_vPos.x > WINSIZEX || tf->m_vPos.x < 0 || tf->m_vPos.y > WINSIZEY || tf->m_vPos.y < 0)
	{
		tf->go->Destroy();
	}

	tf->m_vPos.x += cosf(bulletDir * PI / 180) * bulletSpeed;
	tf->m_vPos.y += -sinf(bulletDir * PI / 180) * bulletSpeed;
}

void Bullet2::LateUpdate()
{
}

void Bullet2::OnRender()
{
}

void Bullet2::OnDestroy()
{
}

void Bullet2::OnCollisionEnter(CObject* _pObj)
{
}

void Bullet2::OnCollisionStay(CObject* _pObj)
{
}

void Bullet2::OnCollisionExit(CObject* _pObj)
{
}

void Bullet2::Init(float _dir)
{
	tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
	bulletDir = _dir + 90;
	bulletSpeed = 3;
}

void Bullet2::Init(float _dir, Vec2 _pos)
{
	tf->m_vPos = _pos;
	bulletDir = _dir + 90;
	bulletSpeed = 3;
}

void Bullet2::Init(float _dir, float _speed)
{
	tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
	bulletDir = _dir + 90;
	bulletSpeed = _speed;
}

void Bullet2::Init(float _dir, float _speed, Vec2 _pos)
{
	tf->m_vPos = _pos;
	bulletDir = _dir + 90;
	bulletSpeed = _speed;
}
