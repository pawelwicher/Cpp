#include "Przeksztalcenie.h"

Przeksztalcenie::Przeksztalcenie(Dane dane)
{
    ImgWe=new Obraz(dane.PlikWe);
    ImgWy=new Obraz(dane.PlikWy,dane.Xres,dane.Yres,dane.tlo);
    if(WyliczTransform(dane.W1,dane.W2,dane.W3,dane.P1,dane.P2,dane.P3,A,B));
}

Przeksztalcenie::~Przeksztalcenie()
{
    delete ImgWe;
    delete ImgWy;
}

int Przeksztalcenie::WyliczTransform(
double W1[2],
double W2[2],
double W3[2],
double P1[2],
double P2[2],
double P3[2],
MTR2x2 &A,
VECT2 &B)
{
    double Xwe1=W1[0],Ywe1=W1[1];
    double Xwe2=W2[0],Ywe2=W2[1];
    double Xwe3=W3[0],Ywe3=W3[1];

    double Xwy1=P1[0],Ywy1=P1[1];
    double Xwy2=P2[0],Ywy2=P2[1];
    double Xwy3=P3[0],Ywy3=P3[1];

    double W=Xwy1*Ywy2+Ywy1*Xwy3+Xwy2*Ywy3-Ywy2*Xwy3-Xwy1*Ywy3-Ywy1*Xwy2;

    if(W!=0)
    {
      A.a11=(Xwe1*Ywy2+Ywy1*Xwe3+Xwe2*Ywy3-Ywy2*Xwe3-Xwe1*Ywy3-Ywy1*Xwe2)/W;
      A.a12=(Xwy1*Xwe2+Xwe1*Xwy3+Xwy2*Xwe3-Xwe2*Xwy3-Xwy1*Xwe3-Xwe1*Xwy2)/W;
      B.b1=(Xwy1*Ywy2*Xwe3+Ywy1*Xwe2*Xwy3+Xwe1*Xwy2*Ywy3-Xwe1*Ywy2*Xwy3-Xwy1*Xwe2*Ywy3-Ywy1*Xwy2*Xwe3)/W;

      A.a21=(Xwe1*Ywy2+Ywy1*Ywe3+Ywe2*Ywy3-Ywy2*Ywe3-Ywe1*Ywy3-Ywy1*Ywe2)/W;
      A.a22=(Xwy1*Ywe2+Ywe1*Xwy3+Xwy2*Ywe3-Ywe2*Xwy3-Xwy1*Ywe3-Ywe1*Xwy2)/W;
      B.b2=(Xwy1*Ywy2*Ywe3+Ywy1*Ywe2*Xwy3+Ywe1*Xwy2*Ywy3-Ywe1*Ywy2*Xwy3-Xwy1*Ywe2*Ywy3-Ywy1*Xwy2*Ywe3)/W;
      return 1;
    }
    else
      return 0;
}




void Przeksztalcenie::Funkcja()
{
    float px,py,alfa,beta;
    int x,y;
    int r0,g0,b0,r1,g1,b1,r2,g2,b2,r3,g3,b3;
    RGBQUAD RGB,RGB1,RGB2,rgb0,rgb1,rgb2,rgb3;

    for(int i=0;i<ImgWy->szerokosc;i++)
        for(int j=0;j<ImgWy->wysokosc;j++)
            {
            px=A.a11*i+A.a12*j+B.b1;
            py=A.a21*i+A.a22*j+B.b2;

            x=px;
            y=py;
            alfa=px-x;
            beta=py-y;
            beta=0.5;

            if(px>=0 && py>=0 && px<=ImgWe->szerokosc-1 && py<=ImgWe->wysokosc-1)
                {

                rgb0=ImgWe->PobierzPixel(x,y);
                r0=rgb0.rgbRed; g0=rgb0.rgbGreen; b0=rgb0.rgbBlue;

                rgb1=ImgWe->PobierzPixel(x+1,y);
                r1=rgb1.rgbRed; g1=rgb1.rgbGreen; b1=rgb1.rgbBlue;

                rgb2=ImgWe->PobierzPixel(x+1,y+1);
                r2=rgb2.rgbRed; g2=rgb2.rgbGreen; b2=rgb2.rgbBlue;

                rgb3=ImgWe->PobierzPixel(x,y+1);
                r3=rgb3.rgbRed; g3=rgb3.rgbGreen; b3=rgb3.rgbBlue;

                RGB1.rgbRed=r0*(1-alfa)+r1*alfa;
                RGB2.rgbRed=r3*(1-alfa)+r2*alfa;

                RGB1.rgbGreen=g0*(1-alfa)+g1*alfa;
                RGB2.rgbGreen=g3*(1-alfa)+g2*alfa;

                RGB1.rgbBlue=b0*(1-alfa)+b1*alfa;
                RGB2.rgbBlue=b3*(1-alfa)+b2*alfa;

                RGB.rgbRed=RGB1.rgbRed*(1-beta)+RGB2.rgbRed*beta;
                RGB.rgbGreen=RGB1.rgbGreen*(1-beta)+RGB2.rgbGreen*beta;
                RGB.rgbBlue=RGB1.rgbBlue*(1-beta)+RGB2.rgbBlue*beta;

                ImgWy->UstawPixel(i,j,RGB);
                }
            }

    ImgWy->ZapiszObraz();
}
