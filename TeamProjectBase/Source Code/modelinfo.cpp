//-----------------------------------------------------------------------------
//
//モデル情報管理  [modelinfo.cpp]
// Author : Yoshiki Hosoya
//
//-----------------------------------------------------------------------------
#include "modelinfo.h"
#include "manager.h"
#include "renderer.h"
//-----------------------------------------------------------------------------
//静的メンバ変数の初期化
//-----------------------------------------------------------------------------
std::vector<std::shared_ptr<CModelInfo>> CModelInfo::m_apModelList = {};

//テクスチャ名の設定
std::vector<CModelInfo::MODELNAME> CModelInfo::m_aModelFileNameList =
{
	//マップモデル
	{ "data/MODEL/Map/Block.x" ,			MODEL_MAPOBJECT_BLOCK },				//立方体
	{ "data/MODEL/Map/Sphere.x" ,			MODEL_MAPOBJECT_SPHERE },				//球体

	//爆弾関係
	{ "data/MODEL/Bomb/bombbox.x" ,			MODEL_BOMBBOX },						//爆弾

	//モジュール
	{ "data/MODEL/Bomb/Module.x" ,			MODEL_MODULE_DEFAULT },							//モジュール
	{ "data/MODEL/Bomb/Module_none.x" ,		MODEL_MODULE_NONE },					//モジュール　何もないやつ　茶色の
	{ "data/MODEL/Bomb/Timer.x" ,			MODEL_MODULE_TIMER },					//タイマー

	//モジュールのパーツ
	{ "data/MODEL/Bomb/Lamp.x" ,			MODEL_MODULEPARTS_CLEARLAMP },			//ランプ
	{ "data/MODEL/Bomb/keypad.x" ,			MODEL_MODULEPARTS_KEYPAD },				//キーパッド

	{ "data/MODEL/BombTimer/BombTimer.x" ,			MODEL_TEST_BOMBTIMER },				//キーパッド
	{ "data/MODEL/ButtonParts/ButtonParts.x" ,		MODEL_TEST_BUTTON },				//キーパッド
	{ "data/MODEL/ButtonParts/button.x" ,			MODEL_TEST_BUTTONPARTS },				//キーパッド

};

//-----------------------------------------------------------------------------
//コンストラクタ
//-----------------------------------------------------------------------------
CModelInfo::CModelInfo()
{
	//初期化
	m_aName = {};
	m_matBuff = nullptr;
	m_mesh = nullptr;
	m_matNum = 0;
};

//-----------------------------------------------------------------------------
//デストラクタ
//-----------------------------------------------------------------------------
CModelInfo::~CModelInfo()
{
	//バッファ開放
	if (m_matBuff)
	{
		m_matBuff->Release();
		m_matBuff = nullptr;
	}
	//メッシュ開放
	if (m_mesh)
	{
		m_mesh->Release();
		m_mesh = nullptr;
	}
}

//-----------------------------------------------------------------------------
//モデル読み込み
//----------------------------------------------------------------------------
void CModelInfo::ModelLoad(HWND hwnd)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	for (size_t nCnt = 0; nCnt < m_aModelFileNameList.size(); nCnt++)
	{
		//debug
		std::cout << "Model Load - " << nCnt << m_aModelFileNameList[nCnt].modelname.data() << NEWLINE;

		m_apModelList.emplace_back(std::make_shared<CModelInfo>());
		m_apModelList[nCnt]->m_modeltype = m_aModelFileNameList[nCnt].modeltype;

		// Xファイルの読み込み
		if (FAILED(D3DXLoadMeshFromX(m_aModelFileNameList[nCnt].modelname.data(),
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&m_apModelList[nCnt]->m_matBuff,
			NULL,
			&m_apModelList[nCnt]->m_matNum,
			&m_apModelList[nCnt]->m_mesh)))
		{
			//失敗したとき
			std::cout << "LOAD FAILED!!!! >> " << m_aModelFileNameList[nCnt].modelname.data() << NEWLINE;
		}
	}
}

//-----------------------------------------------------------------------------
//モデル破棄
//----------------------------------------------------------------------------
void CModelInfo::ModelUnload()
{
	m_apModelList.clear();
}

//-----------------------------------------------------------------------------
//モデル取得
//----------------------------------------------------------------------------
std::shared_ptr<CModelInfo> CModelInfo::GetModelInfo(CModelInfo::MODEL_TYPE modeltype)
{
	//サイズ分繰り返す
	for (size_t nCnt = 0; nCnt < m_apModelList.size(); nCnt++)
	{
		//nullcheck
		if (m_apModelList[nCnt])
		{
			//モデルタイプが一致しているかどうか
			if (m_apModelList[nCnt]->GetModelType() == modeltype)
			{
				return m_apModelList[nCnt];
			}
		}
	}
	return nullptr;
}
