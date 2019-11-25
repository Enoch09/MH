#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "Math.h"

int main()
{
	Framework& f = Framework::GetInstance();
	f.Run(new TitleScene(), L"타이틀", 1200, 900, false);
	//f.Run(new GameScene(),L"타이틀", 1200, 900, false);

	return 0;
}