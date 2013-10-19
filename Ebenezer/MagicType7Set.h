#if !defined(AFX_MAGICTYPE7SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_)
#define AFX_MAGICTYPE7SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MagicType7Set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMagicType7Set recordset

class CMagicType7Set : public CRecordset
{
public:
	CMagicType7Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMagicType7Set)
	// Field/Param Data
	//{{AFX_FIELD(CMagicType7Set, CRecordset)
	long	iNum;
	BYTE	bValidGroup;
	BYTE	bNationChange;
	int		sMonsterNum;
	BYTE	bTargetChange;
	BYTE	bStateChange;
	BYTE	bRadius;
	int		sHitRate;
	int		sDuration;
	int		sDamage;
	BYTE	bVision;
	long	nNeedItem;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagicType7Set)
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

#endif // !defined(AFX_MAGICTYPE7SET_H__CE4EE739_4C6D_43D1_8EB6_E9CC144F9EE2__INCLUDED_)
