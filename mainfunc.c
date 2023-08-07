#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "include/Pi0.h"
#include "include/v0_cl.h"

#define MPI 0.14
#define	MSIGMA 0.435
#define MF 0.31

#define FIXED_TEMPERATURE 0

double Delta_eB(int , double );

double Delta_T(int );

int main()
{
	double temp, eB, beta, mu, lambda, g, mp;

	int l_max, count;

	l_max = 10000;

	mu = 0.0;

	lambda = 3.67;

	g = 0.46;

	count = 0;

#if FIXED_TEMPERATURE==1

	double eB_min, eB_max;

	temp = 0.1;

	beta = 1.0/temp;

	printf("------------------------------- T = %lf MeV--------------------------------------\n",temp);

	eB_min = 0.05*pow(MPI,2); eB_max = 20*pow(MPI,2);

	FILE *fptr = fopen("V_data/basic_pi0_mass_T100.dat","w+");

	if (fptr == NULL)
		{
			printf("File open unsucessful!\n");
			exit(1);
		}

	eB = eB_min;

	do
	{
		mp = mass_pi0(v0_cl(MPI, MSIGMA, lambda), eB,beta,mu,MPI,MSIGMA,MF,l_max,lambda,g,0);

		printf("%lf %lf\n",eB, mp);

		fprintf(fptr,"%lf %lf\n", eB, mp);

		count++;

		eB +=Delta_eB(count,MPI);

	}while ( eB >= eB_min && eB <= eB_max );

	fclose(fptr);

#elif FIXED_TEMPERATURE==0

	double temp_min, temp_max;

	eB = 5*pow(MPI,2);

	printf("------------------------------- eB = %lf --------------------------------------\n",eB/pow(MPI,2));

	temp_min = 0.001; temp_max = 0.14;

	FILE *fptr = fopen("V_data/basic_pi0_mass_eB=5mpi2.dat","w+");

	if (fptr == NULL)
		{
			printf("File open unsucessful!\n");
			exit(1);
		}

	temp = temp_min;

	do
	{
		beta = 1.0/temp;

		mp = mass_pi0(v0_cl(MPI, MSIGMA, lambda), eB, beta, mu, MPI, MSIGMA, MF, l_max, lambda, g, 0);

		printf("%lf %lf\n", temp, mp);

		fprintf(fptr,"%lf %lf\n", temp , mp);

		count++;

		temp +=Delta_T(count);

	}while ( temp >= temp_min && temp <= temp_max );

	fclose(fptr);

#else

	printf("FIXED_TEMPERATURE must be either 0 or 1\n");

#endif

	return 0;
}
