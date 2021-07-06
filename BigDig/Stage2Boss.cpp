#include "DXUT.h"
#include "Stage2Boss.h"

void Stage2Boss::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("Stage2Boss"), SortingLayer::Default, RenderMode::Default);
}

void Stage2Boss::Start()
{
}

void Stage2Boss::Update()
{
	if (GAME.isStart)
	{
		bossPatternTime += dt;

		if (bossPatternTime >= 5)
		{
			nextPattern = math::RandRange(1, 4);
			if (nextPattern == 2)
			{
				bossPatternTime = -5;
			}
			else
			{
				bossPatternTime = 0;
			}
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
}

void Stage2Boss::OnCollisionStay(CObject* _pObj)
{
}

void Stage2Boss::OnCollisionExit(CObject* _pObj)
{
}

void Stage2Boss::Pattern1()
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
			bullet->ac<Bullet>()->Init(i);
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
			bullet->ac<Bullet>()->Init(i);
		}
		isP1_2 = false;
		P1Time_2 = 0;
	}
}

void Stage2Boss::Pattern2()
{
	P2Time += dt;

	if (P2Time >= 0.1)
	{
		P2Dir += 10;
		CObject* bullet = OBJECT.AddObject(Tag::Boss);
		bullet->ac<Bullet>()->Init(P2Dir, 2);
		CObject* bullet2 = OBJECT.AddObject(Tag::Boss);
		bullet2->ac<Bullet>()->Init(P2Dir + 180, 2);
		P2Time = 0;
	}
}

void Stage2Boss::Pattern3()
{
	P3Time += dt;

	if (P3Time >= 1.6)
	{
		meteorPos.x = RandRange((TILESIZEX - WINSIZEX) / 2, TILESIZEX + ((TILESIZEX - WINSIZEX) / 2));
		meteorPos.y = RandRange((TILESIZEY - WINSIZEY) / 2, TILESIZEY + ((TILESIZEY - WINSIZEY) / 2));

		for (int i = 0; i < 360; i += 30)
		{
			CObject* bullet = OBJECT.AddObject(Tag::Boss);
			bullet->ac<Bullet>()->Init(i, 2, meteorPos);
		}

		P3Time = 0;
	}
}
