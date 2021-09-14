//Date: 20/06/2008 17:58:42

#if !defined(H_MYLOCALIZ_H)
#define H_MYLOCALIZ_H

#define MyS_Language 1

# ifdef MyS_Language

#if (MyS_Language == 1)   //Russian

#else if (MyS_Language == 2) //English

#endif

#endif




//--------------------------------------------------------------------------------------
#define MYWM_NOTIFYICON (WM_USER + 1)// Описываем сообщение, которое будет посылаться при взаимодействии юзера с нашей иконкой в систрееСоздаем (глобальную) функцию 
//TrayMessage
BOOL TrayMessage (HWND hDlg, DWORD dwMessage, UINT uID, HICON hIcon, PSTR pszTip)
 // systray icon
{
	BOOL res;
	NOTIFYICONDATA tnd;
	tnd.cbSize = sizeof(NOTIFYICONDATA);
	tnd.hWnd = hDlg;
	tnd.uID = uID;
	tnd.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	tnd.uCallbackMessage = MYWM_NOTIFYICON; // Сообщение, которое пошлется при всяких там кликах на иконке...
	tnd.hIcon = hIcon;
	if (pszTip)
	{
		lstrcpyn(tnd.szTip, pszTip, sizeof(tnd.szTip));
	}
	else
	{
		tnd.szTip[0] = '\0';
	}
	res = Shell_NotifyIcon(dwMessage, &tnd);
	return res; 
}

//-----------------------------------------------------------------
static char* GlobalValueReg;
static DWORD GlobalLengthReg;

//CheckReg
BOOL RegCheck(CString& ReturnEAX,LPCSTR SubKey, LPCSTR ValueNm)
{
	HKEY hk;
	BOOL result = TRUE;

	GlobalLengthReg = 512L;
	GlobalValueReg = new char[GlobalLengthReg];

	if(RegOpenKey(HKEY_LOCAL_MACHINE, SubKey,&hk) == ERROR_SUCCESS)
	{
     if(RegQueryValueEx(hk, ValueNm, NULL, NULL, (BYTE*)GlobalValueReg, &GlobalLengthReg) == ERROR_SUCCESS)
	 {
		  ReturnEAX = GlobalValueReg;
	 }
	 else
	 {
		 result = FALSE;
		 ReturnEAX = "";
	 }
	}
	else result = FALSE;

	RegCloseKey(HKEY_LOCAL_MACHINE);
	delete[] GlobalValueReg;
	
	return result;
}

#endif