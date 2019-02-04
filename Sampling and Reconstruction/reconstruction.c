#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Created by Rebecca D'souza on 23-01-19
void main() {
	double A,f,F,X,f1,t,opt;
	// Taking in input of ampliture and frequency for an analog signal defined with cosine function.
	printf("Enter amplitude(A) and frequency(f) of the analog signal, where equation of the signal is x(t) = Acos(f*3.14*t)\n");
	scanf("%lf%lf",&A,&f);
	while(1){
		// Taking in sampling frequency for sampling and reconstruction of analog signal.
		printf("\nEnter sampling frequency : ");
		scanf("%lf",&F);
		printf("\nSampling at F = %.2lfHz\n\n",F);
		X = f/F;
		while(X>2 || abs(2-X)<X) X = 2.00-X;
		f1 = X*F;
		// Printing the equations for analog, digital and reconstructed analog signal after sampling.
		printf("\tx(t)  = %.0lfcos(%.2lf*3.14*t) i.e. %.0lfcos(%.2lft)\n\n",A,f,A,f*3.14);
		printf("\tx(n)  = %.0lfcos(%.2lf*3.14*n) i.e. %.0lfcos(%.2lfn)\n\n",A,X,A,X*3.14);
		printf("\tx'(t) = %.0lfcos(%.2lf*3.14*t) i.e. %.0lfcos(%.2lft)\n\n",A,f1,A,f1*3.14);
		// Printing table of values of original analog signal and reconstructed analog signal with randome values for t.
		printf("\t---------------------\n");
		printf("\tt\tx(t1)\tx'(t)\n");
		printf("\t---------------------\n");
		for(int i = 0;i<3;i++){
			t = (double)rand()/(double)RAND_MAX;
			printf("\t%.2lf\t%.2lf\t%.2lf\n",t,A*cos(f*3.14*t),A*cos(f1*3.14*t));
		}
		printf("\t---------------------\n");
		// Printing whether the analog signal was correctly resampled or if aliasing took place.
		if(f>f1) printf("\nEntered sampling frequency is lesser than the minimum sampling frequency hence recovery not possible and x(t)!=x'(t)\n\n");
		else printf("\nEntered sampling frequency is not lesser than the minimum sampling frequency hence recovery is possible and x(t)=x'(t)\n\n");
		// Presenting option to sample signal at a different sampling frequency or to exit program.
		printf("\nPress 1 to enter another sampling frequency\nPress 2 to exit\n");
		scanf("%lf",&opt);
		if(opt==2) break;
	}
	// Printing minimum sampling rate to avoid aliasing and perform accurate reconstruction.
	printf("\nMinimum sampling rate to avoid aliasing = %.2lf\n\n",f);
}
