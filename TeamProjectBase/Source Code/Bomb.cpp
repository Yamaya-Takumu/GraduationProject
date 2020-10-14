//------------------------------------------------------------------------------
//
//爆弾の処理  [Bomb.cpp]
//Author:Yoshiki Hosoya
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//インクルード
//------------------------------------------------------------------------------
#include "Bomb.h"
#include "renderer.h"
#include "manager.h"
#include "modelinfo.h"
#include "module.h"
//------------------------------------------------------------------------------
//静的メンバ変数の初期化
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//マクロ
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//コンストラクタ
//------------------------------------------------------------------------------
CBomb::CBomb()
{

}

//------------------------------------------------------------------------------
//デストラクタ
//------------------------------------------------------------------------------
CBomb::~CBomb()
{

}
//------------------------------------------------------------------------------
//初期化処理
//------------------------------------------------------------------------------
HRESULT CBomb::Init()
{
	CSceneX::Init();
	return S_OK;
}
//------------------------------------------------------------------------------
//終了処理
//------------------------------------------------------------------------------
void CBomb::Uninit()
{
	CSceneX::Uninit();
}
//------------------------------------------------------------------------------
//更新処理
//------------------------------------------------------------------------------
void CBomb::Update()
{
	CSceneX::Update();
}
//------------------------------------------------------------------------------
//描画処理
//------------------------------------------------------------------------------
void CBomb::Draw()
{
	CSceneX::Draw();
}
//------------------------------------------------------------------------------
//デバッグ情報表記
//------------------------------------------------------------------------------
void CBomb::ShowDebugInfo()
{
#ifdef _DEBUG

#endif //DEBUG
}

//------------------------------------------------------------------------------
//生成関数
//------------------------------------------------------------------------------
std::shared_ptr<CBomb> CBomb::Create(D3DXVECTOR3 const pos, D3DXVECTOR3 const rot, int const nModuleNum)
{
	//メモリ確保
	std::shared_ptr<CBomb> pBomb = std::make_shared<CBomb>();

	//初期化
	pBomb->Init();

	//座標とサイズ設定
	pBomb->SetPos(pos);
	pBomb->SetRot(rot);

	//モデル情報設定
	pBomb->BindModelInfo(CModelInfo::GetModelInfo(CModelInfo::MODEL_BOMBOBJECT_BOMB));

	//モジュール生成
	pBomb->CreateModule(nModuleNum);

	//Scene側で管理
	pBomb->SetObjType(CScene::OBJTYPE_BOMB);
	pBomb->AddSharedList(pBomb);

	return pBomb;
}

//------------------------------------------------------------------------------
//モジュール生成
//------------------------------------------------------------------------------
void CBomb::CreateModule(int const nModuleNum)
{
	for (int nCnt = 0; nCnt < nModuleNum; nCnt++)
	{
		CModule::Create(D3DXVECTOR3(-30.0f, 15.0f, -30.0f), GetMtxWorldPtr());
	}
}
