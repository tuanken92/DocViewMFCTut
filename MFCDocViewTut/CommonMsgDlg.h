#pragma once

#include "btnEnh.h"
#include "resource.h"

// CCommonMsgDlg 대화 상자입니다.

#define		M_SYSTEMTYPESET			0x110
#define		M_LANGUAGETYPESET		0x120

class CCommonMsgDlg : public CDialog
{
	DECLARE_DYNAMIC(CCommonMsgDlg)

public:
	CCommonMsgDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCommonMsgDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_COMMON_MSG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
	/**
	 * 멤버 변수를 초기화 한다.
	 */
	void clearVariable();

// 이벤트 처리기
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

// 버튼 클릭 함수
public:
	DECLARE_EVENTSINK_MAP()
	void ClickMyabort();
	void ClickMyok();
	void ClickMyyes();
	void ClickMyretry3();
	void ClickMyok2();
	void ClickMyretry();
	void ClickMycancel();
	void ClickMycancel3();
	void ClickMyno();
	void ClickMyignore();

private:
	/** 배경색 브러시 */
	CBrush			m_brBckColor;

	/** 현재 실행된 경로 저장 변수 */
	CString			m_strCurrPath;

public:
	CString			m_strNo;
	CString			m_strYes;
	int				m_iTextHeight;
	int				m_iCy;
	int				m_iCx;
	CString			m_strTitle;
	CString			m_strMessage;
	UINT			m_uiIcontype;
	UINT			m_uiType;

private:
	CBtnEnh			m_ctrlBtnMyAbort;
	CBtnEnh			m_ctrlBtnMyCancel;
	CBtnEnh			m_ctrlBtnMyCancel3;
	CBtnEnh			m_ctrlBtnMyIgnore;
	CBtnEnh			m_ctrlBtnMyNo;
	CBtnEnh			m_ctrlBtnMyOk;
	CBtnEnh			m_ctrlBtnMyOk2;
	CBtnEnh			m_ctrlBtnMyRetry;
	CBtnEnh			m_ctrlBtnMyRetry3;
	CBtnEnh			m_ctrlBtnMyYes;
	CBtnEnh			m_ctrlBtnMyIcon;
	CBtnEnh			m_ctrlBtnMsg;
};
