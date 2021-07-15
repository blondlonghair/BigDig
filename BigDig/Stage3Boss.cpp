#include "DXUT.h"
#include "Stage3Boss.h"

void Stage3Boss::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("Stage1Boss"), SortingLayer::Default, RenderMode::Default);
	player = new Stage3Player();
}

void Stage3Boss::Start()
{
	player = OBJECT.Find(Tag::Player)->gc<Stage3Player>();

	leftHand = OBJECT.AddObject(Tag::Boss);
	leftHand->ac<CSpriteRenderer>()->Init(SPRITE("leftHand"), SortingLayer::Default, RenderMode::Default);
	leftHand->ac<CCollider>()->Init(90);
	leftHand->tf->m_vPos = Vec2(WINSIZEX / 2 - 300, WINSIZEY / 2);

	rightHand = OBJECT.AddObject(Tag::Boss);
	rightHand->ac<CSpriteRenderer>()->Init(SPRITE("rightHand"), SortingLayer::Default, RenderMode::Default);
	rightHand->ac<CCollider>()->Init(90);
	rightHand->tf->m_vPos = Vec2(WINSIZEX / 2 + 300, WINSIZEY / 2);
}

void Stage3Boss::Update()
{
	if (GAME.isStart)
	{
		bossPatternTime += dt;
		BPTime += dt;

		if (bossPatternTime >= 5)
		{
			nextPattern = math::RandRange(1, 4);
			leftTime = 0; rightTime = -2;
			leftTime = 0; rightTime = -2;
			bossPatternTime = 0;
		}
		switch (nextPattern)
		{
		case 1: Pattern1(); break;
		case 2: Pattern2(); break;
		case 3: Pattern3(); break;
		default: Pattern3(); break;
		}

		if (BPTime >= 5)
		{
			nextBP = math::RandRange(1, 4);
			if (nextBP == 2)
			{
				BPTime = -5;
			}
			else
			{
				BPTime = 0;
			}
		}
		switch (nextBP)
		{
		case 1: BP1(); break;
		case 2: BP2(); break;
		case 3: BP3(); break;
		default: BP3(); break;
		}
	}
}
void Stage3Boss::LateUpdate()
{
}

void Stage3Boss::OnRender()
{
}

void Stage3Boss::OnDestroy()
{
}

void Stage3Boss::OnCollisionEnter(CObject* _pObj)
{
}

void Stage3Boss::OnCollisionStay(CObject* _pObj)
{
}

void Stage3Boss::OnCollisionExit(CObject* _pObj)
{
}

void Stage3Boss::Pattern1()
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

void Stage3Boss::Pattern2()
{
	leftHand->tf->m_vPos -= (leftHand->tf->m_vPos - leftPos) / 20;
	rightHand->tf->m_vPos -= (rightHand->tf->m_vPos - rightPos) / 20;

	leftHand->tf->m_vRot -= (leftHand->tf->m_vRot - 0) / 20;
	rightHand->tf->m_vRot -= (rightHand->tf->m_vRot - 0) / 20;
}

void Stage3Boss::Pattern3()
{
	leftTime += dt;
	rightTime += dt;

	if (leftTime <= 2.5)
	{
		leftHand->tf->m_vRot = (math::Atan2(leftHand->tf->m_vPos, player->tf->m_vPos));
		lPlayerPos = player->tf->m_vPos;
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
		rightHand->tf->m_vRot = (math::Atan2(rightHand->tf->m_vPos, player->tf->m_vPos) - 180);
		rPlayerPos = player->tf->m_vPos;
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

void Stage3Boss::BP1()
{
	P1Time += dt;
	P1Time_2 += dt;

	if (P1Time >= 0.5)
	{
		isP1 = true;
	}

	if (isP1)
	{
		for (int i = 0; i < 360; i += 40)
		{
			CObject* bullet = OBJECT.AddObject(Tag::Boss);
			bullet->ac<Bullet2>()->Init(i);
		}
		isP1 = false;
		P1Time = 0;
	}

	if (P1Time_2 >= 0.5)
	{
		isP1_2 = true;
	}

	if (isP1_2)
	{
		for (int i = 20; i < 380; i += 40)
		{
			CObject* bullet = OBJECT.AddObject(Tag::Boss);
			bullet->ac<Bullet2>()->Init(i);
		}
		isP1_2 = false;
		P1Time_2 = 0;
	}
}

void Stage3Boss::BP2()
{
	P2Time += dt;

	if (P2Time >= 0.1)
	{
		P2Dir += 10;
		CObject* bullet = OBJECT.AddObject(Tag::Boss);
		bullet->ac<Bullet2>()->Init(P2Dir, 2);
		CObject* bullet2 = OBJECT.AddObject(Tag::Boss);
		bullet2->ac<Bullet2>()->Init(P2Dir + 180, 2);
		P2Time = 0;
	}
}

void Stage3Boss::BP3()
{
	P3Time += dt;

	if (P3Time >= 1.6)
	{
		meteorPos.x = RandRange((TILESIZEX - WINSIZEX) / 2, TILESIZEX + ((TILESIZEX - WINSIZEX) / 2));
		meteorPos.y = RandRange((TILESIZEY - WINSIZEY) / 2, TILESIZEY + ((TILESIZEY - WINSIZEY) / 2));

		for (int i = 0; i < 360; i += 30)
		{
			CObject* bullet = OBJECT.AddObject(Tag::Boss);
			bullet->ac<Bullet2>()->Init(i, 2, meteorPos);
		}

		P3Time = 0;
	}
}
