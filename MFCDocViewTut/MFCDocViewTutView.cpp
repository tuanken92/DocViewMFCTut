
// MFCDocViewTutView.cpp : implementation of the CMFCDocViewTutView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCDocViewTut.h"
#endif

#include "MFCDocViewTutDoc.h"
#include "MFCDocViewTutView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDocViewTutView

IMPLEMENT_DYNCREATE(CMFCDocViewTutView, CFormView)

BEGIN_MESSAGE_MAP(CMFCDocViewTutView, CFormView)
	ON_BN_CLICKED(IDC_BUT_TEST_PROCESS_BAR, &CMFCDocViewTutView::OnBnClickedButTestProcessBar)
	ON_BN_CLICKED(IDC_BUT_TEST_MESSAGEBOX, &CMFCDocViewTutView::OnBnClickedButTestMessagebox)
	ON_BN_CLICKED(IDC_BUT_TEST_GETVALUE, &CMFCDocViewTutView::OnBnClickedButTestGetvalue)
	ON_BN_CLICKED(IDC_BUT_TEST_GET_NUMBER, &CMFCDocViewTutView::OnBnClickedButTestGetNumber)
END_MESSAGE_MAP()

// CMFCDocViewTutView construction/destruction

CMFCDocViewTutView::CMFCDocViewTutView()
	: CFormView(IDD_MFCDOCVIEWTUT_FORM)
{
	// TODO: add construction code here

}

CMFCDocViewTutView::~CMFCDocViewTutView()
{
}

void CMFCDocViewTutView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFCDocViewTutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMFCDocViewTutView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMFCDocViewTutView diagnostics

#ifdef _DEBUG
void CMFCDocViewTutView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCDocViewTutView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCDocViewTutDoc* CMFCDocViewTutView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDocViewTutDoc)));
	return (CMFCDocViewTutDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDocViewTutView message handlers


void CMFCDocViewTutView::OnBnClickedButTestProcessBar()
{
	// TODO: Add your control notification handler code here
	CString str = "";

	CMyProgressWnd ProgWnd(NULL, _T("Destroy Components"));
	ProgWnd.SetRange(0, 100);

	ProgWnd.SetText(_T("Stop Thread"));

	for (int i = 0; i < 100; i++)
	{
		str.Format("%d", i);
		TRACE(str);
		Sleep(10);
		ProgWnd.StepIt();
	}

	
}


void CMFCDocViewTutView::OnBnClickedButTestMessagebox()
{
	// TODO: Add your control notification handler code here
	int a = MyMessageBox(M_ICONERROR, _T("Runtime folder not exist"), _T("YES"), _T("NO"), _T("Not found runtime folder."));
	CString str = "";
	str.Format("a = %d", a);
	MessageBox(str);

	MyMessageBox(_T("Do you Clear Product Data?"), _T("Question"), M_ICONQUESTION | M_YESNO, _T("Yes"), _T("No"));

	MyMessageBox(_T("Do you want start Tray Unloading?"), _T("Question"), M_ICONQUESTION | M_YESNO, _T("Yes"), _T("No"));

	MyMessageBox("Machine Not Ready.", "Move Fail.", M_ICONERROR);

	MyMessageBox(_T("Origin return was complete."), _T("Origin Success"), M_ICONINFORMATION, _T("Confirm"));

	MyMessageBox(17200, _T("Password Input Error"), M_ICONERROR);
}


void CMFCDocViewTutView::OnBnClickedButTestGetvalue()
{
	// TODO: Add your control notification handler code here
	CString strBuf = "";

	GetValueBox(&strBuf, 10, _T(""), _T("Input Password. (Max 10)"), FALSE);

	MessageBox(strBuf);
		
}


void CMFCDocViewTutView::OnBnClickedButTestGetNumber()
{
	// TODO: Add your control notification handler code here
	CString strTemp = "", strBufGet = "";
	strTemp.Format(_T("%.0f"), 123.45);

	GetNumberBox(&strBufGet, 10, strTemp);
	MessageBox(strBufGet);

	strTemp.Format(_T("%d"), 1235);
	GetNumberBox(&strBufGet, 10, strTemp,"sadsad");
	MessageBox(strBufGet);
}
