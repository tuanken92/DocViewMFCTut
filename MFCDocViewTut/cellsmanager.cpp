// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "cellsmanager.h"

// Dispatch interfaces referenced by this interface
#include "TextDescriptor.h"


/////////////////////////////////////////////////////////////////////////////
// CCellsManager properties

long CCellsManager::GetScaleUnit()
{
	long result;
	GetProperty(0x1c, VT_I4, (void*)&result);
	return result;
}

void CCellsManager::SetScaleUnit(long propVal)
{
	SetProperty(0x1c, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CCellsManager operations

BOOL CCellsManager::AddCell(short nUniqueID, short nPercLeft, short nPercTop, short nPercWidth, short nPercHeight, LPCTSTR strText)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_BSTR;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, nPercLeft, nPercTop, nPercWidth, nPercHeight, strText);
	return result;
}

BOOL CCellsManager::DeleteCell(short nUniqueID)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID);
	return result;
}

short CCellsManager::GetCount()
{
	short result;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
	return result;
}

BOOL CCellsManager::FindCell(short nUniqueID)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID);
	return result;
}

BOOL CCellsManager::GetLogFont(short nUniqueID, long pLogFont)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, pLogFont);
	return result;
}

BOOL CCellsManager::SetLogFont(short nUniqueID, long pLogFont)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, pLogFont);
	return result;
}

short CCellsManager::GetCellUniqueID(short nPosition)
{
	short result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		nPosition);
	return result;
}

BOOL CCellsManager::GetCellPos(short nUniqueID, short* pPercLeft, short* pPercTop)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_PI2;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, pPercLeft, pPercTop);
	return result;
}

BOOL CCellsManager::SetCellPos(short nUniqueID, short nPercLeft, short nPercTop)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, nPercLeft, nPercTop);
	return result;
}

BOOL CCellsManager::GetCellSize(short nUniqueID, short* pPercWidth, short* pPercHeight)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_PI2 VTS_PI2;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, pPercWidth, pPercHeight);
	return result;
}

BOOL CCellsManager::SetCellSize(short nUniqueID, short nPercWidth, short nPercHeight)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, nPercWidth, nPercHeight);
	return result;
}

CString CCellsManager::GetInternalDib(short nUniqueID, short nPicture)
{
	CString result;
	static BYTE parms[] =
		VTS_I2 VTS_I2;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		nUniqueID, nPicture);
	return result;
}

BOOL CCellsManager::SetPictureFromHandle(short nUniqueID, long nPicture, long nHandle)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I4;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, nPicture, nHandle);
	return result;
}

BOOL CCellsManager::GetVisible(short nUniqueID)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetVisible(short nUniqueID, BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_BOOL;
	InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, bNewValue);
}

CString CCellsManager::GetText(short nUniqueID)
{
	CString result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetText(short nUniqueID, LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_BSTR;
	InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, lpszNewValue);
}

CTextDescriptor CCellsManager::GetTextDescriptor(short nUniqueID)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, parms,
		nUniqueID);
	return CTextDescriptor(pDispatch);
}

void CCellsManager::SetPictureNormal(short nUniqueID, LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_BSTR;
	InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, lpszNewValue);
}

long CCellsManager::GetTextHorzAlign(short nUniqueID)
{
	long result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetTextHorzAlign(short nUniqueID, long nNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, nNewValue);
}

long CCellsManager::GetTextVertAlign(short nUniqueID)
{
	long result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetTextVertAlign(short nUniqueID, long nNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, nNewValue);
}

long CCellsManager::GetPictureHorzAlign(short nUniqueID)
{
	long result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetPictureHorzAlign(short nUniqueID, long nNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, nNewValue);
}

long CCellsManager::GetPictureVertAlign(short nUniqueID)
{
	long result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetPictureVertAlign(short nUniqueID, long nNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, nNewValue);
}

unsigned long CCellsManager::GetBackColor(short nUniqueID)
{
	unsigned long result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetBackColor(short nUniqueID, unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, newValue);
}

unsigned long CCellsManager::GetBorderColor(short nUniqueID)
{
	unsigned long result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetBorderColor(short nUniqueID, unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, newValue);
}

short CCellsManager::GetBorderWidth(short nUniqueID)
{
	short result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetBorderWidth(short nUniqueID, short nNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I2;
	InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, nNewValue);
}

void CCellsManager::SetPictureDisabled(short nUniqueID, LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_BSTR;
	InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, lpszNewValue);
}

short CCellsManager::GetPictureTranspFactor(short nUniqueID)
{
	short result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetPictureTranspFactor(short nUniqueID, short nNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I2;
	InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, nNewValue);
}

short CCellsManager::GetBackTranspFactor(short nUniqueID)
{
	short result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, parms,
		nUniqueID);
	return result;
}

void CCellsManager::SetBackTranspFactor(short nUniqueID, short nNewValue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I2;
	InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nUniqueID, nNewValue);
}

BOOL CCellsManager::CellAdd(short nUniqueID, float fPosLeft, float fPosTop, float fWidth, float fHeight, LPCTSTR strText)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_BSTR;
	InvokeHelper(0x1d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, fPosLeft, fPosTop, fWidth, fHeight, strText);
	return result;
}

BOOL CCellsManager::CellDelete(short nUniqueID)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x1e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID);
	return result;
}

short CCellsManager::CellGetCount()
{
	short result;
	InvokeHelper(0x1f, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
	return result;
}

BOOL CCellsManager::CellFind(short nUniqueID)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x20, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID);
	return result;
}

BOOL CCellsManager::CellGetLogFont(short nUniqueID, long pLogFont)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x21, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, pLogFont);
	return result;
}

BOOL CCellsManager::CellSetLogFont(short nUniqueID, long pLogFont)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I4;
	InvokeHelper(0x22, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, pLogFont);
	return result;
}

short CCellsManager::CellGetUniqueID(short nPosition)
{
	short result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x23, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		nPosition);
	return result;
}

BOOL CCellsManager::CellGetPos(short nUniqueID, float* pPosLeft, float* pPosTop)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_PR4;
	InvokeHelper(0x24, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, pPosLeft, pPosTop);
	return result;
}

BOOL CCellsManager::CellSetPos(short nUniqueID, float nPosLeft, float nPosTop)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_R4 VTS_R4;
	InvokeHelper(0x25, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, nPosLeft, nPosTop);
	return result;
}

BOOL CCellsManager::CellGetSize(short nUniqueID, float* pWidth, float* pHeight)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_PR4 VTS_PR4;
	InvokeHelper(0x26, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, pWidth, pHeight);
	return result;
}

BOOL CCellsManager::CellSetSize(short nUniqueID, float nWidth, float nHeight)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_R4 VTS_R4;
	InvokeHelper(0x27, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, nWidth, nHeight);
	return result;
}

BOOL CCellsManager::CellSetPictureFromHandle(short nUniqueID, long nPicture, long nHandle)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I2 VTS_I4 VTS_I4;
	InvokeHelper(0x28, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		nUniqueID, nPicture, nHandle);
	return result;
}
