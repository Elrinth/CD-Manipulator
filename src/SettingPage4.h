#pragma once
#include "afxwin.h"


// CSettingPage4 �_�C�A���O

class CSettingPage4 : public CDialog
{
	DECLARE_DYNAMIC(CSettingPage4)

public:
	CSettingPage4(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CSettingPage4();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_SETTING_4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	void Save(void);
	virtual BOOL OnInitDialog();
	CComboBox m_SubQSpeed;
	CComboBox m_SubQMethod;
	void SetLanguage(void);
};
