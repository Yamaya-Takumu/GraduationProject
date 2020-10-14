//------------------------------------------------------------------------------
//
//テクスチャ管理  [texture.cpp]
//Author:Yoshiki Hosoya
//
//------------------------------------------------------------------------------

#ifndef _TEXTURE_H_
#define _TEXTURE_H_
//------------------------------------------------------------------------------
//インクルード
//------------------------------------------------------------------------------
#include "main.h"

//------------------------------------------------------------------------------
//クラス定義
//------------------------------------------------------------------------------
//前方宣言
class CTexture
{
public:
	CTexture() {};
	~CTexture() {};

	//通常のテクスチャ
	enum TEX_TYPE
	{
		TEX_NONE = 0,

		TEX_EFFECT_PARTICLE,					//パーティクル

		//マテリアル
		TEX_MATERIAL_FIELD000,					//マテリアル
		TEX_MATERIAL_FIELD001,					//マテリアル
		TEX_MATERIAL_FIELD002,					//マテリアル
		TEX_MATERIAL_FIELD003,					//マテリアル
		TEX_MATERIAL_FIELD004,					//マテリアル

		TEX_MAX									//MAX
	};

	//アニメーション用のテクスチャ
	//分割されているテクスチャ
	enum SEPARATE_TEX_TYPE
	{
		SEPARATE_TEX_NONE = 0,

		//UI
		SEPARATE_TEX_UI_NUMBER,						//ナンバー

		//エフェクト
		SEPARATE_TEX_EFFECT_EXPLOSION00,			//爆発

		SEPARATE_TEX_MAX							//MAX
	};

	typedef struct
	{
		LPDIRECT3DTEXTURE9 m_apSeparateTexture;		//分割テクスチャへのポインタ
		SEPARATE_TEX_TYPE type;						//テクスチャの種類
		D3DXVECTOR2 m_UVCnt;						//UVの枚数
		D3DXVECTOR2 m_UVSize;						//UVの大きさ

	}SEPARATE_TEX_INFO;

	static void TexLoad(HWND hwnd);						//テクスチャ生成
	static void TexUnload();							//テクスチャ破棄

	static LPDIRECT3DTEXTURE9 GetTexture(TEX_TYPE textype);							//通常テクスチャの取得

	static std::vector<std::string> &GetTexFileName() { return m_aTexFileName; };						//テクスチャ名取得
	static std::vector<std::string> &GetSeparateFileName() { return m_aSeparateTexFileNameList; };		//分割テクスチャ名取得

	static LPDIRECT3DTEXTURE9 GetSeparateTexture(SEPARATE_TEX_TYPE textype);		//分割テクスチャ取得
	static D3DXVECTOR2 GetSparateTex_UVSize(SEPARATE_TEX_TYPE textype);				//分割テクスチャ　UVのサイズ取得
	static D3DXVECTOR2 GetSparateTex_UVCnt(SEPARATE_TEX_TYPE textype);				//分割テクスチャ　UVの枚数取得


private:
	static std::vector<LPDIRECT3DTEXTURE9> m_apTextureList;							//通常テクスチャへのポインタのリスト
	static std::vector<std::string> m_aTexFileName;											//通常テクスチャのファイル名


	static std::vector<std::string> m_aSeparateTexFileNameList;								//分割テクスチャのファイル名
	static std::vector<SEPARATE_TEX_INFO> m_apSeparateTexInfoList;					//分割テクスチャに関する情報のポインタ

};

#endif