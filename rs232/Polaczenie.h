#include <stdio.h>
#include <vcl.h>


class Polaczenie
{
public:
HANDLE hPortID;
DCB dcb;
COMSTAT Stat;
DWORD Errors;
bool tryb;

Polaczenie();
~Polaczenie();

bool SendChar(char&);
bool GetChar(char&);
};


