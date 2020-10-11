#pragma once
#include "CDType.h"
#include "afxext.h"
#include "CDController.h"

// CTocWindow �t���[�� 

class CTocWindow : public CFrameWnd
{
public:
	CTocWindow();           // ���I�����Ŏg�p����� protected �R���X�g���N�^
	virtual ~CTocWindow();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCloseWindow();
	afx_msg void OnClose();
	void SetTOC(TableOfContents * Toc);
	void ClearList(void);
	void ViewDriveName(LPCSTR DriveName);
protected:
	HICON m_hIcon;
	CStatusBar m_StatusBar;
	CListCtrl m_View;
	DECLARE_DYNCREATE(CTocWindow)
public:
	bool CheckSelect(TableOfContents * Toc);
	int GetItemCount(void);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnFileSavetxt();
	afx_msg void OnFileSavehtml();
	afx_msg void OnFileSavecsv();
protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void OnMove(int x, int y);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileSavecue();
	CCDController *m_CD;
	void SetLanguage(void);
//	afx_msg void OnToolReadtrack();
};


