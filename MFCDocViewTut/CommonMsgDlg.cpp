// CommonMsgDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"

#include "Common.h"
#include "CommonMsgDlg.h"


// CCommonMsgDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCommonMsgDlg, CDialog)

CCommonMsgDlg::CCommonMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommonMsgDlg::IDD, pParent)
{
	m_brBckColor.CreateSolidBrush(RGB(255,255,255));

	clearVariable();
}

CCommonMsgDlg::~CCommonMsgDlg()
{
	m_brBckColor.DeleteObject();
}

void CCommonMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, ID_MYABORT, m_ctrlBtnMyAbort);
	DDX_Control(pDX, ID_MYCANCEL, m_ctrlBtnMyCancel);
	DDX_Control(pDX, ID_MYCANCEL3, m_ctrlBtnMyCancel3);
	DDX_Control(pDX, ID_MYIGNORE, m_ctrlBtnMyIgnore);
	DDX_Control(pDX, ID_MYNO, m_ctrlBtnMyNo);
	DDX_Control(pDX, ID_MYOK, m_ctrlBtnMyOk);
	DDX_Control(pDX, ID_MYOK2, m_ctrlBtnMyOk2);
	DDX_Control(pDX, ID_MYRETRY, m_ctrlBtnMyRetry);
	DDX_Control(pDX, ID_MYRETRY3, m_ctrlBtnMyRetry3);
	DDX_Control(pDX, ID_MYYES, m_ctrlBtnMyYes);
	DDX_Control(pDX, IDC_PICTURE, m_ctrlBtnMyIcon);
	DDX_Control(pDX, IDC_EDITLABEL, m_ctrlBtnMsg);
}


BEGIN_MESSAGE_MAP(CCommonMsgDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CCommonMsgDlg 메시지 처리기입니다.
BEGIN_EVENTSINK_MAP(CCommonMsgDlg, CDialog)
	ON_EVENT(CCommonMsgDlg, ID_MYABORT, DISPID_CLICK, CCommonMsgDlg::ClickMyabort, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYOK, DISPID_CLICK, CCommonMsgDlg::ClickMyok, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYYES, DISPID_CLICK, CCommonMsgDlg::ClickMyyes, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYRETRY3, DISPID_CLICK, CCommonMsgDlg::ClickMyretry3, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYOK2, DISPID_CLICK, CCommonMsgDlg::ClickMyok2, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYRETRY, DISPID_CLICK, CCommonMsgDlg::ClickMyretry, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYCANCEL, DISPID_CLICK, CCommonMsgDlg::ClickMycancel, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYCANCEL3, DISPID_CLICK, CCommonMsgDlg::ClickMycancel3, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYNO, DISPID_CLICK, CCommonMsgDlg::ClickMyno, VTS_NONE)
	ON_EVENT(CCommonMsgDlg, ID_MYIGNORE, DISPID_CLICK, CCommonMsgDlg::ClickMyignore, VTS_NONE)
END_EVENTSINK_MAP()

BOOL CCommonMsgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// 현재 실행 경로를 가져온다.
	GetCurrentDirectory(1024, m_strCurrPath.GetBuffer(1024));
	m_strCurrPath.ReleaseBuffer();

	CString strTemp;

	// 타이틀 문자열 설정
	SetWindowText(m_strTitle);

	// 모든 버튼 숨기기
	m_ctrlBtnMyOk2.ShowWindow(SW_HIDE);
	m_ctrlBtnMyOk.ShowWindow(SW_HIDE);
	m_ctrlBtnMyCancel.ShowWindow(SW_HIDE);
	m_ctrlBtnMyYes.ShowWindow(SW_HIDE);
	m_ctrlBtnMyNo.ShowWindow(SW_HIDE);
	m_ctrlBtnMyAbort.ShowWindow(SW_HIDE);
	m_ctrlBtnMyRetry.ShowWindow(SW_HIDE);
	m_ctrlBtnMyIgnore.ShowWindow(SW_HIDE);
	m_ctrlBtnMyCancel3.ShowWindow(SW_HIDE);
	m_ctrlBtnMyRetry3.ShowWindow(SW_HIDE);

	switch(m_uiType)
	{
	case M_OK :
		m_ctrlBtnMyOk2.ShowWindow(SW_SHOW);
		break;

	case M_OKCANCEL :
		m_ctrlBtnMyOk.ShowWindow(SW_SHOW);
		m_ctrlBtnMyCancel.ShowWindow(SW_SHOW);
		break;

	case M_YESNO :
		m_ctrlBtnMyYes.SetCaption(m_strYes);
		m_ctrlBtnMyYes.ShowWindow(SW_SHOW);
		m_ctrlBtnMyNo.SetCaption(m_strNo);
		m_ctrlBtnMyNo.ShowWindow(SW_SHOW);
		break;

	case M_ABORTRETRYIGNORE :
		m_ctrlBtnMyAbort.ShowWindow(SW_SHOW);
		m_ctrlBtnMyRetry.ShowWindow(SW_SHOW);
		m_ctrlBtnMyIgnore.ShowWindow(SW_SHOW);
		break;

	case M_RETRYCANCEL :
		m_ctrlBtnMyCancel3.ShowWindow(SW_SHOW);
		m_ctrlBtnMyRetry3.ShowWindow(SW_SHOW);
		break;

	case M_SYSTEMTYPESET:
		m_ctrlBtnMyAbort.SetCaption( _T("Source") );
		m_ctrlBtnMyAbort.ShowWindow(SW_SHOW);
		m_ctrlBtnMyRetry.SetCaption( _T("Gate") );
		m_ctrlBtnMyRetry.ShowWindow(SW_SHOW);
		m_ctrlBtnMyIgnore.SetCaption( _T("Source\nand Gate") );
		m_ctrlBtnMyIgnore.ShowWindow(SW_SHOW);
		break;

	case M_LANGUAGETYPESET:
		m_ctrlBtnMyAbort.SetCaption( _T("한국어") );
		m_ctrlBtnMyAbort.ShowWindow(SW_SHOW);
		m_ctrlBtnMyRetry.SetCaption( _T("English") );
		m_ctrlBtnMyRetry.ShowWindow(SW_SHOW);
		m_ctrlBtnMyIgnore.SetCaption( _T("Chinese") );
		m_ctrlBtnMyIgnore.ShowWindow(SW_SHOW);
		break;

	default :
		m_ctrlBtnMyOk2.ShowWindow(SW_SHOW);
		break;
	}

	switch(m_uiIcontype)
	{
	case M_ICONINFORMATION:  
		strTemp = m_strCurrPath + _T("\\res\\infoicon.bmp");
		m_ctrlBtnMyIcon.SetPicture(strTemp); 
		m_ctrlBtnMyIcon.SetPicturePosition(10);
		m_ctrlBtnMyIcon.SetPictureKeepRatio(FALSE);
		break;

	case M_ICONQUESTION:
		strTemp = m_strCurrPath + _T("\\res\\quesicon.bmp");
		m_ctrlBtnMyIcon.SetPicture(strTemp); 
		m_ctrlBtnMyIcon.SetPicturePosition(10);
		m_ctrlBtnMyIcon.SetPictureKeepRatio(FALSE);
		break;

	case M_ICONSTOP:
		strTemp = m_strCurrPath + _T("\\res\\stopicon.bmp");
		m_ctrlBtnMyIcon.SetPicture(strTemp); 
		m_ctrlBtnMyIcon.SetPicturePosition(10);
		m_ctrlBtnMyIcon.SetPictureKeepRatio(FALSE);
		break;

	case M_ICONERROR:
		strTemp = m_strCurrPath + _T("\\res\\erricon.bmp");
		m_ctrlBtnMyIcon.SetPicture(strTemp); 
		m_ctrlBtnMyIcon.SetPicturePosition(10);
		m_ctrlBtnMyIcon.SetPictureKeepRatio(FALSE);
		break;

	default:
		strTemp = m_strCurrPath + _T("\\res\\infoicon.bmp");
		m_ctrlBtnMyIcon.SetPicture(strTemp); 
		m_ctrlBtnMyIcon.SetPicturePosition(10);
		m_ctrlBtnMyIcon.SetPictureKeepRatio(FALSE);
		break;
	}

	m_ctrlBtnMsg.SetCaption(m_strMessage);  

	SetTimer(2, 100, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CCommonMsgDlg::PreTranslateMessage(MSG* pMsg)
{
	if( WM_KEYDOWN == pMsg->message )
	{
		if( VK_ESCAPE == pMsg->wParam )
		{
			pMsg->message = 0;
			pMsg->wParam = 0;
		}

		if( VK_DELETE == pMsg->wParam
			|| VK_RETURN == pMsg->wParam)
		{
			ClickMyok();
		}

		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CCommonMsgDlg::clearVariable()
{
	m_strCurrPath.Empty();

	m_strNo.Empty();
	m_strYes.Empty();
	m_iTextHeight	= 0;
	m_iCy			= 110;
	m_iCx			= 16;
	m_strTitle.Empty();
	m_strMessage.Empty();
	m_uiIcontype	= 0;
	m_uiType		= 0;
}

void CCommonMsgDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	// 배경색 칠하기
	CRect rectArea;
	GetClientRect(&rectArea);
	dc.FillRect(rectArea.operator LPRECT(), &m_brBckColor);

	// 항상 위 처리
	SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

void CCommonMsgDlg::OnTimer(UINT_PTR nIDEvent)
{
	//기존의 Program을 활성화 시킨다.
	CWnd* m_pWnd = this;
	m_pWnd->SetForegroundWindow(); 

	CDialog::OnTimer(nIDEvent);
}

void CCommonMsgDlg::ClickMyabort()
{
	EndDialog(IDABORT);
}

void CCommonMsgDlg::ClickMyok()
{
	EndDialog(IDOK);
}

void CCommonMsgDlg::ClickMyyes()
{
	EndDialog(IDYES);
}

void CCommonMsgDlg::ClickMyretry3()
{
	EndDialog(IDRETRY);
}

void CCommonMsgDlg::ClickMyok2()
{
	EndDialog(IDOK);
}

void CCommonMsgDlg::ClickMyretry()
{
	EndDialog(IDRETRY);
}

void CCommonMsgDlg::ClickMycancel()
{
	EndDialog(IDCANCEL);
}

void CCommonMsgDlg::ClickMycancel3()
{
	EndDialog(IDCANCEL);
}

void CCommonMsgDlg::ClickMyno()
{
	EndDialog(IDNO);
}

void CCommonMsgDlg::ClickMyignore()
{
	EndDialog(IDIGNORE);
}


