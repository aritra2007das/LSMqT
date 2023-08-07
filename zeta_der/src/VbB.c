#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
//#include<complex.h>
#include<gsl/gsl_math.h>
#include "../include/myheaders.h"

double VbB(double eB, double msq, double Lambda)
{
	
	double y = 0.5*(1.0 + (msq / eB) );

	double hz = -0.5*( (1./6) - y + gsl_pow_2(y));

	double f = hz * (1. - log( (2*eB)/gsl_pow_2(Lambda)) );

	//printf("%lf\n",zeta_der(y));
	double y_min, y_max;
	y_min = -3.6; y_max = 5.0;
	if(y > y_max || y < y_min)
	{
		printf("%lf\n",y);
		printf("Error from module zeta_der_real! Interpolation data is out of range!\n");
		exit(1);
	}

	double ans = (1./8.) * gsl_pow_2(eB*M_1_PI) * ( f + zeta_der_real(y) );
	
	return ans;

}