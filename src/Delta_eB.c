#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Delta_eB(int i, double mpi)
{
	double ans;

	if (i > 0 && i <= 10)
	{ 
		ans =  0.1*pow(mpi,2);
	}
	else if (i > 10 && i <= 61)
	{
		ans = 0.5*pow(mpi,2);
	}
	else
	{
		printf("Adjust eB_max accordingly in do-while loop in main!\n");
		exit(1);
	}
	return ans;
}