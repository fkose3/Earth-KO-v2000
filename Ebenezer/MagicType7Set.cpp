// MagicType7Set.cpp : implementation file
//

#include "stdafx.h"
#include "ebenezer.h"
#include "MagicType7Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMagicType7Set

IMPLEMENT_DYNAMIC(CMagicType7Set, CRecordset)

CMagicType7Set::CMagicType7Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMagicType7Set)
	iNum = 0;
	bValidGroup = 0;
	bNationChange = 0;
	sMonsterNum = 0;
	bTargetChange = 0;
	bStateChange = 0;
	bRadius = 0;
	sHitRate = 0;
	sDuration = 0;
	sDamage = 0;
	bVision = 0;
	nNeedItem = 0;
	m_nFields = 12;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CMagicType7Set::GetDefaultConnect()
{
//	return _T("ODBC;DSN=KN_Online");
	return _T("ODBC;DSN=KN_Online;UID=knight;PWD=knight");
}

CString CMagicType7Set::GetDefaultSQL()
{
	return _T("[dbo].[MAGIC_TYPE7]");
}

void CMagicType7Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMagicType7Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[nIndex]"),iNum);
	RFX_Byte(pFX, _T("[byValidGroup]"),bValidGroup);
	RFX_Byte(pFX, _T("[byNatoinChange]"),bNationChange);
	RFX_Int(pFX, _T("[shMonsterNum]"),sMonsterNum);
	RFX_Byte(pFX, _T("[byTargetChange]"),bTargetChange);
	RFX_Byte(pFX, _T("[byStateChange]"),bStateChange);
	RFX_Byte(pFX, _T("[byRadius]"),bRadius);
	RFX_Int(pFX, _T("[shHitRate]"),sHitRate);
	RFX_Int(pFX, _T("[shDuration]"),sDuration);
	RFX_Int(pFX, _T("[shDamage]"),sDamage);
	RFX_Byte(pFX, _T("[byVisoin]"),bVision);
	RFX_Long(pFX, _T("[nNeedItem]"),nNeedItem);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMagicType7Set diagnostics

#ifdef _DEBUG
void CMagicType7Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMagicType7Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
