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
  int N;
  printf("Enter the range of signal x[n], N \n");
	scanf("%d",&N);
	printf("Enter the values of the signal x[n]\n");
	for(int i = 0;i<N;i++)scanf("%lf",&x[i].real);

  printf("\n\nN/4 point DFT\n\n");
  number v_11_0 = add(x[0],multiply(x[4],W(2,0)));
  print(v_11_0,"v11(0)");
  number v_11_1 = sub(x[0],multiply(x[4],W(2,0)));
  print(v_11_1,"v11(1)");

  number v_12_0 = add(x[2],multiply(x[6],W(2,0)));
  print(v_12_0,"v12(0)");
  number v_12_1 = sub(x[2],multiply(x[6],W(2,0)));
  print(v_12_1,"v12(1)");

  number v_21_0 = add(x[1],multiply(x[5],W(2,0)));
  print(v_21_0,"v21(0)");
  number v_21_1 = sub(x[1],multiply(x[5],W(2,0)));
  print(v_21_1,"v21(1)");

  number v_22_0 = add(x[3],multiply(x[7],W(2,0)));
  print(v_22_0,"v22(0)");
  number v_22_1 = sub(x[3],multiply(x[7],W(2,0)));
  print(v_22_1,"v22(1)");

  printf("\n\nN/2 point DFT\n\n");

  number F_1_0 = add(v_11_0,multiply(W(4,0),v_12_0));
  print(F_1_0,"F1(0)");
  number F_1_2 = sub(v_11_0,multiply(W(4,0),v_12_0));
  print(F_1_2,"F1(2)");

  number F_1_1 = add(v_11_1,multiply(W(4,1),v_12_1));
  print(F_1_1,"F1(1)");
  number F_1_3 = sub(v_11_1,multiply(W(4,1),v_12_1));
  print(F_1_3,"F1(3)");

  number F_2_0 = add(v_21_0,multiply(W(4,0),v_22_0));
  print(F_2_0,"F2(0)");
  number F_2_2 = sub(v_21_0,multiply(W(4,0),v_22_0));
  print(F_2_2,"F2(2)");

  number F_2_1 = add(v_21_1,multiply(W(4,1),v_22_1));
  print(F_2_1,"F2(1)");
  number F_2_3 = sub(v_21_1,multiply(W(4,1),v_22_1));
  print(F_2_3,"F2(3)");

  printf("\n\nN point DFT\n\n");
  number X_0 = add(F_1_0,multiply(W(8,0),F_2_0));
  print(X_0,"X(0)");
  number X_4 = sub(F_1_0,multiply(W(8,0),F_2_0));
  print(X_4,"X(4)");

  number X_1 = add(F_1_1,multiply(W(8,1),F_2_1));
  print(X_1,"X(1)");
  number X_5 = sub(F_1_1,multiply(W(8,1),F_2_1));
  print(X_5,"X(5)");

  number X_2 = add(F_1_2,multiply(W(8,2),F_2_2));
  print(X_2,"X(2)");
  number X_6 = sub(F_1_2,multiply(W(8,2),F_2_2));
  print(X_6,"X(6)");

  number X_3 = add(F_1_3,multiply(W(8,3),F_2_3));
  print(X_3,"X(3)");
  number X_7 = sub(F_1_3,multiply(W(8,3),F_2_3));
  print(X_7,"X(7)");
}
