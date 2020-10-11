#pragma once
#include "afxwin.h"


// CSettingPage1 ダイアログ

class CSettingPage1 : public CDialog
{
	DECLARE_DYNAMIC(CSettingPage1)

public:
	CSettingPage1(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CSettingPage1();

// ダイアログ データ
	enum { IDD = IDD_SETTING_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

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
