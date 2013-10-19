// MagicType6Set.cpp : implementation file
//

#include "stdafx.h"
#include "ebenezer.h"
#include "MaigcType6Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMagicType6Set

IMPLEMENT_DYNAMIC(CMagicType6Set, CRecordset)

CMagicType6Set::CMagicType6Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMagicType6Set)
	iNum = 0;
	sSize = 0;
	sTransformID = 0;
	sDuration = 0;
	sMaxHp = 0;
	sMaxMp = 0;
	bSpeed = 0;
	sAttackSpeed = 0;
	sTotalHit = 0;
	sTotalAc = 0;
	sTotalHitRate = 0;
	sTotalEvasionRate = 0;
	sTotalFireR = 0;
	sTotalColdR = 0;
	sTotalLightningR = 0;
	sTotalMagicR = 0;
	sTotalDiseaseR = 0;
	sTotalPoisonR = 0;
	sClass = 0;
	bUserSkillUse = 0;
	bNeedItem = 0;
	bSkillSuccessRate = 0;
	bMonsterFriendly = 0;
	m_nFields = 23;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CMagicType6Set::GetDefaultConnect()
{
//	return _T("ODBC;DSN=KN_Online");
	return _T("ODBC;DSN=KN_Online;UID=knight;PWD=knight");
}

CString CMagicType6Set::GetDefaultSQL()
{
	return _T("[dbo].[MAGIC_TYPE6]");
}

void CMagicType6Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMagicType6Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[iNum]"),iNum);
	RFX_Int(pFX, _T("[Size]"),sSize);
	RFX_Int(pFX, _T("[TransformID]"),sTransformID);
	RFX_Int(pFX, _T("[Duration]"),sDuration);
	RFX_Int(pFX, _T("[MaxHp]"),sMaxHp);
	RFX_Int(pFX, _T("[MaxMp]"),sMaxMp);
	RFX_Byte(pFX, _T("[Speed]"),bSpeed);
	RFX_Int(pFX, _T("[AttackSpeed]"),sAttackSpeed);
	RFX_Int(pFX, _T("[TotalHit]"),sTotalHit);
	RFX_Int(pFX, _T("[TotalAc]"),sTotalAc);
	RFX_Int(pFX, _T("[TotalHitRate]"),sTotalHitRate);
	RFX_Int(pFX, _T("[TotalEvasionRate]"),sTotalEvasionRate);
	RFX_Int(pFX, _T("[TotalFireR]"),sTotalFireR);
	RFX_Int(pFX, _T("[TotalColdR]"),sTotalColdR);
	RFX_Int(pFX, _T("[TotalLightningR]"),sTotalLightningR);
	RFX_Int(pFX, _T("[TotalMagicR]"),sTotalMagicR);
	RFX_Int(pFX, _T("[TotalDiseaseR]"),sTotalDiseaseR);
	RFX_Int(pFX, _T("[TotalPoisonR]"),sTotalPoisonR);
	RFX_Int(pFX, _T("[Class]"),sClass);
	RFX_Byte(pFX, _T("[UserSkillUse]"),bUserSkillUse);
	RFX_Byte(pFX, _T("[NeedItem]"),bNeedItem);
	RFX_Byte(pFX, _T("[SkillSuccessRate]"),bSkillSuccessRate);
	RFX_Byte(pFX, _T("[MonsterFriendly]"),bMonsterFriendly);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMagicType6Set diagnostics

#ifdef _DEBUG
void CMagicType6Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMagicType6Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
