#include<stdio.h>
//#include<math.h>
#include<stdlib.h>
#include<complex.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_math.h>

struct my_params {double eB; double beta; int lmax; double msq;};

static double my_func(double x, void * p)
{
	struct my_params * poin = (struct my_params *) p;

	double beta = (poin -> beta);

	double eB = (poin -> eB);

	double msq = (poin -> msq);

	int lmax = (poin -> lmax); 

	double complex sum, E, f;

	sum = 0.0;

	for(int l = 0; l <= lmax; l++)
 	{
		E = csqrt(gsl_pow_2(x) + gsl_pow_2(beta) * ( (2*l+1)*eB + msq ) );

		//Z = -cexp(-E);

		f = clog(1-cexp(-E));

		sum += f;

	}

	return creal(sum);
}

double VbThM(double eB, double beta, int lmax, double msq)
{
	printf("-------In VbThM.c ---------\n");

	double result, error;

	/* Default tol = 1e-4 */

	double tol = 1e-3;

	gsl_function F;

	F.function = &my_func;

	struct my_params params = {eB, beta, lmax, msq};

	F.params = &params;

	//printf("In subroutine\n");

	//printf("%d,\t%lf\n", l, GSL_FN_EVAL(&F,1.0));

	//printf("Out subroutine\n");

	size_t w_size = 9000;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(w_size);

	gsl_integration_qagiu(&F, 0.0, 0.0, tol, w_size, w, &result, &error);

	gsl_integration_workspace_free(w);

	//printf("%lf",error);

	double ans = ((eB*gsl_pow_2(M_1_PI))/(2.0*gsl_pow_2(beta))) * result;

	printf("-------Out VbThM.c ---------\n");

	return ans;
}
