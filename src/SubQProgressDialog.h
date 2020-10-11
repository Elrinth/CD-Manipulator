#pragma once

#include "CDController.h"
#include "LogWindow.h"
#include "subqthread.h"
#include "afxwin.h"
#include "Resource.h"

// CSubQProgressDialog �_�C�A���O

class CSubQProgressDialog : public CDialog
{
	DECLARE_DYNAMIC(CSubQProgressDialog)

public:
	CSubQProgressDialog(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CSubQProgressDialog();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_SUBQPROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_Message;
	bool AnalyzeSubQ(CCDController * cd, CLogWindow * logWnd);
protected:
	CSubQThread m_Thread;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
	CButton m_CancelButton;
	afx_msg void OnBnClickedLog();
	CString m_Sector;
	afx_msg void OnWindowClose();
	afx_msg void OnUpdateDialog();
};
