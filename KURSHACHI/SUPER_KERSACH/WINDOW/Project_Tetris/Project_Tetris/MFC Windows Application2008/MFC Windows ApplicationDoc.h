
// MFC Windows ApplicationDoc.h : interface of the CMFCWindowsApplicationDoc class
//


#pragma once


class CMFCWindowsApplicationDoc : public CDocument
{
protected: // create from serialization only
	CMFCWindowsApplicationDoc();
	DECLARE_DYNCREATE(CMFCWindowsApplicationDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CMFCWindowsApplicationDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


