#pragma once
#include "afxwin.h"


// CReadSettingDialog4 �_�C�A���O

class CReadSettingDialog4 : public CDialog
{
	DECLARE_DYNAMIC(CReadSettingDialog4)

public:
	CReadSettingDialog4(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CReadSettingDialog4();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_READSETTING_4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	void Load(void);
	void Save(void);
	CComboBox m_Speed;
	virtual BOOL OnInitDialog();
protected:
	void SetLanguage(void);
};
