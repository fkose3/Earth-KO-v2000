// VersionManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VersionManager.h"
#include "VersionManagerDlg.h"
#include "IOCPSocket2.h"
#include "VersionSet.h"
#include "SettingDlg.h"
#include "User.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CIOCPort	CVersionManagerDlg::m_Iocport;

/////////////////////////////////////////////////////////////////////////////
// CVersionManagerDlg dialog

CVersionManagerDlg::CVersionManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVersionManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVersionManagerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
	memset( m_strFtpUrl, NULL, 256 );
	memset( m_strFilePath, NULL, 256 );
	memset( m_strDefaultPath, NULL, _MAX_PATH );
	m_nLastVersion = 0;
	memset( m_ODBCName, NULL, 32 );
	memset( m_ODBCLogin, NULL, 32 );
	memset( m_ODBCPwd, NULL, 32 );
	memset( m_TableName, NULL, 32 );
	
	memset( m_News[0], NULL, 120);
	memset( m_News[1], NULL, 120);
	memset( m_News[2], NULL, 120);

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVersionManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVersionManagerDlg)
	DDX_Control(pDX, IDC_LIST1, m_OutputList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVersionManagerDlg, CDialog)
	//{{AFX_MSG_MAP(CVersionManagerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SETTING, OnVersionSetting)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVersionManagerDlg message handlers

BOOL CVersionManagerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_Iocport.Init( MAX_USER, CLIENT_SOCKSIZE, 1 );
	
	for(int i=0; i<MAX_USER; i++) {
		m_Iocport.m_SockArrayInActive[i] = new CUser;
	}

	if ( !m_Iocport.Listen( _LISTEN_PORT ) ) {
		AfxMessageBox("FAIL TO CREATE LISTEN STATE");
		AfxPostQuitMessage(0);
		return FALSE;
	}

	if( !GetInfoFromIni() ) {
		AfxMessageBox("Ini File Info Error!!");
		AfxPostQuitMessage(0);
		return FALSE;
	}
	
	char strconnection[256];
	memset(strconnection, NULL, 256 );
	sprintf( strconnection, "ODBC;DSN=%s;UID=%s;PWD=%s", m_ODBCName, m_ODBCLogin, m_ODBCPwd );
	if( !m_DBProcess.InitDatabase( strconnection ) ) {
		AfxMessageBox("Database Connection Fail!!");
		AfxPostQuitMessage(0);
		return FALSE;
	}
	if( !m_DBProcess.LoadVersionList() ) {
		AfxMessageBox("Load Version List Fail!!");
		AfxPostQuitMessage(0);
		return FALSE;
	}

	m_OutputList.AddString( strconnection );
	CString version;
	version.Format("Guncel Version : %d", m_nLastVersion );
	m_OutputList.AddString( version );

	::ResumeThread( m_Iocport.m_hAcceptThread );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

BOOL CVersionManagerDlg::GetInfoFromIni()
{
	int errorcode = 0;
	CString errorstr, inipath;

	inipath.Format( "%s\\iniFiles\\Login.ini", GetProgPath() );
	GetPrivateProfileString( "DOWNLOAD", "URL", "", m_strFtpUrl, 256, inipath );
	GetPrivateProfileString( "DOWNLOAD", "PATH", "", m_strFilePath, 256, inipath );

	GetPrivateProfileString( "ODBC", "DSN", "", m_ODBCName, 32, inipath );
	GetPrivateProfileString( "ODBC", "UID", "", m_ODBCLogin, 32, inipath );
	GetPrivateProfileString( "ODBC", "PWD", "", m_ODBCPwd, 32, inipath );
	GetPrivateProfileString( "ODBC", "TABLE", "", m_TableName, 32, inipath );
	GetPrivateProfileString( "CONFIGURATION", "DEFAULT_PATH", "", m_strDefaultPath, 256, inipath );
	
	GetPrivateProfileString( "NEWS", "TITLE1", "", m_News[0], 32, inipath );
	GetPrivateProfileString( "NEWS", "TITLE2", "", m_News[1], 32, inipath );
	GetPrivateProfileString( "NEWS", "TITLE3", "", m_News[2], 32, inipath );

	m_nServerCount = GetPrivateProfileInt( "SERVER_LIST", "COUNT", 0, inipath );

	if( !strlen(m_strFtpUrl) || !strlen(m_strFilePath) ) return FALSE;
	if( !strlen(m_ODBCName) || !strlen(m_ODBCLogin) || !strlen(m_ODBCPwd) || !strlen(m_TableName) ) return FALSE;
	if( m_nServerCount <= 0 ) return FALSE;
	
	char ipkey[20]; memset( ipkey, 0x00, 20 );
	char namekey[20]; memset( namekey, 0x00, 20 );
	char FreeKey[20]; memset( FreeKey, 0x00, 20 );
	char PreKey[20]; memset( PreKey, 0x00, 20 );
	char king[2][20]; memset( king[0], 0x00, 20); memset( king[1], 0x00, 20);
	char KingMessage[2][20]; memset( KingMessage[0], 0x00, 20); memset( KingMessage[1], 0x00, 20);

	_SERVER_INFO* pInfo = NULL;
	
	m_ServerList.reserve(20);
	for( int i=0; i<m_nServerCount; i++ ) {
		pInfo = new _SERVER_INFO;
		sprintf( ipkey, "SERVER_%02d", i );
		sprintf( namekey, "NAME_%02d", i );
		sprintf( FreeKey, "FREELIMIT_%02d", i);
		sprintf( PreKey, "PREMLIMIT_%02d", i);
		sprintf( king[0], "KING1_%02d", i);
		sprintf( king[1], "KING2_%02d", i);
		sprintf( KingMessage[0], "KINGMSG1_%02d", i);
		sprintf( KingMessage[1], "KINGMSG2_%02d", i);
		
		
		GetPrivateProfileString( "SERVER_LIST", ipkey, "", pInfo->strServerIP, 32, inipath );
		GetPrivateProfileString( "SERVER_LIST", namekey, "", pInfo->strServerName, 32, inipath );
		pInfo->strFreelimit = GetPrivateProfileInt( "SERVER_LIST", FreeKey, 0, inipath );
		pInfo->strPrelimit = GetPrivateProfileInt( "SERVER_LIST", PreKey, 0, inipath );
		GetPrivateProfileString( "SERVER_LIST", king[0], "", pInfo->strKing1, 32 , inipath );
		GetPrivateProfileString( "SERVER_LIST", king[1], "", pInfo->strKing2, 32 , inipath );
		GetPrivateProfileString( "SERVER_LIST", KingMessage[0], "", pInfo->strMess1, 32 , inipath );
		GetPrivateProfileString( "SERVER_LIST", KingMessage[1], "", pInfo->strMess2, 32 , inipath );
		


		m_ServerList.push_back( pInfo );
	}

	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVersionManagerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVersionManagerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CVersionManagerDlg::PreTranslateMessage(MSG* pMsg) 
{
	if( pMsg->message == WM_KEYDOWN ) {
		if( pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE )
			return TRUE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CVersionManagerDlg::DestroyWindow() 
{
	if( !m_VersionList.IsEmpty() )
		m_VersionList.DeleteAllData();
	
	for( int i=0; i<m_ServerList.size(); i++)
		delete m_ServerList[i];
	m_ServerList.clear();

	return CDialog::DestroyWindow();
}

void CVersionManagerDlg::OnVersionSetting() 
{
	CString errorstr, inipath;
	inipath.Format( "%s\\iniFiles\\Login.ini", GetProgPath() );
	CSettingDlg	setdlg(m_nLastVersion, this);
	
	strcpy( setdlg.m_strDefaultPath, m_strDefaultPath );
	if( setdlg.DoModal() == IDOK ) {
		strcpy( m_strDefaultPath, setdlg.m_strDefaultPath );
		WritePrivateProfileString("CONFIGURATION", "DEFAULT_PATH", m_strDefaultPath, inipath);
	}
}
