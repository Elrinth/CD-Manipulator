// Hermit2.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

#define APP_VERSION		"2.70 Final with Elrinth command line functionality!"
// CHermit2App:
// このクラスの実装については、Hermit2.cpp を参照してください。
//

class CCDMApp : public CWinApp
{
public:
	CCDMApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCDMApp theApp;
