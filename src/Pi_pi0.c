#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Pi_ff_B(double eB, double p0, double Mf, double qf);

double Pi_ff_ThM(double eB, double p0, double beta, double mu, double Mf, int l_max, double qf);

double PipiB(double eB, double m);

double PipmThM(double eB, double beta, double mass, int l_max);

double Pi_pi_neutral_Th(double beta, double m);

double Pi_pi0(double eB, double p0, double beta, double mu, double m_pion, double m_sigma, double M, int l_max, double lambda, double g)
{
	//printf("In Pi_pi0.c --------------\n");
	
	double Pi_u, Pi_d, Pi_bpi0, ans;

	int Nc =3;

	Pi_u = Pi_ff_B(eB, p0, M, 2./3.) + Pi_ff_ThM(eB, p0, beta, mu, M, l_max, 2./3.);

	Pi_d = Pi_ff_B(eB, p0, M, 1./3.) + Pi_ff_ThM(eB, p0, beta, mu, M, l_max, 1./3.);

	Pi_bpi0 = 8.0*(PipiB(eB,m_pion) + PipmThM(eB,beta,m_pion,l_max)) + 4.0*Pi_pi_neutral_Th(beta,m_pion) + 12.0*Pi_pi_neutral_Th(beta,m_sigma);
	
	ans = Nc*pow(g,2)*(Pi_u+Pi_d) + lambda*Pi_bpi0;
	
	//printf("Out Pi_pi0.c --------------\n");

	return ans;
}
