#pragma once
#include "CComponent.h"

class CPlayer :
    public CComponent
{
public:
	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void OnRender() override;
	virtual void OnDestroy() override;
	virtual void OnCollisionEnter(CObject* _pObj) override;
	virtual void OnCollisionStay(CObject* _pObj) override;
	virtual void OnCollisionExit(CObject* _pObj) override;

private:
	int xPos;
	int yPos;
	enum MoveRot
	{
		None, Up, Down, Left, Right
	};
	MoveRot moveRot = None;
	int gridTemp[TILESIZEX][TILESIZEY];

private:
	void Move();
	int MoveCheck();
	bool MoveCheck2();
	void DrawLine();
	void CheckFloodFill();
	void CheckFloodFillGrid();
	void FillColor();
	void FloodFill(int x, int y);
	void ReturnFill(int x, int y);
};

