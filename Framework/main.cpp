#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "Math.h"

int main()
{
	Framework& f = Framework::GetInstance();
	f.Run(new TitleScene(), L"Ÿ��Ʋ", 1200, 900, false);
	//f.Run(new GameScene(),L"Ÿ��Ʋ", 1200, 900, false);

	return 0;
}