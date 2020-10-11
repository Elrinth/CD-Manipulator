// LanguageDialog.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CDM.h"
#include "LanguageDialog.h"
#include "Setting.h"

// CLanguageDialog �_�C�A���O

IMPLEMENT_DYNAMIC(CLanguageDialog, CDialog)
CLanguageDialog::CLanguageDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLanguageDialog::IDD, pParent)
{
}

CLanguageDialog::~CLanguageDialog()
{
}

void CLanguageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
}


BEGIN_MESSAGE_MAP(CLanguageDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
//	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnNMDblclkList)
END_MESSAGE_MAP()


// CLanguageDialog ���b�Z�[�W �n���h��

BOOL CLanguageDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO :  �����ɏ�������ǉ����Ă�������
	m_List.InsertColumn(0,"Language",LVCFMT_LEFT,150,0);
	m_List.InsertColumn(1,"Author",LVCFMT_LEFT,150,1);
	m_List.InsertColumn(2,"Language file",LVCFMT_LEFT,100,2);
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	SearchLanguageFile();
	DetectLanguageInfo();
	return TRUE;  // return TRUE unless you set the focus to a control
	// ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}

void CLanguageDialog::SearchLanguageFile(void)
{
	CString FindPath;
	HANDLE hFind;
	WIN32_FIND_DATA FindData;
	int id;

	m_List.DeleteAllItems();

	FindPath.Format("%s*.cml",theSetting.m_Dir);
	hFind = FindFirstFile(FindPath,&FindData);
	if(hFind == INVALID_HANDLE_VALUE){
		return;
	}

	while(1){
		id = m_List.InsertItem(m_List.GetItemCount(),FindData.cFileName);
		m_List.SetItemText(id,2,FindData.cFileName);
		if(!FindNextFile(hFind,&FindData)){
			break;
		}
	}

	FindClose(hFind);
}

void CLanguageDialog::DetectLanguageInfo(void)
{
	int i,max;
	CString FileName,cs;

	max = m_List.GetItemCount();
	for(i=0;i<max;i++){
		FileName = m_List.GetItemText(i,2);
		cs = theSetting.m_Dir + FileName;
		CheckCML(cs,i);
	}
}

void CLanguageDialog::OnBnClickedOk()
{
	// TODO : �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	POSITION pos;
	int id;

	pos = m_List.GetFirstSelectedItemPosition();
	if(pos == NULL){
		MessageBox("Please select a language.","Warning",MB_OK);
		return;
	}
	id = m_List.GetNextSelectedItem(pos);
	theSetting.m_LangFile = theSetting.m_Dir + m_List.GetItemText(id,2);

	OnOK();
}

void CLanguageDialog::OnBnClickedCancel()
{
	// TODO : �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	OnCancel();
}

void CLanguageDialog::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO : �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	POSITION pos;

	pos = m_List.GetFirstSelectedItemPosition();
	if(pos){
		OnBnClickedOk();
	}
	*pResult = 0;
}

void CLanguageDialog::CheckCML(LPCSTR FileName,int ID)
{
	FILE *fp;
	char Buffer[256],tmp[12];
	int fg;

	fp = fopen(FileName,"r");
	if(fp == NULL){
		return;
	}
	fg = 0;
	while(!feof(fp)){
		Buffer[0] = '\0';
		fgets(Buffer,256,fp);
		if(Buffer[0] == '\0'){
			break;
		}
		if(Buffer[lstrlen(Buffer) - 1] == '\n'){
			Buffer[lstrlen(Buffer) - 1] = '\0';
		}
		strncpy(tmp,Buffer,11);
		tmp[10] = '\0';
		if(lstrcmpi(tmp,"#Language:") == 0){
			m_List.SetItemText(ID,0,Buffer+10);
			fg = fg | 1;
		}
		tmp[8] = '\0';
		if(lstrcmpi(tmp,"#Author:") == 0){
			m_List.SetItemText(ID,1,Buffer+8);
			fg = fg | 2;
		}
		if(fg == 3){
			break;
		}
	}
	fclose(fp);
}
