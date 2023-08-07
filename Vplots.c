//This file is used to plot effective potential as a function of v
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "include/V_decl.h"
#include "include/Pi0.h"

#define MPI 0.14
#define MSIGMA 0.435
#define MF 0.31

int main()
{
	double eB, beta, temp, mu, lambda, g, a, Lambda, tol; int l_max, flag;

	eB = pow(MPI,2); temp = 0.001; mu = 0.0; lambda = 3.67; g = 0.46; tol =5*1e-3; l_max = 20000; flag = 1;

	a = sqrt(( pow(MSIGMA,2) - 3.0 * pow(MPI,2) )/ 2.0);

	Lambda = a;

	printf("|-----------------------------|\n");
	
	printf("|           eB = %lf          |\n",eB);
	
	printf("|           T = %lf           |\n",temp);
	
	printf("|           ch. pot = %lf     |\n",mu);
	
	printf("|        lambda = %lf         |\n",lambda);
	
	printf("|           g = %lf           |\n",g);
	
	printf("|           a = %lf           |\n",a);
	
	printf("|       l_max = %d            |\n",l_max);

	printf("|        Lambda = %lf         |\n",a);

	printf("|\t\t\t\t\t\t\t\t\n");

	printf("|-----------------------------|\n");

	beta = 1.0/temp;

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

	//plot V_eff

	double v, v_min, v_max, Vtot; int count;

	FILE * fileptr = fopen("Vnew_data/Vtotal_1Mev_mpi2_changed_2.dat","w+");

	if (fileptr == NULL)
	{
		printf("File to write plot data for V_total is not opened!\n");
		exit(1);
	}

	v_min = 0.13; v_max = 0.195; count = 0;

	v = v_min;

	do
	{
		Vtot = V_total(v,eB,beta,mu,MPI,MSIGMA,l_max,lambda,g,Lambda,tol,flag,x_ptr,y_ptr,N_dat);

		fprintf(fileptr,"%lf %lf\n", v, Vtot);

		printf("%lf %lf\n", v, Vtot);

		v += 0.0001;

		printf("Data-point number  = %d\n", count);

		count++;

	} while(v >= v_min && v <= v_max);

	fclose(fileptr);

	free(x_ptr); free(y_ptr);
	
	return 0;
}

