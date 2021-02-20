// CommonGetValueDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CommonGetValueDlg.h"


// CCommonGetValueDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCommonGetValueDlg, CDialog)

CCommonGetValueDlg::CCommonGetValueDlg(int iMaxchar			/* = 10*/, 
									   CString strGetnum	/* = _T("")*/,
									   CString strTitle		/* = _T("Input the Value.")*/,
									   CWnd* pParent		/* = NULL*/,
									   BOOL bPwd			/* = FALSE*/, 
									   BOOL bBtnDisable		/* = FALSE*/)
	: CDialog(CCommonGetValueDlg::IDD, pParent)
{
	clearVariable();

	m_intMaxChar	= iMaxchar;
	m_strGetVal		= strGetnum;
	m_strWndText	= strTitle;
	m_bpwd			= bPwd;
	m_bbtndisable	= bBtnDisable;
}

CCommonGetValueDlg::~CCommonGetValueDlg()
{
	clearVariable();
}

void CCommonGetValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DISP_VAL, m_sDispValue);
	DDX_Control(pDX, IDB_KEY_DOT, m_bDot);
	DDX_Control(pDX, IDB_KEY_EQUAL, m_bEqual);
	DDX_Control(pDX, IDB_KEY_COLON, m_bColon);
	DDX_Control(pDX, IDB_KEY_WON, m_bWon);
}

BEGIN_MESSAGE_MAP(CCommonGetValueDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CCommonGetValueDlg, CDialog)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_OK, DISPID_CLICK, CCommonGetValueDlg::ClickKeyOk, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_ESC, DISPID_CLICK, CCommonGetValueDlg::ClickKeyEsc, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_BACK, DISPID_CLICK, CCommonGetValueDlg::ClickKeyBack, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_CLEAR, DISPID_CLICK, CCommonGetValueDlg::ClickKeyClear, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_1, DISPID_CLICK, CCommonGetValueDlg::ClickKey1, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_2, DISPID_CLICK, CCommonGetValueDlg::ClickKey2, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_3, DISPID_CLICK, CCommonGetValueDlg::ClickKey3, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_4, DISPID_CLICK, CCommonGetValueDlg::ClickKey4, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_5, DISPID_CLICK, CCommonGetValueDlg::ClickKey5, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_6, DISPID_CLICK, CCommonGetValueDlg::ClickKey6, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_7, DISPID_CLICK, CCommonGetValueDlg::ClickKey7, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_8, DISPID_CLICK, CCommonGetValueDlg::ClickKey8, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_9, DISPID_CLICK, CCommonGetValueDlg::ClickKey9, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_0, DISPID_CLICK, CCommonGetValueDlg::ClickKey0, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_Q, DISPID_CLICK, CCommonGetValueDlg::ClickKeyQ, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_W, DISPID_CLICK, CCommonGetValueDlg::ClickKeyW, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_E, DISPID_CLICK, CCommonGetValueDlg::ClickKeyE, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_R, DISPID_CLICK, CCommonGetValueDlg::ClickKeyR, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_T, DISPID_CLICK, CCommonGetValueDlg::ClickKeyT, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_Y, DISPID_CLICK, CCommonGetValueDlg::ClickKeyY, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_U, DISPID_CLICK, CCommonGetValueDlg::ClickKeyU, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_I, DISPID_CLICK, CCommonGetValueDlg::ClickKeyI, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_O, DISPID_CLICK, CCommonGetValueDlg::ClickKeyO, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_P, DISPID_CLICK, CCommonGetValueDlg::ClickKeyP, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_A, DISPID_CLICK, CCommonGetValueDlg::ClickKeyA, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_S, DISPID_CLICK, CCommonGetValueDlg::ClickKeyS, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_D, DISPID_CLICK, CCommonGetValueDlg::ClickKeyD, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_F, DISPID_CLICK, CCommonGetValueDlg::ClickKeyF, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_G, DISPID_CLICK, CCommonGetValueDlg::ClickKeyG, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_H, DISPID_CLICK, CCommonGetValueDlg::ClickKeyH, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_J, DISPID_CLICK, CCommonGetValueDlg::ClickKeyJ, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_K, DISPID_CLICK, CCommonGetValueDlg::ClickKeyK, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_L, DISPID_CLICK, CCommonGetValueDlg::ClickKeyL, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_Z, DISPID_CLICK, CCommonGetValueDlg::ClickKeyZ, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_X, DISPID_CLICK, CCommonGetValueDlg::ClickKeyX, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_C, DISPID_CLICK, CCommonGetValueDlg::ClickKeyC, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_V, DISPID_CLICK, CCommonGetValueDlg::ClickKeyV, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_B, DISPID_CLICK, CCommonGetValueDlg::ClickKeyB, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_N, DISPID_CLICK, CCommonGetValueDlg::ClickKeyN, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_M, DISPID_CLICK, CCommonGetValueDlg::ClickKeyM, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_EQUAL, DISPID_CLICK, CCommonGetValueDlg::ClickKeyEqual, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_WON, DISPID_CLICK, CCommonGetValueDlg::ClickKeyWon, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_COLON, DISPID_CLICK, CCommonGetValueDlg::ClickKeyColon, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_DOT, DISPID_CLICK, CCommonGetValueDlg::ClickKeyDot, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_DASH, DISPID_CLICK, CCommonGetValueDlg::ClickKeyDash, VTS_NONE)
	ON_EVENT(CCommonGetValueDlg, IDB_KEY_UNDER_BAR, DISPID_CLICK, CCommonGetValueDlg::ClickKeyUnderBar, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

// CCommonGetValueDlg 메시지 처리기입니다.

void CCommonGetValueDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	UpdateDisplay();
}

BOOL CCommonGetValueDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	if(m_intMaxChar <= 0) 
		m_intMaxChar = 1;

	if( m_bbtndisable ) 
		btnDisable();

	SetWindowText(m_strWndText);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CCommonGetValueDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_KEYDOWN)
	{ 
		switch(pMsg->wParam)
		{
		case VK_NUMPAD0:
		case VK_0:
			ClickKey0();
			break;
		case VK_NUMPAD1:
		case VK_1:
			ClickKey1();
			break;
		case VK_NUMPAD2:
		case VK_2:
			ClickKey2();
			break;
		case VK_NUMPAD3:
		case VK_3:
			ClickKey3();
			break;
		case VK_NUMPAD4:
		case VK_4:
			ClickKey4();
			break;
		case VK_NUMPAD5:
		case VK_5:
			ClickKey5();
			break;
		case VK_NUMPAD6:
		case VK_6:
			ClickKey6();
			break;
		case VK_NUMPAD7:
		case VK_7:
			ClickKey7();
			break;
		case VK_NUMPAD8:
		case VK_8:
			ClickKey8();
			break;
		case VK_NUMPAD9:
		case VK_9:
			ClickKey9();
			break;
		case VK_BACK:
			ClickKeyBack();
			break;
		case VK_DECIMAL:
		case VK_OEM_PERIOD:
			ClickKeyDot();
			break;
		case VK_A:
			ClickKeyA();
			break;
		case VK_B:
			ClickKeyB();
			break;
		case VK_C:
			ClickKeyC();
			break;
		case VK_D:
			ClickKeyD();
			break;
		case VK_E:
			ClickKeyE();
			break;
		case VK_F:
			ClickKeyF();
			break;
		case VK_G:
			ClickKeyG();
			break;
		case VK_H:
			ClickKeyH();
			break;
		case VK_I:
			ClickKeyI();
			break;
		case VK_J:
			ClickKeyJ();
			break;
		case VK_K:
			ClickKeyK();
			break;
		case VK_L:
			ClickKeyL();
			break;
		case VK_M:
			ClickKeyM();
			break;
		case VK_N:
			ClickKeyN();
			break;
		case VK_O:
			ClickKeyO();
			break;
		case VK_P:
			ClickKeyP();
			break;
		case VK_Q:
			ClickKeyQ();
			break;
		case VK_R:
			ClickKeyR();
			break;
		case VK_S:
			ClickKeyS();
			break;
		case VK_T:
			ClickKeyT();
			break;
		case VK_U:
			ClickKeyU();
			break;
		case VK_V:
			ClickKeyV();
			break;
		case VK_W:
			ClickKeyW();
			break;
		case VK_X:
			ClickKeyX();
			break;
		case VK_Y:
			ClickKeyY();
			break;
		case VK_Z:
			ClickKeyZ();
			break;
		case VK_RETURN:
			ClickKeyOk();
			return TRUE;
		case VK_OEM_MINUS:
			if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
				ClickKeyUnderBar();
			else
				ClickKeyDash();
			break;
		case VK_SUBTRACT:
			ClickKeyDash();
			break;
		case VK_OEM_5:
			ClickKeyWon();
			break;
		case VK_OEM_PLUS:
			ClickKeyEqual();
			break;
		case VK_OEM_1:
			ClickKeyColon();
			break;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CCommonGetValueDlg::clearVariable()
{
	m_strGetVal.Empty();
	m_bpwd			= FALSE;
	m_bbtndisable	= FALSE;
	m_intMaxChar	= 0;

	m_strWndText.Empty();

	m_cxChar		= 0;
	m_cyChar		= 0;
}

void CCommonGetValueDlg::btnDisable()
{
	// TODO: Add your control notification handler code here
	m_bDot.EnableWindow(FALSE);
	m_bColon.EnableWindow(FALSE);
	m_bWon.EnableWindow(FALSE);
	m_bEqual.EnableWindow(FALSE);
}

void CCommonGetValueDlg::ClickKeyOk() 
{
	CDialog::OnOK();
}

void CCommonGetValueDlg::ClickKeyEsc() 
{
	CDialog::OnCancel();
}

void CCommonGetValueDlg::ClickKeyBack() 
{
	int len = m_strGetVal.GetLength();
	if( len )
	{
		m_strGetVal.SetAt(len-1, _T(' '));
		m_strGetVal.TrimRight();
		UpdateDisplay();
	}
}

void CCommonGetValueDlg::ClickKeyClear() 
{
	m_strGetVal = _T("");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey1() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("1");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey2() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("2");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey3() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("3");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey4() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("4");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey5() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("5");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey6() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("6");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey7() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("7");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey8() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("8");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey9() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("9");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKey0() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("0");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyQ() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("Q");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyW() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("W");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyE() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("E");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyR() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("R");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyT() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("T");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyY() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("Y");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyU() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("U");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyI() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("I");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyO() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("O");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyP() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("P");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyA() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("A");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyS() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("S");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyD() 
{
	if( !VerifyMaxChar() ) 
		return;
	
	m_strGetVal += _T("D");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyF() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("F");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyG() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("G");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyH() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("H");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyJ() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("J");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyK() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("K");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyL() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("L");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyZ() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("Z");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyX() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("X");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyC() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("C");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyV() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("V");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyB() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("B");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyN() 
{
	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("N");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyM() 
{
	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("M");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyEqual() 
{
	if( m_bpwd ) 
		return;

	if( !VerifyMaxChar() )
		return;

	m_strGetVal += _T("=");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyWon() 
{
	if( m_bpwd ) 
		return;

	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("\\");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyColon() 
{
	if( m_bpwd ) 
		return;

	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T(":");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyDot() 
{
	if( m_bpwd ) 
		return;

	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T(".");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyDash() 
{
	if( m_bpwd ) 
		return;

	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("-");	
	UpdateDisplay();
}

void CCommonGetValueDlg::ClickKeyUnderBar() 
{
	if( m_bpwd ) 
		return;

	if( !VerifyMaxChar() ) 
		return;

	m_strGetVal += _T("_");	
	UpdateDisplay();
}

BOOL CCommonGetValueDlg::VerifyMaxChar()
{
	if( m_strGetVal.GetLength() >= m_intMaxChar ) 
		return FALSE;
	else
		return TRUE;
}

void CCommonGetValueDlg::UpdateDisplay(COLORREF bkcolor)
{
	UNUSED_ALWAYS(bkcolor);

	int len, i;
	CString bufstr;

	if( m_bpwd )
	{
		len = m_strGetVal.GetLength();
		if( len <= 0 ) 
		{
			bufstr = _T("");
			m_sDispValue.SetCaption(bufstr);
			return;
		}

		for(i=0;i<len;i++) 
			bufstr += _T("*");

		m_sDispValue.SetCaption(bufstr);
	}
	else
	{
		m_sDispValue.SetCaption(m_strGetVal);
	}
}

void CCommonGetValueDlg::InitStaticDispWnd()
{
    CStatic* pRect = (CStatic*)GetDlgItem(IDC_DISP_VAL);
    pRect->GetWindowRect(&m_rect);
    pRect->DestroyWindow();
    ScreenToClient(&m_rect);

    TEXTMETRIC tm;
    CClientDC dc(this);
    dc.GetTextMetrics(&tm);
    m_cxChar = tm.tmAveCharWidth;
    m_cyChar = tm.tmHeight - tm.tmDescent;
}

CString CCommonGetValueDlg::GetStringValue()
{
	return m_strGetVal;
}
