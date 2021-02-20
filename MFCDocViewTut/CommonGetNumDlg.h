#pragma once

#include "btnEnh.h"
#include "resource.h"

#include "DefUserVK.h"

// CCommonGetNumDlg 대화 상자입니다.

class CCommonGetNumDlg : public CDialog
{
	DECLARE_DYNAMIC(CCommonGetNumDlg)

public:
	CCommonGetNumDlg(int iMaxchar		= 10, 
					CString strGetnum	= _T("123"), 
					CString strTitle	= _T("Insert Number Only."),
					CWnd* pParent		= NULL,
					BOOL bPwd			= FALSE);   // 표준 생성자입니다.
	virtual ~CCommonGetNumDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_COMMON_GET_NUMBER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();

public:
	void SetWindowTitle(CString strTitle);

private:
	/**
	 * 멤버 변수를 초기화 한다,
	 */
	void clearVariable();
	void UpdateDisplay(COLORREF bkcolor = RGB(255, 255, 255));

protected:
	BOOL VerifyMaxChar();
	void InitStaticDispWnd();

public:
	DECLARE_EVENTSINK_MAP()
	void ClickBtnPlus();
	void ClickBtnMinus();
	void ClickBtnEqual();
	void ClickBtnDot();
	void ClickBtnSign();
	void ClickBtnBack();
	void ClickBtnClear();
	void ClickBtnOk();
	void ClickBtnEsc();
	void ClickBtn1();
	void ClickBtn2();
	void ClickBtn3();
	void ClickBtn4();
	void ClickBtn5();
	void ClickBtn6();
	void ClickBtn7();
	void ClickBtn8();
	void ClickBtn9();
	void ClickBtn0();


private:
	int						m_cyChar;
	int						m_cxChar;
	BOOL					m_numFlag;
	CRect					m_rect;

public:
	CString					m_strGetNum;

protected:
	int						m_nPointNum;
	BOOL					m_bCalu;
	int						m_nCalu;
	BOOL					m_FirstFlag;
	BOOL					m_bpwd;

	CString					m_strOrg;
	int						m_intMaxChar;
	CString					m_strWndText;

// 컨트롤 변수
private:
	CBtnEnh					m_ctrlBtnSetValue;
	CBtnEnh					m_ctrlBtnDispNum;
	
};
