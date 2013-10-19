#if !defined(AFX_MAGICTYPE9SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_)
#define AFX_MAGICTYPE9SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MagicType9Set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMagicType9Set recordset

class CMagicType9Set : public CRecordset
{
public:
	CMagicType9Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMagicType9Set)
	// Field/Param Data
	//{{AFX_FIELD(CMagicType9Set, CRecordset)
	long	iNum;
	BYTE	bValidGroup;
	BYTE	bNationChange;
	int 	sMonsterNum;
	BYTE	bTargetChange;
	BYTE	bStateChange;
	int 	sRadius;
	int 	sHitRate;
	int 	sDuration;
	int 	sDamage;
	int 	sVision;
	long	nNeedItem;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagicType9Set)
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

#endif // !defined(AFX_MAGICTYPE9SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_)
