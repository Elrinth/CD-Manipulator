#pragma once


// CMsfDialog �_�C�A���O

class CMsfDialog : public CDialog
{
	DECLARE_DYNAMIC(CMsfDialog)

public:
	CMsfDialog(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CMsfDialog();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_CALCMSF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_MSF_M;
	CString m_MSF_S;
	CString m_MSF_F;
	CString m_MSF150_M;
	CString m_MSF150_S;
	CString m_MSF150_F;
	CString m_LBA;
	CString m_LBAHex;
	afx_msg void OnBnClickedCalcMsf();
	afx_msg void OnBnClickedCalcMsf150();
	afx_msg void OnBnClickedCalcLba();
	afx_msg void OnBnClickedCalcLbahex();
	virtual BOOL OnInitDialog();
protected:
	void CalcMSF(DWORD LBA);
public:
	afx_msg void OnBnClickedZero();
};
