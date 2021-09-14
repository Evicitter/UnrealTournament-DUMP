//Date: 15/08/2008 16:27:20

#if !defined(AFX_URUNDLG_H__971C836A_F3B9_4970_8DCE_059B04FA7ED4__INCLUDED_)
#define AFX_URUNDLG_H__971C836A_F3B9_4970_8DCE_059B04FA7ED4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xShadeButton.h"
#include "afxwin.h"

//USER NNRT
#define dfieldStartup(x, y) \
	if (CreateProcess(x,NULL,NULL,NULL,FALSE,NULL,NULL,NULL,&GThisSUI,&GThisPI)==TRUE) \
	{ \
	 m_btn[y].EnableWindow(FALSE); \
	 SetTimer(0xffaa2400 + y,1500,NULL); \
	 hProcceses[y] = GThisPI.hProcess; \
	 ZeroMemory(&GThisPI,sizeof(PROCESS_INFORMATION)); \
	 TrayMessage(m_hWnd, NIM_ADD, 0x77ff77aa, m_hIcon, "Maximized AutoRun"); \
	 ShowWindow(SW_HIDE); \
	} \
//--------------------------------------------/
//--------------------------------------------/

/////////////////////////////////////////////////////////////////////////////
// CURunDlg dialog

class CURunDlg : public CDialog
{
// Construction
public:
	CURunDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CURunDlg)
	enum { IDD = IDD_URUN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CxShadeButton	m_Ok;
	CxShadeButton	m_DVD;
	CxShadeButton	m_btn[6];

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CURunDlg)
	public:
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CURunDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	HANDLE hProcceses[6];
	STARTUPINFO GThisSUI;
	PROCESS_INFORMATION GThisPI;

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void UpdateButState(void);
	
	afx_msg void OnButtonD1();
	afx_msg void OnButtonD2();
	afx_msg void OnButtonD3();
	afx_msg void OnButtonD4();
	afx_msg void OnButtonD5();
	afx_msg void OnButtonD6();
	afx_msg void OnBnClickedButton6();
};

#endif // !defined(AFX_URUNDLG_H__971C836A_F3B9_4970_8DCE_059B04FA7ED4__INCLUDED_)
