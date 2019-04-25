#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct number{
  double real;
  double img;
} number;

number x[100];

void print(number a, char* s){
  printf("%s : (%.4f)+j(%.4f)\n",s,a.real,a.img);
}

number multiply(number a, number b){
  number temp;
  temp.real = a.real*b.real - a.img*b.img;
  temp.img  = a.real*b.img + a.img*b.real;
  return temp;
}

number add(number a, number b){
  number temp;
  temp.real = a.real + b.real;
  temp.img  = a.img + b.img;
  return temp;
}

number sub(number a, number b){
  number temp;
  temp.real = a.real - b.real;
  temp.img  = a.img - b.img;
  return temp;
}

number W(double N, double E){
  number temp;
  temp.real = cos(2*3.14*E/N);
  temp.img = -sin(2*3.14*E/N);
  return temp;
}

void main(){

  printf("\n\nN/2 point DFT\n\n");

  number w20 = W(2,0);
  print(w20,"W2 ** 0");
  number w40 = W(4,0);
  print(w40,"W4 ** 0");
  number w42 = W(4,2);
  print(w42,"W4 ** 2");
  number w80 = W(8,0);
  print(w80,"W8 ** 0");
  number w81 = W(8,1);
  print(w81,"W8 ** 1");
  number w82 = W(8,2);
  print(w82,"W8 ** 2");
  number w83 = W(8,3);
  print(w83,"W8 ** 3");

}
