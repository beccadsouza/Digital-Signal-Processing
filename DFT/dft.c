#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct number{
  double real;
  double img;
} number;
number x[100];
number X[100];
int N;
void print(number x[], char* s){
	for(int i = 0;i<N;i++)
    printf("\t\t%s(%d) = %lf + j(%lf)\n",s,i,x[i].real,x[i].img);
}
number multiply(number a, number b){
  number temp;
  temp.real = a.real*b.real - a.img*b.img;
  temp.img  = a.real*b.img + a.img*b.real;
  return temp;
}
void main(){
  printf("Enter the range of signal x[n], N \n");
	scanf("%d",&N);
	printf("Enter the values of the signal x[n]\n");
	for(int i = 0;i<N;i++)
		scanf("%lf",&x[i].real);
  print(x,"x");
  for(int k = 0;k<N;k++){
    for(int n = 0;n<N;n++){
      X[k].real += x[n].real*cos(2*3.14*k*n/N);
      X[k].img += -x[n].real*sin(2*3.14*k*n/N);
    }
  }
  printf("\nFOURIER TRANSFORM : \n");
  print(X,"X");
  for(int n = 0;n<N;n++){
    x[n].img = 0;
    x[n].real = 0;
    for(int k = 0;k<N;k++){
      number e;
      e.real = cos(2*3.14*k*n/N);
      e.img  = sin(2*3.14*k*n/N);
      number t = multiply(e,X[k]);
      t.real /= (double)N;
      t.img  /= (double)N;
      x[n].real += t.real;
      x[n].img += t.img;
    }
  }
  printf("\nINVERSE FOURIER TRANSFORM : \n");
  print(x,"x");
}
