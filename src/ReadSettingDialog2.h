#pragma once
#include "afxwin.h"


// CReadSettingDialog2 �_�C�A���O

class CReadSettingDialog2 : public CDialog
{
	DECLARE_DYNAMIC(CReadSettingDialog2)

public:
	CReadSettingDialog2(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CReadSettingDialog2();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_READSETTING_2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	void Load(void);
	void Save(void);
	bool m_SettingAtCopy;
	BOOL m_TestRead;
	BOOL m_ExtMenu;
	BOOL m_AnalyzePregap;
	BOOL m_AnalyzeSubQ;
	BOOL m_IgnoreReaderror;
	BOOL m_FastErrorskip;
	BOOL m_BurstErrorScan;
	CComboBox m_AudioSpeed;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedExtmenu();
	void SetLanguage(void);
};
