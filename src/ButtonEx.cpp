// ButtonEx.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CDM.h"
#include "ButtonEx.h"


// CButtonEx

IMPLEMENT_DYNAMIC(CButtonEx, CButton)
CButtonEx::CButtonEx()
{
}

CButtonEx::~CButtonEx()
{
}


BEGIN_MESSAGE_MAP(CButtonEx, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CButtonEx ���b�Z�[�W �n���h��


void CButtonEx::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO : �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	CButton::OnMouseMove(nFlags, point);
	GetParent()->SendMessage(WM_MOUSEMOVE,point.x,point.y);
}
