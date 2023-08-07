#include<stdio.h>
#include<math.h>
#include<gsl/gsl_math.h>
#include<gsl/gsl_integration.h>

struct params {double omega_n; double kz; double k_perp; double eB; double m;};

static double my_func(double s, void * p)
{
	struct params * poin = (struct params *) p;

	double omega_n = (poin -> omega_n);

	double kz = (poin -> kz);

	double k_perp = (poin -> k_perp);

	double eB = (poin -> eB);

	double m = (poin -> m);

	double ans;

	ans = (1.0/cosh(eB*s))*exp(-s*( gsl_pow_2(omega_n) + gsl_pow_2(kz) + gsl_pow_2(m) ) 
		- (tanh(eB*s)/eB)*gsl_pow_2(k_perp));

	return ans;
}

double scalar_propagator_B_proper_time(double omega_n, double kz, double k_perp, double eB, double m)
{
	struct params my_params = {omega_n, kz, k_perp, eB, m};

	gsl_function F;

	F.function = &my_func;

	F.params = &my_params;

	double tol = 1e-8;
	double epsabs =0.0;
	double result, error, Delta_B;

	size_t n = 1000;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(n);

	gsl_integration_qagiu(&F, 0.0, epsabs, tol, n, w, &result, &error);

	Delta_B = result;

	//printf("status = %d\n", status);

	gsl_integration_workspace_free(w);

	return Delta_B; 	
}