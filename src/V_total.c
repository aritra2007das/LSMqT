#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include "../include/V_decl.h"
#include "../include/Pi0.h"

#define FLAG 

double V_total(double v, double eB, double beta, double mu, double m_pion, double m_sigma, int l_max, double lambda, 
	double g, double Lambda, double tol, int flag, double *x_ptr, double *y_ptr, int N_dat)
{
	printf("In V_total ------------\n");
	double a;

	double m_pion_sq, m_sigma_sq, mf, V_cl, Vcounter;

	a = sqrt( ( pow(m_sigma,2) - 3.0*pow(m_pion,2)) / 2.0 );

	V_cl = - 0.5 * ( pow(a,2)+pow(m_pion,2) ) * pow(v,2) + 0.25 * lambda * pow(v,4);

	mf = g * v;

	double Pi;

	/*

	printf("Pi_total = %lf \t Pi_thermal = %lf\n", Pi_total, Pi_thermal); */

	#ifdef FLAG

	//z = -pow(a,2) + eB + Pi_total;

	double Mf = 0.31; // fixed constituent quark mass in Pi

	double Pi_total = Pi_pi0(eB, 0.001, beta, mu, m_pion, m_sigma, Mf, l_max, lambda, g);

	Pi = Pi_total;

	#else

	//z = -pow(a,2) + eB + Pi_thermal;

	double Pi_thermal = Pi_total_thermal(beta, mu, lambda, g);

	Pi = Pi_thermal;

	#endif

	//printf("Pi = %lf\n",Pi);

	//double err_in_Pi = fabs((Pi_thermal - Pi_total)/Pi_total) * 100;

	/*

	bool c = ( z > 0); */

	//printf("error in thermal aprroximation in Pi in eff. pot. = %lf percent \n",err_in_Pi);
	/*
	printf("---------------------------------------------------\n");

	printf("condition = 1 for true and condition = 0 for false \n ");

	printf("---------------------------------------------------\n");


	printf("condition = %d\n",c);
	
	printf("condition = %lf\n",z);

	if (c == 0)
	{
		printf("Logarithm issue unresolved\n Terminating the program\n");

		exit(1);
	}

	if (flag != 1 && flag != 0)
	{
		printf("flag can be either 0 or 1\n");
		exit(1);
	}
	*/
	m_pion_sq = lambda * pow(v,2) - pow(a,2) + flag * Pi;

	m_sigma_sq = 3.0 * lambda * pow(v,2) - pow(a,2) + flag * Pi;

	Vcounter = Vct(v,m_pion,m_sigma,lambda,g,Lambda);

	double V_pi_pm = VbB(eB,m_pion_sq,Lambda,x_ptr,y_ptr, N_dat) + VbThM(eB,beta,m_pion_sq,l_max);

	//printf("\nV_pi_pm = %e\n",V_pi_pm);

	/*Default tolerance 1e-6*/

	double V_pi_pi0 = Vb(m_pion_sq,Lambda) + VbTh(beta,m_pion_sq,tol);

	//printf("\nV_pi_pi0 = %e\n",V_pi_pi0);

	double V_sigma = Vb(m_sigma_sq,Lambda) + VbTh(beta,m_sigma_sq,tol);

	//printf("\nV_sigma = %e\n",V_sigma);

	double V_f_qu = VfB(eB,mf,Lambda,2./3.,x_ptr,y_ptr,N_dat) + VffThM(eB,beta,mu,mf,l_max,2./3.); 

	//printf("\nV_f_qu = %e\n",V_f_qu);

	double V_f_qd = VfB(eB,mf,Lambda,1./3.,x_ptr,y_ptr,N_dat) + VffThM(eB,beta,mu,mf,l_max,1./3.); 

	//printf("\nV_f_qd = %e\n",V_f_qd);

	double V_f = V_f_qu + V_f_qd;

	double Vtotal = V_cl + (2.0 * V_pi_pm) + V_pi_pi0 + V_sigma + V_f + Vcounter;
	
	printf("out V_total ------------\n");

	return Vtotal;
}
