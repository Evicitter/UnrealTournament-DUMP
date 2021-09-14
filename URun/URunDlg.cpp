//Date: 17/08/2008 01:14:37

#include "stdafx.h"
#include <shellapi.h>
#include "URun.h"
#include "URunDlg.h"
#include "MyLocaliz.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "xShadeButton.h"


/////////////////////////////////////////////////////////////////////////////
// CURunDlg dialog

static CString UGFolder;
static CString UTFolder;
static CString UTRTFolder;
static CString UT2Folder;
static CString U2Folder;
static CString TestUChaos;

#define XBS_INSTALL 512i16
#define XBS_UNINSTALL 513i16
#define XBS_BROWSE	514i16
#define XBS_INSTALLED 515i16
#define XBS_notINSTALLED 516i16

//CxShadeButton
CURunDlg::CURunDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CURunDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	ZeroMemory(&GThisSUI,sizeof(STARTUPINFO));
}

void CURunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	///{{AFX_DATA_MAP(CURunDlg)
	for(char i=0; i < 6; ++i)
		DDX_Control(pDX, IDC_BUTTONS_OFFSET + i, m_btn[i]);
	DDX_Control(pDX, IDOK, m_Ok);
	DDX_Control(pDX, IDC_BUTTON7, m_DVD);
	///}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CURunDlg, CDialog)
	//{{AFX_MSG_MAP(CURunDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOVE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_BN_DOUBLECLICKED(IDC_BUTTON1, &CURunDlg::OnButtonD1)
	ON_BN_DOUBLECLICKED(IDC_BUTTON2, &CURunDlg::OnButtonD2)
	ON_BN_DOUBLECLICKED(IDC_BUTTON3, &CURunDlg::OnButtonD3)
	ON_BN_DOUBLECLICKED(IDC_BUTTON4, &CURunDlg::OnButtonD4)
	ON_BN_DOUBLECLICKED(IDC_BUTTON5, &CURunDlg::OnButtonD5)
	ON_BN_DOUBLECLICKED(IDC_BUTTON6, &CURunDlg::OnButtonD6)
	ON_BN_CLICKED(IDC_BUTTON7, &CURunDlg::OnBnClickedButton6)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CURunDlg message handlers

BOOL CURunDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	/*if(ch_topwin.GetCheck() == 1)
		::SetWindowPos (m_hWnd, HWND_TOPMOST, 0,0,0,0, SWP_NOMOVE|SWP_NOSIZE);
	else
		::SetWindowPos (m_hWnd, HWND_NOTOPMOST, 0,0,0,0, SWP_NOMOVE|SWP_NOSIZE);*/

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//Set Special button parameters
	m_Ok.SetShade(SHS_METAL);

	m_DVD.xSetButtonState(XBS_BROWSE);
	m_DVD.SetToolTipText("Browse DVD Folder");
	m_DVD.SetShade(SHS_METAL);
	m_DVD.SetTextColor(RGB(0,120,20));
	m_DVD.SetIcon(IDI_ICON5,BS_LEFT); //Browse DVD	
	//------------------------------------------------------------------------------

	// TODO: Add extra initialization here
	for(char iter=0; iter < 6; ++iter)
	{
		m_btn[iter].SetTextAlign(BS_RIGHT);
		m_btn[iter].SetFlat(1);
		m_btn[iter].xSetButtonState(XBS_INSTALL);
		m_btn[iter].SetShade(SHS_HBUMP,0,45,10);
	}

	m_btn[0].SetIcon(IDI_ICON7,BS_LEFT); //Unreal Gold
	m_btn[1].SetIcon(IDI_ICON1,BS_LEFT); //UT
	m_btn[2].SetIcon(IDI_ICON2,BS_LEFT); //Chaos
	m_btn[3].SetIcon(IDI_ICON3,BS_LEFT); //Run Time
	m_btn[4].SetIcon(IDI_ICON4,BS_LEFT); //UT2004
    m_btn[5].SetIcon(IDI_ICON6,BS_LEFT); //Unreal 2


	//Color Text :Red
	m_btn[0].SetTextColor(RGB(120,0,0)); //Unreal Red
	m_btn[1].SetTextColor(RGB(120,0,0)); //UT Red
	m_btn[3].SetTextColor(RGB(120,0,0)); //RT Red
	m_btn[4].SetTextColor(RGB(120,0,0)); //UT2004 Red
	m_btn[5].SetTextColor(RGB(120,0,0)); //Unreal2 Red
	//----------------------------------------------------------------

	UpdateButState();
	//End UT check Registry

	return TRUE;
}

void CURunDlg::OnPaint() 
{
	if (IsIconic())
	{
		CRect rect;
		CPaintDC dc(this); 
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		GetClientRect(&rect);
		dc.DrawIcon((rect.Width() - GetSystemMetrics(SM_CXICON) + 1) >> 1, (rect.Height() - GetSystemMetrics(SM_CYICON) + 1) >> 1, m_hIcon);
	}
	else { CDialog::OnPaint(); }
}

HCURSOR CURunDlg::OnQueryDragIcon() { return (HCURSOR) m_hIcon; }

void CURunDlg::WinHelp(DWORD dwData, UINT nCmd) {	MessageBeep(0);	}

void CURunDlg::OnMove(int x, int y) 
{
 CRect rect;
 CRect TmpR;
 GetWindowRect(&rect);

 bool ischange = false;

 if(rect.left < 0) { rect.right = rect.Width(); rect.left = 0; ischange = true; }
 if(rect.top < 0)  { rect.bottom = rect.Height(); rect.top = 0; ischange = true; }
 if(rect.right > (TmpR.bottom = GetSystemMetrics(SM_CXSCREEN)))
 {
  rect.left = TmpR.bottom - rect.Width();
  rect.right = TmpR.bottom;
  ischange = true;
 }

 if(rect.bottom > (TmpR.left = GetSystemMetrics(SM_CYSCREEN)))
 {
  rect.top = TmpR.left - rect.Height();
  rect.bottom = TmpR.left;
  ischange = true;
 }

 if(ischange)
    MoveWindow(LPCRECT(rect));
}

void CURunDlg::OnButton1()//Category - Unreal Engine 1
{
 if((m_btn[0].xGetButtonState() == XBS_UNINSTALL) && (UGFolder != ""))
 {
	dfieldStartup(LPCSTR(UGFolder + CString("\\UGUninstall.exe")),0)
 }
 else
 {
	dfieldStartup("Unreal1\\UGSetup.exe",0)
 }
}

void CURunDlg::OnButton2() 
{  
 if((m_btn[1].xGetButtonState() == XBS_UNINSTALL) && (UTFolder != ""))
 {
	dfieldStartup(LPCSTR(UTFolder + CString("\\UT_Uninstall.exe")),1)
 }
 else
 {
	dfieldStartup("Unreal1\\UTSetup.exe",1)
 }
}

void CURunDlg::OnButton3()
{ 
 if((m_btn[2].xGetButtonState() == XBS_UNINSTALL) && (TestUChaos != ""))
 {
	dfieldStartup(LPCSTR(TestUChaos + CString("\\UChaosUninstall.exe")),2)
 }
 else
 {
	dfieldStartup("Unreal1\\UTChaos.exe",2)
 }
}

void CURunDlg::OnButton4() //Category - Unreal Engine 2
{ 
 if((m_btn[3].xGetButtonState() == XBS_UNINSTALL) && (UTRTFolder != ""))
 {
	dfieldStartup(LPCSTR(UTRTFolder + CString("\\URTUninstall.exe")),3)
 }
 else
 {
	dfieldStartup("URTSetup.exe",3)
 }
}

void CURunDlg::OnButton5() 
{
 if((m_btn[4].xGetButtonState() == XBS_UNINSTALL) && (UT2Folder != ""))
 {
	dfieldStartup(LPCSTR(UT2Folder + CString("\\UT2k4Uninstall.exe")),4)
 }
 else
 {
	dfieldStartup("UT2k4\\UT2k4Setup.exe",4)
 }
}

void CURunDlg::OnButton6()
{
	if((m_btn[5].xGetButtonState() == XBS_UNINSTALL) && (U2Folder != ""))
 {
	dfieldStartup(LPCSTR(U2Folder + CString("\\U2Uninstall.exe")),5)
 }
 else
 {
	dfieldStartup("Unreal2\\U2Setup.exe",5)
 }
}

LRESULT CURunDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	/*if((message == WM_POWERBROADCAST) || (message == WM_POWER)) 
	{
	 if(wParam == PWR_SUSPENDRESUME)
		MessageBox("WOW");
	}*/
	if((lParam == WM_LBUTTONDOWN) && (message == MYWM_NOTIFYICON))
	{
		 MessageBeep(0);
		 //ShowWindow(SW_SHOWNORMAL);
		 //TrayMessage(m_hWnd, NIM_DELETE, 0x77ff77aa, 0, 0);
	}
	return CDialog::WindowProc(message, wParam, lParam);
}

void CURunDlg::OnTimer(UINT_PTR nIDEvent)
{
	int Strep = nIDEvent - 0xffaa2400;
	if(Strep < 6)
	{
		if(WaitForSingleObject(hProcceses[Strep],10) != 0)
		{
			return;
		}
		else
		{
		 //Hide to Tray
		  ShowWindow(SW_SHOWNORMAL);
		  TrayMessage(m_hWnd, NIM_DELETE, 0x77ff77aa, 0, 0);
		 //--------------------------------------------------
		 hProcceses[Strep] = NULL;
		 m_btn[Strep].EnableWindow();
		 KillTimer(nIDEvent);
		  UpdateButState();
		}
	}
}

void CURunDlg::UpdateButState(void)
{
	//-------------------------------------------------------------------------------------------------------
	//Unreal Gold
	if( RegCheck(UGFolder,"SOFTWARE\\Unreal Technology\\Installed Apps\\Unreal Gold","Folder") == TRUE )
	{
		if(GetFileAttributes(LPCSTR(UGFolder + CString("\\UGUninstall.exe"))) != -1)
		{
			m_btn[0].SetWindowText("Del Unreal");
			m_btn[0].SetToolTipText("UnInstall Unreal Gold");
			m_btn[0].SetShade(SHS_METAL,32,10,50,RGB(220,20,0));
			m_btn[0].xSetButtonState(XBS_UNINSTALL);
		}
	}
	else
	{
		m_btn[0].xSetButtonState(XBS_INSTALL);
		m_btn[0].SetWindowText("Unreal Gold");
		m_btn[0].SetToolTipText("Install Unreal Gold");
		m_btn[0].SetShade(SHS_HBUMP,0,45,10);
	}
	//-------------------------------------------------------------------------------------------------------
	//Unreal Tournament
    if( RegCheck(UTFolder,"SOFTWARE\\Unreal Technology\\Installed Apps\\UnrealTournament","Folder") == TRUE )
	{
		if(GetFileAttributes(LPCSTR(UTFolder + CString("\\UT_Uninstall.exe"))) != -1)
		{
			m_btn[1].SetWindowText("Del UT");
			m_btn[1].SetToolTipText("UnInstall Unreal Tournament");
			m_btn[1].SetShade(SHS_METAL,32,10,50,RGB(220,20,0));
			m_btn[1].xSetButtonState(XBS_UNINSTALL);
		}
	}
	else
	{
		m_btn[1].xSetButtonState(XBS_INSTALL);
		m_btn[1].SetWindowText("UT classic");
		m_btn[1].SetToolTipText("Install Unreal Tournament");
		m_btn[1].SetShade(SHS_HBUMP,0,45,10);
	}
//------------------------------------------------------------------------------------
	//UChaos
	   if( RegCheck(TestUChaos,"SOFTWARE\\Unreal Technology\\Installed Apps\\UnrealTournament","ChaosMod") == TRUE )
	   {
		if(GetFileAttributes(LPCSTR(TestUChaos + CString("\\UChaosUninstall.exe"))) != -1)
		{
			m_btn[2].SetWindowText("Del UTChaos");
			m_btn[2].SetToolTipText("UnInstall Unreal Tournament: Chaos mod");
			m_btn[2].SetShade(SHS_METAL,32,10,50,RGB(220,20,0));
			m_btn[2].xSetButtonState(XBS_UNINSTALL);
			
			if(m_btn[1].xGetButtonState() == XBS_INSTALL)
			{
			 m_btn[2].SetTextColor(RGB(0,0,255));
		     m_btn[2].SetShade(SHS_METAL,8,17,10,RGB(255,0,0));
			}
			else
			{
				m_btn[2].SetTextColor(0);
			    m_btn[2].SetShade(SHS_HBUMP,0,45,10);
			}
		}
	   }
	   else
	   {
		m_btn[2].xSetButtonState(XBS_INSTALL);
		m_btn[2].SetWindowText("UT chaos");
		m_btn[2].SetToolTipText("Install Unreal Tournament chaos");
		m_btn[2].SetShade(SHS_HBUMP,0,45,10);

			if(m_btn[1].xGetButtonState() == XBS_INSTALL)
			{
			 m_btn[2].SetTextColor(RGB(0,0,255));
		     m_btn[2].SetShade(SHS_METAL,8,17,10,RGB(255,0,0));
			}
			else
			{
				m_btn[2].SetTextColor(0);
			    m_btn[2].SetShade(SHS_HBUMP,0,45,10);
			}
	   }
//---------------------------------------------------------------------------------
	//RunTime
	if( RegCheck(UTRTFolder,"SOFTWARE\\Unreal Technology\\Installed Apps\\UE2Runtime","Folder") == TRUE )
	{
		if(GetFileAttributes(LPCSTR(UTRTFolder + CString("\\URTUninstall.exe"))) != -1)
		{
			m_btn[3].SetWindowText("Del RunTime");
			m_btn[3].SetToolTipText("UnInstall Unreal Engine 2: Run Time");
			m_btn[3].SetShade(SHS_METAL,32,10,50,RGB(220,20,0));
			m_btn[3].xSetButtonState(XBS_UNINSTALL);
		}
	}
	else
	{
		m_btn[3].xSetButtonState(XBS_INSTALL);
		m_btn[3].SetWindowText("UE2:RT");
		m_btn[3].SetToolTipText("Instal Unreal Engine 2: Run Time");
		m_btn[3].SetShade(SHS_HBUMP,0,45,10);
	}
//--------------------------------------------------------------------------------------
	//Unreal Tournament 2004
	if( RegCheck(UT2Folder,"SOFTWARE\\Unreal Technology\\Installed Apps\\UT2004","Folder") == TRUE )
	{
		if(GetFileAttributes(LPCSTR(UT2Folder + CString("\\UT2k4Uninstall.exe"))) != -1)
		{
			m_btn[4].SetWindowText("Del UT2004");
			m_btn[4].SetToolTipText("UnInstall Unreal Tournament 2004");
			m_btn[4].SetShade(SHS_METAL,32,10,50,RGB(220,20,0));
			m_btn[4].xSetButtonState(XBS_UNINSTALL);
		}
	}
	else
	{
		m_btn[4].xSetButtonState(XBS_INSTALL);
		m_btn[4].SetWindowText("UT2004");
		m_btn[4].SetToolTipText("Instal Unreal Tournament 2004");
		m_btn[4].SetShade(SHS_HBUMP,0,45,10);
	}

	//Unreal 2: The Awakening
	if( RegCheck(U2Folder,"SOFTWARE\\Unreal Technology\\Installed Apps\\Unreal2","Folder") == TRUE )
	{
		if(GetFileAttributes(LPCSTR(U2Folder + CString("\\U2Uninstall.exe"))) != -1)
		{
			m_btn[5].SetWindowText("Del Unreal2");
			m_btn[5].SetToolTipText("UnInstall Unreal 2: The Awakening");
			m_btn[5].SetShade(SHS_METAL,32,10,50,RGB(220,20,0));
			m_btn[5].xSetButtonState(XBS_UNINSTALL);
		}
	}
	else
	{
		m_btn[5].xSetButtonState(XBS_INSTALL);
		m_btn[5].SetWindowText("Unreal 2");
		m_btn[5].SetToolTipText("Instal Unreal 2: The Awakening");
		m_btn[5].SetShade(SHS_HBUMP,0,45,10);
	}
}

void CURunDlg::OnButtonD1()
{
	if( RegCheck(UGFolder,"SOFTWARE\\Unreal Technology\\Installed Apps\\Unreal Gold","Folder") == TRUE )
		    ShellExecute(NULL,NULL,"explorer.exe",(LPCSTR)UGFolder,NULL,1);
}

void CURunDlg::OnButtonD2()
{
	if( RegCheck(UTFolder,"SOFTWARE\\Unreal Technology\\Installed Apps\\UnrealTournament","Folder") == TRUE )
		    ShellExecute(NULL,NULL,"explorer.exe",(LPCSTR)UTFolder,NULL,1);
}

void CURunDlg::OnButtonD3()
{
	// TODO: Add your control notification handler code here
}

void CURunDlg::OnButtonD4()
{
	if( RegCheck(UTRTFolder,"SOFTWARE\\Unreal Technology\\Installed Apps\\UE2Runtime","Folder") == TRUE )
		    ShellExecute(NULL,NULL,"explorer.exe",(LPCSTR)UTRTFolder,NULL,1);
}

void CURunDlg::OnButtonD5()
{
	if( RegCheck(UT2Folder,"SOFTWARE\\Unreal Technology\\Installed Apps\\UT2004","Folder") == TRUE )
		    ShellExecute(NULL,NULL,"explorer.exe",(LPCSTR)UT2Folder,NULL,1);
}

void CURunDlg::OnButtonD6()
{
	if( RegCheck(U2Folder,"SOFTWARE\\Unreal Technology\\Installed Apps\\Unreal2","Folder") == TRUE )
		    ShellExecute(NULL,NULL,"explorer.exe",(LPCSTR)U2Folder,NULL,1);
}

void CURunDlg::OnBnClickedButton6()
{
	CString xdf;
	xdf = GetCommandLine();
	xdf = xdf.Mid(1, xdf.Find('\\'));
	if(!xdf.IsEmpty())
		ShellExecute(NULL,NULL,"explorer.exe",(LPCSTR)xdf,NULL,1);
}