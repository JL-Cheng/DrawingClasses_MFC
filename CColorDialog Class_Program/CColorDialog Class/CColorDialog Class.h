
// CColorDialog Class.h : CColorDialog Class Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCColorDialogClassApp:
// �йش����ʵ�֣������ CColorDialog Class.cpp
//

class CCColorDialogClassApp : public CWinApp
{
public:
	CCColorDialogClassApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCColorDialogClassApp theApp;
