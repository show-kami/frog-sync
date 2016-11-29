#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMofEQUS 2
#define PHI_DIV_NUM 1000
#define R_START 0
#define R_END 10*sqrt(2)

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
double DphiDt(double phi, double r){
	double K = 8.0;
	double gamma = 1.3;
	double alpha = (r/345 + 0.02) / 0.25 * 2 * M_PI;
	return K * (sin(phi + alpha) - gamma * sin(2*(phi + alpha)) + sin(phi - alpha) - gamma * sin(2 * (phi - alpha)));
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
	double r;
	double value, tmp;
	double phi = 0;
	FILE *fp_stable = myfopen("output_forBifurcationOfPhaseshift_stable.csv", "w");
	FILE *fp_unstable = myfopen("output_forBifurcationOfPhaseshift_unstable.csv", "w");

	// 数値計算を実行
	r = R_START;
	do{
		phi = 0;
		tmp = DphiDt(-M_PI / PHI_DIV_NUM, r);
		/* ファイルの各行の先頭に，rの値を出力する */
		fprintf(fp_stable, "%f", r);
		fprintf(fp_unstable, "%f",r);
		do{
			/* あるrの値に対して，平衡解をφ=[0,2pi)の範囲で探す。 */
			value = DphiDt(phi, r);
			if ((tmp > 0 && value < 0) || (tmp > 0 && value == 0)){
				/* この条件を満たすとき，このphiは安定平衡解である */
				fprintf(fp_stable, ", %f", phi);
			}
			if ((tmp < 0 && value > 0) || (tmp < 0 && value == 0)){
				/* この条件を満たすとき，このphiは不安定平衡解である */
				fprintf(fp_unstable, ", %f", phi);
			}

			tmp = value;
			phi += M_PI / PHI_DIV_NUM;
		} while (phi < 2 * M_PI);

		/* 各行の最後に改行を入れる。 */
		fprintf(fp_stable, "\n");
		fprintf(fp_unstable, "\n");
		
		r += 0.01;
	} while (r < R_END);

	// executeRK(f, NUMofEQUS, t_0, t_end, dt, x_0, x);

	fclose(fp_stable);
	fclose(fp_unstable);
	return 0;
}
