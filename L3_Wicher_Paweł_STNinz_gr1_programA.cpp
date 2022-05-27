/*L3_Wicher_STNinz_gr1_programA
Pawe³ Wicher 55555
Program A */
#include<iostream>
using namespace std;

main()
{


          
float x,y,r;
int n,licznik;
char end;

cout<<"Podaj promien okregu: ";
cin>>r;
cout<<"\nPodaj liczbe punktow, ktore chcesz sprawdzic: ";
cin>>n;

       for(int i=1;i<n+1;i++)
       {
         cout<<"\nPodaj wspolrzêdne punktu nr: "<<i<<"\n";
         cout<<"x("<<i<<")="; cin>>x;
         cout<<"y("<<i<<")="; cin>>y;
         
         if(x*x+y*y<r*r) {cout<<"\nPunkt ("<<x<<","<<y<<") lezy WEWNATRZ okregu o promieniu "<<r<<"\n";licznik++;}
         else {cout<<"\nPunkt ("<<x<<","<<y<<") NIE lezy WEWNATRZ okregu o promieniu "<<r<<"\n";}
         
         if(y>x) {cout<<"Punkt lezy ("<<x<<","<<y<<") lezy POWYZEJ prostej y=x\n";licznik++;}
         else {cout<<"Punkt lezy ("<<x<<","<<y<<") lezy PONIZEJ lub NA prostej y=x\n";}
       }
       
       

system("pause");


}