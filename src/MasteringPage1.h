#pragma once
#include "afxcmn.h"


// CMasteringPage1 ダイアログ

class CMasteringPage1 : public CDialog
{
	DECLARE_DYNAMIC(CMasteringPage1)

public:
	CMasteringPage1(CWnd* pParent = NULL);   // 標準コンストラクタ
	virtual ~CMasteringPage1();

// ダイアログ データ
	enum { IDD = IDD_MASTERING_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	CMenu m_TrackMenu;

	DECLARE_MESSAGE_MAP()
public:
	CWnd *m_MainDialog;
	CListCtrl m_TrackList;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnKeydownTracklist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRclickTracklist(NMHDR *pNMHDR, LRESULT *pResult);
	void InsertMode1MasteringTrack(void);
	void DeleteSelectedTracks(void);
	void InsertWaveAudioTrack(void);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnBnClickedUpOrder();
	afx_msg void OnBnClickedDownOrder();
protected:
	void SwapItem(int id1, int id2);
public:
	void SetLanguage(void);
	void InsertIsoTrack(LPCSTR FileName);
protected:
	int CheckIsoType(LPCSTR FileName);
};
