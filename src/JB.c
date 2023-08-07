#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_math.h>
#include<gsl/gsl_sf_psi.h>
#include<gsl/gsl_sf_gamma.h>
#include<gsl/gsl_integration.h>

struct my_params {double eB; double p0; double m;};

static double my_func (double x, void * p)
{

	struct my_params * poin = (struct my_params *) p;

	double eB = (poin -> eB);

	double p0 = (poin -> p0);

	double m = (poin -> m);

	double f = gsl_sf_psi(0.5 + (( gsl_pow_2(m) - x*(1.0 -x)*gsl_pow_2(p0) ) / (2.0*eB)) );

	return f;
}

double JB(double eB, double p0, double m)
{
	printf("----In JB.c-------\n");
	struct my_params params = {eB, p0, m};

	gsl_function F;

	F.function = &my_func;

	F.params = &params;

	double result, error;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(100);

	gsl_integration_qags (&F, 0., 1., 0, 1e-8, 100, w, &result, &error);

	double d = ((4.0*gsl_pow_2(m))/(gsl_pow_2(p0))) -1.0;

	double f = log(gsl_pow_2(m)/(2.0*eB)) + 2.0 * sqrt(d)* atan(1./sqrt(d)) - 2.0 - result;

	printf("----Out JB.c-------\n");

	return (gsl_pow_2(M_1_PI)/16.0) * f;

}