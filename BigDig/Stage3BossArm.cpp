#include "DXUT.h"
#include "Stage3BossArm.h"

void Stage3BossArm::Awake()
{
}

void Stage3BossArm::Start()
{
}

void Stage3BossArm::Update()
{
}

void Stage3BossArm::LateUpdate()
{
}

void Stage3BossArm::OnRender()
{
}

void Stage3BossArm::OnDestroy()
{
}

void Stage3BossArm::OnCollisionEnter(CObject* _pObj)
{
	if (_pObj->m_Tag == Tag::Player)
	{
		CObject* player = OBJECT.Find(Tag::Player);
		player->gc<Stage3Player>()->isHit = true;
	}
	//OutputDebugStringA("\nBossEnter\n");
}

void Stage3BossArm::OnCollisionStay(CObject* _pObj)
{
	//OutputDebugStringA("\nBossStay\n");
}

void Stage3BossArm::OnCollisionExit(CObject* _pObj)
{
	//OutputDebugStringA("\nBossExit\n");
}
