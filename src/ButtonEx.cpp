// ButtonEx.cpp : 実装ファイル
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



// CButtonEx メッセージ ハンドラ


void CButtonEx::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO : ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。
	CButton::OnMouseMove(nFlags, point);
	GetParent()->SendMessage(WM_MOUSEMOVE,point.x,point.y);
}
