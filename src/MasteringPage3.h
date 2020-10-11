#pragma once
#include "afxwin.h"


// CMasteringPage3 ダイアログ

class CMasteringPage3 : public CDialog
{
	DECLARE_DYNAMIC(CMasteringPage3)

public:
	CMasteringPage3(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CMasteringPage3();

// ダイアログ データ
	enum { IDD = IDD_MASTERING_3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_AlwaysOnTop;
	CWnd *m_MainDialog;
	virtual BOOL OnInitDialog();
	void SetLanguage(void);
	afx_msg void OnBnClickedAlwaysTop();
	BOOL m_NotifyTruncated;
	afx_msg void OnBnClickedNotifyTruncated();
	CComboBox m_Protection;
	afx_msg void OnCbnSelchangeProtectionFeatures();
};
