#include "DXUT.h"
#include "Stage1Boss.h"

void Stage1Boss::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("Stage1Boss"), SortingLayer::Default, RenderMode::Default);
}

void Stage1Boss::Start()
{
	player = OBJECT.Find(Tag::Player)->gc<Stage1Player>();

	leftHand = OBJECT.AddObject(Tag::Boss);
	leftHand->ac<CSpriteRenderer>()->Init(SPRITE("leftHand"), SortingLayer::Default, RenderMode::Default);
	leftHand->ac<CCollider>()->Init(40);
	leftHand->ac<Stage1BossArm>();
	leftHand->tf->m_vPos = Vec2(WINSIZEX / 2 - 300, WINSIZEY / 2);

	rightHand = OBJECT.AddObject(Tag::Boss);
	rightHand->ac<CSpriteRenderer>()->Init(SPRITE("rightHand"), SortingLayer::Default, RenderMode::Default);
	rightHand->ac<CCollider>()->Init(40);
	rightHand->ac<Stage1BossArm>();
	rightHand->tf->m_vPos = Vec2(WINSIZEX / 2 + 300, WINSIZEY / 2);
}

void Stage1Boss::Update()
{
	if (fuck)
	{
		Pattern3();
	}
}
void Stage1Boss::LateUpdate()
{
}

void Stage1Boss::OnRender()
{
}

void Stage1Boss::OnDestroy()
{
}

void Stage1Boss::OnCollisionEnter(CObject* _pObj)
{
	if (_pObj->m_Tag == Tag::Player)
	{
		_pObj->gc<Stage1Player>()->isHit = true;
		GAME.m_playerLife--;
		CObject* stage1UI = OBJECT.Find(Tag::Stage1UI);
		stage1UI->gc<Stage1UI>()->HeartUI();
		fuck = false;
	}
}

void Stage1Boss::OnCollisionStay(CObject* _pObj)
{
}

void Stage1Boss::OnCollisionExit(CObject* _pObj)
{
}

void Stage1Boss::Pattern1()
{
	leftHand->tf->m_vPos.x = cos(1);
	leftHand->tf->m_vPos.y = sin(1);
}

void Stage1Boss::Pattern2()
{
}

void Stage1Boss::Pattern3()
{
	fTime += dt;

	if (fTime <= 2)
	{
		leftHand->tf->m_vRot = (math::Atan2(leftHand->tf->m_vPos, player->tf->m_vPos));
		rightHand->tf->m_vRot = (math::Atan2(rightHand->tf->m_vPos, player->tf->m_vPos) - 180);
		playerPos = player->tf->m_vPos;
	}
	if (fTime >= 3)
	{
		leftHand->tf->m_vPos -= (leftHand->tf->m_vPos - playerPos) / 10;
		rightHand->tf->m_vPos -= (rightHand->tf->m_vPos - playerPos) / 10;
	}
	if (fTime >= 3.5)
	{
		fTime = 0;
		return;
	}
}
