
// ChildView.cpp : CChildView ���O����@
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



// CChildView �T���B�z�`��

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
	CPaintDC dc(this); // ø�s���˸m���e
	
	// TODO: �b���[�J�z���T���B�z�`���{���X
	
	// ���n�I�s�yø�T���� CWnd::OnPaint()
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	m_ptEnd = m_ptStart = point;
	SetCapture();
//	m_bPainting = true;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
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
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	if (GetCapture() != this)
		return;
	CWnd::OnLButtonUp(nFlags, point);
}
