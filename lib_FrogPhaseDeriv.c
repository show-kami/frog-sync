#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_FrogPhaseDeriv.h"

double Interaction(double theta_passive, double theta_active){	double K = 1.0;
	double gamma = 0.25;
	double PhaseShiftPara = M_PI;
	double PhaseDiff = theta_active - theta_passive + PhaseShiftPara;
	return -K * (sin(PhaseDiff) - gamma * sin(2 * PhaseDiff));
}

double f_0(double t, double *x){
	int IndividualID = 0;
	double omega = 8 * M_PI;
	double result = omega;
	int fi;
	for(fi = 0; fi < 2; fi++){
		if(fi != IndividualID){
			result += Interaction(x[IndividualID], x[fi]) / 1;
		}
	}
	return result;
}

double f_1(double t, double *x){
	int IndividualID = 1;
	double omega = 8 * M_PI;
	double result = omega;
	int fi;
	for(fi = 0; fi < 2; fi++){
		if(fi != IndividualID){
			result += Interaction(x[IndividualID], x[fi]) / 1;
		}
	}
	return result;
}


void makePointerToFrogPhaseDeriv(double (*f[])(double t, double *x), int n){
	f[0] = f_0; if (n == 1) return;
	f[1] = f_1; if (n == 2) return;
}

