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
			if (GAME.m_Stage1Tile[x][y] == 0)
			{
				value++;
			}
		}
	}

	persentage = value / TILESIZEX * TILESIZEY * 100;
	
	int num1 = persentage /= 10;
	int num2 = persentage % 10;

	//OutputDebugStringA(num1);
	//OutputDebugStringA(num2);

	//firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number" + num1);
	//secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number" + num2);

	string Temp = to_string(persentage);
	for (int i = 0; i < 10; i++)
	{
		if (num1 == i)
		{
			firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number" + i);
		}

		if (num2 == i)
		{
			secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number" + i);
		}

	}
		//else
		//{
		//	firstVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number9");
		//	secondVal->gc<CSpriteRenderer>()->m_pSprite = SPRITE("number9");
		//}
	LPCSTR ch = (LPCSTR)Temp.c_str();
	OutputDebugStringA(ch + '\n');
}