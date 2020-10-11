// Hermit2.cpp : �A�v���P�[�V�����̃N���X������`���܂��B
//

#include "stdafx.h"
#include "afxwin.h"
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

// CHermit2App �R���X�g���N�V����

CCDMApp::CCDMApp()
{
    // TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
    // ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}

// CHermit2App �I�u�W�F�N�g�ł��B

CCDMApp theApp;
CSetting theSetting;
CThemeController theTheme;

// CHermit2App ������

LPSTR *CommandLineToArgvA(LPSTR lpCmdLine, INT *pNumArgs)
{
    int retval;
    retval = MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, lpCmdLine, -1, NULL, 0);
    if (!SUCCEEDED(retval))
        return NULL;

    LPWSTR lpWideCharStr = (LPWSTR)malloc(retval * sizeof(WCHAR));
    if (lpWideCharStr == NULL)
        return NULL;

    retval = MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, lpCmdLine, -1, lpWideCharStr, retval);
    if (!SUCCEEDED(retval))
    {
        free(lpWideCharStr);
        return NULL;
    }

    int numArgs;
    LPWSTR *args;
    args = CommandLineToArgvW(lpWideCharStr, &numArgs);
    free(lpWideCharStr);
    if (args == NULL)
        return NULL;

    int storage = numArgs * sizeof(LPSTR);
    for (int i = 0; i < numArgs; ++i)
    {
        BOOL lpUsedDefaultChar = FALSE;
        retval = WideCharToMultiByte(CP_ACP, 0, args[i], -1, NULL, 0, NULL, &lpUsedDefaultChar);
        if (!SUCCEEDED(retval))
        {
            LocalFree(args);
            return NULL;
        }

        storage += retval;
    }

    LPSTR *result = (LPSTR *)LocalAlloc(LMEM_FIXED, storage);
    if (result == NULL)
    {
        LocalFree(args);
        return NULL;
    }

    int bufLen = storage - numArgs * sizeof(LPSTR);
    LPSTR buffer = ((LPSTR)result) + numArgs * sizeof(LPSTR);
    for (int i = 0; i < numArgs; ++i)
    {
        _ASSERT(bufLen > 0);
        BOOL lpUsedDefaultChar = FALSE;
        retval = WideCharToMultiByte(CP_ACP, 0, args[i], -1, buffer, bufLen, NULL, &lpUsedDefaultChar);
        if (!SUCCEEDED(retval))
        {
            LocalFree(result);
            LocalFree(args);
            return NULL;
        }

        result[i] = buffer;
        buffer += retval;
        bufLen -= retval;
    }

    LocalFree(args);

    *pNumArgs = numArgs;
    return result;
}

BOOL CCDMApp::InitInstance()
{
    // �A�v���P�[�V�����@�}�j�t�F�X�g���@visual �X�^�C����L���ɂ��邽�߂ɁA
    // ComCtl32.dll �o�[�W���� 6�@�ȍ~�̎g�p���w�肷��ꍇ�́A
    // Windows XP �Ɂ@InitCommonControls() ���K�v�ł��B�����Ȃ���΁A�E�B���h�E�쐬�͂��ׂĎ��s���܂��B
    theSetting.Load();

    InitCommonControls();

    CWinApp::InitInstance();

    LPSTR wat = GetCommandLineA();
    int argc;
    LPSTR *argv = CommandLineToArgvA(wat, &argc);
    bool nextArgIsDriveIndex = false;
    bool nextArgIsOutputPath = false;

    int driveIndex = -1;
    LPSTR outputPath;

    for (int i = 0; i < argc; i++)
    {
        LPSTR arg = argv[i];
        if (nextArgIsDriveIndex)
        {
            driveIndex = _ttoi(arg);
            nextArgIsDriveIndex = false;
        }
        if (strcmp(arg, LPSTR("-driveindex")) == 0)
        {
            nextArgIsDriveIndex = true;
        }

        if (nextArgIsOutputPath)
        {
            outputPath = arg;
            nextArgIsOutputPath = false;
        }
        if (strcmp(arg, LPSTR("-o")) == 0)
        {
            nextArgIsOutputPath = true;
        }
    }

    if (outputPath != NULL && driveIndex != -1)
    {
        theSetting.m_LastAccessFile = outputPath;
        theSetting.m_DriveNo = driveIndex;
        theSetting.m_autostart = true;
    }

    CCDMDlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO: �_�C�A���O�� <OK> �ŏ����ꂽ���̃R�[�h��
        //       �L�q���Ă��������B
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: �_�C�A���O�� <�L�����Z��> �ŏ����ꂽ���̃R�[�h��
        //       �L�q���Ă��������B
    }

    // �_�C�A���O�͕����܂����B�A�v���P�[�V�����̃��b�Z�[�W �|���v���J�n���Ȃ���
    // �A�v���P�[�V�������I�����邽�߂� FALSE ��Ԃ��Ă��������B
    //delete[] outputPath;
    LocalFree(argv);
    if (theSetting.m_canceled)
    {
        char *s = "Canceled";
        AllocConsole();
        DWORD NumberOfBytesWritten = 0;
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s, lstrlen(s), &NumberOfBytesWritten, 0);
        delete[] s;
    }
    return FALSE;
}
