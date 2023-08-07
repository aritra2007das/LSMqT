#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_math.h>

struct my_params {double p0; double beta; double m;};

static double my_func(double x, void * p)
{
	struct my_params * poin = (struct my_params *) p;

	double p0 = (poin -> p0);

	double beta = (poin -> beta);

	double m = (poin -> m);

	double E = sqrt(pow(x,2) + pow(beta,2)*pow(m,2));

	double f = pow(x,2) / (pow(beta*p0,2) - 4.0*pow(E,2));

	double nB = 1. / ( exp(E) - 1. );

	return (1.0/E) * f * nB;
 
}

double ITh(double p0, double beta, double m)
{
	printf("------In ITh.c------\n");
	gsl_function F;

	F.function = &my_func;

	struct my_params params = {p0, beta, m};

	F.params = &params;

	double result, error;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(100);

	gsl_integration_qagiu(&F, 0., 0., 1e-8, 100, w, &result, &error);

	gsl_integration_workspace_free(w);

	printf("-------Out ITh.c--------\n");

	return -gsl_pow_2(M_1_PI)*result;
}
