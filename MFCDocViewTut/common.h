#pragma once

#include "CommonMsgDlg.h"
#include "CommonGetNumDlg.h"
#include "CommonGetValueDlg.h"


#include "MyMsgWnd.h"
#include "MyWnd.h"

// Button Color
const long DEF_OFF_COLOR = 0x008A8A8A;
const long DEF_ON_COLOR = 0x0095CAFF;
//
/////////////////////////////////////
//*----- For MyMessageBox --------*//

#define  M_ICONINFORMATION    0x01 
#define  M_ICONQUESTION       0x02 
#define  M_ICONSTOP           0x04 
#define  M_ICONERROR          0x08 	

#define  M_OK                 0x10
#define  M_OKCANCEL           0x20
#define  M_YESNO              0x40
#define  M_ABORTRETRYIGNORE   0x80
#define  M_RETRYCANCEL        0x100


//BOOL TactTimeSave(char* pn);

//*----- For MyMessageBox --------*//
/////////////////////////////////////

////////////////////////////////////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//*------------------------------- For Common Function --------------------------------------------*//

UINT		MyMessageBox(CString strMessage, CString strTitle, UINT type,
						CString strYesBut = _T("Yes"), CString strNoBut = _T("No"));

// 가변형 인자 처리 전까지 주석처리함 - 2013.11.26 최석원
//UINT		MyMessageBox(UINT type, CString strTitle, CString strYesBut, CString strNoBut, char* message ...);
UINT		MyMessageBox(UINT type, CString strTitle, CString strYesBut, CString strNoBut, CString strMessage);

UINT		MyMessageBox(UINT i, CString strTitle, UINT type = M_OK, 
						CString strYesBut = _T("Yes"), CString strNoBut = _T("No"));

UINT		MyMessageBox(CString strMsg, UINT i, CString strTitle, UINT type,
			CString strYesBut = _T("Yes"), CString strNoBut = _T("No"));

BOOL		GetNumberBox(CString* pstrGetNum, int iMaxchar = 10,	
						CString strDefaultNum = _T(""), CString strTitle = _T("Insert Number Only."), BOOL bPwd = FALSE);

BOOL		GetValueBox(CString* pstrVal, int iMaxchar = 10,
						CString strDefaultVal = _T(""), CString strTitle = _T("Insert Character"), BOOL bPwd = FALSE, BOOL bBtnDisable = FALSE);

int			CheckPassword(CString strPassword);
void		ChangePassword(CString strOldPassword, CString *newPassword);

int			MyAbs( int val );
double		MyAbs( double val );
BOOL		FileDeleteAll(char * pn);
BOOL		CheckDirExist(char * pn);
BOOL		CheckFileExist(char * pn);
int			FileCountInDir(char* pn);
int			DirCountInDir(char* pn);
BOOL		CopyFileDir(char* dest, char* src, int deletemode=FALSE);
//void		SetStatusText(LPCTSTR sText);
void		DisplayMessage(char* msg);
UINT		GetIOKey(BOOL sts);

BOOL		ErrorDisplay(UINT err);
BOOL		ErrorDisplay(UINT err, BOOL AutoMode);
void		ClearError();

int			get_fpoint(FILE* fp, char* s, char* sbuf);





//*------------------------------- For Common Function --------------------------------------------*//
//////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL ErrorListSave(char* pn);

BOOL STUCamDataInitial();
DWORD HexToInt(char* s);

double ConvertPointNum(double val, int cnt);
double ConvertPointNum(char* val, int cnt);
int ConvertPointNum(char* val);
void ChartoDec(char* tmp, int &rval);
void DectoBin(int tmp,char* rval);
void GetDigitalPressure(int sel, int pressure, int &rval);
void GetRealPressure(int sel, int dpressure, int &rval);

double rad2deg(double s);
double deg2rad(double s);
void Set_OP_Status(UINT op_status);
UINT Get_OP_Status();


void TempCheckSum(char* str);


BOOL DispTactTime(double dt);

CString ChoiceKorEngString(CString strText);


//_________________________________________________________________
