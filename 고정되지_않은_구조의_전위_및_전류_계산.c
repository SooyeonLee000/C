#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int L,N,deg, i, j, k, check_saturation ;
	deg = 3;

	N = 2*L;

	printf("Input L: ");
	scanf("%d", &L);

	int R,A[N][deg];
	double  numerator, denominator;
	double V[N], prev_V[N];	

	
 	 for(i=1; i< L-1; i++)
          {
                  A[i][0] = i-1;
                  A[i][1] = i+1;
                  A[i][2] = i+L;
          }
         for(i=L+1; i<2*L-1; i++)
          {
                 A[i][0] = i-L;
                 A[i][1] = i-1;
                 A[i][2] = i+1;
         }
	
	A[0][0] = 1, A[0][1] = L-1, A[0][2] = L;
	A[L-1][0] = 0, A[L-1][1] =L-2, A[L-1][2] = N-1;
	A[L][0] = 0, A[L][1] = L+1, A[L][2] = N-1;
	A[N-1][0] = L-1, A[N-1][1] = L, A[N-1][2] = N-2;
	
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
                                 numerator = numerator + V[A[i][k]];
                                 denominator = denominator + 1.0;
                         }
                         V[i] = numerator/denominator ;
		}

		check_saturation = 0;

		for(i=1; i<N-1; i++)
		{
		 	if(fabs(V[i]-prev_V[i])>1e-8)
				check_saturation = 1;
		}

		if(check_saturation == 0)
			break;

		for(i=1; i<N-1; i++)
			prev_V[i] = V[i];

		}
				

	for(i=0; i<N; i++)
	{
		printf("V[%d]=%f\n",i,V[i]);
	}
	for(i=0; i<deg; i++)

	{	
		printf("0 to %d : %f\n",A[0][i],(-V[A[0][i]]+V[0]));
	}

	for(i=0; i<deg; i++)
	 {     
		 printf("%d to %d : %f\n",A[N-1][i],N-1,(+V[A[N-1][i]]-V[N-1]));
         }

	double X;
	X=0;

	for(i=0; i<deg; i++)
	{
		X = X + (-V[A[0][i]]+V[0]);
	}

	printf("composite resistance between 0 and %d : %f\n",N-1,1.0/X);

	return 0 ; 

}
