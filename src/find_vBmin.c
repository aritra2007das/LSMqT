#include<stdio.h>
#include<stdlib.h>
#include<gsl/gsl_math.h>
#include<gsl/gsl_min.h>
#include<gsl/gsl_errno.h>
#include "../include/V_decl.h"

struct my_params {double eB; double beta; double mu; double m_pion; double m_sigma; int l_max; double lambda; double g; double Lambda; double tol; int flag; double * x_ptr; double * y_ptr; int N_dat;};

static double my_func(double x, void * p)
{
	struct my_params * poin = (struct my_params *) p;

	double eB = (poin -> eB);double beta = (poin -> beta);double mu = (poin -> mu);
	double m_pion = (poin -> m_pion);double m_sigma = (poin -> m_sigma);int l_max = (poin -> l_max);
	double lambda = (poin -> lambda);double g = (poin -> g);double Lambda = (poin -> Lambda);
	double tol = (poin -> tol);int flag = (poin -> flag);double *x_ptr = (poin -> x_ptr);
	double *y_ptr = (poin -> y_ptr);int N_dat = (poin -> N_dat);

	double VV;

	double A = sqrt(( pow(m_sigma,2) - 3.0 * pow(m_pion,2) )/ 2.0);

	VV = V_total(x,eB,beta,mu,m_pion,m_sigma,l_max,lambda,g,Lambda,tol,flag,x_ptr,y_ptr,N_dat)/pow(A,4);

	return VV;
}

double  vBmin(double eB, double beta, double mu, double m_pion, double m_sigma, int l_max, double lambda, 
	double g, double Lambda, double tol, int flag, double * x_ptr, double * y_ptr, int N_dat)
{
	double x_minimum, x_upper, x_lower;

	double epsabs, tolarence;

	int st, status;

	//Default 
	x_minimum = .14; x_upper = .21; x_lower = .07;

	tolarence = 0.0; epsabs = 1e-6; 

	struct my_params params = {eB,beta,mu,m_pion,m_sigma,l_max,lambda,g,Lambda,tol,flag,x_ptr,y_ptr,N_dat};
	
	gsl_function F;

	F.function = &my_func;

	F.params = &params;

	const gsl_min_fminimizer_type * T = gsl_min_fminimizer_brent;

	gsl_min_fminimizer * s = gsl_min_fminimizer_alloc (T);

	st = gsl_min_fminimizer_set(s, &F, x_minimum, x_lower, x_upper);

	if(st == GSL_EINVAL)
	{
		printf("The minimum is not there in the interval specified!\n");

		exit(1);
	}

	double result;

	int iter = 0;

	int max_iter = 5000;
	
	do
	{
		iter++;

		status =  gsl_min_fminimizer_iterate(s);

		//printf("status = %d\n",status);

		x_minimum = gsl_min_fminimizer_x_minimum(s);

		//printf("x_minimum = %lf\n",x_minimum);

		x_lower = gsl_min_fminimizer_x_lower(s);

		//printf("x_lower = %lf\n",x_lower);

		x_upper = gsl_min_fminimizer_x_upper(s);

		//printf("x_upper = %lf\n",x_upper);

		status = gsl_min_test_interval(x_lower, x_upper, epsabs, tolarence);

		if (status == GSL_SUCCESS) {printf("minimum converged!\n");}

		//printf("status = %d\n",status);


	}while( (status == GSL_CONTINUE) && (iter < max_iter));

	result = x_minimum;

	//printf("maximum iteration = %d reached with minimum = %lf\n ", iter, x_minimum);

	gsl_min_fminimizer_iterate(s);

	return result;
}