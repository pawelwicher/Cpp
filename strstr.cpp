#include <iostream>
#include <string.h>
using namespace std;


int main()
{
char tekst1[]="przykladowy tekst";
char tekst2[]="kladjhk";

if((strstr(tekst1,tekst2))==NULL) cout<<"nie ma\n";
else cout<<"jest\n";



system("pause");
}
