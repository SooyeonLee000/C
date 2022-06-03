#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int N,deg, i, j, k, check_saturation ;
	N=8, deg = 3;
	int A[N][deg];
	double R[N][deg], numerator, denominator;
	double V[N], prev_V[N];	
	A[0][0] = 1 ,A[0][1] = 3 ,A[0][2] = 7 ;
	A[1][0] = 0 ,A[1][1] = 2 ,A[1][2] = 4 ;
	A[2][0] = 1 ,A[2][1] = 3 ,A[2][2] = 5 ;
	A[3][0] = 0 ,A[3][1] = 2 ,A[3][2] = 6 ;
	A[4][0] = 1 ,A[4][1] = 5 ,A[4][2] = 7 ;
	A[5][0] = 2 ,A[5][1] = 4, A[5][2] = 6 ;
	A[6][0] = 3 ,A[6][1] = 5 ,A[6][2] = 7 ;
	A[7][0] = 0 ,A[7][1] = 4 ,A[7][2] = 6 ;
	
	R[0][0] = 1 ,R[0][1] = 2 ,R[0][2] = 1 ;
	R[1][0] = 1 ,R[1][1] = 2 ,R[1][2] = 1 ;
	R[2][0] = 2 ,R[2][1] = 1 ,R[2][2] = 1 ;
	R[3][0] = 2 ,R[3][1] = 1 ,R[3][2] = 1 ;
	R[4][0] = 1 ,R[4][1] = 2 ,R[4][2] = 1 ;
	R[5][0] = 1 ,R[5][1] = 2 ,R[5][2] = 1 ;
	R[6][0] = 1 ,R[6][1] = 1 ,R[6][2] = 2 ;
	R[7][0] = 1 ,R[7][1] = 1 ,R[7][2] = 2 ;
	
	V[0] = 1, V[N-1] = 0;
	
	for(i=1; i<N-1; i++)
	{	
		V[i] = 1.0;
		prev_V[i] = 1.0;
	}
	
	while(1)
	{
		for(i=1;i<N-1;i++)
		{
			numerator = 0;
			denominator = 0;
			for(k=0; k<deg; k++)
			{
				numerator = numerator + V[A[i][k]]/R[i][k];
				denominator = denominator + 1.0/R[i][k];
			}
			V[i] = numerator/denominator ; 
		} 
		
		check_saturation = 0;
		
		for(i=1;i<N-1;i++)
		{
			if(fabs(V[i]-prev_V[i]) > 10e-8)
			check_saturation = 1 ;  
		}

		if(check_saturation == 0 )
			break;

		for(i=1; i<N-1; i++)
		{
			prev_V[i] = V[i];
		}
	
	}
 	double X,Y;
		X =0,Y=0;	
	for(i=0; i<N; i++)
	{
		printf("V[%d]=%f\n",i,V[i]);
	}
	for(i=0; i<deg; i++)
	{	
		printf("0 to %d : %f\n",A[0][i],(-V[A[0][i]]+V[0])/R[0][i]);
		X = X + (-V[A[0][i]]+V[0])/R[0][i];
	}
	for(i=0; i<deg; i++)
         {     
		 printf("%d to 7 : %f\n",A[7][i],(+V[A[7][i]]-V[7])/R[7][i]);
         }
	printf("composite resistance between 0 and 7 : %f\n",1.0/X);


	return 0 ; 

}
