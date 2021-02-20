#pragma once

#include "btnEnh.h"
#include "resource.h"

#include "DefUserVK.h"

// CCommonGetValueDlg 대화 상자입니다.

class CCommonGetValueDlg : public CDialog
{
	DECLARE_DYNAMIC(CCommonGetValueDlg)

public:
	CCommonGetValueDlg(int iMaxchar			= 10, 
						CString strGetnum	= _T(""), 
						CString strTitle	= _T("Input the Value."),
						CWnd* pParent		= NULL,
						BOOL bPwd			= FALSE, 
						BOOL bBtnDisable	= FALSE);   // 표준 생성자입니다.
	virtual ~CCommonGetValueDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_COMMON_GET_VALUE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

public:
	DECLARE_EVENTSINK_MAP()
	void ClickKeyOk();
	void ClickKeyEsc();
	void ClickKeyBack();
	void ClickKeyClear();
	void ClickKey1();
	void ClickKey2();
	void ClickKey3();
	void ClickKey4();
	void ClickKey5();
	void ClickKey6();
	void ClickKey7();
	void ClickKey8();
	void ClickKey9();
	void ClickKey0();
	void ClickKeyQ();
	void ClickKeyW();
	void ClickKeyE();
	void ClickKeyR();
	void ClickKeyT();
	void ClickKeyY();
	void ClickKeyU();
	void ClickKeyI();
	void ClickKeyO();
	void ClickKeyP();
	void ClickKeyA();
	void ClickKeyS();
	void ClickKeyD();
	void ClickKeyF();
	void ClickKeyG();
	void ClickKeyH();
	void ClickKeyJ();
	void ClickKeyK();
	void ClickKeyL();
	void ClickKeyZ();
	void ClickKeyX();
	void ClickKeyC();
	void ClickKeyV();
	void ClickKeyB();
	void ClickKeyN();
	void ClickKeyM();
	void ClickKeyEqual();
	void ClickKeyWon();
	void ClickKeyColon();
	void ClickKeyDot();
	void ClickKeyDash();
	void ClickKeyUnderBar();	

private:
	/** 
	 * 멤버 변수를 초기화 한다.
	 */
	void clearVariable();

	void btnDisable();

	BOOL VerifyMaxChar();

	void UpdateDisplay(COLORREF bkcolor = RGB(255, 255, 255));

public:
	void InitStaticDispWnd();
	
	CString GetStringValue();

private:
	CBtnEnh			m_sDispValue;
	CBtnEnh			m_bDot;
	CBtnEnh			m_bEqual;
	CBtnEnh			m_bColon;
	CBtnEnh			m_bWon;

public:
	CString			m_strGetVal;

private:
	BOOL			m_bpwd;
	BOOL			m_bbtndisable;
	int				m_intMaxChar;

	CString			m_strWndText;

	int				m_cxChar;
	int				m_cyChar;
	CRect			m_rect;
};
