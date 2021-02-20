// CommonGetNumDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CommonGetNumDlg.h"




// CCommonGetNumDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCommonGetNumDlg, CDialog)

CCommonGetNumDlg::CCommonGetNumDlg(int iMaxchar			/* = 10*/, 
									CString strGetnum	/* = _T("123")*/,
									CString strTitle	/* = _T("Insert Number Only.")*/,
									CWnd* pParent		/* = NULL*/, 
									BOOL bPwd			/* = FALSE*/)
	: CDialog(CCommonGetNumDlg::IDD, pParent)
{
	clearVariable();

	m_intMaxChar		= iMaxchar;
	m_bpwd				= bPwd;
	m_strGetNum			= strGetnum;
	m_strWndText		= strTitle;
	m_strOrg			= m_strGetNum;

	if(m_bpwd)
		BOOL Create(CWnd* pParentWnd);

	m_cxChar = 0;
	m_cyChar = 0;

	if( -1 == m_strGetNum.Find(_T('-')) )
		m_numFlag = TRUE;
	else
		m_numFlag= FALSE;

	if( -1 == m_strGetNum.Find(_T('.')) )
		m_nPointNum = 0;
	else
		m_nPointNum = 6;
}

CCommonGetNumDlg::~CCommonGetNumDlg()
{
	clearVariable();
}

void CCommonGetNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRESENT, m_ctrlBtnSetValue);
	DDX_Control(pDX, IDC_MODIFY, m_ctrlBtnDispNum);
}


BEGIN_MESSAGE_MAP(CCommonGetNumDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CCommonGetNumDlg, CDialog)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_PLUS, DISPID_CLICK, CCommonGetNumDlg::ClickBtnPlus, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_MINUS, DISPID_CLICK, CCommonGetNumDlg::ClickBtnMinus, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_EQUAL, DISPID_CLICK, CCommonGetNumDlg::ClickBtnEqual, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_DOT, DISPID_CLICK, CCommonGetNumDlg::ClickBtnDot, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_SIGN, DISPID_CLICK, CCommonGetNumDlg::ClickBtnSign, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_BACK, DISPID_CLICK, CCommonGetNumDlg::ClickBtnBack, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_CLEAR, DISPID_CLICK, CCommonGetNumDlg::ClickBtnClear, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_OK, DISPID_CLICK, CCommonGetNumDlg::ClickBtnOk, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDB_BTN_ESC, DISPID_CLICK, CCommonGetNumDlg::ClickBtnEsc, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_1, DISPID_CLICK, CCommonGetNumDlg::ClickBtn1, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_2, DISPID_CLICK, CCommonGetNumDlg::ClickBtn2, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_3, DISPID_CLICK, CCommonGetNumDlg::ClickBtn3, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_4, DISPID_CLICK, CCommonGetNumDlg::ClickBtn4, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_5, DISPID_CLICK, CCommonGetNumDlg::ClickBtn5, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_6, DISPID_CLICK, CCommonGetNumDlg::ClickBtn6, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_7, DISPID_CLICK, CCommonGetNumDlg::ClickBtn7, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_8, DISPID_CLICK, CCommonGetNumDlg::ClickBtn8, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_9, DISPID_CLICK, CCommonGetNumDlg::ClickBtn9, VTS_NONE)
	ON_EVENT(CCommonGetNumDlg, IDC_BTN_0, DISPID_CLICK, CCommonGetNumDlg::ClickBtn0, VTS_NONE)
END_EVENTSINK_MAP()

BOOL CCommonGetNumDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowText(m_strWndText);
	//m_ctrlBtnDispNum.SetCaption(m_strOrg);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CCommonGetNumDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_KEYDOWN)
	{ 
		switch(pMsg->wParam)
		{
		case VK_NUMPAD0:
		case VK_0:
			ClickBtn0();
			break;
		case VK_NUMPAD1:
		case VK_1:
			ClickBtn1();
			break;
		case VK_NUMPAD2:
		case VK_2:
			ClickBtn2();
			break;
		case VK_NUMPAD3:
		case VK_3:
			ClickBtn3();
			break;
		case VK_NUMPAD4:
		case VK_4:
			ClickBtn4();
			break;
		case VK_NUMPAD5:
		case VK_5:
			ClickBtn5();
			break;
		case VK_NUMPAD6:
		case VK_6:
			ClickBtn6();
			break;
		case VK_NUMPAD7:
		case VK_7:
			ClickBtn7();
			break;
		case VK_NUMPAD8:
		case VK_8:
			ClickBtn8();
			break;
		case VK_NUMPAD9:
		case VK_9:
			ClickBtn9();
			break;
		case VK_BACK:
			ClickBtnBack();
			break;
		case VK_DECIMAL:
		case VK_OEM_PERIOD:
			ClickBtnDot();
			break;
		case VK_ADD:
			ClickBtnPlus();
			break;
		case VK_SUBTRACT:
			ClickBtnMinus();
			break;
		case VK_RETURN:
			if (m_bCalu == TRUE) {
				ClickBtnEqual();
			}
			else {
				ClickBtnOk();
			}
			return TRUE;
			break;	
		case VK_DIVIDE:
		case VK_OEM_2:
			ClickBtnSign();
			break;
		}
	} 

	return CDialog::PreTranslateMessage(pMsg);
}

void CCommonGetNumDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	UpdateDisplay();
}

// CCommonGetNumDlg 메시지 처리기입니다.

void CCommonGetNumDlg::SetWindowTitle(CString strTitle)
{
	m_strWndText = strTitle;
}

void CCommonGetNumDlg::clearVariable()
{
	m_cyChar		= 0;
	m_cxChar		= 0;
	m_numFlag		= FALSE;
	m_strGetNum.Empty();

	m_nPointNum		= 0;
	m_bCalu			= FALSE;
	m_nCalu			= 0;
	m_FirstFlag		= TRUE;
	m_bpwd			= FALSE;

	m_strOrg.Empty();
	m_intMaxChar	= 0;
	m_strWndText.Empty();
}

void CCommonGetNumDlg::UpdateDisplay(COLORREF bkcolor/* = RGB(255, 255, 255)*/)
{
	UNUSED_ALWAYS(bkcolor);
	m_ctrlBtnDispNum.SetCaption(m_strGetNum);
 }

BOOL CCommonGetNumDlg::VerifyMaxChar()
{
	if( m_strGetNum.GetLength() >= m_intMaxChar ) 
		return FALSE;
	else 
		return TRUE;
}

void CCommonGetNumDlg::InitStaticDispWnd()
{
	CStatic* pRect = (CStatic*)GetDlgItem(IDC_MODIFY);
	pRect->GetWindowRect(&m_rect);
	pRect->DestroyWindow();
	ScreenToClient(&m_rect);

	TEXTMETRIC tm;
	CClientDC dc(this);
	dc.GetTextMetrics(&tm);
	m_cxChar = tm.tmAveCharWidth;
	m_cyChar = tm.tmHeight - tm.tmDescent;
}

void CCommonGetNumDlg::ClickBtnPlus()
{
	if( !m_FirstFlag ) 
		return;

	m_bCalu			= TRUE;
	m_nCalu			= TRUE;

	m_FirstFlag		= TRUE;

	m_strOrg		= m_strGetNum;
	m_strGetNum		= _T("+");

	m_ctrlBtnSetValue.SetCaption(m_strOrg);
	UpdateDisplay();	
}

void CCommonGetNumDlg::ClickBtnMinus() 
{
	if( !m_FirstFlag ) return;

	m_bCalu = TRUE;
	m_nCalu = FALSE;

	m_FirstFlag = TRUE;

	m_strOrg = m_strGetNum;
	m_strGetNum = _T("-");

	m_ctrlBtnSetValue.SetCaption(m_strOrg);
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtnEqual() 
{
	double fi, se, rel;
	CString strBuf;

	if( !m_bCalu ) return;

	m_strGetNum.Remove(_T('+'));
	m_strGetNum.Remove(_T('-'));

	fi = _tstof(m_strOrg);
	se = _tstof(m_strGetNum);

	if( m_nCalu )
		rel = (fi) + (se);
	else
		rel = (fi) - (se);

	if( !m_nPointNum )
		strBuf.Format(_T("%.0f"), rel);
	else
		strBuf.Format(_T("%.6f"), rel);

	m_strGetNum = strBuf;
	UpdateDisplay();

	m_FirstFlag = TRUE;
	m_bCalu		= FALSE;
}

void CCommonGetNumDlg::ClickBtnDot() 
{
	if( m_bpwd ) 
		return;

	if( !VerifyMaxChar() ) 
		return;

	m_strGetNum += _T(".");	
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtnSign() 
{
	if( m_bpwd ) 
		return;

	if( !m_strGetNum.GetLength() ) 
		return;

	if(TRUE == m_numFlag)
	{
		m_strGetNum.Insert(0, _T('-'));
		m_numFlag=FALSE;
	}
	else
	{
		m_strGetNum.Remove( _T('-') );
		m_numFlag=TRUE;
	}

	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtnBack() 
{
	m_FirstFlag = FALSE;

	int len = m_strGetNum.GetLength();
	if(len)
	{
		m_strGetNum.SetAt(len-1, _T(' ') );
		m_strGetNum.TrimRight();
		UpdateDisplay();
	}
}

void CCommonGetNumDlg::ClickBtnClear() 
{
	m_strGetNum = _T("");	
	m_numFlag	= TRUE;
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtnOk() 
{
	if (m_bCalu == TRUE) {
		ClickBtnEqual();
	}

	if(m_bpwd)
		DestroyWindow();
	else
		CDialog::OnOK();
}

void CCommonGetNumDlg::ClickBtnEsc() 
{
	if(m_bpwd)
		DestroyWindow();
	else 
		CDialog::OnCancel();
}

void CCommonGetNumDlg::ClickBtn1() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() ) 
		return;

	m_strGetNum += _T("1");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn2() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() ) 
		return;

	m_strGetNum += _T("2");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn3() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() ) 
		return;

	m_strGetNum += _T("3");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn4() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() ) 
		return;

	m_strGetNum += _T("4");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn5() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() ) return;

	m_strGetNum += _T("5");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn6() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() )
		return;

	m_strGetNum += _T("6");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn7() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() )
		return;

	m_strGetNum += _T("7");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn8() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() ) 
		return;

	m_strGetNum += _T("8");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn9() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() ) 
		return;

	m_strGetNum += _T("9");
	UpdateDisplay();
}

void CCommonGetNumDlg::ClickBtn0() 
{
	if( m_FirstFlag )
	{
		m_FirstFlag		= FALSE;
		m_numFlag		= TRUE;
		m_strGetNum		= _T("");

		if (m_bCalu) {
			if (m_nCalu)	m_strGetNum += _T("+");
			else			m_strGetNum += _T("-");
		}
	}

	if( !VerifyMaxChar() )
		return;

	m_strGetNum += _T("0");
	UpdateDisplay();
}

