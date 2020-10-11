#pragma once
#include "afxcmn.h"
#include "CDController.h"
#include "LogWindow.h"
#include "writethread.h"
#include "Resource.h"
#include "afxwin.h"
#include "DirStructure.h"

// CWriteProgressDialog ダイアログ

class CWriteProgressDialog : public CDialog
{
	DECLARE_DYNAMIC(CWriteProgressDialog)

public:
	CWriteProgressDialog(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CWriteProgressDialog();

// ダイアログ データ
	enum { IDD = IDD_WRITEPROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	CString m_Message;
	CProgressCtrl m_Progress;
	CString m_Percent;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	void WriteDisc(LPCSTR FileName, CCDController *CD, CLogWindow *Log);
	void Mastering(CDirStructure *Dir,LPCSTR VolumeLabel,CListCtrl *List, CCDController *CD, CLogWindow *Log);
public:
	afx_msg void OnBnClickedLog();
protected:
	CWriteThread m_Thread;
public:
	CButton m_CancelButton;
	afx_msg void OnWindowClose();
	bool m_NoConfirm;
	CString m_RawFlag;
	afx_msg void OnUpdateDialog();
};
