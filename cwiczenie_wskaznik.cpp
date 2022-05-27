#include <iostream>
using namespace std;


int main()
{
int t[2];
int *p;

p=t;
t[0]=1;
t[1]=2;
cout<<t[0]<<" "<<t[1]<<"   //*p++\n";
cout<<*p++<<"\n";
cout<<*p<<"\n";
cout<<t[0]<<" "<<t[1]<<"\n";
cout<<"\n";

p=t;
t[0]=1;
t[1]=2;
cout<<t[0]<<" "<<t[1]<<"   //*++p\n";
cout<<*++p<<"\n";
cout<<*p<<"\n";
cout<<t[0]<<" "<<t[1]<<"\n";
cout<<"\n";

p=t;
t[0]=1;
t[1]=2;
cout<<t[0]<<" "<<t[1]<<"   ///++*p\n";
cout<<++*p<<"\n";
cout<<*p<<"\n";
cout<<t[0]<<" "<<t[1]<<"\n";
cout<<"\n";

p=t;
t[0]=1;
t[1]=2;
cout<<t[0]<<" "<<t[1]<<"   //(*p)++\n";
cout<<(*p)++<<"\n";
cout<<*p<<"\n";
cout<<t[0]<<" "<<t[1]<<"\n";
cout<<"\n";

p=t;
t[0]=1;
t[1]=2;
cout<<t[0]<<" "<<t[1]<<"   //++(*p)\n";
cout<<++(*p)<<"\n";
cout<<*p<<"\n";
cout<<t[0]<<" "<<t[1]<<"\n";
cout<<"\n";




system("pause");
}
