#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double ITh(double p0, double beta, double m);

double JB(double eB, double p0, double m);

double JThM(double eB, double p0, double beta, double m, int l_max);

double lambda_eff(double eB, double p0, double beta, double m_pion, double m_sigma, double lambda, int l_max)
{
	double f_n = 9.0*ITh(p0, beta, m_sigma) + ITh(p0, beta, m_pion);

	double f_c = 4.0*(JB(eB, p0, m_pion) + JThM(eB, p0, beta, m_pion, l_max));

	return lambda + 1.5 * pow(lambda,2) * (f_n + f_c);
}