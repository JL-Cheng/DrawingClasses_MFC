
// CFontDialog Class.h : CFontDialog Class Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCFontDialogClassApp:
// �йش����ʵ�֣������ CFontDialog Class.cpp
//

class CCFontDialogClassApp : public CWinApp
{
public:
	CCFontDialogClassApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCFontDialogClassApp theApp;
