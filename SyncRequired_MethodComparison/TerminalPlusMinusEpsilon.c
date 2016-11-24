#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_RungeKutta_TerminalPlusMinusEpsilon.h"

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
	double K = 1.0;
	double gamma = 0.25;
	double PhaseDiff = theta_active - theta_passive;
	return -K * (sin(PhaseDiff) - gamma * sin(2 * PhaseDiff));
}

double f_A(double t, double *x){
	int IndividualID = 0;
	double omega = 8 * M_PI;
	double result = omega;
	int fi;
	for(fi = 0; fi < NUMofEQUS; fi++){
		if(fi != IndividualID){
			result += Interaction(x[IndividualID], x[fi]);
		}
	}
	return result;
}

double f_B(double t, double *x){
	int IndividualID = 1;
	double omega = 8 * M_PI;
	double result = omega;
	int fi;
	for(fi = 0; fi < NUMofEQUS; fi++){
		if(fi != IndividualID){
			result += Interaction(x[IndividualID], x[fi]);
		}
	}
	return result;
}

double f_C(double t, double *x){
	int IndividualID = 2;
	double omega = 8 * M_PI;
	double result = omega;
	int fi;
	for(fi = 0; fi < NUMofEQUS; fi++){
		if(fi != IndividualID){
			result += Interaction(x[IndividualID], x[fi]);
		}
	}
	return result;
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
	int i, fi, fj;
	double SyncRequiredTime[1000]; /* 初期位相差を(0, pi] でpi/1000ステップで変えた時のそれぞれの同期所要時間を格納する */

	// 微分方程式へのポインタを格納
	f[0] = f_A;
	if(NUMofEQUS >= 2) f[1] = f_B;
	if(NUMofEQUS >= 3) f[2] = f_C;

	// 従属変数の初期値を格納
	x_0[0] = 0;
	if(NUMofEQUS >= 2) x_0[1] = M_PI/4;
	if(NUMofEQUS >= 3) x_0[2] = M_PI/8;

	// 独立変数のスパンを決め，その分の独立変数・従属変数計算結果を格納する配列を用意
	t_0 = 0;
	t_end = 10;
	dt = 0.01;
	x = malloc(sizeof(double *) * (NUMofEQUS + 1)); /* 解くべき方程式の本数+1だけのメモリを用意 */
	for(i=0; i<NUMofEQUS + 1; i++){
		x[i] = malloc(sizeof(double) * NumOfSlice(t_0, t_end, dt));
	}



	// 数値計算を実行
	executeRK(f, NUMofEQUS, t_0, t_end, dt, x_0, x);

	// 各個体の位相の時間変化を出力
	/* ヘッダ行を書く */
	fp = myfopen("output_theta.csv", "w");
	fprintf(fp, "time");
	for(fi = 0; fi < NUMofEQUS; fi++){
		fprintf(fp, ", theta_%d", fi+1);
	}
	if(NUMofEQUS == 2){
		fprintf(fp, ", phase_diff");
	}
	fprintf(fp, "\n");
	/* 数値を書く */
	for(fi = 0; fi < NumOfSlice(t_0, t_end, dt); fi++){
		fprintf(fp, "%f", x[0][fi]);
		for(fj = 0; fj < NUMofEQUS; fj++){
			fprintf(fp, ", %f", sin(x[fj+1][fi]));
		}
		if(NUMofEQUS == 2){
			fprintf(fp, ", %f\n", fabs(x[1][fi] - x[2][fi]));
		}
		fprintf(fp, "\n");
	}
	fclose(fp);



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
