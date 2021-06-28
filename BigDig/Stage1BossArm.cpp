#include "DXUT.h"
#include "Stage1BossArm.h"

void Stage1BossArm::Awake()
{
}

void Stage1BossArm::Start()
{
}

void Stage1BossArm::Update()
{
}

void Stage1BossArm::LateUpdate()
{
}

void Stage1BossArm::OnRender()
{
}

void Stage1BossArm::OnDestroy()
{
}

void Stage1BossArm::OnCollisionEnter(CObject* _pObj) 
{
	if (_pObj->m_Tag == Tag::Player)
	{
		_pObj->gc<Stage1Player>()->isHit = true;
		GAME.m_playerLife--;
		CObject* stage1UI = OBJECT.Find(Tag::Stage1UI);
		stage1UI->gc<Stage1UI>()->HeartUI();
		
	}
}

void Stage1BossArm::OnCollisionStay(CObject* _pObj)
{
}

void Stage1BossArm::OnCollisionExit(CObject* _pObj)
{
}
