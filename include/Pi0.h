#pragma once

double Pi_ff_B(double eB, double p0, double Mf, double qf);

double Pi_ff_ThM(double eB, double p0, double beta, double mu, double Mf, int l_max, double qf);

double PipiB(double eB, double m);

double PipmThM(double eB, double beta, double mass, int l_max);

double Pi_pi_neutral_Th(double beta, double m);

double ITh(double p0, double beta, double m);

double JB(double eB, double p0, double m);

double JThM(double eB, double p0, double beta, double m, int l_max);

double lambda_eff(double eB, double p0, double beta, double m_pion, double m_sigma, double lambda, int l_max);

double Pi_pi0(double eB, double p0, double beta, double mu, double m_pion, double m_sigma, double M, 
	int l_max, double lambda, double g);

double Pi_pi0_Vertex(double eB, double p0, double beta,  double mu, double m_pion, double m_sigma, double M, 
	int l_max, double lambda, double g);

double pi0_disp(double v, double eB, double p0, double beta,  double mu, double m_pion, double m_sigma, double M, 
	int l_max, double lambda, double g, int flag);

double disp_interp(double eB, double p0, double beta,  double mu, double m_pion, double m_sigma, double M, 
	int l_max, double lambda, double g, int flag);

double mass_pi0(double v, double eB, double beta,  double mu, double m_pion, double m_sigma, double M, 
	int l_max, double lambda, double g, int flag);

double Pi_total_thermal(double beta, double mu, double lambda, double g);
