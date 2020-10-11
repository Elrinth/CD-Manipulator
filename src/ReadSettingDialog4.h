#pragma once
#include "afxwin.h"


// CReadSettingDialog4 ダイアログ

class CReadSettingDialog4 : public CDialog
{
	DECLARE_DYNAMIC(CReadSettingDialog4)

public:
	CReadSettingDialog4(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CReadSettingDialog4();

// ダイアログ データ
	enum { IDD = IDD_READSETTING_4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	void Load(void);
	void Save(void);
	CComboBox m_Speed;
	virtual BOOL OnInitDialog();
protected:
	void SetLanguage(void);
};
