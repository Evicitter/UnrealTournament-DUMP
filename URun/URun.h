//Date: 21/04/2008 20:54:12

#if !defined(AFX_URUN_H__3F957990_8B74_4AE4_8D35_9367361794B9__INCLUDED_)
#define AFX_URUN_H__3F957990_8B74_4AE4_8D35_9367361794B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#define IDC_BUTTONS_OFFSET IDC_BUTTON1


class CURunApp : public CWinApp
{
public:
	CURunApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CURunApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CURunApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_URUN_H__3F957990_8B74_4AE4_8D35_9367361794B9__INCLUDED_)
