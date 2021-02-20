
// MFCDocViewTutView.h : interface of the CMFCDocViewTutView class
//

#pragma once
#include "MyProgressWnd.h"
#include "common.h"
class CMFCDocViewTutView : public CFormView
{
protected: // create from serialization only
	CMFCDocViewTutView();
	DECLARE_DYNCREATE(CMFCDocViewTutView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCDOCVIEWTUT_FORM };
#endif

// Attributes
public:
	CMFCDocViewTutDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CMFCDocViewTutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButTestProcessBar();
	afx_msg void OnBnClickedButTestMessagebox();
	afx_msg void OnBnClickedButTestGetvalue();
	afx_msg void OnBnClickedButTestGetNumber();
};

#ifndef _DEBUG  // debug version in MFCDocViewTutView.cpp
inline CMFCDocViewTutDoc* CMFCDocViewTutView::GetDocument() const
   { return reinterpret_cast<CMFCDocViewTutDoc*>(m_pDocument); }
#endif

