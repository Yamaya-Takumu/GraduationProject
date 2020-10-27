//*************************************************************************************************************
//
// 絵用のペン処理[PaintingPen.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _PAINTINGPEN_H_
#define _PAINTINGPEN_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "Mylibrary.h"

//-------------------------------------------------------------------------------------------------------------
// クラス定義
//-------------------------------------------------------------------------------------------------------------
class CPaintingPen
{
public:
	typedef enum
	{
		MODE_NONE,										// 無し
		MODE_BRUSH,										// ブラシ
		MODE_ERASER,									// 消しゴム
		MODE_MAX										// 最大
	}MODE;

	CPaintingPen() {};									// コンストラクタ
	~CPaintingPen() {};									// デストラクタ

	void Init(void);									// 初期化
	void Uninit(void);									// 終了
	void Update(void);									// 更新

	void PaintCol(D3DXCOLOR *pCol);						// 色を塗る

	inline void Set(MODE mode) { m_mode = mode; }		// 設定
private:
	void PaintBrush(D3DXCOLOR *pCol);					// ブラシで塗る
	void PaintEraser(D3DXCOLOR *pCol);					// 消しゴムで塗る

	MODE m_mode;
	VEC3 m_NomDire;
	FLOAT3 m_pos;
};


#endif