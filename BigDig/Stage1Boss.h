#pragma once
#include "CComponent.h"
class Stage1Boss :
	public CComponent
{
private:
	// CComponent을(를) 통해 상속됨
	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void OnRender() override;
	virtual void OnDestroy() override;
	virtual void OnCollisionEnter(CObject* _pObj) override;
	virtual void OnCollisionStay(CObject* _pObj) override;
	virtual void OnCollisionExit(CObject* _pObj) override;

public:
	void Pattern1();
	void Pattern2();
	void Pattern3();
public:
	CObject *leftHand, *rightHand;
private:
	Stage1Player* player;
	float leftTime = 0;
	float rightTime = -2;
	Vec2 lPlayerPos;
	Vec2 rPlayerPos;
	float bossPatternTime;
	float Pattern1Time = 0;
	int nextPattern = 1;
	Vec2 leftPos = Vec2(WINSIZEX / 2 - 300, WINSIZEY / 2);
	Vec2 rightPos = Vec2(WINSIZEX / 2 + 300, WINSIZEY / 2);
};

