#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
#include<gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>

double zeta_der_real(double x, double * x_ptr, double * y_ptr, int N_dat){
	
	gsl_interp_accel * acc = gsl_interp_accel_alloc();
	
	const gsl_interp_type * T = gsl_interp_cspline;

	gsl_spline * w = gsl_spline_alloc(T, N_dat); 

	gsl_spline_init (w, x_ptr, y_ptr, N_dat);
	
	double ans;
	
	ans = gsl_spline_eval(w, x, acc);
	
	gsl_spline_free (w);

	gsl_interp_accel_free (acc);
	
	return ans;
}
