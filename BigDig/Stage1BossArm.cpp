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
		CObject* player = OBJECT.Find(Tag::Player);
		player->gc<Stage1Player>()->isHit = true;
	}
	//OutputDebugStringA("\nBossEnter\n");
}

void Stage1BossArm::OnCollisionStay(CObject* _pObj)
{
	//OutputDebugStringA("\nBossStay\n");
}

void Stage1BossArm::OnCollisionExit(CObject* _pObj)
{
	//OutputDebugStringA("\nBossExit\n");
}
