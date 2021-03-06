//------------------------------------------------------------------------------
//
//パーティクルの管理処理  [ParticleManager.h]
//Author:Yoshiki Hosoya
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//インクルード
//------------------------------------------------------------------------------
#include "ParticleManager.h"
#include "manager.h"
#include "renderer.h"
#include "particle.h"
//------------------------------------------------------------------------------
//静的メンバ変数の初期化
//------------------------------------------------------------------------------
std::vector<std::unique_ptr<CParticle>> CParticleManager::m_pParticleList = {};

//------------------------------------------------------------------------------
//マクロ
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//コンストラクタ
//------------------------------------------------------------------------------
CParticleManager::CParticleManager()
{
}

//------------------------------------------------------------------------------
//デストラクタ
//------------------------------------------------------------------------------
CParticleManager::~CParticleManager()
{
	m_pParticleList.clear();
	CParticle::ReleaseVertex();
}
//------------------------------------------------------------------------------
//初期化処理
//------------------------------------------------------------------------------
HRESULT CParticleManager::Init()
{
	return S_OK;
}

//------------------------------------------------------------------------------
//更新処理
//------------------------------------------------------------------------------
void CParticleManager::Update()
{
	//頂点番号リセット
	CParticle::ResetVertexID();

	//nullcheck
	if (!m_pParticleList.empty())
	{
		for (size_t nCnt = 0; nCnt < m_pParticleList.size(); nCnt++)
		{
			//更新処理
			m_pParticleList[nCnt]->Update();

			//フラグ立っているかチェック
			if(m_pParticleList[nCnt]->GetDeleteFlag())
			{
				//終了処理してメモリ開放
				m_pParticleList[nCnt].reset();

				//配列から削除
				m_pParticleList.erase(m_pParticleList.begin() + nCnt);

				//削除してカウントがずれた分修正
				nCnt--;
			}
		}

		//頂点番号リセット
		CParticle::ResetVertexID();

		for (size_t nCnt = 0; nCnt < m_pParticleList.size(); nCnt++)
		{
			//頂点バッファ更新処理
			m_pParticleList[nCnt]->UpdateVertex();
		}
	}
}
//------------------------------------------------------------------------------
//描画処理
//------------------------------------------------------------------------------
void CParticleManager::Draw()
{
	//頂点番号リセット
	CParticle::ResetVertexID();

	//nullcheck
	if (!m_pParticleList.empty())
	{
		for (size_t nCnt = 0; nCnt < m_pParticleList.size(); nCnt++)
		{
			m_pParticleList[nCnt]->Draw();
		}
	}
}

//------------------------------------------------------------------------------
//デバッグ情報表示
//------------------------------------------------------------------------------
void CParticleManager::ShowDebugInfo()
{
#ifdef _DEBUG

#endif // _DEBUG
}

//------------------------------------------------------------------------------
//パーティクル生成
//------------------------------------------------------------------------------
void CParticleManager::Create()
{
	//メモリ確保 Scene側で管理
	std::unique_ptr<CParticleManager> pParticle = std::make_unique<CParticleManager>();

	//初期化
	pParticle->Init();

	//パーティクルの頂点バッファ確保
	CParticle::MakeVertex();

	//Sceneで管理
	pParticle->SetObjType(CScene::OBJTYPE_EFFECT);
	pParticle->AddUniqueList(std::move(pParticle));

}
//------------------------------------------------------------------------------
//破棄
//------------------------------------------------------------------------------
void CParticleManager::Release()
{

}
//------------------------------------------------------------------------------
//パーティクルのリスト
//------------------------------------------------------------------------------
void CParticleManager::AddParticleList(std::unique_ptr<CParticle> pParticle)
{
	//配列に追加
	m_pParticleList.emplace_back(std::move(pParticle));
}

