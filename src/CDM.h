// Hermit2.h : PROJECT_NAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#pragma once

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h" // ���C�� �V���{��

#define APP_VERSION "2.71 Final with Elrinth command line functionality!"
// CHermit2App:
// ���̃N���X�̎����ɂ��ẮAHermit2.cpp ���Q�Ƃ��Ă��������B
//

class CCDMApp : public CWinApp
{
public:
	CCDMApp();

	// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

	// ����

	DECLARE_MESSAGE_MAP()
};

extern CCDMApp theApp;
