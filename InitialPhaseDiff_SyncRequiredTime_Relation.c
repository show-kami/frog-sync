//--------------------------------------------------------------------------
// 初期の位相差を変えると，同期に要する時間がどのように変化するのかを確かめるためのプログラム。
//--------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_RungeKutta.h"

#define NUMofEQUS 2

FILE* myfopen(char* FileName, char* type){
	FILE* fp = fopen(FileName, type);
	if(fp == NULL){
		printf("ERROR: File Not Found.\n");
		exit(1);
	}
	return fp;
}

int NumOfSlice(double start, double end, double step){
	return (end - start) / step + 1;
}

double Interaction(double theta_passive, double theta_active){
	double K = 8.0;
	double gamma = 0.25;
	double PhaseDiff = theta_active - theta_passive;
	return -K * (sin(PhaseDiff) - gamma * sin(2 * PhaseDiff));
}

double f_A(double t, double *x){
	double omega_A = 8 * M_PI;
	return omega_A + Interaction(x[0], x[1]);
}

double f_B(double t, double *x){
	double omega_B = 8 * M_PI;
	return omega_B + Interaction(x[1], x[0]);
}

//--------------------------------------------------------------------------
// 関数名	:convertPhase
// 概要		:角θを，区間[0,2pi]内の値に変更する
// 戻り値	:double theta (θ in [0, 2pi])
// 引数		:double theta (θ in [-inf, +inf])
//--------------------------------------------------------------------------
double convertPhase(double theta){
	do{
		if(theta < 0){
			theta += 2 * M_PI;
		} else if (theta >= 2 * M_PI){
			theta -= 2 * M_PI;
		}
	} while (theta < 0 || theta >= 2 * M_PI);
	return theta;
}

double frog(double theta){
	theta = convertPhase(theta);
	if (theta <= M_PI/2){
		return 1;
	} else {
		return 0;
	}
	return theta;
}

int main(void){
	FILE *fp;
	double **x;
	double (*f[NUMofEQUS])(double t, double *x);
	double x_0[NUMofEQUS];
	double t_0, t_end, dt;
	int i, fi;
	double SyncRequiredTime[1000]; /* 初期位相差を(0, pi] でpi/1000ステップで変えた時のそれぞれの同期所要時間を格納する */

	f[0] = f_A;
	f[1] = f_B;

	t_0 = 0;
	t_end = 10;
	dt = 0.001;
	x = malloc(sizeof(double *) * (NUMofEQUS + 1)); /* 解くべき方程式の本数+1だけのメモリを用意 */
	for(i=0; i<NUMofEQUS + 1; i++){
		x[i] = malloc(sizeof(double) * NumOfSlice(t_0, t_end, dt));
	}

	// 初期位相差と，同期所要時間との関係を調べたい
	/* 初期位相差を(0, pi] でpi/1000ステップ作ろう */
	for(fi=0; fi < 1000; fi++){
		x_0[0] = (fi + 1) * M_PI / 1000;
		x_0[1] = 0;
		executeRK(f, NUMofEQUS, t_0, t_end, dt, x_0, x);
		SyncRequiredTime[fi] = x[0][NumOfSlice(t_0, t_end, dt)-1];
	}

	// 初期位相差と同期所要時間との関係を出力
	fp = myfopen("output_InitialPhaseDiff_SyncRequiredTime_Relation.csv", "w");
	fprintf(fp, "initial_phase_difference, sync_required_time\n");
	for(fi = 0; fi < 1000; fi++){
		fprintf(fp, "%f, %f\n", (fi+1)*M_PI/1000, SyncRequiredTime[fi]);
	}
	fclose(fp);

	return 0;
}
