#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>
#include<gsl/gsl_math.h>

double Vb(double msq, double Lambda)
{
	printf("-----In Vb.c ------\n");
	complex double ans; 
	
	
	ans = ( gsl_pow_2(msq * M_1_PI) / 64.0 ) * (clog(msq/gsl_pow_2(Lambda) ) -1.5);

	printf("-----out Vb.c ------\n");
	
	return creal(ans);

}
