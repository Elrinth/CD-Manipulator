#pragma once


// CMessageDialog ダイアログ

class CMessageDialog : public CDialog
{
	DECLARE_DYNAMIC(CMessageDialog)

public:
	CMessageDialog(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CMessageDialog();

// ダイアログ データ
	enum { IDD = IDD_MESSAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	CString m_Message;
	void MessageBox(LPCTSTR Title, LPCTSTR Message);
	virtual BOOL OnInitDialog();
protected:
	CString m_Title;
};
