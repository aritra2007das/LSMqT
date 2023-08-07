#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 4.0 * atan(1.0)

double Vct(double v, double m_pion, double m_sigma, double lambda, double g, double Lambda)
{
	
	double a = sqrt(0.5*pow(m_sigma,2) - 1.5*pow(m_pion,2));

	double delta_a2 = pow(m_pion,2)/2.0 -(1./(16.0*pow(PI,2)*lambda))*(6*pow(lambda,2)*( pow(a,2) 
		+ 2.0*pow(m_pion,2)) - 8.0*pow(g,4)*( pow(a,2) + pow(m_pion,2)) +3.0*pow(a,2)*pow(lambda,2)*
	(2.0*log(m_pion/Lambda)+log((2.0*pow(a,2) + 3.0*pow(m_pion,2))/pow(Lambda,2)))); 

	double delta_lambda2 = (lambda/2.)*( pow(m_pion,2)/(pow(a,2)+pow(m_pion,2)) )-(1.0/(16.0*pow(PI,2)))
	*(-8.0*pow(g,4)*log(pow(g,2) * ( (pow(a,2)+pow(m_pion,2))/(lambda*pow(Lambda,2)) ) ) 
		+ 3.0*pow(lambda,2)*(2.0*log(m_pion/Lambda)+3.0*log((2.0*pow(a,2) 
			+ 3.0*pow(m_pion,2))/pow(Lambda,2))));

	double ans = -0.5*delta_a2*pow(v,2) + 0.25*delta_lambda2*pow(v,4);
		
	return ans;
}