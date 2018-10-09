
// ChildView.cpp : CChildView 類別的實作
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_ptStart(0)
	, m_ptEnd(0)
	, m_bPainting(false)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView 訊息處理常式

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 繪製的裝置內容
	
	// TODO: 在此加入您的訊息處理常式程式碼
	
	// 不要呼叫描繪訊息的 CWnd::OnPaint()
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	m_ptEnd = m_ptStart = point;
	SetCapture();
//	m_bPainting = true;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
//	if (!m_bPainting)
//		return;
	if (GetCapture() != this)
		return;


	CClientDC dc(this);
	CPen penWhite(PS_SOLID, 1, RGB(255, 255, 255));
	

	CPen *pOldPen = dc.SelectObject(&penWhite);

	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);

	CPen penBlack(PS_SOLID, 1, RGB(0, 0, 0));
	
	m_ptEnd = point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);

	dc.SelectObject(pOldPen);
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	if (GetCapture() != this)
		return;
	CWnd::OnLButtonUp(nFlags, point);
}
