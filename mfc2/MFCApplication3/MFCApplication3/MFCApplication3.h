
// MFCApplication3.h : MFCApplication3 ���ε{�����D���Y��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"       // �D�n�Ÿ�


// CMFCApplication3App:
// �аѾ\��@�����O�� MFCApplication3.cpp
//

class CMFCApplication3App : public CWinAppEx
{
public:
	CMFCApplication3App();


// �мg
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �{���X��@
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication3App theApp;
