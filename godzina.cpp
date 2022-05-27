/*
Data
*/

#include <iostream>

using namespace std;

int main()
{
int godzina, minuta, sekunda,i;   
char end;

do
{
cout<<"Podaj godzine\n";
cin>>godzina;
cout<<"\n";
cout<<"Podaj minute\n";
cin>>minuta;
cout<<"\n";
cout<<"Podaj sekunde\n";
cin>>sekunda;
cout<<"\n";
cout<<"\n";

cout<<"Podany czas to: "<<godzina<<":"<<minuta<<":"<<sekunda<<"\n";

for(i=1;i<10;i++)
{
/*
if(sekunda==59)
{
sekunda=0;
minuta++;
          if(minuta==60)
          {
          minuta=0;
          godzina++;
                   if(godzina==24)
                   {
                   godzina=0;
                   }
          }
}
else
{
sekunda++;
}
*/

sekunda++;
if(sekunda==60)
{
sekunda=0;
minuta++;
         if(minuta==60)
         {
         minuta=0;
         godzina++;
                  if(godzina==24)
                  godzina=0;
         }
}

cout<<"\nPodany czas to po uplywie 1 sekundy to: "<<godzina<<":"<<minuta<<":"<<sekunda<<"\n";

}

cout<<"\n\nq - koniec, dowolny znak - kontynuacja\n";
cin>>end; 
} 
while(end!='q');    
}
