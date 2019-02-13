#include <stdio.h>
#include <stdlib.h>
int h[100],x[100],nx[100],nh[100];
int rangex,rangeh,startx,starth;
void print(int signal[],int n[],char* s,int range){
	for(int i = 0;i<range;i++)printf("\t\t%s(%d) = %d\n",s,n[i],signal[i]);
}
int findindex(int k, int n[], int range){
	for(int i = 0;i<range;i++){
		if(n[i]==k) return i;
		if(n[i]>k) return -1;
	}
	return -1;
}
void rotate(int x[], int range){
	int temp = x[range-1];
	for(int i = range-2;i>=0;i--)x[i+1] = x[i];
	x[0] = temp;
}
void main(){
	printf("Enter the range and start of the signal x[n]\n");
	scanf("%d%d",&rangex,&startx);
	printf("Enter the values of the signal x[n]\n");
	for(int i = 0;i<rangex;i++,startx++){
		scanf("%d",&x[i]);
		nx[i] = startx;
	}
	startx = nx[0];
	printf("Signal x[n] :\n");
	print(x,nx,"x",rangex);
	printf("Enter the range and start of the signal h[n]\n");
	scanf("%d%d",&rangeh,&starth);
	printf("Enter the values of the signal h[n]\n");
	for(int i = 0;i<rangeh;i++,starth++){
		scanf("%d",&h[i]);
		nh[i] = starth;
	}
	starth = nh[0];
	printf("Signal h[n] :\n");
	print(h,nh,"h",rangeh);
	printf("\nLinear Convolution y[n] :\n");
	for(int y = startx+starth;y<(startx+starth+rangex+rangeh-1);y++){
		int temp = 0,a = 0,b = 0;
		for(int k = startx+starth;k<(startx+starth+rangex+rangeh-1);k++){
			a = ((k<(startx+rangex))&&(k>=startx))?x[findindex(k,nx,rangex)]:0;
			b = ((y-k<(starth+rangeh))&&(y-k>=starth))?h[findindex(y-k,nh,rangeh)]:0;
			temp += a*b;
		}
		printf("\t\t\ty(%d) = %d\n",y,temp);
	}
	int diff = abs(rangex-rangeh);
	while(diff>0){
		if(rangex<rangeh){
			x[rangex] = 0;
			rangex++;
		}
		else{
			h[rangeh]=0;
			rangeh++;	
		}
		diff--;
	}
	int c[rangex][rangex];
	for(int j = 0;j<rangex;j++){
		for(int k=0;k<rangex;k++)c[k][j] = x[k];
		rotate(x,rangex);
	}
	printf("\nCircular Convolution y[n] :\n");
	for(int i = 0;i<rangex;i++){
		int temp = 0;
		for(int j = 0;j<rangex;j++)temp += c[i][j]*h[j];
		printf("\t\t\ty(%d) = %d\n",i,temp);
	}
}
