#pragma once
#include "CComponent.h"
class Bullet2 :
    public CComponent
{
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
    void Init(float _dir);
    void Init(float _dir, Vec2 _pos);
    void Init(float _dir, float _speed);
    void Init(float _dir, float _speed, Vec2 _pos);


private:
    float bulletDir;
    float playerPos;
    float bulletSpeed;
};

