#pragma once
#include "Scene.h"

class Object;
class Shop :public Scene
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Shop();
	virtual	~Shop();
};
