#pragma once
#include "cdcontroller.h"


// CDriveCapabilityDialog �_�C�A���O

class CDriveCapabilityDialog : public CDialog
{
	DECLARE_DYNAMIC(CDriveCapabilityDialog)

public:
	CDriveCapabilityDialog(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CDriveCapabilityDialog();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_DRIVE_CAPABILITY };

protected:
	void SenseCapability(void);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	CCDController *m_CD;
	virtual BOOL OnInitDialog();
	CString m_Vendor;
	CString m_Product;
	CString m_Revision;
	CString m_Sao;
	CString m_Raw96;
	CString m_Raw16;
	CString m_Raw96P;
	CString m_SaoTest;
	CString m_Raw16Test;
	CString m_Raw96Test;
	CString m_Raw96PTest;
	CString m_BufferSize;
	CString m_Writer;
	CString m_DefaultCommand;
	CString m_Address;
};
