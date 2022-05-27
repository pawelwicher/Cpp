#include "Polaczenie.h"

Polaczenie::Polaczenie()
{
    FILE *f=fopen("port.txt","rt");

    char port[10];
    fscanf(f,"%s",&port);
    fclose(f);

    hPortID=CreateFile(port,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);

    dcb.DCBlength = sizeof(dcb);
    dcb.BaudRate = CBR_9600;
    dcb.Parity = ODDPARITY;
    dcb.StopBits = ONESTOPBIT;
    dcb.ByteSize = 7;
    dcb.fParity = TRUE;
    dcb.fDtrControl = DTR_CONTROL_DISABLE;
    dcb.fRtsControl = RTS_CONTROL_DISABLE;
    dcb.fOutxCtsFlow = FALSE;
    dcb.fOutxDsrFlow = FALSE;
    dcb.fDsrSensitivity = FALSE;
    dcb.fAbortOnError = FALSE;
    dcb.fOutX = FALSE;
    dcb.fInX = FALSE;
    dcb.fErrorChar = FALSE;
    dcb.fNull = FALSE;

    SetCommState(hPortID,&dcb);
}

Polaczenie::~Polaczenie()
{
    CloseHandle(hPortID);
}

bool Polaczenie::SendChar(char &c)
{
DWORD LiczbaBajtowZapisanych;

   if(WriteFile(hPortID,&c,(DWORD)1,&LiczbaBajtowZapisanych,NULL)>0)
     return true;
   else
     return false;
}

bool Polaczenie::GetChar(char &buf)
{
DWORD LiczbaBajtowPrzeczytanych=0;

    ClearCommError(hPortID,&Errors,&Stat);
    if(Stat.cbInQue>0)
      ReadFile(hPortID,&buf,(DWORD)1,&LiczbaBajtowPrzeczytanych,NULL);

    if(LiczbaBajtowPrzeczytanych>0)
      return true;
    else
      return false;
}

