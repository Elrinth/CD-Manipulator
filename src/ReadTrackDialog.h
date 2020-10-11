#pragma once
#include "afxwin.h"
#include "CDType.h"

// CReadTrackDialog ダイアログ

class CReadTrackDialog : public CDialog
{
	DECLARE_DYNAMIC(CReadTrackDialog)

public:
	CReadTrackDialog(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CReadTrackDialog();

// ダイアログ データ
	enum { IDD = IDD_READTRACK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	CString m_ImageName;
	CListBox m_FileList;
	afx_msg void OnBnClickedBrows();
	int DoModalOriginal(TableOfContents * Toc);
	TableOfContents *m_Toc;
	CString m_DriveName;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	BOOL m_IgnoreReaderror;
	BOOL m_SwapChannel;
	BOOL m_AutoDetectReadMethod;
	CComboBox m_AudioMethod;
	CComboBox m_AudioSpeed;
	CComboBox m_DataSpeed;
	afx_msg void OnBnClickedAutodetectCommand();
	BOOL m_BurstErrorScan;
	void SetLanguage(void);
	BOOL m_ExtMenu;
	afx_msg void OnBnClickedExtmenu();
};
