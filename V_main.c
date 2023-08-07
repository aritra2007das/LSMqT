// This file plots eB vs v_B vs M_pi kepping temperature fixed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "include/V_decl.h"
#include "include/Pi0.h"

#define MPI 0.14
#define MSIGMA 0.435
#define MF 0.31

double Delta_eB(int , double );

#define QUANTUM_EFFECTS
/*
double V_total(double v, double eB, double beta, double mu, double m_pion, double m_sigma, int l_max, double lambda, double g, double Lambda, double tol, int flag);

double Pi_total_thermal(double beta, double mu, double lambda, double g);

double Pi_pi0(double eB, double p0, double beta,  double mu, double m_pion, double m_sigma, double M, 
	int l_max, double lambda, double g);

double Vct(double v, double m_pion, double m_sigma, double lambda, double g, double Lambda);

double Vb(double msq, double Lambda);

double VbB(double eB, double msq, double Lambda);

double VfB(double eB, double Mf, double Lambda, double qf);

double VbTh(double beta, double msq);

double VbThM(double eB, double beta, double msq, int l_max);

double VffThM(double eB, double beta, double mu, double Mf, int l_max, double qf); 
*/

int main()
{

	clock_t start_time, end_time;

	start_time = clock();
	// setting parameters

	printf("|--------------------------------\n");
	double eB = pow(MPI,2);
	printf("|           eB = %lf           \n",eB);
	double beta = 1.0/0.001;
	printf("|           T = %lf           \n",1.0/beta);
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
	double tol_sigma = 1.e-3;

	double Lambda = a;


	/*
	double v = 0.0;

	double m_pion_sq = lambda * pow(v,2) - pow(a,2);

	double m_sigma_sq = (3.0 * lambda * pow(v,2) ) - pow(a,2);

	double mf = g * v;

	double V_cl = - 0.5 * ( pow(a,2)+pow(MPI,2) ) * pow(v,2) + 0.25 * lambda * pow(v,4);

	double V_pi_pm = VbB(eB,m_pion_sq,Lambda) +VbThM(eB,beta,m_pion_sq,l_max);

	double V_pi_pi0 = Vb(m_pion_sq,Lambda) + VbTh(beta,m_pion_sq,1e-13);

	double V_sigma = Vb(m_sigma_sq,Lambda) + VbTh(beta,m_sigma_sq,tol_sigma);

	double V_f_qu = VfB(eB,mf,Lambda,2./3.)+VffThM(eB,beta,mu,mf,l_max,2./3.); 

	double V_f_qd = VfB(eB,mf,Lambda,1./3.) + VffThM(eB,beta,mu,mf,l_max,1./3.); 

	double V_f = V_f_qu + V_f_qd;

	double Vcounter = Vct(v,MPI,MSIGMA,lambda,g,Lambda);

	double Vtot = V_total(v,eB,beta,mu,MPI,MSIGMA,l_max,lambda,g,Lambda,tol_sigma);

	printf("-----Printing a sample value of V_total ---------\n\n");

	printf("V_cl = %e\n ", V_cl);

	printf("V_pi_pm = %e\n ", V_pi_pm);

	printf("V_pi_pi0 = %e\n ", V_pi_pi0);

	printf("V_sigma = %e\n ", V_sigma);
	   
	printf("V_f = %e\n ", V_f);

	printf("V_ct = %e\n", Vcounter);

	printf("........ V_total..................\n");

	printf("V_total = %e\n ", Vtot);

	printf("V_total = %e\n ", (2.*V_pi_pm)+V_pi_pi0+V_sigma+V_f+V_cl+Vcounter);

	printf("--------------------------------------------------\n\n");
	*/

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
	/*
	int count = 0;

	for(int i = 0; i < N_dat; ++i)
	{
		printf("%lf\t%lf\n",*((double *)(x_ptr) + i), *((double *)(y_ptr) + i));
		count += 1;
	}

	printf("count = %d\n", count);
	*/

	/*

	// creating plot of effective potetial 

	double x = 0.12;

	double ans = 0.0;

	FILE * fp;

	fp = fopen("V_data/V_total_B=5.0mpi^2_T=100MeV.dat","w+");

	if (fp == NULL){
		printf("file open unsucessful!\n");
		exit(1);
	}
	
	do
	{
		ans = V_total(x,eB,beta,mu,MPI,MSIGMA,l_max,lambda,g,Lambda,tol_sigma,1,(double *)x_ptr,(double *)y_ptr,N_dat);

		fprintf(fp,"%lf \t %lf \n",x, ans/pow(a,4));
		
		x = x + 0.001;

		printf("--------------------------------------\n");

	}while( x <= 0.19);	

	fclose(fp);

	*/

	// creating plot for vB and M_{\pi_0} with varying B

	
		// open file

	FILE * fileptr;

	fileptr = fopen("V_data/extended_vB_T=1MeV.dat","w+");

	if (fileptr == NULL){
		printf("file open unsucessful!\n");
		exit(1);
	}

	double Mass_Pi0, vB_minimum;

	// double eB_max = 20.0*pow(MPI,2);  This is default

	double eB_max = 3.0;

	int count = 0;

	do{
		#ifdef QUANTUM_EFFECTS

		vB_minimum = vBmin(eB,beta,mu,MPI,MSIGMA,l_max,lambda,g,Lambda,tol_sigma,1,(double *)x_ptr,(double *)y_ptr,N_dat);

		Mass_Pi0 = mass_pi0(vB_minimum, eB, beta, mu, MPI, MSIGMA, MF, l_max, lambda, g, 1);

		#else

		vB_minimum = v0_cl(MPI,MSIGMA,lambda);

		Mass_Pi0 = mass_pi0(vB_minimum, eB, beta, mu, MPI, MSIGMA, MF, l_max, lambda, g, 0);

		#endif

		fprintf(fileptr, "%lf %lf %lf\n", eB, vB_minimum, Mass_Pi0);

		printf("%lf \t %lf \t %lf\n", eB, vB_minimum, Mass_Pi0);

		count = count + 1;

		printf("----------count = %d---------------\n",count);

		// eB = eB + Delta_eB(count,MPI); This is default

		eB += 0.2;
	
	} while(eB <= eB_max);

	fclose(fileptr);

	//printf("vBmin = %lf\n",vB_minimum);

	//printf("Mass_Pi0 = %lf\n",Mass_Pi0);

	free(x_ptr); free(y_ptr);

	end_time = clock();

	printf("time taken = %lf seconds \n",  ((double)end_time - (double)start_time) / CLOCKS_PER_SEC );
	
	return 0;
}
