#pragma once
#include "afxwin.h"


// CReadSettingDialog3 �_�C�A���O

class CReadSettingDialog3 : public CDialog
{
	DECLARE_DYNAMIC(CReadSettingDialog3)

public:
	CReadSettingDialog3(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CReadSettingDialog3();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_READSETTING_3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	void Load(void);
	void Save(void);
	void SetLanguage(void);
	virtual BOOL OnInitDialog();
	bool m_SettingAtCopy;
	BOOL m_FastErrorskip;
	BOOL m_AnalyzePregap;
	CComboBox m_AudioSpeed;
};
