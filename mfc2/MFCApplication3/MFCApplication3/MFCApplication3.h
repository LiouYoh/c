
// MFCApplication3.h : MFCApplication3 應用程式的主標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// CMFCApplication3App:
// 請參閱實作此類別的 MFCApplication3.cpp
//

class CMFCApplication3App : public CWinAppEx
{
public:
	CMFCApplication3App();


// 覆寫
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 程式碼實作
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication3App theApp;
