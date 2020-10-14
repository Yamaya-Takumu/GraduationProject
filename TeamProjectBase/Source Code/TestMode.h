//------------------------------------------------------------------------------
//
//テストモード処理  [testMode.cpp]
//Author:Yoshiki Hosoya
//
//------------------------------------------------------------------------------
#ifndef _TESTMODE_H_
#define _TESTMODE_H_
//------------------------------------------------------------------------------
//インクルード
//------------------------------------------------------------------------------
#include "main.h"
#include "basemode.h"
//------------------------------------------------------------------------------
//マクロ
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//クラス定義
//------------------------------------------------------------------------------
class CTestMode : public CBaseMode
{
public:

	CTestMode();
	~CTestMode();
	HRESULT Init(HWND hWnd);								//初期化
	void Uninit();											//終了
	void Update();											//更新
	void Draw();											//描画
	void ShowDebugInfo();									//デバッグ情報表記

private:
};

#endif