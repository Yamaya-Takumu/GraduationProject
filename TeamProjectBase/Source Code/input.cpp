//------------------------------------------------------------------------------
//
//入力処理  [input.cpp]
//Author:Yoshiki Hosoya
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//インクルード
//------------------------------------------------------------------------------
#include "input.h"

//------------------------------------------------------------------------------
//静的メンバ変数の初期化
//------------------------------------------------------------------------------
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//------------------------------------------------------------------------------
//コンストラクタ
//------------------------------------------------------------------------------
CInput::CInput()
{

}
//------------------------------------------------------------------------------
//デストラクタ
//------------------------------------------------------------------------------
CInput::~CInput()
{
	// DirectInputオブジェクトの開放
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}
//------------------------------------------------------------------------------
//初期化処理
//------------------------------------------------------------------------------
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	// DirectInputオブジェクトの作成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
	{
		//失敗
		return E_FAIL;
	}
	return S_OK;
}