#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE* myfopen(char* FileName, char* type){
	FILE* fp = fopen(FileName, type);
	if(fp == NULL){
		printf("ERROR: File Not Found.\n");
		exit(1);
	}
	return fp;
}

double PhaseDiff(double phi, double gamma){
	double K = 1.0;
	return 2 * K * (sin(phi) - gamma * sin(2*phi));
}

int main(void){
	double phi = 0;
	FILE *fp = myfopen("output_GammaDphidtRel.csv", "w");

	fprintf(fp, "phi, gamma0, gamma0.25, gamma0.5, gamma0.75, gamma1.0\n");
	do{
		fprintf(fp, "%f, %f, %f, %f, %f, %f\n", phi, PhaseDiff(phi,0), PhaseDiff(phi,0.25), PhaseDiff(phi,0.5), PhaseDiff(phi,0.75), PhaseDiff(phi,1.0));
		phi += 0.01 * M_PI;
	} while (phi < 2*M_PI);

	fclose(fp);
	return 0;
}
