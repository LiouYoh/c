
// MFCApplication3Doc.cpp : CMFCApplication3Doc ���O����@
//

#include "stdafx.h"
// SHARED_HANDLERS �i�H�w�q�b��@�w���B�Y�ϩM�j�M�z�����B�z�`����
// ATL �M�פ��A�ä��\�P�ӱM�צ@�Τ��{���X�C
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication3Doc

IMPLEMENT_DYNCREATE(CMFCApplication3Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication3Doc, CDocument)
END_MESSAGE_MAP()


// CMFCApplication3Doc �غc/�Ѻc

CMFCApplication3Doc::CMFCApplication3Doc()
{
	// TODO: �b���[�J�@���غc�{���X

}

CMFCApplication3Doc::~CMFCApplication3Doc()
{
}

BOOL CMFCApplication3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �b���[�J���s��l�Ƶ{���X
	// (SDI ���|���Φ����)

	return TRUE;
}




// CMFCApplication3Doc �ǦC��

void CMFCApplication3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �b���[�J�x�s�{���X
	}
	else
	{
		// TODO: �b���[�J���J�{���X
	}
}

#ifdef SHARED_HANDLERS

// �Y�Ϫ��䴩
void CMFCApplication3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �ק�o�q�{���X�Hø�s��󪺸��
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �j�M�B�z�`�����䴩
void CMFCApplication3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// �]�w�Ӧۤ���ƪ��j�M���e�C
	// ���e�������ӥH ";" �j�}

	// �d��:     strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplication3Doc �E�_

#ifdef _DEBUG
void CMFCApplication3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplication3Doc �R�O
