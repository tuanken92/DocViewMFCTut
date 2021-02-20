#include "stdafx.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "Common.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif
 
TCHAR ErrorDataFileName[100];
TCHAR MinPassWord[50];

//___________________________________________________________________

UINT MyMessageBox(CString strMessage, CString strTitle, UINT type, CString strYesBut/*="Yes"*/, CString strNoBut/*="No"*/)
{
	CCommonMsgDlg dlg;
	
	if( type & M_ICONINFORMATION ) dlg.m_uiIcontype = M_ICONINFORMATION;
	else if( type & M_ICONQUESTION ) dlg.m_uiIcontype = M_ICONQUESTION;
	else if( type & M_ICONSTOP ) dlg.m_uiIcontype = M_ICONSTOP;
	else if( type & M_ICONERROR ) dlg.m_uiIcontype = M_ICONERROR;
	else dlg.m_uiIcontype = M_ICONINFORMATION;
	
	if( type & M_OK ) dlg.m_uiType = M_OK;
	else if( type & M_OKCANCEL ) dlg.m_uiType = M_OKCANCEL;
	else if( type & M_YESNO ) dlg.m_uiType = M_YESNO;
	else if( type & M_ABORTRETRYIGNORE ) dlg.m_uiType = M_ABORTRETRYIGNORE;
	else if( type & M_RETRYCANCEL ) dlg.m_uiType = M_RETRYCANCEL;
	else dlg.m_uiType = M_OK;
	
	dlg.m_strMessage = strMessage;
	dlg.m_strTitle = strTitle;
	dlg.m_strYes = strYesBut;
	dlg.m_strNo = strNoBut;

   return (UINT(dlg.DoModal()));
}

#if 0	// 가변형 인자 처리 전까지 주석처리함 - 2013.11.26 최석원
UINT MyMessageBox(UINT type, char* title,  char* YesBut, char* NoBut, char* message ...)
{
	CCommonMsgDlg dlg;
	int iRtn = 0;

	if( type & M_ICONINFORMATION ) dlg.m_uiIcontype = M_ICONINFORMATION;
	else if( type & M_ICONQUESTION ) dlg.m_uiIcontype = M_ICONQUESTION;
	else if( type & M_ICONSTOP ) dlg.m_uiIcontype = M_ICONSTOP;
	else if( type & M_ICONERROR ) dlg.m_uiIcontype = M_ICONERROR;
	else dlg.m_uiIcontype = M_ICONINFORMATION;

	if( type & M_OK ) dlg.m_uiType = M_OK;
	else if( type & M_OKCANCEL ) dlg.m_uiType = M_OKCANCEL;
	else if( type & M_YESNO ) dlg.m_uiType = M_YESNO;
	else if( type & M_ABORTRETRYIGNORE ) dlg.m_uiType = M_ABORTRETRYIGNORE;
	else if( type & M_RETRYCANCEL ) dlg.m_uiType = M_RETRYCANCEL;
	else dlg.m_uiType = M_OK;

	va_list args;
	char	cmessage[_MAX_PATH];

	va_start(args, message);
	_vstprintf(cmessage, message, args);
	va_end(args);

	dlg.m_strMessage = cmessage;
	dlg.m_strTitle = title;
	dlg.m_strYes = YesBut;
	dlg.m_strNo = NoBut;

	return (dlg.DoModal());

/*
	if (AfxGetMainWnd() != NULL)
	{
		HWND m_hWnd = AfxGetMainWnd()->m_hWnd;

		::SendMessage(m_hWnd, WM_MSGBOX_MSG, (WPARAM)&iRtn, (LPARAM)&dlg);

		while (TRUE)
		{
			if (iRtn != 0)
				break;
		}

		return iRtn;
	}
	else
	{
		return (dlg.DoModal());
	}
*/
}
#endif

UINT MyMessageBox(UINT type, CString strTitle, CString strYesBut, CString strNoBut, CString strMessage)
{
	CCommonMsgDlg dlg;

	if (type & M_ICONINFORMATION) dlg.m_uiIcontype = M_ICONINFORMATION;
	else if (type & M_ICONQUESTION) dlg.m_uiIcontype = M_ICONQUESTION;
	else if (type & M_ICONSTOP) dlg.m_uiIcontype = M_ICONSTOP;
	else if (type & M_ICONERROR) dlg.m_uiIcontype = M_ICONERROR;
	else dlg.m_uiIcontype = M_ICONINFORMATION;

	if (type & M_OK) dlg.m_uiType = M_OK;
	else if (type & M_OKCANCEL) dlg.m_uiType = M_OKCANCEL;
	else if (type & M_YESNO) dlg.m_uiType = M_YESNO;
	else if (type & M_ABORTRETRYIGNORE) dlg.m_uiType = M_ABORTRETRYIGNORE;
	else if (type & M_RETRYCANCEL) dlg.m_uiType = M_RETRYCANCEL;
	else dlg.m_uiType = M_OK;

	dlg.m_strMessage = strMessage;
	dlg.m_strTitle = strTitle;
	dlg.m_strYes = strYesBut;
	dlg.m_strNo = strNoBut;

	return (UINT(dlg.DoModal()));
}

UINT MyMessageBox(UINT i, CString strTitle, UINT type /*= M_OK*/, CString strYesBut /*= _T("Yes")*/, CString strNoBut /*= _T("No")*/)
{
	CString strTmp, strTmp2;
	CString strMessage;

	TCHAR language_select[50];
	TCHAR cTmp[200], cTmp2[200];
	
	strTmp.Format(_T("%ld"), i); //한글출력
	UINT uiTmp = GetPrivateProfileString(_T("MESSAGE"), strTmp, _T("error"), cTmp, 200, _T(".\\Data\\DisMessage.dat"));

	strTmp2.Format(_T("%ld"), i + 40000); //영문출력
	uiTmp = GetPrivateProfileString(_T("MESSAGE"), strTmp2, _T("error"), cTmp2, 200, _T(".\\Data\\DisMessage.dat"));

	uiTmp = GetPrivateProfileString(_T("LANGUAGE"), _T("100"), _T("language"), language_select, 200, _T(".\\Data\\DisMessage.dat"));
	if (_tstoi(language_select) == 1)			strMessage.Format(_T("%s"), cTmp);
	else if (_tstoi(language_select) == 2)		strMessage.Format(_T("%s"), cTmp2);
	else if (_tstoi(language_select) == 3)		strMessage.Format(_T("%s\n\n%s"), cTmp2, cTmp);
	else										strMessage.Format(_T("%s"), _T("Language Select Error!!!"));

	return(MyMessageBox(strMessage, strTitle, type, strYesBut, strNoBut));
}

UINT MyMessageBox(CString strMsg, UINT i, CString strTitle, UINT type, CString strYesBut /*= "Yes"*/, CString strNoBut /*= "No"*/)
{
	CString strTmp,aaa;
	CString strMessage;
	TCHAR cTmp[200];

	strTmp.Format(_T("%ld"), i); //한글출력
	
	UINT uiTmp = GetPrivateProfileString(_T("MESSAGE"), strTmp, _T("error"), cTmp, 200, _T(".\\Data\\DisMessage.dat"));
	UNUSED_ALWAYS(uiTmp);
	
	strMessage = strMsg;

	return(MyMessageBox(strMessage, strTitle, type, strYesBut, strNoBut));
}

BOOL GetNumberBox(CString* pstrGetNum, int iMaxchar /*= 10*/, CString strDefaultNum /*= _T("")*/, CString strTitle /*= _T("Insert Number Only.")*/, BOOL bPwd /*= FALSE*/)
{
	CCommonGetNumDlg dlg(iMaxchar, strDefaultNum, strTitle, NULL, bPwd);
	if (dlg.DoModal() == IDOK)
	{
		*pstrGetNum = dlg.m_strGetNum;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL GetValueBox(CString* pstrVal, int iMaxchar /*= 10*/, CString strDefaultVal /*= _T("")*/, CString strTitle /*= _T("Insert Character")*/, BOOL bPwd /*= FALSE*/, BOOL bBtnDisable /*= FALSE*/)
{
	CCommonGetValueDlg dlg(iMaxchar, strDefaultVal, strTitle, NULL, bPwd, bBtnDisable);

	if (dlg.DoModal() == IDOK)
	{
		*pstrVal = dlg.m_strGetVal;
		return TRUE;
	}

	else
	{
		return FALSE;
	}
}

int CheckPassword(CString strPassword)
{
	CString strBuf;

	if (!GetValueBox(&strBuf, 10, _T(""), _T("Input Password. (Max 10)"), TRUE))
		return 2;

	if (strPassword == strBuf)
		return FALSE;
	else
		return 1;
}

void ChangePassword(CString strOldPassword, CString *newPassword)
{
	CString strBuf;
	CString strBuf_1;

	if (!GetValueBox(&strBuf, 10, _T(""), _T("Input Old Password. (Max 10))"), TRUE)) return;

	if (strOldPassword != strBuf)
	{
		MyMessageBox(17200, _T("Password Input Error"), M_ICONERROR);
		//17200=이전 암호가 틀렸습니다. 다시 생각 해보세요.
		return;
	}

	if (!GetValueBox(&strBuf, 10, _T(""), _T("Input New Password. (Max 10)"), TRUE)) return;
	if (!GetValueBox(&strBuf_1, 10, _T(""), _T("Input Agian New Password. (Max 10)"), TRUE)) return;

	if (strBuf != strBuf_1)
	{
		MyMessageBox(17201, _T("Password Changeing Confirm Error"), M_ICONERROR);
		//17201=두번 입력한 암호가 서로 틀립니다. 다시 시도해 보세요.
		return;
	}

	*newPassword = strBuf;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0

double rad2deg(double s)
{
	return (s*180.0 / 3.1415926535);
}

double deg2rad(double s)
{
	return (s*3.1415926535 / 180.0);
}


DWORD HexToInt(char* s)
{
	char hexch[] = _T("0123456789ABCDEF");
	int i,j;
   DWORD r,n,k;
   char ch;

  	k=1; r=0;
  	for(i=strlen(s);  i>0; i--) 
	{
   	ch = s[i-1]; if (ch > 0x3f) ch &= 0xDF;
   	n = 0;
    	for(j = 0; j<16; j++)
		{
      	if (ch == hexch[j])
         	n = j;
		}
    	r += (n*k);
     	k *= 16;
	}
  	return r;
}

/*
void SetStatusText(LPCTSTR sText)
{
	CStatusBar* pStatusBar = NULL;

   CWnd *pMainWnd = AfxGetMainWnd();

   if(!pMainWnd) return;

   pStatusBar = (CStatusBar*)pMainWnd->GetDescendantWindow(AFX_IDW_STATUS_BAR);
    
   // - OR -
   // if (!pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
   // pStatusBar = (CStatusBar*) ((CFrameWnd*) pFrame)->GetMessageBar();

   if(!pStatusBar || !pStatusBar->IsKindOf(RUNTIME_CLASS(CStatusBar))) return;

   pStatusBar->SetWindowText(sText);
}
*/
BOOL DisplayErrorDialog = FALSE;

BOOL ErrorDisplay(UINT err)
{
	CString strErrNo,strTmp;
	char cTmp[500], cTmp2[200], MessageBuf[200];
	
	FILE* fp;
	
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format( _T("%m/%d-%H:%M:%S") );

	if(DisplayErrorDialog)
	{
		MyMessageBox(17203, _T("Error Display Error"), M_ICONERROR);
					//17203=이미 Error Dialog Box가 실행중입니다.
		return FALSE;
	}

	DisplayErrorDialog = TRUE;

	if( (err < 1) || (err > 49999) )
	{
		MyMessageBox(17204, _T("Error"), M_ICONERROR);
					//17204=Error Number는 10000 ~ 49999사이에 있어야 합니다.
		DisplayErrorDialog = FALSE;
		return FALSE;
	}
	strErrNo.Format(_T("%d"),err);

	//////////////////////////////////////////////
	if((fp = fopen(ErrorDataFileName, _T("rt"))) == NULL)
	{
		MyMessageBox(17205, _T("Error"), M_ICONERROR);
					//17205=Error File을 Open할 수가 없습니다.
		DisplayErrorDialog = FALSE;
		return FALSE;
	}
	else fclose(fp);

	strTmp.Format(_T("%ld"), err); //한글출력
	char language_select[50];
	UINT uiTmp = GetPrivateProfileString(_T("PCBERROR"), strTmp, _T("Cannot find the Error Number in the Error File."), cTmp, 200, _T(".\\Data\\Error.dat"));
	//strTmp.Format("%s", cTmp);
	strTmp.Format("%ld",err+40000); //영문출력
	uiTmp = GetPrivateProfileString(_T("PCBERROR"), strTmp, _T("Cannot find the Error Number in the Error File."), cTmp2, 200, _T(".\\Data\\Error.dat")_T();

	//ckh1024
	uiTmp = GetPrivateProfileString_T(("LANGUAGE"), _T("100"), _T("language"), language_select, 200, _T(".\\Data\\Error.dat"));
	if( atoi(language_select) == 1) sprintf(MessageBuf, _T("%s"),cTmp);
	else if( atoi(language_select) == 2) sprintf(MessageBuf, _T("%s"),cTmp2);
	else if( atoi(language_select) == 3) sprintf(MessageBuf, _T("%s\n%s"),cTmp2, cTmp);
	else sprintf(MessageBuf, _T("language Select Error!!!"));
	//ckh1024

//	if(Pcb_OpManager.GetOpMode() == AUTORUN_MODE)
//	{
//		P_M.Error(err);
//		Sleep(300);
//	}

	MyMessageBox(MessageBuf, _T("Error"), M_ICONERROR);
	Sleep(200);
	
	//ckh1024
//	char * ErrSav = strtok(MessageBuf,"\n");
	
	/////////////////////////
//	if(Pcb_OpManager.GetOpMode() == AUTORUN_MODE)
//	{
//		P_M.ErrorReset();
//	}

	DisplayErrorDialog = FALSE;

	sprintf(cTmp,"%s,%s,%s",strErrNo,MessageBuf,strTime);
	//CString ErrorSave;
	//ErrorSave.Format("%s",cTmp);
	//ErrorSave = ErrorSave+","+strTime;

//	if(Pcb_OpManager.GetOpMode() == AUTORUN_MODE)
//	{
//		if(!ErrorListSave(cTmp))
//			return FALSE;
//	}
	return TRUE;
}                                                                                                                                                                                                                                                                                                                      

BOOL ErrorDisplay(UINT err, BOOL AutoMode)
{
	UINT key = 0;
	FILE* fp;
	char tmp[20];
	BOOL buzzerflag = FALSE;
	
	CTime t = CTime::GetCurrentTime();
	CString s = t.Format( _T(", %y/%m/%d-%H:%M") );

	if( DisplayErrorDialog )
	{
		MyMessageBox(17203, _T("Error Display Error"), M_ICONERROR);
					//17203=이미 Error Dialog Box가 실행중입니다.
		return FALSE;
	}

	if( (err < 1) || (err > 9999999) )
	{
		MyMessageBox(17204, _T("Error"), M_ICONERROR);
					//17204=Error Number는 10000 ~ 49999사이에 있어야 합니다.
		return FALSE;
	}

	if((fp = fopen(ErrorDataFileName, _T("rt"))) == NULL)
	{
		MyMessageBox(17205, _T("Error"),M_ICONERROR);
					//17205=Error File을 Open할 수가 없습니다.
		return FALSE;
	}

	_itoa(err, tmp, 10);

	char Error[100];
	s = tmp + s;

	if(strlen(s) > 100){
		fclose(fp);
		return FALSE;
	}
	strcpy(Error, s);

	strcat(tmp, _T(":"));
	char buf[500];

	if( !get_fpoint(fp,tmp,buf))
	{
		_itoa(99999, tmp, 10);
		strcat(tmp, _T(":"));
		if( !get_fpoint(fp,tmp,buf))
		{
			fclose(fp);
			sprintf(buf, _T("Cannot find the Error Number in the Error File. : (%d) I am sorry, but can you call Mechatronics Center with Memo of this Number and Step!!!"), err);
			sprintf(buf, _T("%d"), err);
			MyMessageBox(buf, 17207, _T("Error"), M_ICONERROR|M_OK);
						//17207=Error File에서 Error 번호를 찾을수가 없습니다. : (%d) 죄송하지만 이번호와 Step을 Memo해서 생기센타로 연락해 주세요 !!!
			return FALSE;
		}
	}
	fclose(fp);
	 
	DisplayErrorDialog = TRUE;

	_itoa(err, tmp, 10);

	CString emsg = buf;
	CString stmp = tmp;
	CString orgmsg;

	stmp += _T(":");

	emsg.TrimLeft(stmp);
	emsg.TrimLeft();

	stmp.Empty();
	orgmsg.Empty();

	int rel,i;
	while(1)
	{
		rel = emsg.Find("^");
		if( rel == -1 )
		{
			orgmsg += emsg;
			break;
		}

		stmp = emsg.Left(rel);
		stmp += _T("\r\n");
		orgmsg += stmp;
		stmp.Empty();

		for(i=0;i<rel+1;i++)
		{
			emsg.SetAt(i,' ');
		}
		emsg.TrimLeft();
	}

	char ebuf[100];
	memset(&ebuf, 0, sizeof(ebuf));

//	if( err == 18071 ) // temp winpcb
//	{
//		orgmsg += _T("\r\n");
//		sprintf(ebuf, _T("( 기준값 : %d, 측정값 : %d )"), PCBRightBlob, PCBRightBlobArea);
//		orgmsg += ebuf;
//	}
	
//	if( err == 18072 )
//	{
//		orgmsg += _T("\r\n");
//		sprintf(ebuf, _T("( 기준값 : %d, 측정값 : %d )"), PCBLeftBlob, PCBLeftBlobArea);
//		orgmsg += ebuf;
//	}

	if(AutoMode == TRUE)
	{
//		ErrorListSave(Error);
	}

//	CErrorDlg* errdlg = new CErrorDlg;

//	errdlg->SetTextMsg(tmp, orgmsg);
//	errdlg->CenterWindow();
//	errdlg->ShowWindow(SW_SHOW);
//	errdlg->PeekAndPump();

/*	ResetLamp(IO_ON); // temp Winpcb

#ifdef _LINE_CONTROLLER
	switch( err )
	{
		case 16050 :
		case 16051 :
			break;

		default : 
			P_M.Error(err);
			break;
	}
#endif

	buzzerflag = FALSE;
	while(1)
	{
		errdlg->PeekAndPump();
		if(errdlg->m_Cancel) 
		{	
			delete errdlg;
			break;
		}

		if( !buzzerflag )
		{
			if( errdlg->m_BuzzerOffFlag )
			{
				BuzzerOnOff(IO_OFF);
				buzzerflag = TRUE;
			}
		}

		key = GetOldIOKey();
		if( (key == IO_RESET_KEY) ||
			 (key == IO_STOP_KEY) ||
			 (key == IO_ESTOP_KEY) )
		{
			delete errdlg;
			break;
		}
	}

	while(1)
	{
		if( !GetOldIOKey() ) break;
	}

	ResetLamp(IO_OFF);
	TowerLamp(T_YELLOW);
	BuzzerOnOff(IO_OFF);
*/
	DisplayErrorDialog = FALSE;

//#ifdef _LINE_CONTROLLER
//	P_M.SetFlag(PM_ERROR_CLEAR);
//#endif

	return TRUE;
}

//////////////////////////////////////////////////////////////
// Error List File 저장
BOOL ErrorListSave(char* pn)
{
	FILE* fsource, *ftarget;
	CFileFind fn;
	char fname[100] = _T(".\\data\\ErrorList.dat");
	char fname1[100] = _T(".\\data\\ErrorList.bak");


	if(fn.FindFile(fname,0))
	{
		if(!CopyFile(fname, fname1, FALSE))
		{
			MyMessageBox(17208, _T("Data\\ErrorList.bak File Write Error!"), M_ICONERROR);
						//17208=Error List Backup File을 만들수가 없습니다. Data\\ErrorList.bak을 점검하시오.
			return FALSE;
		}
		if(!DeleteFile(fname))
		{
			MyMessageBox(17209, _T("Data\\ErrorList.dat을 File Delete Error!"), M_ICONERROR);
						//17209=Error List  File을 지울수가 없습니다. Data\\ErrorList.dat을 점검하시오.
			return FALSE;
		}
	}
	if((fsource = fopen(_T(".\\data\\ErrorList.dat"), _T("w+"))) == NULL)
	{
		MyMessageBox(17210, _T("Data\\ErrorList.Dat File Write Error!"), M_ICONERROR);
					//17210=Error List File을 만들수가 없습니다. Data\\ErrorList.dat를 확인하시오.
		return FALSE;
	}
	fprintf(fsource, _T("%s\n"), pn);

	if(!fn.FindFile(fname1,0))
	{
		fclose(fsource);
		return TRUE;
	}
	else if((ftarget = fopen(_T(".\\data\\ErrorList.bak"), _T("r"))) == NULL)
	{
		MyMessageBox(17211, _T("Data\\ErrorList.bak File Read Error!"), M_ICONERROR);
					//17211=Error List File을 읽을수가 없습니다. Data\\ErrorList.bak를 확인하시오.
		// Resource Leak
		fclose(fsource);
		return FALSE;
	}

	char buf[200];
	int count=0;

	fgets( buf,200,ftarget );
	while(!feof(ftarget))
	{
		if(count > 200) break; //cyj 2003.11.26 100->200
		fputs(buf,fsource);
		fgets( buf,100,ftarget );
		count += 1;
	}

	fclose(fsource);
	fclose(ftarget);

	return TRUE;
}



int get_fpoint(FILE* fp, char* s, char* sbuf)
{
	char buf[500];
	int len,rel;
	CString strBuf;

	while(1)
	{
		if( feof( fp ) ) return FALSE;
		fgets( buf,500,fp );
		strBuf = buf;
		rel = strBuf.Find(s);
		if( strBuf.Find(s) >= 0 ) break;
	}

	len = strlen(buf);
	strncpy(sbuf,buf,len);
	sbuf[len-1] = '\0';

	return TRUE;
}

int MyAbs( int val )
{
	int tmpval;

	tmpval = val;

	if( tmpval < 0 ) tmpval *= -1;

	return tmpval;
}

double MyAbs( double val )
{
	double tmpval;

	tmpval = val;

	if( tmpval < 0.0 ) tmpval *= -1.0;

	return tmpval;
}

BOOL FileDeleteAll(char * pn)
{
	char buf[100];
	CFileFind fn;
	int nextfile, i;
	int filecnt=0;

	sprintf(buf,"%s\\*.*", pn);
	
	filecnt = FileCountInDir(buf);

	if( !filecnt ) return TRUE;

	CString* filename = new CString[filecnt+1];

	filecnt = 0;
	if( !fn.FindFile(buf,0) )
	{
		delete[] filename;
		return FALSE;
	}

	nextfile = fn.FindNextFile();
	while(1)
	{
		if( !fn.IsDirectory() )
		{
			filename[filecnt] = fn.GetFileName();
			filecnt++;
		}

		if( !nextfile) break;
		nextfile = fn.FindNextFile();
	}


	CMyProgressWnd ProgWnd(NULL, _T("Call the Model....."));
	ProgWnd.SetRange(0,filecnt);
	ProgWnd.SetText(_T("...is delete a File...\n")
						  _T("Wait a moment..."));

	for(i=0;i<filecnt;i++)
	{
		sprintf(buf, _T("%s\\%s"), pn, (LPCTSTR)filename[i]);
		CFile::Remove(buf);

		ProgWnd.StepIt();
		ProgWnd.PeekAndPump();
	}

	delete[] filename;
	return TRUE;
}

BOOL CheckDirExist(char * pn)
{
	CFileFind fn;
	char buf[100];
	int nextfile;

	sprintf(buf, _T("%s\\*.*"), pn);

	if( !fn.FindFile(buf,0) )
	{
		MyMessageBox(17212, _T("Error"), M_ICONERROR);
					//17212=File Searching Error
		return FALSE;
	}

	nextfile = fn.FindNextFile();

	while(1)
	{
		if( fn.IsDirectory() ) 
			if( !fn.IsDots() ) return FALSE;
		if(!nextfile) break;
		nextfile = fn.FindNextFile();
	}
	return TRUE;
}

BOOL CheckFileExist(char * pn)
{
	CFileFind fn;

	if( !fn.FindFile(pn,0) ) return FALSE;
	else return TRUE;
}

int FileCountInDir(char* pn)
{
	CFileFind ff;
	int cnt=0, nt;

	if( !ff.FindFile(pn,0) ) return FALSE;

	nt = ff.FindNextFile();
	while(1)
	{
		if( !ff.IsDirectory() ) cnt++;
		if( !nt ) break;
		nt = ff.FindNextFile();
	}

	return cnt;
}

BOOL CopyFileDir(char* dest, char* src, int deletemode/*=FALSE*/)
{
	int cnt=0, nt, i;
	char buf[100];

	CFileFind ff;

	sprintf(buf,"%s\\*.*",src);
	cnt = FileCountInDir(buf);

	if( !cnt )
	{
		MyMessageBox(17213,"Confirm",M_ICONSTOP);
					//17213=Directory에 File이 없습니다.
		return FALSE;
	}

	if( deletemode ) FileDeleteAll(dest);

	CString* filename = new CString[cnt+1];

	cnt=0;
	if( !ff.FindFile(buf,0) )
	{
		delete[] filename;
		return FALSE;
	}

	nt = ff.FindNextFile();
	while(1)
	{
		if( !ff.IsDirectory() )
		{
			filename[cnt] = ff.GetFileName();
			cnt++;
		}
		if( !nt ) break;
		nt = ff.FindNextFile();
	}

	CMyProgressWnd ProgWnd(NULL, _T("Model Copy....."));
	ProgWnd.SetRange(0,cnt);
	ProgWnd.SetText(_T("...is copying a File...\n")
					 _T("Wait a moment..."));

	char destfile[100];
	char srcfile[100];

	for(i=0; i<cnt; i++)
	{
		sprintf(srcfile, _T("%s\\%s"), src, filename[i]);
		sprintf(destfile, _T("%s\\%s"), dest, filename[i]);
		if( !CopyFile(srcfile, destfile, FALSE) )
		{
			delete[] filename;
			MyMessageBox(17214, _T("Error"), M_ICONERROR);
						//17214=File Copy중 Error가 발생하였습니다.
			return FALSE;
		}
		ProgWnd.StepIt();
		ProgWnd.PeekAndPump();
	}

	delete[] filename;
	return TRUE;
}

int DirCountInDir(char* pn)
{
	CFileFind ff;
	int cnt=0, nt;

	if( !ff.FindFile(pn,0) ) return FALSE;

	nt = ff.FindNextFile();
	while(1)
	{
		if( ff.IsDirectory() ) 
		{
			if( !ff.IsDots() ) cnt++;
		}
		if( !nt ) break;
		nt = ff.FindNextFile();
	}

	return cnt;
}

void DisplayMessage(char* msg)
{
   CMyMsgWnd* mwnd = new CMyMsgWnd();
   mwnd->SetMessage(msg);
   while(1)
   {
//      mwnd->SetFocus();
      mwnd->PeekAndPump();
      if(mwnd->m_CancelFlag) break;
// 		if( GetOldIOKey() == IO_RESET_KEY ) break; //temp winpcb
   }

//	mwnd->DestroyWindow();
	delete mwnd;
}


CString ChoiceKorEngString(CString strText)
{
//	strText.Format("%s",Text);
	//////////////////////....... 한/영 전환 ........///////////////
	int no = strText.Find('$',0);
	int length = strText.GetLength();
	if(no != -1)
	{
//		if(g_bEnglishDisplay) 	strText = strText.Left(no);
//		else 	strText = strText.Mid(no+1,length-no);
	}
	return strText;
}

#endif