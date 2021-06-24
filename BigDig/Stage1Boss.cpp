#include "DXUT.h"
#include "Stage1Boss.h"

void Stage1Boss::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("Stage1Boss"), SortingLayer::Default, RenderMode::Default);
}

void Stage1Boss::Start()
{
	CObject* Boss = OBJECT.Find(Tag::Boss);

	leftHand = OBJECT.AddObject(Tag::Boss);
	leftHand->ac<CSpriteRenderer>()->Init(SPRITE("leftHand"), SortingLayer::Default, RenderMode::Default);
	leftHand->ac<CCollider>()->Init(40);
	leftHand->SetParent(Boss);
	leftHand->tf->m_vPos = Vec2(WINSIZEX / 2 - 300, WINSIZEY / 2);

	rightHand = OBJECT.AddObject(Tag::Boss);
	rightHand->ac<CSpriteRenderer>()->Init(SPRITE("rightHand"), SortingLayer::Default, RenderMode::Default);
	rightHand->ac<CCollider>()->Init(40);
	rightHand->SetParent(Boss);
	rightHand->tf->m_vPos = Vec2(WINSIZEX / 2 + 300, WINSIZEY / 2);
}

void Stage1Boss::Update()
{
	CObject* Player = OBJECT.Find(Tag::Player);

	leftHand->tf->m_vRot = (math::Atan2(leftHand->tf->m_vPos, Player->tf->m_vPos));
	rightHand->tf->m_vRot = (math::Atan2(rightHand->tf->m_vPos, Player->tf->m_vPos) - 180);
	//ifdsa += 1;
	//tf->m_vRot = ifdsa;
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
	}
}

void Stage1Boss::OnCollisionStay(CObject* _pObj)
{
}

void Stage1Boss::OnCollisionExit(CObject* _pObj)
{
}

void Stage1Boss::Patern1()
{
	leftHand->tf->m_vRot = ifdsa;
}

void Stage1Boss::Patern2()
{

}

void Stage1Boss::Patern3()
{

}
