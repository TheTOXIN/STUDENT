
// MFC Windows ApplicationView.cpp : implementation of the CMFCWindowsApplicationView class
//

#include "stdafx.h"
#include "MFC Windows Application.h"

#include "MFC Windows ApplicationDoc.h"
#include "MFC Windows ApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWindowsApplicationView

IMPLEMENT_DYNCREATE(CMFCWindowsApplicationView, CView)

BEGIN_MESSAGE_MAP(CMFCWindowsApplicationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCWindowsApplicationView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCWindowsApplicationView construction/destruction

CMFCWindowsApplicationView::CMFCWindowsApplicationView()
{
	// TODO: add construction code here

}

CMFCWindowsApplicationView::~CMFCWindowsApplicationView()
{
}

BOOL CMFCWindowsApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCWindowsApplicationView drawing

void CMFCWindowsApplicationView::OnDraw(CDC* /*pDC*/)
{
	CMFCWindowsApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCWindowsApplicationView printing


void CMFCWindowsApplicationView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CMFCWindowsApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCWindowsApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCWindowsApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCWindowsApplicationView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCWindowsApplicationView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CMFCWindowsApplicationView diagnostics

#ifdef _DEBUG
void CMFCWindowsApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCWindowsApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCWindowsApplicationDoc* CMFCWindowsApplicationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCWindowsApplicationDoc)));
	return (CMFCWindowsApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCWindowsApplicationView message handlers
