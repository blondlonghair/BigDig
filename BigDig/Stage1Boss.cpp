#include "DXUT.h"
#include "Stage1Boss.h"

void Stage1Boss::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("Stage1Boss"), SortingLayer::Default, RenderMode::Default);
}

void Stage1Boss::Start()
{
	player = OBJECT.Find(Tag::Player)->gc<Stage1Player>();

	leftHand = OBJECT.AddObject(Tag::Boss);
	leftHand->ac<CSpriteRenderer>()->Init(SPRITE("leftHand"), SortingLayer::Default, RenderMode::Default);
	leftHand->ac<CCollider>()->Init(90);
	leftHand->ac<Stage1BossArm>();
	leftHand->tf->m_vPos = Vec2(WINSIZEX / 2 - 300, WINSIZEY / 2);

	rightHand = OBJECT.AddObject(Tag::Boss);
	rightHand->ac<CSpriteRenderer>()->Init(SPRITE("rightHand"), SortingLayer::Default, RenderMode::Default);
	rightHand->ac<CCollider>()->Init(90);
	rightHand->ac<Stage1BossArm>();
	rightHand->tf->m_vPos = Vec2(WINSIZEX / 2 + 300, WINSIZEY / 2);
}

void Stage1Boss::Update()
{
	//if (leftHand->tf->m_vRot >= 180)
	//{
	//	leftHand->gc<CSpriteRenderer>()->m_pSprite = SPRITE("flippedLeftHand");
	//}
	//else
	//{
	//	leftHand->gc<CSpriteRenderer>()->m_pSprite = SPRITE("flippedLeftHand");
	//}

	if (GAME.isStart)
	{
		/*return maplestory 병신직엄 ? adel = false : blaster = true;*/
		//Pattern3();
		Pattern1();
	}
}
void Stage1Boss::LateUpdate()
{
}

void Stage1Boss::OnRender()
{
}

void Stage1Boss::OnDestroy()
{
}

void Stage1Boss::OnCollisionEnter(CObject* _pObj)
{
}

void Stage1Boss::OnCollisionStay(CObject* _pObj)
{
}

void Stage1Boss::OnCollisionExit(CObject* _pObj)
{
}
float X = 0;
float Y = 0;
void Stage1Boss::Pattern1()
{
	for (int i = 0; i < 5; i++)
	{
		leftHand->tf->m_vPos.x += cos(X -= D3DX_PI / 180);
		leftHand->tf->m_vPos.y += sin(Y += D3DX_PI / 180);
	}
}

void Stage1Boss::Pattern2()
{
}

void Stage1Boss::Pattern3()
{
	leftTime += dt;
	rightTime += dt;

	if (leftTime <= 2)
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

	if (rightTime <= 2)
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
