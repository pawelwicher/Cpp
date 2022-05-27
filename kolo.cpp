/*
Podaj wynik dzialania programu
*/

#include <iostream>

using namespace std;

long sumaA(int,int);
void sumaB(int,int,long*);
int XXX(int);
int PorownajDaty(int,int,int,int,int,int);
int IleDni(int,int);

int main()
{
int n,p,a,b,z,dzien1,miesiac1,rok1,dzien2,miesiac2,rok2,miesiac,rok;
long c;  
char end;

do
{
//zadanie 1
cout<<"zadanie 1\n";
n=0; while(n<=7) n++; cout<<n<<"\n";
n=p=0; while(n<=4) n+=++p; cout<<n<<"\n";
n=p=0; while(p<=4) n+=p++; cout<<n<<"\n";
//zadanie 1

cout<<"\n";

//zadanie 2
cout<<"zadanie 2\n";
a=6;
b=4;
c=sumaA(a,b);
cout<<c<<"\n";

a=12;
b=8;
sumaB(a,b,&c);
cout<<c<<"\n";
//zadanie 2

cout<<"\n";

//zadanie 3
cout<<"zadanie 3\n";
z=123;
cout<<XXX(z)<<"\n";
//zadanie 3

cout<<"\n";

/*zadanie 4
cout<<"zadanie 4\n";
cout<<"Wczytaj PIERWSZA date; dzien/miesiac/rok\n";
cin>>dzien1>>miesiac1>>rok1;
cout<<"\nWczytaj DRUGA date; dzien/miesiac/rok\n";
cin>>dzien2>>miesiac2>>rok2;
cout<<"\nPIERWSZA data: "<<dzien1<<"-"<<miesiac1<<"-"<<rok1;
cout<<"\nDRUGA data: "<<dzien2<<"-"<<miesiac2<<"-"<<rok2<<"\n";
cout<<PorownajDaty(dzien1,dzien2,miesiac1,miesiac2,rok1,rok2);
//zadanie 4*/

cout<<"\n";

//zadanie 5
cout<<"zadanie 5\n";
cout<<"Podaj miesiac i rok\n";
cin>>miesiac>>rok;
cout<<"\nW roku "<<rok<<" miesiac "<<miesiac<<" ma "<<IleDni(miesiac,rok)<<" dni";
//zadanie 5



cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}


  

long sumaA(int x,int y)
{return x+y;}


void sumaB(int x,int y,long *z)
{*z=x+y;}


int XXX(int liczba)
{
int s=0;
while(liczba) {liczba/=10; s++;}
return s;
}



int PorownajDaty(int d1,int d2,int m1,int m2,int r1,int r2)
{
    if(r1<r2) return 1;
    else{if(r1>r2) return 0;
         else{if(m1<m2) return 1;
              else{if(m1>m2) return 0;
                   else{if(d1<d2) return 1;
                        else{if(d1>d2) return 0;
                             else return 0;}
                        }
                   }
              }
         }
}
                             



int IleDni(int m,int r)
{
int d;

switch(m)
{
         case 4: case 6: case 9: case 11:
         {
         d=30;
         break;
         }
         case 2:
         {
         if((r%400==0)||((r%4==0)&&(r%100!=0))) d=29;
         else d=28;
         break;
         }
         default :
         d=31;
}
return d;
} 
