#include<iostream>
#include<cstdlib>
#include<cmath>
#include<chrono>
#include "Pi0.h"
//#include<gsl/gsl_integration.h>
//#include<gsl/gsl_math.h>

#define MPI 0.14
#define	MSIGMA 0.435

//struct my_params {double eB; int l; double beta; double m;};

//double my_func (double x, void * p);


//double integ (double eB, int l, double beta, double m);


// double PipmThM(double eB, double temp, double mass, int l_max);

// double Pi_pi_neutral_Th(double temp, double m);

// double PipiB(double eB, double m);

// double Pi_ff_ThM (double eB, double p0, double beta, double mu, double m, int l_max, double qf);

// double Pi_ff_B(double eB, double p0, double Mf, double qf);

// double JB(double eB, double p0, double m);

// double JThM(double eB, double p0, double beta, double m, int l_max);

// double ITh(double p0, double beta, double m);

// double lambda_eff(double eB, double p0, double beta, double m_pion, double m_sigma, double lambda, int l_max);

// double Pi_pi0(double eB, double p0, double beta,  double mu, double m_pion, double m_sigma, double M, int l_max, double lambda, double g);

// double Pi_pi0_Vertex(double eB, double p0, double beta,  double mu, double m_pion, double m_sigma, double M,int l_max, double lambda, double g);

// double pi0_disp(double eB, double p0, double beta,  double mu, double m_pion, double m_sigma, double M, int l_max, double lambda, double g, int flag);

int main()
{
	//double eB = 0.5;

	//double p0 = 0.1;

	double temp = 0.14;

	double beta = 1.0/temp;

	int l_max = 3000;

	double mu = 0.0;

	double Mf = 0.3;

	double lambda = 3.67;

	double g = 0.46;

	//double qu = 2./3.; double qd = 1./3.;

	//double Pi_pi0_b, Pi_pi0_ff; 
	
	//Pi_pi0_b = lambda*(PipiB(eB,mpi)+PipmThM(eB,temp,mpi,l_max) + Pi_pi_neutral_Th(temp,mpi)+ Pi_pi_neutral_Th(temp,msigma));

	//Pi_pi0_ff = pow(g,2)*(Pi_ff_ThM(eB,p0,temp,mu,Mf,l_max,qu) + Pi_ff_ThM(eB,p0,temp,mu,Mf,l_max,qd));

	// std::cout << Pi_pi0_b+Pi_pi0_ff+Pi_ff_B(eB,p0,Mf,qu)+Pi_ff_B(eB,p0,Mf,qd)<< std::endl

	//std::cout << lambda_eff(eB, p0, beta, mpi, msigma,lambda,l_max) << std::endl;

	//std::cout << ITh(0.1,beta,mpi)<< std::endl;

	//std::cout << JThM(eB,p0,beta,mpi,l_max)<< std::endl;

	//std::cout << Pi_pi0(eB,p0,beta,mu,MPI,MSIGMA,Mf,l_max,lambda,g) << std::endl;

	//std::cout << Pi_ff_B(0.0196, 0.1, 0.3, 2./3.) + Pi_ff_B(0.0196, 0.1, 0.3, 1./3.) << std::endl;

	// std::cout << PipiB(0.0196,0.14) << std::endl;

	// std::cout << Pi_ff_ThM(0.0196,0.1,1.0/0.14,0.0,0.3,3000,2./3.)+Pi_ff_ThM(0.0196,0.1,1.0/0.14,0.0,0.3,3000,1./3.)<< std::endl;

	// std::cout << PipmThM(0.0196,1.0/0.14,0.14,3000) << std::endl;

	// std::cout << Pi_pi_neutral_Th(1.0/0.14, 0.14)<< std::endl;

	// std::cout << lambda_eff(0.0196,0.1,1.0/0.14,0.14,0.435,3.67,3000)<< std::endl;

	// std::cout << Pi_pi0_Vertex(eB,p0,beta,mu,MPI,MSIGMA,Mf,l_max,lambda,g) << std::endl;
	/*
	for(int i=0;i<100;i++)
	{
		std::cout << 0.000001+i*0.001 <<"\t"<< pi0_disp(eB,0.0001+i*0.01,beta,mu,MPI,MSIGMA,Mf,l_max,lambda,g,1) 
		<< std::endl;
	}
	*/
	// printf("mass_pi0\n");

	//std::cout << mass_pi0(eB,beta,mu,MPI,MSIGMA,Mf,l_max,lambda,g,1) << std::endl;

	
	double mp;

	FILE *fptr = fopen("pi0_mass_T140.dat","w+");

	if (fptr==NULL)
		{
			printf("File open unsucessful!\n");
			exit(EXIT_FAILURE);
		}

	auto begin = std::chrono::high_resolution_clock::now();

	for(double x = 0.001; x <= 1.0; x +=0.005)
	{
		mp = mass_pi0(x,beta,mu,MPI,MSIGMA,Mf,l_max,lambda,g,0);

		printf("%lf\n",mp);

		fprintf(fptr, "%lf\t %lf\n", x, mp);
	}

	auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - begin);

	fclose(fptr);
	
	printf("Time measured: %.3lld seconds.\n", elapsed.count());

	return 0;
}