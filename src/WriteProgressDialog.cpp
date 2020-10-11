// WriteProgressDialog.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CDM.h"
#include "WriteProgressDialog.h"
#include "Mmsystem.h"
#include "MessageDialog.h"

#include "Setting.h"
#define STR(i) (theSetting.m_Lang.m_Str[LP_WRITEP + i])

// CWriteProgressDialog �_�C�A���O

IMPLEMENT_DYNAMIC(CWriteProgressDialog, CDialog)
CWriteProgressDialog::CWriteProgressDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CWriteProgressDialog::IDD, pParent)
	, m_Message(_T(""))
	, m_Percent(_T(""))
	, m_RawFlag(_T(""))
{
	m_NoConfirm = false;
}

CWriteProgressDialog::~CWriteProgressDialog()
{
}

void CWriteProgressDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MESSAGE, m_Message);
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
	DDX_Text(pDX, IDC_PERCENT, m_Percent);
	DDX_Control(pDX, IDCANCEL, m_CancelButton);
	DDX_Text(pDX, IDC_RAWFLAG, m_RawFlag);
}


BEGIN_MESSAGE_MAP(CWriteProgressDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_LOG, OnBnClickedLog)
	ON_COMMAND(ID_WINDOW_CLOSE, OnWindowClose)
	ON_COMMAND(ID_UPDATE_DIALOG, OnUpdateDialog)
END_MESSAGE_MAP()


// CWriteProgressDialog ���b�Z�[�W �n���h��

void CWriteProgressDialog::OnBnClickedOk()
{
	// TODO : �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
//	OnOK();
}

void CWriteProgressDialog::OnBnClickedCancel()
{
	// TODO : �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	m_Thread.m_LogWnd->AddMessage(LOG_WARNING,MSG(17));
	m_Thread.m_StopFlag = true;
//	m_Thread.StopThread();
//	OnCancel();
}

BOOL CWriteProgressDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowText(STR(0));
	SetDlgItemText(IDC_LOG,STR(1));
	SetDlgItemText(IDCANCEL,STR(2));

	// TODO :  �����ɏ�������ǉ����Ă�������
	m_Progress.SetRange(0,100);
	m_Thread.StartThread();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}

void CWriteProgressDialog::WriteDisc(LPCSTR FileName, CCDController *CD, CLogWindow *Log)
{
	m_Thread.m_LogWnd = Log;
	m_Thread.m_CD = CD;
	m_Thread.m_CueFileName = FileName;
	m_Thread.m_ParentWnd = this;

	DoModal();

	m_Thread.StopThread();
}

void CWriteProgressDialog::Mastering(CDirStructure *Dir,LPCSTR VolumeLabel,CListCtrl *List, CCDController *CD, CLogWindow *Log)
{
	m_Thread.m_LogWnd = Log;
	m_Thread.m_CD = CD;
	m_Thread.m_ParentWnd = this;
	m_Thread.m_List = List;
	m_Thread.m_Dir = Dir;
	m_Thread.m_VolumeLabel = VolumeLabel;

	DoModal();

	m_Thread.StopThread();
}

void CWriteProgressDialog::OnBnClickedLog()
{
	// TODO : �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	if(m_Thread.m_LogWnd->GetStyle() & 0x10000000){
		m_Thread.m_LogWnd->ShowWindow(SW_HIDE);
	} else {
		m_Thread.m_LogWnd->ShowWindow(SW_SHOW);
	}
}

void CWriteProgressDialog::OnWindowClose()
{
	// TODO : �����ɃR�}���h �n���h�� �R�[�h��ǉ����܂��B
	CMessageDialog dlg;

	if(m_Thread.m_StopFlag){
		m_Thread.StopThread();
	} else {
		m_Thread.StopThread();
		if(!m_Thread.m_Success){
			CString cs;
			cs.Format("%s\n%s",m_Message,MSG(18));
			if(theSetting.m_WavOnFail != ""){
				PlaySound(theSetting.m_WavOnFail,NULL,SND_ASYNC);
			}
			dlg.MessageBox(CONF_MSG,cs);
		} else if(!m_NoConfirm){
			if(theSetting.m_WavOnSuccess != ""){
				PlaySound(theSetting.m_WavOnSuccess,NULL,SND_ASYNC);
			}
			dlg.MessageBox(CONF_MSG,MSG(19));
		}
	}

	OnCancel();
}

void CWriteProgressDialog::OnUpdateDialog()
{
	// TODO : �����ɃR�}���h �n���h�� �R�[�h��ǉ����܂��B
	UpdateData(FALSE);
}
