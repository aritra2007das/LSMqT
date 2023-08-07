#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_math.h>

struct my_params {double eB; double beta; double m; int l_max;};

static double my_func (double x, void * p)
{
	struct my_params * poin = (struct my_params *) p;

	double eB = (poin -> eB);

	int l_max = (poin -> l_max);

	double beta = (poin -> beta);

	double m = (poin -> m);
	
	double sum = 0.;	
	
	double E, f;
	
	for(int l = 0; l <= l_max; ++l)
	{

		E = sqrt( pow(x,2) + pow(beta,2) * ( (2*l+1) *eB + pow(m,2) ) );

		f = (1. / E ) * (1. / (exp(E) - 1.) );
		
		sum += f;
	}

	return sum;
}

double PipmThM(double eB, double beta, double mass, int l_max)
{

	printf("In PipiThM.c -------------\n");

	gsl_function F;

	F.function = &my_func;

	struct my_params params = {eB, beta, mass, l_max};

	F.params = &params;

	double result, error, ans;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(100);

	gsl_integration_qagiu(&F, 0., 0., 1e-8, 100, w, &result, &error);

	gsl_integration_workspace_free(w);
	
	ans = (eB/(8.0*M_PI*M_PI))*result;
	
	printf("Out PipiThM.c -------------\n");

	return ans;
	
}
