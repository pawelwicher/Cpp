#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

double f(double,double);

int main()
{
const double a=-5;
const double b=5;
const double c=-5;
const double d=5;
const double lx=10;
const double ly=10;
const double wysokosc=10;
const double szerokosc=10;
const double sq=0.707167812;
double hx,hy,sx,sy,x2,y2,x1,y1,x,y,xmin,xmax,ymin,ymax;
int j,i;

        
    

   hx=(d-c)/lx;
   hy=(b-a)/ly;
   sx=(d-c)/wysokosc;
   sy=(b-a)/szerokosc;
   
   xmin=0;
   xmax=0;
   ymin=0;
   ymax=0;

    for(j=0;j<=lx;j++)
    {
    y=c+j*hx;
        for(i=0;i<=szerokosc;i++)
        {
        x=a+i*sy;
        x1=x-sq*y;
        y1=-f(x,y)+sq*y;
        if (x1<xmin) xmin=x1;
        if (x1>xmax) xmax=x1;
        if (y1<ymin) ymin=y1;
        if (y1>ymax) ymax=y1;
        }
    }

    for(j=0;j<=ly;j++)
    {
    x=a+j*hy;
        for(i=0;i<=wysokosc;i++)
        {
        y=c+i*sy;
        x1=x-sq*y;
        y1=-f(x,y)+sq*y;
        if (x1<xmin) xmin=x1;
        if (x1>xmax) xmax=x1;
        if (y1<ymin) ymin=y1;
        if (y1>ymax) ymax=y1;
        }
    }

    xmax=szerokosc/(xmax-xmin);
    ymax=wysokosc/(ymax-ymin);
    
    for(j=lx;j>=0;j--)
    {
    y=c+j*hx;
    x1=a-sq*y;
    y1=(-f(a,y)+sq*y);
    x2=xmax*(x1-xmin);
    y2=ymax*(y1-ymin);      
    //Kanwa.moveto(round(x2),round(y2));
          
    
        for(i=1;i<=szerokosc;i++)
        {
        x=a+i*sy;
        x1=x-sq*y;
        y1=(-f(x,y)+sq*y);
        x2=xmax*(x1-xmin);
        y2=ymax*(y1-ymin);
        
        
        //Kanwa.lineto(round(x2),round(y2))
        }
    }

    for(i=0;i<=ly;i++)
    {
    
    x=a+i*hy;
    x1=x-sq*c;
    y1=(-f(x,c)+sq*c);
    x2=xmax*(x1-xmin);
    y2=ymax*(y1-ymin);
    //Kanwa.moveto(round(x2),round(y2));
        for(j=1;j<=wysokosc;j++)
        {
        y=c+j*sx;
        x1=x-sq*y;
        y1=(-f(x,y)+sq*y);
        x2=xmax*(x1-xmin);
        y2=ymax*(y1-ymin);
        cout<<x2<<"   "<<y2<<"\n";
        //Kanwa.lineto(round(x2),round(y2));
        }
    }




system("pause");
}


double f(double x,double y)
{return x*x+y*y;}
