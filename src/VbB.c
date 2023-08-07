#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
//#include<complex.h>
#include<gsl/gsl_math.h>

double zeta_der_real(double , double *, double *, int);

double VbB(double eB, double msq, double Lambda, double *x_ptr, double *y_ptr, int N_dat)
{
	printf("-------In VbB.c ---------\n");
	double tau = 0.5*(1.0 + (msq / eB) );

	double hz = -0.5*( (1./6) - tau + gsl_pow_2(tau));

	double f = hz * (1. - log( (2*eB)/gsl_pow_2(Lambda)) );

	//printf("%lf\n",zeta_der(y));

	//Range checking of data

	//printf("tau from VbB.c = %lf\n", tau);

	if(tau > x_ptr[N_dat - 1] || tau < x_ptr[0])
	{
		printf("argument of zeta_der_real (tau) = %lf\n",tau);
		printf("Error from module zeta_der_real! Interpolation data is out of range!\n");
		exit(1);
	}

	double ans = (1./8.) * gsl_pow_2(eB*M_1_PI) * ( f + zeta_der_real(tau, x_ptr, y_ptr, N_dat) );
	printf("-------Out VbB.c ---------\n");
	
	return ans;

}
