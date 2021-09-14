# Microsoft Developer Studio Project File - Name="MUTGhoster DLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=MUTGhoster DLL - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MUTGhoster DLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MUTGhoster DLL.mak" CFG="MUTGhoster DLL - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MUTGhoster DLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MUTGHOSTERDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\..\Core\Inc" /I "..\..\Engine\Inc" /I "..\Inc" /D "WIN32" /D "WINDOWS" /D "_WINDOWS" /D "UNICODE" /D "_UNICODE" /D MUTGHOSTER_API=__declspec(dllexport) /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 ..\..\Core\Lib\Core.lib ..\..\Engine\Lib\Engine.lib /nologo /dll /machine:I386 /out:"..\..\System/MUTGhoster.dll"
# Begin Target

# Name "MUTGhoster DLL - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BurnerProj.cpp
# End Source File
# Begin Source File

SOURCE=.\eGhostMut.cpp
# End Source File
# Begin Source File

SOURCE=.\eLensFlareMut.cpp
# End Source File
# Begin Source File

SOURCE=.\eProMesMut.cpp
# End Source File
# Begin Source File

SOURCE=.\eSArenaMut.cpp
# End Source File
# Begin Source File

SOURCE=.\eSim_HDRMut.cpp
# End Source File
# Begin Source File

SOURCE=.\eTestHUDMut.cpp
# End Source File
# Begin Source File

SOURCE=.\eZeroDamage.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\Inc\ABurnerProj.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AeGhostMut.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AeLensFlareMut.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AeProMesMut.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AeSArenaMut.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AeSim_HDRMut.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AeTestHUDMut.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AeZeroDamage.h
# End Source File
# Begin Source File

SOURCE=..\Inc\MUTGhosterClasses.h
# End Source File
# Begin Source File

SOURCE=.\MUTGhosterPrivate.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
