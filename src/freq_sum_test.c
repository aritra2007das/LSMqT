#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI 4.0*atan(1.0)

double f_exact(double tau, double T, double E)
{
	double nB = 1.0/(exp(E/T)-1.0);

	return (1.0/ (2.0*E)) * ( (1.0 + nB)*exp(-E*tau) + nB*exp(E*tau)); 
}

double freq_sum(double tau, double T, double E, int Nmax)
{
	complex double sum = 0. + 0. * I;

	for (int n = -Nmax; n <= Nmax; ++n)
	{
		/* code */

		sum = sum + ( (cexp(-( 0.0 + (2.0*PI*n*T*tau) * I ) ))*(1.0 / ( pow(2.0*PI*n*T,2) + pow(E,2) ) ) );

	}

	return T*creal(sum);
}

int main()
{
	int Nmax = 2000;

	printf("%lf\t%lf\n",f_exact(0.0,0.14,0.3), freq_sum(0.0,0.14,0.3,Nmax));

	return 0;
}