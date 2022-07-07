#pragma once
#include "Scene.h"

class Object;
class Stage :public Scene
{
	/*
private:
	Object* pPlayer;
	Object* pEnemy;
	Object* pBullet[128];
	*/
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage();
	virtual	~Stage();
};

