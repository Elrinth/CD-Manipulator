#pragma once


// CMessageDialog �_�C�A���O

class CMessageDialog : public CDialog
{
	DECLARE_DYNAMIC(CMessageDialog)

public:
	CMessageDialog(CWnd* pParent = NULL);   // �W���R���X�g���N�^
	virtual ~CMessageDialog();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_MESSAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	CString m_Message;
	void MessageBox(LPCTSTR Title, LPCTSTR Message);
	virtual BOOL OnInitDialog();
protected:
	CString m_Title;
};
