#include "DXUT.h"
#include "Stage1Score.h"

void Stage1Score::Awake()
{
	firstVal = OBJECT.AddObject(Tag::UI);
	firstVal->ac<CSpriteRenderer>()->Init(SPRITE("number0"), SortingLayer::UI, RenderMode::UI);
	firstVal->tf->m_vPos = Vec2(50, 75);

	secondVal = OBJECT.AddObject(Tag::UI);
	secondVal->ac<CSpriteRenderer>()->Init(SPRITE("number0"), SortingLayer::UI, RenderMode::UI);
	secondVal->tf->m_vPos = Vec2(150, 75);
}

void Stage1Score::Start()
{
}

void Stage1Score::Update()
{
}

void Stage1Score::LateUpdate()
{
}

void Stage1Score::OnRender()
{
}

void Stage1Score::OnDestroy()
{
}

void Stage1Score::OnCollisionEnter(CObject* _pObj)
{
}

void Stage1Score::OnCollisionStay(CObject* _pObj)
{
}

void Stage1Score::OnCollisionExit(CObject* _pObj)
{
}

void Stage1Score::UpdateScore()
{
	int value = 0;

	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			if (GAME.m_Stage1Tile[x][y] != 0)
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

	//OutputDebugStringA(num1);
	//OutputDebugStringA(num2);

	//firstVal->gc<CSpriteRenderer>()->m_bEnable = false;
	//firstVal->ac<CSpriteRenderer>()->Init(SPRITE("number"  + num1), SortingLayer::UI, RenderMode::UI);

	//string str = "";
	//sprintf((char*)str.c_str(), "%d", num1);
	
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
	//firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number" + str);

	//sprintf((char*)str.c_str(), "%d", num2);

	//secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number" + str);

	//string Temp = to_string(persentage);
	//for (int i = 0; i < 10; i++)
	//{
	//	if (num1 == i)
	//	{
	//		firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number" + i);
	//	}

	//	if (num2 == i)
	//	{
	//		secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number" + i);
	//	}

	//}
		//else
		//{
		//	firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number9");
		//	secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number9");
		//}
	//LPCSTR ch = (LPCSTR)Temp.c_str();
	//OutputDebugStringA(ch + '\n');
}