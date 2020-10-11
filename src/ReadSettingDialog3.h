#pragma once
#include "afxwin.h"


// CReadSettingDialog3 ダイアログ

class CReadSettingDialog3 : public CDialog
{
	DECLARE_DYNAMIC(CReadSettingDialog3)

public:
	CReadSettingDialog3(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CReadSettingDialog3();

// ダイアログ データ
	enum { IDD = IDD_READSETTING_3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

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
