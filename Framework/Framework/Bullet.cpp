#include "Bullet.h"
#include"CursorManager.h"
#include"MathManager.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Time = GetTickCount64();
	Target = nullptr;

	Speed = 1.0f;
}

int Bullet::Update()
{

	switch (Index)
	{
	case 0:
		Info.Position += Info.Direction * Speed;
		if (Time + 5000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
		break;
	case 1:
	{
		Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
		Info.Position += Info.Direction * (Speed * 0.5f);
		if (Time + 10000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
	case 2:
		Info.Position += Info.Direction * Speed;
		if (Time + 5000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
		break;
	}	
	break;
	}

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
	{
		return 1;
	}
	return 0;
}

void Bullet::Render()
{
	switch (Index)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*");
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 12);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 10);
		break;
	}
}

void Bullet::Release()
{
}
