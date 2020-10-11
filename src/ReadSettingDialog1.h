#pragma once
#include "afxwin.h"


// CReadSettingDialog1 ダイアログ

class CReadSettingDialog1 : public CDialog
{
	DECLARE_DYNAMIC(CReadSettingDialog1)

public:
	CReadSettingDialog1(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CReadSettingDialog1();

// ダイアログ データ
	enum { IDD = IDD_READSETTING_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	void Load(void);
	void Save(void);
	bool m_SettingAtCopy;
	BOOL m_TestRead;
	BOOL m_ExtMenu;
	BOOL m_AnalyzeSubQ;
	BOOL m_IgnoreReaderror;
	BOOL m_FastErrorskip;
	BOOL m_BurstErrorScan;
	BOOL m_SwapChannel;
	BOOL m_AutoDetectReadMethod;
	CComboBox m_DataSpeed;
	CComboBox m_AudioSpeed;
	CComboBox m_AudioMethod;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedExtmenu();
	afx_msg void OnBnClickedAutodetectCommand();
	void SetLanguage(void);
};
