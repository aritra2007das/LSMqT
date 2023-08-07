#pragma once

double Vct(double v, double m_pion, double m_sigma, double lambda, double g, double Lambda);

double v0_cl(double m_pion, double m_sigma, double lambda);

double Vb(double msq, double Lambda);

double zeta_der_real(double , double *, double *, int );

double VbB(double eB, double msq, double Lambda, double *x_ptr, double *y_ptr, int N_dat);

double VfB(double eB, double Mf, double Lambda, double qf, double *x_ptr, double *y_ptr, int N_dat);

double VbTh(double beta, double msq, double tol);

double VbThM(double eB, double beta, double msq, int l_max);

double VffThM(double eB, double beta, double mu, double Mf, int l_max, double qf);

double V_total(double v, double eB, double beta, double mu, double m_pion, double m_sigma, int l_max, double lambda, double g, double Lambda, double tol, int flag, double * x_ptr, double * y_ptr, int N_dat);

double  vBmin(double eB, double beta, double mu, double m_pion, double m_sigma, int l_max, double lambda, double g, double Lambda, double tol, int flag, double * x_ptr, double * y_ptr, int N_dat);