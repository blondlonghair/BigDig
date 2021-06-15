#include "DXUT.h"
#include "Stage1Boss.h"

void Stage1Boss::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("Stage1Boss"), SortingLayer::Default, RenderMode::Default);
}

void Stage1Boss::Start()
{
	leftHand = OBJECT.AddObject(Tag::Boss);
	leftHand->ac<CSpriteRenderer>()->Init(SPRITE("leftHand"), SortingLayer::Default, RenderMode::Default);
	leftHand->ac<CCollider>()->Init(40);
	leftHand->m_pParent = 
	rightHand = OBJECT.AddObject(Tag::Boss);
	rightHand->ac<CSpriteRenderer>()->Init(SPRITE("rightHand"), SortingLayer::Default, RenderMode::Default);
	rightHand->ac<CCollider>()->Init(40);
}

void Stage1Boss::Update()
{
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
		_pObj->Destroy();
	}
}

void Stage1Boss::OnCollisionStay(CObject* _pObj)
{
}

void Stage1Boss::OnCollisionExit(CObject* _pObj)
{
}
