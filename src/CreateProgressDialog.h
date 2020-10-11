#pragma once
#include "afxwin.h"


// CCreateProgressDialog �_�C�A���O
#include "IsoCreator.h"
#include "createthread.h"
#include "LogWindow.h"
#include "resource.h"
#include "afxcmn.h"

class CCreateProgressDialog : public CDialog
{
	DECLARE_DYNAMIC(CCreateProgressDialog)

public:
	CCreateProgressDialog(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CCreateProgressDialog();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_CREATPROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void CreateIso(LPCSTR ImgFileName, LPCSTR VolumeLabel, CListCtrl * List, CDirStructure * Dir, CLogWindow *LogWnd);
protected:
	CCreateThread m_Thread;
public:
	virtual BOOL OnInitDialog();
	CString m_Message;
	CButton m_CancelButton;
	afx_msg void OnBnClickedCancel();
	CProgressCtrl m_Progress;
	CString m_Percent;
	afx_msg void OnWindowClose();
	afx_msg void OnBnClickedLog();
	afx_msg void OnUpdateDialog();
};
