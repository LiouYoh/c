
// MFCApplication3View.h : CMFCApplication3View ���O������
//

#pragma once


class CMFCApplication3View : public CView
{
protected: // �ȱq�ǦC�ƫإ�
	CMFCApplication3View();
	DECLARE_DYNCREATE(CMFCApplication3View)

// �ݩ�
public:
	CMFCApplication3Doc* GetDocument() const;

// �@�~
public:

// �мg
public:
	virtual void OnDraw(CDC* pDC);  // �мg�H�yø���˵�
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �{���X��@
public:
	virtual ~CMFCApplication3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication3View.cpp ������������
inline CMFCApplication3Doc* CMFCApplication3View::GetDocument() const
   { return reinterpret_cast<CMFCApplication3Doc*>(m_pDocument); }
#endif

