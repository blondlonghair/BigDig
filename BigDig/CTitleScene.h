#pragma once
#include "CScene.h"
class CTitleScene :
	public CScene
{
private:
	int tilePersent = 0;

public:
	CTitleScene();
	~CTitleScene();
	
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

