#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
//#include<gsl/gsl_sf_log.h>
#include<gsl/gsl_math.h>

double zeta_der_real(double, double *, double *, int );

double VfB(double eB, double Mf, double Lambda, double qf, double *x_ptr, double *y_ptr, int N_dat)
{
	printf("-------In VfB.c ---------\n");
	
	double t1 = (gsl_pow_2(Mf)/4.) * (1.0 - 2.0 * log(Mf/Lambda) );

	double tau = gsl_pow_2(Mf) / (2.0*qf*eB);

	double hz = -0.5*( (1./6) - tau + gsl_pow_2(tau));

	//Range checking of data

	//printf("tau from VfB.c = %lf\n", tau);

	if(tau > x_ptr[N_dat -1] || tau < x_ptr[0])
	{
		printf("argument of zeta_der_real (tau) = %lf\n",tau);
		printf("Error from module zeta_der_real! Interpolation data is out of range!\n");
		exit(1);
	}

	double t2 = (hz * (1. - log( (2*qf*eB)/gsl_pow_2(Lambda)) ) ) + zeta_der_real(tau, x_ptr, y_ptr, N_dat);

	double ans = 0.5*qf*eB*gsl_pow_2(M_1_PI)*( t1 - (qf*eB*t2) );

	//printf("%lf\n",zeta_der(y));

	printf("-------Out VfB.c ---------\n");

	return ans;

}