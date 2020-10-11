// Hermit2.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "CDM.h"
#include "CDMDlg.h"
#include "Setting.h"
#include "ThemeController.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHermit2App

BEGIN_MESSAGE_MAP(CCDMApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CHermit2App コンストラクション

CCDMApp::CCDMApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// CHermit2App オブジェクトです。

CCDMApp theApp;
CSetting theSetting;
CThemeController theTheme;

// CHermit2App 初期化

BOOL CCDMApp::InitInstance()
{
	// アプリケーション　マニフェストが　visual スタイルを有効にするために、
	// ComCtl32.dll バージョン 6　以降の使用を指定する場合は、
	// Windows XP に　InitCommonControls() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	theSetting.Load();

	InitCommonControls();

	CWinApp::InitInstance();


	CCDMDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//       記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ダイアログが <キャンセル> で消された時のコードを
		//       記述してください。
	}

	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	// アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}
