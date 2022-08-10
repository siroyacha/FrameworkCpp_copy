#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"StartManager.h"
Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Start()
{
	StartManager::GetInstance()->Start();
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"Crusader Subaver",10);
}

void Logo::Release()
{

}