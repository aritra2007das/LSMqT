#include<stdio.h>
//#include<math.h>
#include<stdlib.h>
#include<complex.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_math.h>

struct my_params {double eB; double beta; double mu; int lmax; double Mf; double qf;};

static double my_func(double x, void * p)
{
	struct my_params * poin = (struct my_params *) p;

	double beta = (poin -> beta);

	double mu = (poin -> mu);

	double eB = (poin -> eB);

	double Mf = (poin -> Mf);

	int lmax = (poin -> lmax);

	double qf = (poin -> qf);

	double complex E, ap, am, f;

	double complex E0, ap0, am0, f0;

	double complex sum = 0.0;

	for(int l = 1; l <=lmax; l++)
	{
 
		E = csqrt(pow(x,2) + pow(beta,2) * ( 2*l*qf*eB + pow(Mf,2) ) );

		//printf("%f\n", E);

		ap = E - (beta * mu);

		am = E + (beta * mu);

		f = clog( 1.0 + cexp(-ap) ) + clog( 1.0 + cexp(-am) );

		sum = sum + f;

	}

	E0 = csqrt(pow(x,2) + pow(beta,2) * pow(Mf,2)  );

		//printf("%f\n", E);

	ap0 = E0 - (beta * mu);

	am0 = E0 + (beta * mu);

	f0 = clog( 1.0 + cexp(-ap0) ) + clog( 1.0 + cexp(-am0) );

	double complex ans = f0 + 2.0*sum;

	return creal(ans);
}

double VffThM(double eB, double beta, double mu, int lmax, double Mf, double qf)
{
	printf("-------In VffThM.c ---------\n");
	double result, error;

	// Default tolerance tol = 1e-4
	double tol = 1e-3;

	struct my_params params = {eB, beta, mu, lmax, Mf, qf};

	gsl_function F;

	F.function = &my_func;

	F.params = &params;

	//printf("In subroutine\n");

	//printf("%d\t%lf\t%e\n", l, qf, GSL_FN_EVAL(&F,1.0));

	//printf("Out subroutine\n");

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(2000);

	gsl_integration_qagiu(&F, 0.0, 0.0, tol, 2000, w, &result, &error);

	gsl_integration_workspace_free(w);

	double ans = -( (qf*eB*gsl_pow_2(M_1_PI)) / (2*pow(beta,2)) ) * result;

	printf("-------In VffThM.c ---------\n");

	return ans;
}