#include "DXUT.h"
#include "Stage3UI.h"

void Stage3UI::Awake()
{
	//GAME.m_playerLife = 3;

	firstVal = OBJECT.AddObject(Tag::UI);
	firstVal->ac<CSpriteRenderer>()->Init(SPRITE("number0"), SortingLayer::UI, RenderMode::UI);
	firstVal->tf->m_vPos = Vec2(25, 35);

	secondVal = OBJECT.AddObject(Tag::UI);
	secondVal->ac<CSpriteRenderer>()->Init(SPRITE("number0"), SortingLayer::UI, RenderMode::UI);
	secondVal->tf->m_vPos = Vec2(85, 35);

	textPersent = OBJECT.AddObject(Tag::UI);
	textPersent->ac<CSpriteRenderer>()->Init(SPRITE("Persent"), SortingLayer::UI, RenderMode::UI);
	textPersent->tf->m_vPos = Vec2(155, 35);

	heart1 = OBJECT.AddObject(Tag::UI);
	heart1->ac<CSpriteRenderer>()->Init(SPRITE("Heart"), SortingLayer::UI, RenderMode::UI);
	heart1->tf->m_vPos = Vec2(WINSIZEX - 100 - 100 - 50, 34);

	heart2 = OBJECT.AddObject(Tag::UI);
	heart2->ac<CSpriteRenderer>()->Init(SPRITE("Heart"), SortingLayer::UI, RenderMode::UI);
	heart2->tf->m_vPos = Vec2(WINSIZEX - 100 - 50, 34);

	heart3 = OBJECT.AddObject(Tag::UI);
	heart3->ac<CSpriteRenderer>()->Init(SPRITE("Heart"), SortingLayer::UI, RenderMode::UI);
	heart3->tf->m_vPos = Vec2(WINSIZEX - 50, 34);

	HeartUI();
}

void Stage3UI::Start()
{
}

void Stage3UI::Update()
{
}

void Stage3UI::LateUpdate()
{
}

void Stage3UI::OnRender()
{
}

void Stage3UI::OnDestroy()
{
}

void Stage3UI::OnCollisionEnter(CObject* _pObj)
{
}

void Stage3UI::OnCollisionStay(CObject* _pObj)
{
}

void Stage3UI::OnCollisionExit(CObject* _pObj)
{
}

void Stage3UI::UpdateScore()
{
	int value = 0;

	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			if (GAME.m_Stage3Tile[x][y] != 0)
			{
				value++;
			}
		}
	}
	float tileSize = TILESIZEX * TILESIZEY;
	float placeCount = value * 100;
	float persent = (float)(placeCount / tileSize);
	float persentage = persent;

	int num1 = (int)persentage / 10;
	int num2 = (int)persentage % 10;

	switch (num1)
	{
	case 1: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number1"); break;
	case 2: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number2"); break;
	case 3: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number3"); break;
	case 4: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number4"); break;
	case 5: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number5"); break;
	case 6: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number6"); break;
	case 7: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number7"); break;
	case 8: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number8"); break;
	case 9: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number9"); break;
	case 0: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number0"); break;
	default: firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number9"); break;
	}

	switch (num2)
	{
	case 1: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number1"); break;
	case 2: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number2"); break;
	case 3: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number3"); break;
	case 4: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number4"); break;
	case 5: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number5"); break;
	case 6: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number6"); break;
	case 7: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number7"); break;
	case 8: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number8"); break;
	case 9: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number9"); break;
	case 0: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number0"); break;
	default: secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number9"); break;
	}

	if (persentage >= 70)
	{
		SCENE.ChangeScene("TITLE");
	}
}

void Stage3UI::HeartUI()
{
	switch (GAME.m_playerLife)
	{
	case 3:
		break;
	case 2:
		heart1->gc<CSpriteRenderer>()->m_pSprite = SPRITE("BrokenHeart");
		break;
	case 1:
		heart1->gc<CSpriteRenderer>()->m_pSprite = SPRITE("BrokenHeart");
		heart2->gc<CSpriteRenderer>()->m_pSprite = SPRITE("BrokenHeart");
		break;
	case 0:
		heart1->gc<CSpriteRenderer>()->m_pSprite = SPRITE("BrokenHeart");
		heart2->gc<CSpriteRenderer>()->m_pSprite = SPRITE("BrokenHeart");
		heart3->gc<CSpriteRenderer>()->m_pSprite = SPRITE("BrokenHeart");
		break;
	}
}
