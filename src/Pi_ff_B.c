#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_math.h>
#include<gsl/gsl_sf_psi.h>
#include<gsl/gsl_sf_gamma.h>
#include<gsl/gsl_integration.h>

struct my_params {double eB; double p0; double Mf; double qf;};

static double my_func(double x, void * p)
{

	struct my_params * poin = (struct my_params *) p;

	double eB = (poin -> eB);

	double p0 = (poin -> p0);

	double Mf = (poin -> Mf);

	double qf = (poin -> qf);

	double y = gsl_pow_2(p0/Mf);

	double z = eB/gsl_pow_2(Mf);

	double f = gsl_sf_psi( ( 1.0 - x*(1.0 -x)*y ) / (2.0*qf*z) );

	return f;
}

double Pi_ff_B(double eB, double p0, double Mf, double qf)
{
	printf("In Pi_ff_B.c------------\n");

	struct my_params params = {eB, p0, Mf, qf};

	gsl_function F;

	F.function = &my_func;

	F.params = &params;

	double d = ( (4.0*gsl_pow_2(Mf)) / gsl_pow_2(p0) ) -1.0;
	
	//printf("d = %lf\n",d);

	double t1 = log(gsl_pow_2(Mf)/(2.0*qf*eB)) + 2.0 * sqrt(d)* atan(1./sqrt(d));
	
	//printf("t1 = %lf\n",t1);
	
	double t2 = ( (4.0*qf*eB) / (gsl_pow_2(p0)) )* (1.0/sqrt(d))* atan(1./sqrt(d));

	//printf("t2 = %lf\n",t2);

	double t3 = qf*eB*(2.0*log(gsl_sf_gamma(gsl_pow_2(Mf)/(2.0*qf*eB)))+log(gsl_pow_2(Mf)/(4.0*M_PI*qf*eB)));

	//printf("t3 = %lf\n",t3);

	double t4 = gsl_pow_2(Mf)*(1.0-log(gsl_pow_2(Mf)/(2.0*qf*eB)));

	//printf("t4 = %lf\n", t4);
	
	double result, error;

	gsl_integration_workspace * w = gsl_integration_workspace_alloc(1000);

	gsl_integration_qags (&F, 0., 1., 0, 1e-8, 1000, w, &result, &error);

	//std::cout << "acos(sqrt(d)) =" << atan(1./sqrt(d)) << std::endl;
	double ans = (gsl_pow_2(M_1_PI)/4.0) * ( (gsl_pow_2(p0)/2.0) * (t1-2.0-result-t2) + t3 + t4 );
	
	printf("out Pi_ff_B.c------------\n");
	
	return ans;

	//return result;

}
