#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
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
	//CORRELATION	
	
	printf("\nCorrelation y[n] :\n");
	int high = startx+rangex-1-starth;
	int low = -(starth+rangeh-1)+startx;
	for(int l = low;l<high+1;l++){	
		int temp = 0,a,b;
		for(int n = min(startx,starth);n<max(startx+rangex,starth+rangeh)+1;n++){
			a = ((n<(startx+rangex))&&(n>=startx))?x[findindex(n,nx,rangex)]:0;
			b = ((n-l<(starth+rangeh))&&(n-l>=starth))?h[findindex(n-l,nh,rangeh)]:0;
			temp += a*b;
		}
		printf("\t\t\ty(%d) = %d\n",l,temp);
	}
	
	// COEFFICIENT OF CORRELATION
	int h = max(startx+rangex,starth+rangeh), l = min(startx,starth);
	double mx=0,mh=0,sumx=0,sumh=0,num=0;
	for(int i = 0;i<rangex;i++)mx += nx[i];
	for(int i = 0;i<rangeh;i++)mh += nh[i];
	mh /= h-l+1;
	mx /= h-l+1;
	
	for(int i = 0;i<rangex;i++)sumx += (nx[i]-mx)*(nx[i]-mx);
	for(int i = 0;i<rangeh;i++)sumh += (nh[i]-mh)*(nh[i]-mh);
	sumh /= h-l+1;
	sumx /= h-l+1;
	
	for(int i = h;i<l;i++){
		int a = ((i<(startx+rangex))&&(i>=startx))?x[findindex(i,nx,rangex)]:0;
	    int b = ((i<(starth+rangeh))&&(i>=starth))?h[findindex(i,nh,rangeh)]:0;
		num += (a-mx)*(0-mh);
	}
	num /= h-l+1;
	printf("%.2lf",num/(sqrt(sumh)*sqrt(sumx)));
}








