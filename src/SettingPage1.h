#pragma once
#include "afxwin.h"


// CSettingPage1 �_�C�A���O

class CSettingPage1 : public CDialog
{
	DECLARE_DYNAMIC(CSettingPage1)

public:
	CSettingPage1(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CSettingPage1();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_SETTING_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	void Save(void);
	CComboBox m_Priority;
	CString m_LogFileName;
	CString m_CopyTempFile;
	virtual BOOL OnInitDialog();
	void SetLanguage(void);
	BOOL m_AutosaveLog;
	afx_msg void OnBnClickedAutosaveLog();
	afx_msg void OnBnClickedBrowsLog();
	afx_msg void OnBnClickedBrowsTempfile();
};
