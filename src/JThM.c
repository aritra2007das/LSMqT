#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_math.h>

struct my_params {double eB; double p0; int l; double beta; double m;};

static double my_func(double x, void * p)
{
	struct my_params * poin = (struct my_params *) p;

	double eB = (poin -> eB);

	double p0 = (poin -> p0);

	int l = (poin -> l);

	double beta = (poin -> beta);

	double m = (poin -> m);

	double E, f, nB;

	E = sqrt(gsl_pow_2(x) + gsl_pow_2(beta)*((2*l+1)*eB + gsl_pow_2(m)) );

	f = 1. / (pow(beta*p0,2) - 4.0*pow(E,2));

	nB = 1. / ( exp(E) - 1. );

	return (1.0/E) * f * nB;
 
}

static double integ(double eB, double p0, int l, double beta, double m)
{
	gsl_function F;

	F.function = &my_func;

	struct my_params params = {eB, p0, l, beta, m};

	F.params = &params;

	double result, error;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(2000);

	gsl_integration_qagiu(&F, 0., 0., 1e-8, 2000, w, &result, &error);

	gsl_integration_workspace_free(w);

	return result;
}

double JThM(double eB, double p0, double beta, double m, int l_max)
{
	printf("------------ In JThM --------------\n");

	double sum = 0.0;

	for(int l = 0; l <= l_max; l++)
	{
		sum += integ(eB, p0, l, beta, m);
	}

	printf("------------ Out JThM --------------\n");

	return -eB * gsl_pow_2(beta*M_1_PI) * sum;
}