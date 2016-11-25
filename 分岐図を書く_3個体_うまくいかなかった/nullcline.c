#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMofEQUS 3
#define PHI_DIV_NUM 1000

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

// dφ/dt の値を返す
double PhaseDeriv(double gamma, double phi_main, double phi_sub){
	double K = 1.0;
	double phi_diff = phi_main - phi_sub;
	return 2 * K * (sin(phi_main) - gamma * sin(2*phi_main)) + K * (sin(phi_sub) - gamma * sin(2*phi_sub) + sin(phi_diff) - gamma * sin(2*phi_diff));
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

int main(void){
	double gamma;
	FILE *fp_phi12 = myfopen("output_nullcline_phi12.csv","w");
	FILE *fp_phi13 = myfopen("output_nullcline_phi13.csv","w");

	// ヘッダ行を追加
	fprintf(fp_phi12, "phi_12, phi_13\n");
	fprintf(fp_phi13, "phi_12, phi_13\n");

	// 数値計算を実行
	printf("input gamma value...");
	scanf("%lf", &gamma);
	printf("gamma: %f\n", gamma);

	/* 必要な変数を定義 */
	double phi_12 = 0;
	double phi_13 = 0;
	/* 各gammaの値に対して，平衡解を計算 */
	do{
		phi_13 = 0;
		do{
			/* (phi_12, phi_13) in [0, 2pi)^2 について網羅的に計算する */
			double f = PhaseDeriv(gamma, phi_12, phi_13);
			double g = PhaseDeriv(gamma, phi_13, phi_12);
			/* 解をこの間に持つかどうか判別するための式…ほんとに↓でいいのだろうか？？ */
			double f_up = PhaseDeriv(gamma, phi_12 + M_PI / PHI_DIV_NUM, phi_13);
			double f_right = PhaseDeriv(gamma, phi_12, phi_13 + M_PI / PHI_DIV_NUM);
			double g_up = PhaseDeriv(gamma, phi_13 + M_PI / PHI_DIV_NUM, phi_12);
			double g_right = PhaseDeriv(gamma, phi_13, phi_12 + M_PI / PHI_DIV_NUM);
			if (f * f_up < 0 || f * f_right < 0){
				fprintf(fp_phi12, "%f, %f\n", phi_12, phi_13);
			}
			if (g * g_up < 0 || g * g_right < 0){
				fprintf(fp_phi13, "%f, %f\n", phi_12, phi_13);
			}
			phi_13 += M_PI / PHI_DIV_NUM;
		} while (phi_13 < 2 * M_PI);
		phi_12 += M_PI / PHI_DIV_NUM;
	} while (phi_12 < 2 * M_PI);

	fclose(fp_phi12);
	fclose(fp_phi13);
	return 0;
}
