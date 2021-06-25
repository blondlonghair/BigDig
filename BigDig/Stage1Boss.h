#pragma once
#include "CComponent.h"
class Stage1Boss :
	public CComponent
{
public:
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
	void Patern1();
	void Patern2();
	void Patern3();
public:
	CObject *leftHand, *rightHand;
	//int ifdsa = 0;
};

