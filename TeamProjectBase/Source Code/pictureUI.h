//*************************************************************************************************************
//
// �G��UI���� [pictureUI.h]
// Author:IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _PICTUREUI_H_
#define _PICTUREUI_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "scene.h"
#include "Mylibrary.h"

//-------------------------------------------------------------------------------------------------------------
// �N���X��`
//-------------------------------------------------------------------------------------------------------------
class CScene2D;
class CPictureUI : public CScene
{
public:
	/* �񋓌^��` */
	typedef enum 
	{
		TYPE_NONE = -1,
		TYPE_BRUSH,			// �u���V
		TYPE_ERASER,		// �����S��
		TYPE_MAX
	} TYPE;

	/* �\���� */
	typedef struct CREATEINFO
	{
		D3DXVECTOR3        pos;			// �ʒu
		D3DXVECTOR3        size;		// �T�C�Y
		D3DXCOLOR          col;			// �F
		LPDIRECT3DTEXTURE9 tex;			// �e�N�X�`���|�C���^
		CScene::OBJTYPE    objtype;		// �I�u�W�F�N�g�^�C�v
	}CREATEINFO;

	CPictureUI();				// �R���X�g���N�^
	~CPictureUI();				// �f�X�g���N�^

	static std::shared_ptr<CPictureUI>Create(void);	// ����

	HRESULT Init();				//������
	void Update();				//�X�V
	void Draw();				//�`��
	void ShowDebugInfo();		//�f�o�b�O���\�L

private:
	static CREATEINFO m_aCreateInfo[TYPE_MAX];
	std::shared_ptr<CScene2D> *m_pScene2D[TYPE_MAX];		// �V�[��2D


};
#endif