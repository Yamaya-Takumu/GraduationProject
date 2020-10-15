//------------------------------------------------------------------------------
//
//ゲーム処理  [game.cpp]
//Author:Yoshiki Hosoya
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//インクルード
//------------------------------------------------------------------------------
#include "game.h"
#include "manager.h"
#include "renderer.h"
#include "sound.h"
#include "fade.h"
#include "camera.h"
#include "Bomb.h"
#include "Map.h"
//------------------------------------------------------------------------------
//静的メンバ変数の初期化
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//マクロ
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//コンストラクタ
//------------------------------------------------------------------------------
CGame::CGame()
{
	m_nCntState = 0;
	m_gamestate = STATE_READY;
}
//------------------------------------------------------------------------------
//デストラクタ
//------------------------------------------------------------------------------
CGame::~CGame()
{
}
//------------------------------------------------------------------------------
//初期化処理
//------------------------------------------------------------------------------
HRESULT CGame::Init(HWND hWnd)
{
	//カメラ座標設定
	CManager::GetRenderer()->GetCamera()->SetState(CCamera::CAMERA_DEBUG);

	//初期化
	SetGamestate(CGame::STATE_READY);

	//爆弾生成
	CBomb::Create(D3DXVECTOR3(0.0f,120.0f,0.0f), ZeroVector3, 12);

	CMap::Create();

	return S_OK;
}

//------------------------------------------------------------------------------
//終了処理
//------------------------------------------------------------------------------
void CGame::Uninit()
{
}

//------------------------------------------------------------------------------
//更新処理
//------------------------------------------------------------------------------
void CGame::Update()
{

}

//------------------------------------------------------------------------------
//描画処理
//------------------------------------------------------------------------------
void CGame::Draw()
{

}
//------------------------------------------------------------------------------
//デバッグ情報表記
//------------------------------------------------------------------------------
void CGame::ShowDebugInfo()
{
#ifdef _DEBUG


#endif //_DEBUG
}


//------------------------------------------------------------------------------
//ゲームステートセット
//------------------------------------------------------------------------------
void CGame::SetGamestate(STATE gamestate)
{
	//ステートが進んでいる場合
	if (m_gamestate != CGame::STATE_NONE)
	{
		//ステート変更
		m_gamestate = gamestate;

	}
}
