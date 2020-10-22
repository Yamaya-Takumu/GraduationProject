//------------------------------------------------------------------------------
//
//モジュールの処理  [module.cpp]
//Author:Yoshiki Hosoya
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//インクルード
//------------------------------------------------------------------------------
#include "module_timer.h"
#include "renderer.h"
#include "manager.h"
#include "modelinfo.h"
#include "timer.h"

//------------------------------------------------------------------------------
//静的メンバ変数の初期化
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//マクロ
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//コンストラクタ
//------------------------------------------------------------------------------
CModule_Timer::CModule_Timer()
{
	m_pTimer.reset();
}

//------------------------------------------------------------------------------
//デストラクタ
//------------------------------------------------------------------------------
CModule_Timer::~CModule_Timer()
{
	m_pTimer.reset();
}
//------------------------------------------------------------------------------
//初期化処理
//------------------------------------------------------------------------------
HRESULT CModule_Timer::Init()
{
	//モデル情報設定
	BindModelInfo(CModelInfo::GetModelInfo(CModelInfo::MODEL_TEST_BOMBTIMER));

	//モジュール選択不可
	CModule_Base::SetCanModuleSelect(false);

	//タイマーの生成
	m_pTimer = CTimer::Create(ZeroVector3, 360, GetMtxWorldPtr());

	CSceneX::Init();
	return S_OK;
}
//------------------------------------------------------------------------------
//終了処理
//------------------------------------------------------------------------------
void CModule_Timer::Uninit()
{
	CSceneX::Uninit();
}
//------------------------------------------------------------------------------
//更新処理
//------------------------------------------------------------------------------
void CModule_Timer::Update()
{
	m_pTimer->UpdateTimer();

	CSceneX::Update();
}
//------------------------------------------------------------------------------
//描画処理
//------------------------------------------------------------------------------
void CModule_Timer::Draw()
{
	CSceneX::Draw();
}
//------------------------------------------------------------------------------
//デバッグ情報表記
//------------------------------------------------------------------------------
void CModule_Timer::ShowDebugInfo()
{
#ifdef _DEBUG

#endif //DEBUG
}