
// ChildView.h : CChildView 類別的介面
//


#pragma once
#include "atltypes.h"


// CChildView 視窗

class CChildView : public CWnd
{
// 建構
public:
	CChildView();

// 屬性
public:

// 作業
public:

// 覆寫
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 程式碼實作
public:
	virtual ~CChildView();

	// 產生的訊息對應函式
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint m_ptStart;
	CPoint m_ptEnd;
	bool m_bPainting;
};

