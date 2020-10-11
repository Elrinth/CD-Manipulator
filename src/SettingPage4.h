#pragma once
#include "afxwin.h"


// CSettingPage4 ダイアログ

class CSettingPage4 : public CDialog
{
	DECLARE_DYNAMIC(CSettingPage4)

public:
	CSettingPage4(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CSettingPage4();

// ダイアログ データ
	enum { IDD = IDD_SETTING_4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	void Save(void);
	virtual BOOL OnInitDialog();
	CComboBox m_SubQSpeed;
	CComboBox m_SubQMethod;
	void SetLanguage(void);
};
