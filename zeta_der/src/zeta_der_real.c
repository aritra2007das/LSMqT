#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
#include<gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>

double zeta_der_real(double x){
	
	int N = 861;
	
	double * ptr_x = (double*)malloc(N*sizeof(double));
	
	if((void *) ptr_x == NULL){ 
	
		printf("1. Allocation is unsucessful!\n"); 
		exit(1);
	
	}
	
	double * ptr_y = (double*)malloc(N*sizeof(double));
	
	if((void *) ptr_y == NULL)
	{ 
	
		printf("2. Allocation is unsucessful!\n"); 
		exit(1);
	
	}
	/*
	double * ptr_z = (double*)malloc(N*sizeof(double));
	
	if((void *) ptr_z == NULL)
	{ 
	
		printf("3. Allocation is unsucessful!\n"); exit(1);
	
	}*/
	
	
	//FILE *fptr = fopen("~/Dropbox/LSMq_T/C++_codes/LSMq_codes/zeta_der/src/zeta_tab.dat","r");
	FILE *fptr = fopen("src/zeta_tab.dat","r");
	
	if(fptr == NULL)
	{
		printf("file open unsucessful!\n");
		exit(1);
	}
	
	for(int i = 0; i < N; ++i)
	{
		fscanf(fptr,"%lf %lf\n", ptr_x+i, ptr_y+i);
	}
	/*
	for(int i = 0; i < N; ++i)
	{
		printf("%lf\t%lf\n",ptr_x[i], ptr_y[i]);
	}
	*/
	gsl_interp_accel * acc = gsl_interp_accel_alloc();
	
	const gsl_interp_type * T = gsl_interp_cspline;

	gsl_spline * w = gsl_spline_alloc(T, N); 

	gsl_spline_init (w, ptr_x, ptr_y, N);
	
	double ans;
	
	ans = gsl_spline_eval(w, x, acc);
	
	gsl_spline_free (w);

	gsl_interp_accel_free (acc);
	
	free(ptr_x);
	
	free(ptr_y);
	fclose(fptr);
	
	/*free(ptr_z);*/
	
	return ans;
}
