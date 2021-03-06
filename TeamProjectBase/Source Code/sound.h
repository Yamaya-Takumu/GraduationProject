//------------------------------------------------------------------------------
//
// サウンド処理 [sound.h]
// Author : Yoshiki Hosoya
//
//------------------------------------------------------------------------------
#ifndef _SOUND_H_
#define _SOUND_H_

#define _CRT_SECURE_NO_WARNINGS

//-----------------------------------------------------------------------------
// インクルードファイル
//-----------------------------------------------------------------------------
#include "main.h"
#include "xaudio2.h"


class CSound
{
public:

	// サウンドファイル
	typedef enum
	{
		LABEL_BGM_TITLE = 0,					//タイトル
		LABEL_BGM_GAME,							//ゲーム
		LABEL_BGM_RESULT,						//リザルト

		//エフェクト
		LABEL_SE_EXPLOSION_00,					//爆発
		LABEL_SE_BLACK_OUT,						//ブラックアウト

		//モジュールの音
		LABEL_SE_COUNTDOWN_TIMER,				//タイマーカウントダウン
		LABEL_SE_MISS,							//失敗　ブザー
		LABEL_SE_CUT,							//ワイヤーとかカット
		LABEL_SE_MODULE_PUSH,					//ボタンプッシュ
		LABEL_SE_SELECT_BUTTON,					//選択ボタン

		//システム音
		LABEL_SE_DECISION,						//決定
		LABEL_SE_CANCEL,						//キャンセル
		LABEL_SE_SELECT,						//選択
		LABEL_SE_PAUSE,							//ポーズ
		LABEL_SE_TUTORIALPAGE,					//ポーズ

		LABEL_MAX,
	} LABEL;

	CSound();
	~CSound();

	HRESULT Init(HWND hWnd);
	HRESULT Play(LABEL label);

	void Stop(LABEL label);
	void StopAll(void);

	void SetMute(bool bMute)	{ m_bMute = bMute; };
	bool GetMute()				{ return m_bMute; };

private:

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	IXAudio2 *m_pXAudio2 = NULL;										// XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;					// マスターボイス
	IXAudio2SourceVoice *m_apSourceVoice[LABEL_MAX] = {};				// ソースボイス
	BYTE *m_apDataAudio[LABEL_MAX] = {};								// オーディオデータ
	DWORD m_aSizeAudio[LABEL_MAX] = {};									// オーディオデータサイズ

	bool m_bMute;														//ミュート

	typedef struct
	{
		char *pFilename;	// ファイル名
		int nCntLoop;		// ループカウント
	} SOUNDPARAM;

	// 各音素材のパラメータ
	SOUNDPARAM m_aParam[LABEL_MAX] =
	{
		//BGM
		{ "data/BGM/title.wav", -1 },								//BGM
		{ "data/BGM/game.wav", -1 },								//BGM
		{ "data/BGM/result.wav", -1 },								//BGM

		//エフェクト
		{ "data/SE/Effect/explosion_00.wav", 0 },					//SE 爆発
		{ "data/SE/Effect/blackout.wav", 0 },						//SE 暗転用

		//モジュールアクション
		{ "data/SE/Module/Timer.wav", 0 },							//SE タイマーカウントダウン
		{ "data/SE/Module/Miss00.wav", 0 },							//SE 失敗
		{ "data/SE/Module/WireCut.wav", 0 },						//SE カット
		{ "data/SE/Module/Push.wav", 0 },							//SE カット
		{ "data/SE/Module/SelectButton.wav", 0 },					//SE 選択


		//システム音
		{ "data/SE/System/decision.wav", 0 },						//SE 決定
		{ "data/SE/System/cancel.wav", 0 },							//SE キャンセル
		{ "data/SE/System/select.wav", 0 },							//SE 選択
		{ "data/SE/System/pause.wav", 0 },							//SE ポーズ
		{ "data/SE/System/TutorialPage.wav", 0 },							//SE ポーズ

	};

};


#endif
