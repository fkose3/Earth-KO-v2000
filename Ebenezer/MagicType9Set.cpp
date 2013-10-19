// MagicType9Set.cpp : implementation file
//

#include "stdafx.h"
#include "ebenezer.h"
#include "MagicType9Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMagicType9Set

IMPLEMENT_DYNAMIC(CMagicType9Set, CRecordset)

CMagicType9Set::CMagicType9Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMagicType9Set)
	iNum = 0;
	bValidGroup = 0;
	bNationChange = 0;
	sMonsterNum = 0;
	bTargetChange = 0;
	bStateChange = 0;
	sRadius = 0;
	sHitRate = 0;
	sDuration = 0;
	sDamage = 0;
	sVision = 0;
	nNeedItem = 0;
	m_nFields = 12;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CMagicType9Set::GetDefaultConnect()
{
//	return _T("ODBC;DSN=KN_Online");
	return _T("ODBC;DSN=KN_Online;UID=knight;PWD=knight");
}

CString CMagicType9Set::GetDefaultSQL()
{
	return _T("[dbo].[MAGIC_TYPE9]");
}

void CMagicType9Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMagicType9Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[iNum]"), iNum);
	RFX_Byte(pFX, _T("[ValidGroup]"), bValidGroup);
	RFX_Byte(pFX, _T("[NationChange]"), bNationChange);
	RFX_Int(pFX, _T("[MonsterNum]"), sMonsterNum);
	RFX_Byte(pFX, _T("[TargetChange]"), bTargetChange);
	RFX_Byte(pFX, _T("[StateChange]"), bStateChange);
	RFX_Int(pFX, _T("[Radius]"), sRadius);
	RFX_Int(pFX, _T("[Hitrate]"), sHitRate);
	RFX_Int(pFX, _T("[Duration]"), sDuration);
	RFX_Int(pFX, _T("[AddDamage]"), sDamage);
	RFX_Int(pFX, _T("[Vision]"), sVision);
	RFX_Long(pFX, _T("[NeedItem]"), nNeedItem);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMagicType9Set diagnostics

#ifdef _DEBUG
void CMagicType9Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMagicType9Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
