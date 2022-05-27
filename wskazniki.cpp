#include <iostream>
using namespace std;

int main()
{

int a=1;
const int b=0;

//wskaznik na int
int* w1=&a;

//staly wskaznik na int
int* const w2=&a;

//wskaznik na const int
const int* w3=&b; 

//staly wskaznik  na const int
const int* const w4=&b;


cout<<"\n\n";
system("pause");
}
