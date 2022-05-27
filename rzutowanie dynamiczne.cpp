#include <iostream>
using namespace std;


class Zwierze
{
public:
bool z;
virtual void f(){}
};
class Ptak : public Zwierze{};
class Ryba : public Zwierze{};
class Sowa : public Ptak{};





int main()
{
Zwierze *P=new Ptak;
Zwierze *R=new Ryba;
Zwierze *S=new Sowa;

S->z=1;

//Ptak *Pt=S; - nie zachula "invalid conversion"
Ptak *Pt=dynamic_cast<Ptak*>(S);

cout<<Pt->z<<"\n";

if(Pt!=NULL) cout<<"Rzutowanie powiodlo sie.\n";
else cout<<"Rzutowanie nieudane.\n";

cout<<"\n";
system("pause");
}
