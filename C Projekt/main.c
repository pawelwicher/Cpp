#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

char* Fun(char* s1, char* s2)
{
  char *a = s1, *b = s2, *c, *ret;
  int len = 0;
  
  while(*a++)
    len++;
  while(*b++)
    len++;    
    
  c = malloc(len * sizeof(char));
  ret = c;
  
  while(*c++ = *s1++);
  c--;
  while(*c++ = *s2++);
  
  return ret;
}

void F(int** i)
{
  *i = (*i) + 1;
}

typedef struct
{
    int i;
    double d;
} unia;

double sum(int num, ...)
  {
    double sum=0.0, t;
    va_list argptr;
    va_start(argptr, num);
    
    for( ; num; num--)
    {
      t = va_arg(argptr, double);
      sum += t;
    }
    va_end(argptr);
    return sum;
  }
  
typedef struct
{
  int id;
  char nazwisko[40];
} osoba;

typedef struct
{
  int i:1;
} test;



int main(int argc, char *argv[])
{
  /*
  char text1[] = "hello world";
  char text2[] = " from simple C program";
  char* c = Fun(text1, text2);
  printf("%s\n", c);
  free(c);
  
  
  char t[4][3] = {
                       {'1','2','3'},
                       {'4','5','6'},
                       {'7','8','9'},
                       {'a','b','c'},
                     };
  int i=0,j=0;
  for(i = 0; i < 4; i++)
  {
    for(j = 0; j < 3; j++)
    {
      printf("%c ", *(*(t + i) + j));
    }
    printf("\n");
  }
  
  printf("%f\n", sum(3,1.3,4.6,2.5));
  
  
  osoba o1 = {1, "Kowalski"};
  osoba o2 = {2, "Nowak"};
  osoba a,b;
  FILE *fp;

  if((fp=fopen("test.txt", "r"))==NULL)
  {
    printf("IO error\n");
    exit(1);
  }

  fread(&a, sizeof(osoba), 1, fp);
  fread(&b, sizeof(osoba), 1, fp);
  fclose(fp);
  
  printf("%d. %s\n", a.id, a.nazwisko); 
  printf("%d. %s\n", b.id, b.nazwisko); 
  char tpl[255]; 
  char* p; 
  FILE *fp;

  if((fp=fopen("test1.txt", "r"))==NULL)
  {
    printf("IO error\n");
    exit(1);
  }  
  fread(&tpl, sizeof(tpl), 1, fp);
  fclose(fp);
  
  p = strchr(tpl, '#');
  *p = '\0';

  if((fp=fopen("test2.txt", "w"))==NULL)
  {
    printf("IO error\n");
    exit(1);
  }
  fprintf(fp, tpl, "Pawel", "Wicher");
  fclose(fp);
  */
  test t = {1};
 
  
  printf("%d\n", sizeof t);
  system("PAUSE");	
  return 0;
}
