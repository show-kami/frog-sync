// めも: main.cをコンパイルするときには↓のように打つ。他のライブラリを含めてやんなきゃいけないから。
// gcc -pedantic -Wall lib_RungeKutta.o lib_Frog100PhaseDeriv.o main.c

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

double Interaction(double theta_passive, double theta_active){
	double K = 8.0;
	double gamma = 0.25;
	// double PhaseShiftPara = (0.33 - 0.295 - 1/345) / 0.33 * 2 * M_PI;
	double PhaseShiftPara = 0;
	double PhaseDiff = theta_active - theta_passive + PhaseShiftPara;
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


int NumOfSlice(double start, double end, double step){
	return (end - start) / step + 1;
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

//--------------------------------------------------------------------------
// 関数名	:plotPhaseTimeRel
// 概要		:各個体の位相の時間変化をファイルに出力
// 戻り値	:void
// 引数		:double **x		(x[n]は，出力すべきデータを格納した配列)
// 引数		:double t_0 	(出力すべきデータの最初の独立変数)
// 引数		:double t_end (出力すべきデータの最後の独立変数)
// 引数		:double dt		(出力すべきデータの独立変数の刻み幅)
//--------------------------------------------------------------------------
void outputPhaseTimeRel(double **x, double t_0, double t_end, double dt){
	int fi,fj;
	FILE *fp;

	// ヘッダ行を書く
	fp = myfopen("output_two_theta.csv", "w");
	fprintf(fp, "time");
	for(fi = 0; fi < NUMofEQUS; fi++){
		fprintf(fp, ", theta_%d", fi);
	}
	if(NUMofEQUS == 2){
		/* 2個体のときは，frog0とfrog1との位相差を出力する */
		fprintf(fp, ", PhaseDifference(0_1)");
	} else if(NUMofEQUS == 3){
		/* 3個体のときは，frog0とfrog2との位相差，frog1とfrog2との位相差も出力する */
		fprintf(fp, ", PhaseDifference(0_2)");
		fprintf(fp, ", PhaseDifference(1_2)");
	}
	fprintf(fp, ", OrderPara_drawX, OrderPara_drawY, OrderPara_Abs");
	fprintf(fp, ", OrderParaAnti_drawX, OrderParaAnti_drawY, OrderParaAnti_Abs");
	fprintf(fp, "\n");

	// 各時間における各数値を出力
	for(fi = 0; fi < NumOfSlice(t_0, t_end, dt); fi++){
		// 各個体の位相を書く (2個体 or 3個体のときには個体間の位相差も)
		fprintf(fp, "%f", x[0][fi]);
		for(fj = 0; fj < NUMofEQUS; fj++){
			fprintf(fp, ", %f", convertPhase(x[fj+1][fi]));
		}
		if(NUMofEQUS == 2){
			/* 2個のときには，frog0とfrog1との位相差を出力する */
			fprintf(fp, ", %f", convertPhase(fabs(x[1][fi] - x[2][fi])));
		} else if(NUMofEQUS == 3){
			/* 3個体のときは，frog0とfrog2との位相差，frog1とfrog2との位相差も出力する */
			fprintf(fp, ", %f", convertPhase(fabs(x[1][fi] - x[3][fi])));
			fprintf(fp, ", %f", convertPhase(fabs(x[2][fi] - x[3][fi])));
		}

		// 秩序パラメータを書く
		double OrderPara_drawX, OrderPara_drawY, OrderPara_Abs;
		double x_tmp = 0;
		double y_tmp = 0;
		for(fj = 0; fj < NUMofEQUS; fj++){
			double phase = x[fj+1][fi];
			x_tmp += cos(phase);
			y_tmp += sin(phase);
		}
		OrderPara_drawX = x_tmp / NUMofEQUS;
		OrderPara_drawY = y_tmp / NUMofEQUS;
		OrderPara_Abs = sqrt(pow(OrderPara_drawX, 2) + pow(OrderPara_drawY, 2));
		fprintf(fp, ", %f, %f, %f", OrderPara_drawX, OrderPara_drawY, OrderPara_Abs);

		// 秩序パラメータ (逆相同期用) を書く
		x_tmp = 0;
		y_tmp = 0;
		for(fj = 0; fj < NUMofEQUS; fj++){
			double phase = x[fj+1][fi];
			x_tmp += cos(2*phase);
			y_tmp += sin(2*phase);
		}
		OrderPara_drawX = x_tmp / NUMofEQUS;
		OrderPara_drawY = y_tmp / NUMofEQUS;
		OrderPara_Abs = sqrt(pow(OrderPara_drawX, 2) + pow(OrderPara_drawY, 2));
		fprintf(fp, ", %f, %f, %f", OrderPara_drawX, OrderPara_drawY, OrderPara_Abs);

		// 改行
		fprintf(fp, "\n");
	}

	fclose(fp);
	return;
}

//--------------------------------------------------------------------------
// 関数名	:outputRasterPlotSource
// 概要		:各個体が鳴いたタイミングを表すラスタープロットを作成するためのデータを出力
// 戻り値	:void
// 引数		:double **x (各個体の，各時間ごとの位相データ)
// 引数		:double t_0 	(出力すべきデータの最初の独立変数)
// 引数		:double t_end (出力すべきデータの最後の独立変数)
// 引数		:double dt		(出力すべきデータの独立変数の刻み幅)
//--------------------------------------------------------------------------
void outputRasterPlotSource(double **x, double t_0, double t_end, double dt){
	int fi, fj;
	FILE *fp = myfopen("output_two_thetaForRasterPlot.csv","w");

	// ヘッダ行を書く
	fprintf(fp, "time");
	for(fi = 0; fi < NUMofEQUS; fi++){
		fprintf(fp, ", frog_%d", fi);
	}
	fprintf(fp, "\n");

	// ラスタープロット用データを書く。
	/* 位相が0あたりになったら個体番号を出力。他では0を出力。 */
	for(fi = 0; fi < NumOfSlice(t_0, t_end, dt); fi++){
		/* 1行に各時刻のデータを出力し，改行する */
		fprintf(fp, "%f", x[0][fi]); /* 時刻を1列目に出力 */
		for(fj = 0; fj < NUMofEQUS; fj++){
			/* 各列に各個体のデータを出力する */
			double ConvertedPhase = convertPhase(x[fj+1][fi]);
			if (ConvertedPhase >= 0 && ConvertedPhase <= M_PI/2){
				/* 位相が0~PI/2の範囲にあるときは個体番号を出力する */
				fprintf(fp, ", %d", fj);
			} else {
				/* そうでなければ-1を出力する。 */
				fprintf(fp, ", -1");
			}
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
	return;
}

void outputDthetaDt(double **x, double t_0, double t_end, double dt){
	int fi, fj;
	double tmp[NUMofEQUS];
	FILE *fp = myfopen("output_two_DthetaDt.csv","w");

	// ヘッダ行を書く
	fprintf(fp, "time, frog_A, frog_B\n");

	// 数値を書く
	for(fi = 0; fi < NumOfSlice(t_0, t_end, dt); fi++){
		fprintf(fp, "%f, ", x[0][fi]);

		for(fj = 0; fj < NUMofEQUS; fj++){
			tmp[fj] = x[fj][fi];
		}
		fprintf(fp, "%f, %f\n", f_A(0, tmp), f_B(0, tmp));
	}
}

int main(void){
	double **x;
	double (*f[NUMofEQUS])(double t, double *x);
	double x_0[NUMofEQUS];
	double t_0, t_end, dt;
	int fi;

	// 微分方程式へのポインタを格納
	f[0] = f_A;
	f[1] = f_B;

	// 従属変数の初期値を格納
	x_0[0] = 0;
	x_0[1] = M_PI/4;

	// 独立変数のスパンを決め，その分の独立変数・従属変数計算結果を格納する配列を用意
	t_0 = 0;
	t_end = 5;
	dt = 0.001;
	x = malloc(sizeof(double *) * (NUMofEQUS + 1)); /* 解くべき方程式の本数+1だけのメモリを用意 */
	for(fi=0; fi<NUMofEQUS + 1; fi++){
		x[fi] = malloc(sizeof(double) * NumOfSlice(t_0, t_end, dt));
	}

	// 数値計算を実行
	fprintf(stderr, "start calc...\n");
	executeRK(f, NUMofEQUS, t_0, t_end, dt, x_0, x);

	// 各個体の位相の時間変化を出力
	outputPhaseTimeRel(x, t_0, t_end, dt);

	// ラスタープロット用のデータを出力
	outputRasterPlotSource(x, t_0, t_end, dt);

	// dtheta/dtの値を出力
	outputDthetaDt(x, t_0, t_end, dt);

	return 0;
}
