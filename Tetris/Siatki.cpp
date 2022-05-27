#include "Siatki.h"
 
void Kopiuj_tablice(int t1[4][4][4],int t2[4][4][4],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                    t1[i][j][k]=t2[i][j][k];     
}

int klocek1[4][4][4]={
{{1,0,0,0},
 {1,0,0,0},
 {1,0,0,0},
 {1,0,0,0}},
{{1,1,1,1},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}}};
 
int klocek2[4][4][4]={
{{0,1,0,0},
 {0,1,0,0},
 {1,1,0,0},
 {0,0,0,0}},
{{1,0,0,0,},
 {1,1,1,0},
 {0,0,0,0},
 {0,0,0,0}},
{{1,1,0,0},
 {1,0,0,0},
 {1,0,0,0},
 {0,0,0,0}},
{{1,1,1,0},
 {0,0,1,0},
 {0,0,0,0},
 {0,0,0,0}}};
 
int klocek3[4][4][4]={
{{1,0,0,0},
 {1,0,0,0},
 {1,1,0,0},
 {0,0,0,0}},
{{1,1,1,0},
 {1,0,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{1,1,0,0},
 {0,1,0,0},
 {0,1,0,0},
 {0,0,0,0}},
{{0,0,1,0},
 {1,1,1,0},
 {0,0,0,0},
 {0,0,0,0}}};
 
int klocek4[4][4][4]={
{{1,1,0,0},
 {1,1,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}}};

int klocek5[4][4][4]={
{{0,1,0,0},
 {1,1,1,0},
 {0,0,0,0},
 {0,0,0,0}},
{{1,0,0,0},
 {1,1,0,0},
 {1,0,0,0},
 {0,0,0,0}},
{{1,1,1,0},
 {0,1,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,1,0,0},
 {1,1,0,0},
 {0,1,0,0},
 {0,0,0,0}}};
 
int klocek6[4][4][4]={
{{1,1,0,0},
 {0,1,1,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,1,0,0},
 {1,1,0,0},
 {1,0,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}}};
 
int klocek7[4][4][4]={
{{0,1,1,0},
 {1,1,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{1,0,0,0},
 {1,1,0,0},
 {0,1,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}},
{{0,0,0,0},
 {0,0,0,0},
 {0,0,0,0},
 {0,0,0,0}}};