
// MFC Windows ApplicationView.h : interface of the CMFCWindowsApplicationView class
//


#pragma once


class CMFCWindowsApplicationView : public CView
{
protected: // create from serialization only
	CMFCWindowsApplicationView();
	DECLARE_DYNCREATE(CMFCWindowsApplicationView)

// Attributes
public:
	CMFCWindowsApplicationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCWindowsApplicationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC Windows ApplicationView.cpp
inline CMFCWindowsApplicationDoc* CMFCWindowsApplicationView::GetDocument() const
   { return reinterpret_cast<CMFCWindowsApplicationDoc*>(m_pDocument); }
#endif

