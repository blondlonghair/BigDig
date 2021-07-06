#pragma once
class Stage2Boss :
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

private:
	float bossPatternTime = 0;
	int nextPattern = 1;

	float P1Time = 0;
	float P1Time_2 = -0.25;
	bool isP1;
	bool isP1_2;

	float P2Time = 0;
	float P2Dir = 0;

	float P3Time = 0;
	Vec2 meteorPos;
};

