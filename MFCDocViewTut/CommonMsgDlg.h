#pragma once

#include "btnEnh.h"
#include "resource.h"

// CCommonMsgDlg ��ȭ �����Դϴ�.

#define		M_SYSTEMTYPESET			0x110
#define		M_LANGUAGETYPESET		0x120

class CCommonMsgDlg : public CDialog
{
	DECLARE_DYNAMIC(CCommonMsgDlg)

public:
	CCommonMsgDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCommonMsgDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_COMMON_MSG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
	/**
	 * ��� ������ �ʱ�ȭ �Ѵ�.
	 */
	void clearVariable();

// �̺�Ʈ ó����
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

// ��ư Ŭ�� �Լ�
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
	/** ���� �귯�� */
	CBrush			m_brBckColor;

	/** ���� ����� ��� ���� ���� */
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
