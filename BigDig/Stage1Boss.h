#pragma once
#include "CComponent.h"
class Stage1Boss :
	public CComponent
{
private:
	// CComponent��(��) ���� ��ӵ�
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
};

