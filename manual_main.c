//This function prints both eB, T dependence of mpi, v_B
//It is not used for plotting
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "include/V_decl.h"
#include "include/Pi0.h"

#define MPI 0.14
#define MSIGMA 0.435
#define MF 0.31

int main()
{

	clock_t start_time, end_time;

	start_time = clock();
	// setting parameters

	printf("|--------------------------------\n");
	double eB = pow(MPI,2);
	printf("|           eB = %lf           \n",eB);
	double temp = 0.001;
	printf("|           T = %lf           \n",temp);
	double mu = 0.0;
	printf("|           ch. pot = %lf      \n",mu);
	double lambda = 3.67;
	printf("|        lambda = %lf           \n",lambda);
	double g = 0.46;
	printf("|           g = %lf           \n",g);
	double a = sqrt(( pow(MSIGMA,2) - 3.0 * pow(MPI,2) )/ 2.0);
	printf("|           a = %lf           \n",a);
	int l_max = 10000;
	printf("|       l_max = %d          \n",l_max);
	printf("|\t\t\t\t\t\t\t\t\n");
	printf("|--------------------------------\n");
	double tol_sigma = 1.e-4;

	double Lambda = a;


	// reading zeta_der from file  

	int N_dat = 20001;

	void *x_ptr = malloc(N_dat*sizeof(double));
	void *y_ptr = malloc(N_dat*sizeof(double));

	if( x_ptr == NULL || y_ptr == NULL)
	{
		printf("Memory allocation required for zeta_der failed!\n");
	}

	FILE *fptr = fopen("src/zeta_tab.dat","r+");

	//int st;
	
	if(fptr == NULL)
	{
		printf("file open unsucessful for reading zeta_der!\n");
		exit(1);
	}
	
	for(int i = 0; i < N_dat; ++i)
	{
		fscanf(fptr,"%lf%lf\n", (double *)(x_ptr) + i, (double *)(y_ptr) + i);

	}

	fclose(fptr);

	//Plots

	double beta, vB_minimum, Mass_Pi0;
	beta = 1.0 / temp;

	vB_minimum = vBmin(eB,beta,mu,MPI,MSIGMA,l_max,lambda,g,Lambda,tol_sigma,1,(double *)x_ptr,(double *)y_ptr,N_dat);

	Mass_Pi0 = mass_pi0(vB_minimum, eB, beta, mu, MPI, MSIGMA, MF, l_max, lambda, g, 1);

	printf("%lf %lf %lf %lf\n", eB, temp, vB_minimum, Mass_Pi0);		

	free(x_ptr); free(y_ptr);

	end_time = clock();

	printf("time taken = %lf seconds \n",  ((double)end_time - (double)start_time) / CLOCKS_PER_SEC );
	
	return 0;
}
