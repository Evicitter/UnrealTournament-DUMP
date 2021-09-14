cd System
if exist MUTGhoster.u del MUTGhoster.u
UCC.exe make -nobind
if not exist MUTGhoster.u NOTEPAD UCC.log