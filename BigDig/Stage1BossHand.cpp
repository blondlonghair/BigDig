#include "DXUT.h"
#include "Stage1BossHand.h"

void Stage1BossHand::Awake()
{
}

void Stage1BossHand::Start()
{
	CObject* Boss = OBJECT.Find(Tag::Boss);
}

void Stage1BossHand::Update()
{
}

void Stage1BossHand::LateUpdate()
{
}

void Stage1BossHand::OnRender()
{
}

void Stage1BossHand::OnDestroy()
{
}

void Stage1BossHand::OnCollisionEnter(CObject* _pObj)
{
	if (_pObj->m_Tag == Tag::Player)
	{
		_pObj->Destroy();
	}
}

void Stage1BossHand::OnCollisionStay(CObject* _pObj)
{
}

void Stage1BossHand::OnCollisionExit(CObject* _pObj)
{
}
