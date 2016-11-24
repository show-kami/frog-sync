#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMofEQUS 3
#define PHI_DIV_NUM 100
#define GAMMA_DIV_NUM 1000

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

double PhaseDeriv2nd(double gamma, double phi_main, double phi_sub){
	double K = 1.0;
	double phi_diff = phi_main - phi_sub;
	double phi_main_deriv = PhaseDeriv(gamma, phi_main, phi_sub);
	double phi_sub_deriv = PhaseDeriv(gamma, phi_sub, phi_main);
	double phi_diff_deriv = phi_main_deriv - phi_sub_deriv;
	return 2*K*(phi_main_deriv * cos(phi_main) - 2*gamma*phi_main_deriv*cos(2*phi_main))
					+ K * (
					       	phi_sub_deriv * cos(phi_sub) - 2*gamma*phi_sub_deriv*cos(2*phi_sub)
					       	+ phi_diff_deriv * cos(phi_diff) - 2*gamma*phi_diff_deriv*cos(2*phi_diff)
					       );
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
	FILE *fp_stable = myfopen("output_forBifurcation3_stable.csv", "w");
	FILE *fp_unstable = myfopen("output_forBifurcation3_unstable.csv", "w");

	// 出力ファイルにヘッダ行を入力
	fprintf(fp_stable, "gamma, phi_12, phi_13\n");
	fprintf(fp_unstable, "gamma, phi_12, phi_13\n");

	// 数値計算を実行
	gamma = 0;
	do{
		/* 必要な変数を定義 */
		double phi_12 = 0;
		double phi_13 = 0;
		int counter = 0; /* 平衡解の個数を数える */

		fprintf(stderr, "MESSAGE: calculation start (gamma = %f)\n", gamma);

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
				if ((f * f_up < 0 || f * f_right < 0) && (g * g_up < 0 || g * g_right < 0)){
					/* これを満たしているとき，f=0かつg=0，すなわちいまの(phi_12, phi_13)は平衡解である。 */
					/* 平衡解が見つかったら，さらにそれが安定か不安定かを判別 */
					double f_2ndDeriv = PhaseDeriv2nd(gamma, phi_12, phi_13);
					double g_2ndDeriv = PhaseDeriv2nd(gamma, phi_13, phi_12);
					if(f_2ndDeriv < 0 && g_2ndDeriv < 0){
						/* これを満たすとき，(phi_12, phi_13)は安定平衡 */
						/* 安定平衡な解は，その点での傾きが負であるところのみ */
						fprintf(fp_stable, "%f, %f, %f\n", gamma, phi_12, phi_13);
					} else {
						/* その他の解は，みな不安定平衡解である */
						fprintf(fp_unstable, "%f, %f, %f\n", gamma, phi_12, phi_13);
					}
					counter++;
				}
				phi_13 += M_PI / PHI_DIV_NUM;
			} while (phi_13 < 2 * M_PI);
			phi_12 += M_PI / PHI_DIV_NUM;
		} while (phi_12 < 2 * M_PI);

		fprintf(stderr, "when gamma = %f, number of equil sol is %d\n", gamma, counter);
		gamma += 0.001;
	} while (gamma < 1);

	fclose(fp_stable);
	fclose(fp_unstable);
	return 0;
}
