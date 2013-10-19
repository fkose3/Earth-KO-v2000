#if !defined(AFX_MAGICTABLESET_H__E8A08990_A716_4AF2_8C03_7C0C9666F842__INCLUDED_)
#define AFX_MAGICTABLESET_H__E8A08990_A716_4AF2_8C03_7C0C9666F842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MagicTableSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMagicTableSet recordset

class CMagicTableSet : public CRecordset
{
public:
	CMagicTableSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMagicTableSet)

// Field/Param Data
	//{{AFX_FIELD(CMagicTableSet, CRecordset)
	long	iNum;
	int 	nBeforeAction;
	BYTE	bTargetAction;
	BYTE	bSelfEffect;
	BYTE	bFlyingEffect;
	long 	iTargetEffect;
	BYTE	bMoral;
	int 	sSkillLevel;	
	int 	sSkill;
	int 	sMsp;
	int 	sHP;
	BYTE	bItemGroup;
	long 	iUseItem;
	BYTE	bCastTime;
	int 	sReCastTime;
	BYTE	bSuccessRate;
	BYTE	bType1;
	BYTE	bType2;
	int 	sRange;
	int 	sEtc;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagicTableSet)
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

#endif // !defined(AFX_MAGICTABLESET_H__E8A08990_A716_4AF2_8C03_7C0C9666F842__INCLUDED_)
