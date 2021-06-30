#include "DXUT.h"
#include "Stage2BossArm.h"

void Stage2BossArm::Awake()
{
}

void Stage2BossArm::Start()
{
}

void Stage2BossArm::Update()
{
}

void Stage2BossArm::LateUpdate()
{
}

void Stage2BossArm::OnRender()
{
}

void Stage2BossArm::OnDestroy()
{
}

void Stage2BossArm::OnCollisionEnter(CObject* _pObj)
{
	if (_pObj->m_Tag == Tag::Player)
	{
		CObject* player = OBJECT.Find(Tag::Player);
		player->gc<Stage2Player>()->isHit = true;
	}
	//OutputDebugStringA("\nBossEnter\n");
}

void Stage2BossArm::OnCollisionStay(CObject* _pObj)
{
	//OutputDebugStringA("\nBossStay\n");
}

void Stage2BossArm::OnCollisionExit(CObject* _pObj)
{
	//OutputDebugStringA("\nBossExit\n");
}
