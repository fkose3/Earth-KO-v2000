// MagicTableSet.cpp : implementation file
//

#include "stdafx.h"
#include "ebenezer.h"
#include "MagicTableSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMagicTableSet

IMPLEMENT_DYNAMIC(CMagicTableSet, CRecordset)

CMagicTableSet::CMagicTableSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMagicTableSet)
	iNum = 0;
	nBeforeAction = 0;
	bTargetAction = 0;
	bSelfEffect = 0;
	bFlyingEffect = 0;
	iTargetEffect = 0;
	bMoral = 0;
	sSkillLevel = 0;	
	sSkill = 0;
	sMsp = 0;
	sHP = 0;
	bItemGroup = 0;
	iUseItem = 0;
	bCastTime = 0;
	sReCastTime = 0;
	bSuccessRate = 0;
	bType1 = 0;
	bType2 = 0;
	sRange = 0;
	sEtc = 0;
	m_nFields = 20;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CMagicTableSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=KN_Online;UID=knight;PWD=knight");
}

CString CMagicTableSet::GetDefaultSQL()
{
	return _T("[dbo].[MAGIC]");
}

void CMagicTableSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMagicTableSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[MagicNum]"), iNum);
	RFX_Int(pFX, _T("[BeforeAction]"), nBeforeAction);
	RFX_Byte(pFX, _T("[TargetAction]"), bTargetAction);
	RFX_Byte(pFX, _T("[SelfEffect]"), bSelfEffect);
	RFX_Byte(pFX, _T("[FlyingEffect]"), bFlyingEffect);
	RFX_Long(pFX, _T("[TargetEffect]"), iTargetEffect);
	RFX_Byte(pFX, _T("[Moral]"), bMoral);
	RFX_Int(pFX, _T("[SkillLevel]"), sSkillLevel);
	RFX_Int(pFX, _T("[Skill]"), sSkill);
	RFX_Int(pFX, _T("[Msp]"), sMsp);
	RFX_Int(pFX, _T("[HP]"), sHP);
	RFX_Byte(pFX, _T("[ItemGroup]"), bItemGroup);
	RFX_Long(pFX, _T("[UseItem]"), iUseItem);
	RFX_Byte(pFX, _T("[CastTime]"), bCastTime);
	RFX_Int(pFX, _T("[ReCastTime]"), sReCastTime);
	RFX_Byte(pFX, _T("[SuccessRate]"), bSuccessRate);
	RFX_Byte(pFX, _T("[Type1]"), bType1);
	RFX_Byte(pFX, _T("[Type2]"), bType2);
	RFX_Int(pFX, _T("[Range]"), sRange);
	RFX_Int(pFX, _T("[Etc]"), sEtc);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMagicTableSet diagnostics

#ifdef _DEBUG
void CMagicTableSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMagicTableSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
