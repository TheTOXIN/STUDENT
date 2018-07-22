
// MFC Windows ApplicationDoc.cpp : implementation of the CMFCWindowsApplicationDoc class
//

#include "stdafx.h"
#include "MFC Windows Application.h"

#include "MFC Windows ApplicationDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWindowsApplicationDoc

IMPLEMENT_DYNCREATE(CMFCWindowsApplicationDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCWindowsApplicationDoc, CDocument)
END_MESSAGE_MAP()


// CMFCWindowsApplicationDoc construction/destruction

CMFCWindowsApplicationDoc::CMFCWindowsApplicationDoc()
{
	// TODO: add one-time construction code here

}

CMFCWindowsApplicationDoc::~CMFCWindowsApplicationDoc()
{
}

BOOL CMFCWindowsApplicationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCWindowsApplicationDoc serialization

void CMFCWindowsApplicationDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CMFCWindowsApplicationDoc diagnostics

#ifdef _DEBUG
void CMFCWindowsApplicationDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCWindowsApplicationDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCWindowsApplicationDoc commands
