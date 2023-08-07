#include<math.h>
#include<gsl/gsl_sf_laguerre.h>
#include<gsl/gsl_math.h>

double scalar_propagator_B(double omega_n, double kz, double k_perp, double eB, double m, int lmax)
{
	double sum = 0.0;

	double E_2;

	double alpha = pow(k_perp,2)/eB;

	for(int l = 0; l <= lmax; l++)
	{
		E_2 = gsl_pow_2(kz) + (2*l+1) * eB + gsl_pow_2(m);

		sum = sum + ( (pow(-1,l)*gsl_sf_laguerre_n(l, 0.0, 2.0*alpha)) / ( gsl_pow_2(omega_n) + E_2) );
	}
	
	double Delta_B = 2.0 * (1.0 + gsl_expm1(-alpha) ) * sum;

	return Delta_B; 

	
}