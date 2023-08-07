#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "../include/Pi0.h"

double pi0_disp(double v, double eB, double p0, double beta, double mu, double m_pion, double m_sigma, double M, int l_max, double lambda, double g, int flag)
{
	
	double fV = 0.0; double f = 0.0; double h = 0.0;

	double a = sqrt((pow(m_sigma,2) - 3.0*pow(m_pion,2))/2.0);

	if(flag == 0)
	{
		f = Pi_pi0(eB, p0, beta, mu, m_pion, m_sigma, M, l_max, lambda, g);

		return pow(p0,2) - (lambda * pow(v,2) - pow(a,2)) - f;

	}
	else if (flag == 1)
	{

		fV = Pi_pi0_Vertex(eB, p0, beta, mu, m_pion, m_sigma, M, l_max, lambda, g);

		h = lambda_eff(eB,p0,beta,m_pion,m_sigma,lambda,l_max);

		return pow(p0,2) - (h * pow(v,2) - pow(a,2)) - fV;

	}
	else
	{
		printf("flag can be either 0 or 1\n");

		exit(1);
	}
}