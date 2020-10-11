// SettingPage1.cpp : 実装ファイル
//

#include "stdafx.h"
#include "cdm.h"
#include "SettingPage1.h"
#include "Setting.h"

// CSettingPage1 ダイアログ
#define STR(i) (theSetting.m_Lang.m_Str[LP_SET + i])

IMPLEMENT_DYNAMIC(CSettingPage1, CDialog)
CSettingPage1::CSettingPage1(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingPage1::IDD, pParent)
	, m_LogFileName(_T(""))
	, m_CopyTempFile(_T(""))
	, m_AutosaveLog(FALSE)
{
}

CSettingPage1::~CSettingPage1()
{
}

void CSettingPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRIORITY, m_Priority);
	DDX_Text(pDX, IDC_LOG_FILE, m_LogFileName);
	DDX_Text(pDX, IDC_COPYTEMPFILE, m_CopyTempFile);
	DDX_Check(pDX, IDC_AUTOSAVE_LOG, m_AutosaveLog);
}


BEGIN_MESSAGE_MAP(CSettingPage1, CDialog)
	ON_BN_CLICKED(IDC_AUTOSAVE_LOG, OnBnClickedAutosaveLog)
	ON_BN_CLICKED(IDC_BROWS_LOG, OnBnClickedBrowsLog)
	ON_BN_CLICKED(IDC_BROWS_TEMPFILE, OnBnClickedBrowsTempfile)
END_MESSAGE_MAP()


// CSettingPage1 メッセージ ハンドラ

void CSettingPage1::Save(void)
{
	if(m_AutosaveLog == FALSE){
		m_LogFileName = "";
	}
	theSetting.m_AutoLogFile = m_LogFileName;
	theSetting.m_CopyTempFile = m_CopyTempFile;
	if(theSetting.m_PriorityClass != m_Priority.GetCurSel()){
		theSetting.m_PriorityClass = m_Priority.GetCurSel();
		theSetting.SetPriority();
	}
}

BOOL CSettingPage1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO :  ここに初期化を追加してください
	m_Priority.AddString(STR(9));
	m_Priority.AddString(STR(10));
	m_Priority.AddString(STR(11));
	m_Priority.SetCurSel(theSetting.m_PriorityClass);

	m_CopyTempFile = theSetting.m_CopyTempFile;

	m_LogFileName = theSetting.m_AutoLogFile;
	if(m_LogFileName == ""){
		m_AutosaveLog = FALSE;
		GetDlgItem(IDC_LOG_FILE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BROWS_LOG)->ShowWindow(SW_HIDE);
	} else {
		m_AutosaveLog = TRUE;
	}

	UpdateData(FALSE);
	SetLanguage();
	OnBnClickedAutosaveLog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 例外 : OCX プロパティ ページは必ず FALSE を返します。
}

void CSettingPage1::SetLanguage(void)
{
	DWORD CtrlStr[][2] = {
		{IDC_AUTOSAVE_LOG	,2},
		{IDC_STATIC3		,5},
		{IDC_BROWS_LOG		,7},
		{IDC_BROWS_TEMPFILE	,7},
		{IDC_PRIORITY_TXT	,8},
	};
	int i;

	for(i=0;i<5;i++){
		SetDlgItemText(CtrlStr[i][0],STR(CtrlStr[i][1]));
	}
}

void CSettingPage1::OnBnClickedAutosaveLog()
{
	// TODO : ここにコントロール通知ハンドラ コードを追加します。
	UpdateData(TRUE);
	if(m_AutosaveLog == TRUE){
		GetDlgItem(IDC_LOG_FILE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BROWS_LOG)->ShowWindow(SW_SHOW);
	} else {
		GetDlgItem(IDC_LOG_FILE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BROWS_LOG)->ShowWindow(SW_HIDE);
	}
	UpdateData(FALSE);
}

void CSettingPage1::OnBnClickedBrowsLog()
{
	// TODO : ここにコントロール通知ハンドラ コードを追加します。
	CFileDialog dlg(FALSE,".cue",NULL,OFN_HIDEREADONLY,MSG(126));

	UpdateData(TRUE);

	if(dlg.DoModal() == IDOK){
		m_LogFileName = dlg.GetPathName();
	}

	UpdateData(FALSE);
}

void CSettingPage1::OnBnClickedBrowsTempfile()
{
	// TODO : ここにコントロール通知ハンドラ コードを追加します。
	CFileDialog dlg(FALSE,".cue",NULL,OFN_HIDEREADONLY,MSG(91));

	UpdateData(TRUE);

	if(dlg.DoModal() == IDOK){
		m_CopyTempFile = dlg.GetPathName();
	}

	UpdateData(FALSE);
}
