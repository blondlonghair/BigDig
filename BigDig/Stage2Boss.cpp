#include "DXUT.h"
#include "Stage2Boss.h"

void Stage2Boss::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("Stage1Boss"), SortingLayer::Default, RenderMode::Default);
	player2 = new Stage2Player();
}

void Stage2Boss::Start()
{
	player2 = OBJECT.Find(Tag::Player)->gc<Stage2Player>();

	leftHand = OBJECT.AddObject(Tag::Boss);
	leftHand->ac<CSpriteRenderer>()->Init(SPRITE("leftHand"), SortingLayer::Default, RenderMode::Default);
	leftHand->ac<CCollider>()->Init(90);
	leftHand->ac<Stage2BossArm>();
	leftHand->tf->m_vPos = Vec2(WINSIZEX / 2 - 300, WINSIZEY / 2);

	rightHand = OBJECT.AddObject(Tag::Boss);
	rightHand->ac<CSpriteRenderer>()->Init(SPRITE("rightHand"), SortingLayer::Default, RenderMode::Default);
	rightHand->ac<CCollider>()->Init(90);
	rightHand->ac<Stage2BossArm>();
	rightHand->tf->m_vPos = Vec2(WINSIZEX / 2 + 300, WINSIZEY / 2);
}

void Stage2Boss::Update()
{
	if (GAME.isStart)
	{
		bossPatternTime += dt;


		if (bossPatternTime >= 5)
		{
			nextPattern = math::RandRange(1, 4);
			bossPatternTime = 0;
		}
		switch (nextPattern)
		{
		case 1: Pattern1(); break;
		case 2: Pattern2(); break;
		case 3: Pattern3(); break;
		default: Pattern3(); break;
		}
	}
}
void Stage2Boss::LateUpdate()
{
}

void Stage2Boss::OnRender()
{
}

void Stage2Boss::OnDestroy()
{
}

void Stage2Boss::OnCollisionEnter(CObject* _pObj)
{
	if (_pObj->m_Tag == Tag::Player)
	{
		CObject* player = OBJECT.Find(Tag::Player);
		player->gc<Stage2Player>()->isHit = true;
	}
}

void Stage2Boss::OnCollisionStay(CObject* _pObj)
{
}

void Stage2Boss::OnCollisionExit(CObject* _pObj)
{
}

void Stage2Boss::Pattern1()
{
	scale += dt * 500;
	Pattern1Time += dt;

	for (int i = 0; i < 5; i++)
	{
		leftHand->tf->m_vPos.x += cos(X -= D3DX_PI / scale);
		leftHand->tf->m_vPos.y += sin(Y += D3DX_PI / scale);

		rightHand->tf->m_vPos.x -= cos(X -= D3DX_PI / scale);
		rightHand->tf->m_vPos.y -= sin(Y += D3DX_PI / scale);
	}

	if (Pattern1Time >= 4.5)
	{
		scale = 600;
		Pattern1Time = 0;
	}
}

void Stage2Boss::Pattern2()
{
	leftHand->tf->m_vPos -= (leftHand->tf->m_vPos - leftPos) / 20;
	rightHand->tf->m_vPos -= (rightHand->tf->m_vPos - rightPos) / 20;

	leftHand->tf->m_vRot -= (leftHand->tf->m_vRot - 0) / 20;
	rightHand->tf->m_vRot -= (rightHand->tf->m_vRot - 0) / 20;
}

void Stage2Boss::Pattern3()
{
	leftTime += dt;
	rightTime += dt;

	if (leftTime <= 2.5)
	{
		leftHand->tf->m_vRot = (math::Atan2(leftHand->tf->m_vPos, player2->tf->m_vPos));
		lPlayerPos = player2->tf->m_vPos;
	}
	if (leftTime >= 3.5)
	{
		leftHand->tf->m_vPos -= (leftHand->tf->m_vPos - lPlayerPos) / 10;
	}
	if (leftTime >= 4)
	{
		leftTime = 0;
	}

	if (rightTime <= 2.5)
	{
		rightHand->tf->m_vRot = (math::Atan2(rightHand->tf->m_vPos, player2->tf->m_vPos) - 180);
		rPlayerPos = player2->tf->m_vPos;
	}
	if (rightTime >= 3.5)
	{
		rightHand->tf->m_vPos -= (rightHand->tf->m_vPos - rPlayerPos) / 10;
	}
	if (rightTime >= 4)
	{
		rightTime = 0;
	}
}
