#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int signal[100],signal2[100],n[100],n2[100];
int range,start,opt,k,indx;

//Helper functions to perform Signal Operations
void print(){
	for(int i = 0;i<range;i++)printf("\tx(%d)\t",n[i]);
	printf("\n");
	for(int i = 0;i<range;i++)printf("\t%d\t",signal[i]);
}

int findindex(int val){
	for(int i = 0;i<range;i++){
		if(n[i]==val) return i;
		if(n[i]>val) return -1;
	}
	return -1;
}

void reverse(){
	int x,y;
	for(int i = 0;i<range/2;i++){
		x = n[i];
		n[i] = n[range-i-1];
		n[range-i-1] = x;

		x = signal[i];
		signal[i] = signal[range-i-1];
		signal[range-i-1] = x;
	}
}

void arraycopy(){
	for(int i = 0;i<range;i++){
		n[i] = n2[i];
		signal[i] = signal2[i];
	}
}

void main(){
	//Taking signal as an input from user
	printf("Enter the range and start of the signal\n");
	scanf("%d%d",&range,&start);

	printf("Enter the values of the signal\n");
	for(int i = 0;i<range;i++,start++){
		scanf("%d",&signal[i]);
		n[i] = start;
	}

	printf("Entered signal :\n");
	print();

	while(1){
		start = n[0];
		printf("\nPress 1 for time delay\nPress 2 for time advance\nPress 3 for folding\nPress 4 for time scaling\nPress 5 to exit\n");
		scanf("%d",&opt);
		if(opt==5) break;
		switch(opt){
			//Delayed Time Signal
			case 1: printf("Enter value of k (k is +ve) : ");
					scanf("%d",&k);
					printf("Performing DELAY OPERATION x(n) = x(n-%d)\n",k);
					for(int i = 0;i<range;i++)
						n[i] += k;
					print();
					break;
			//Advanced Time Signal
			case 2: printf("Enter value of k (k is -ve) : ");
					scanf("%d",&k);
					printf("Performing ADVANCE OPERATION x(n) = x(n+%d)\n",k);
					for(int i = 0;i<range;i++)
						n[i] += k;
					print();
					break;
			//Folded Time Signal a.k.a Reflection
			case 3: printf("Performing FOLDING OPERATION x(n) = x(-n)\n");
					for(int i = 0;i<range;i++)
						n[i] *= -1;
					reverse();
					print();
					break;
			//Time Scaled Signal a.k.a Downsampling
			case 4: printf("Enter value of k : ");
					scanf("%d",&k);
					printf("Performing TIME SCALING OPERATION x(n) = x(%dn)\n",k);
					int ptr = 0;
					for(int i = 0;i<range;i++){
						indx = findindex(k*n[i]);
						if(indx!=-1){
							signal2[ptr] = signal[indx];
							n2[ptr] = n[i];
							ptr++;
						}
					}
					range = ptr;
					memset(signal, 0, sizeof(signal));
					memset(n,0,sizeof(n));
					arraycopy();
					print();
					break;

			default : printf("Please enter correct option value");
		}
	}
}
