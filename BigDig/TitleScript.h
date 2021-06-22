#pragma once
#include "CComponent.h"
class TitleScript :
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
};

