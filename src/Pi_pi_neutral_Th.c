#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_math.h>

struct my_params {double beta; double m;};

static double my_func (double x, void * p)
{
	struct my_params * poin = (struct my_params *) p;

	double beta = (poin -> beta);

	double m = (poin -> m);	

	double E = sqrt(pow(x,2)+pow(beta,2)*pow(m,2));

	double f = (pow(x,2) / E ) * (1. / (exp(E) - 1.) );

	return f;
}

double Pi_pi_neutral_Th(double beta, double m)
{

	printf("In Pi_pi_neutral_Th.c --------------\n");
	gsl_function F;

	F.function = &my_func;
	
	double ans;

	struct my_params params = {beta, m};

	F.params = &params;

	double result, error;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(100);

	gsl_integration_qagiu(&F, 0., 0., 1e-8, 100, w, &result, &error);

	gsl_integration_workspace_free(w);
	
	ans = (gsl_pow_2(M_1_PI)/(8.0*gsl_pow_2(beta)))*result;
	
	printf("Out Pi_pi_neutral_Th.c --------------\n");

	return ans;
	
}
