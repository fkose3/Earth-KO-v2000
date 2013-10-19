#if !defined(AFX_MAGICTYPE6SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_)
#define AFX_MAGICTYPE6SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MagicType6Set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMagicType6Set recordset

class CMagicType6Set : public CRecordset
{
public:
	CMagicType6Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMagicType6Set)
	// Field/Param Data
	//{{AFX_FIELD(CMagicType6Set, CRecordset)
	long	iNum;
	int		sSize;
	int		sTransformID;
	int		sDuration; // duration, in seconds
	int		sMaxHp;
	int		sMaxMp;
	BYTE	bSpeed;
	int		sAttackSpeed;
	int		sTotalHit;
	int		sTotalAc;
	int		sTotalHitRate;
	int		sTotalEvasionRate;
	int		sTotalFireR;
	int		sTotalColdR;
	int		sTotalLightningR;
	int		sTotalMagicR;
	int		sTotalDiseaseR;
	int		sTotalPoisonR;
	int		sClass;
	BYTE	bUserSkillUse;
	BYTE	bNeedItem;
	BYTE	bSkillSuccessRate;
	BYTE	bMonsterFriendly;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagicType6Set)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAGICTYPE6SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_)
