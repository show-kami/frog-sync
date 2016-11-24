#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_RungeKutta.h"

#define NUMofEQUS 3

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

double FrogDerivative(int IDNo, double *phase){
	double omega = 8 * M_PI;
	double SigmaInteraction = 0;
	int fi;
	for(fi = 0; fi < NUMofEQUS; fi++){
		if(fi != IDNo){
			SigmaInteraction += Interaction(phase[IDNo], phase[fi]);
		}
	}
	return omega + SigmaInteraction / (NUMofEQUS - 1);
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

	/* ヘッダ行を書く */
	fp = myfopen("output_theta.csv", "w");
	fprintf(fp, "time");
	for(fi = 0; fi < NUMofEQUS; fi++){
		fprintf(fp, ", theta_%d", fi+1);
	}
	if(NUMofEQUS >= 2){
		/* 2個体以上いるときは，frog1とfrog2との位相差を出力する */
		fprintf(fp, ", PhaseDifference(1_2)");
	}
	if(NUMofEQUS >= 3){
		/* 3個体以上いるときは，frog1とfrog3との位相差，frog2とfrog3との位相差も出力する */
		fprintf(fp, ", PhaseDifference(1_3)");
		fprintf(fp, ", PhaseDifference(2_3)");
	}
	fprintf(fp, "\n");

	/* 数値を書く */
	for(fi = 0; fi < NumOfSlice(t_0, t_end, dt); fi++){
		fprintf(fp, "%f", x[0][fi]);
		for(fj = 0; fj < NUMofEQUS; fj++){
			fprintf(fp, ", %f", x[fj+1][fi]);
		}
		if(NUMofEQUS >= 2){
			/* 2個体以上いるときには，frog1とfrog2との位相差を出力する */
			fprintf(fp, ", %f", convertPhase(fabs(x[1][fi] - x[2][fi])));
		}
		if(NUMofEQUS >= 3){
			/* 3個体以上いるときは，frog1とfrog3との位相差，frog2とfrog3との位相差も出力する */
			fprintf(fp, ", %f", convertPhase(fabs(x[1][fi] - x[3][fi])));
			fprintf(fp, ", %f", convertPhase(fabs(x[2][fi] - x[3][fi])));
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
	return;
}

void outputNullclineSource(void){
	int fi;
	double phi12 = 0;
	double phi13 = 0;
	double K = 1.0;
	double gamma = 0.25;
	FILE *fp[2];
	fp[0] = myfopen("output_NullclineOfPhi12.txt","w");
	fp[1] = myfopen("output_NullclineOfPhi13.txt","w");
	for(fi = 0; fi < 2; fi++){
		phi12 = 0;
		phi13 = 0;
		do{
			phi12 = 0;
			do{
				double value = 0;
				if(fi == 0){
					value = 2*K*(sin(phi12)-gamma*sin(2*phi12)) + K*(sin(phi13)-gamma*sin(2*phi13)+sin(phi12-phi13)-gamma*sin(2*(phi12-phi13)));
				} else if(fi == 1){
					value = 2*K*(sin(phi13)-gamma*sin(2*phi13)) + K*(sin(phi12)-gamma*sin(2*phi12)+sin(phi13-phi12)-gamma*sin(2*(phi13-phi12)));
				}
				fprintf(fp[fi], "%f\t", value);
				phi12 += 2 * M_PI / 1000;
			} while(phi12 < 2*M_PI);
			fprintf(fp[fi], "\n");
			phi13 += 2 * M_PI / 1000;
		} while (phi13 < 2*M_PI);
	}
	fclose(fp[0]);
	fclose(fp[1]);
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
	FILE *fp = myfopen("output_thetaForRasterPlot.csv","w");

	// ヘッダ行を書く
	fprintf(fp, "time");
	for(fi = 0; fi < NUMofEQUS; fi++){
		fprintf(fp, ", frog_%d", fi+1);
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
				fprintf(fp, ", %d", fj+1);
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

int main(void){
	double **x;
	double (*f[NUMofEQUS])(double t, double *x);
	double x_0[NUMofEQUS];
	double t_0, t_end, dt;
	int i;

	// 微分方程式へのポインタを格納
	f[0] = f_A;
	if(NUMofEQUS >= 2) f[1] = f_B;
	if(NUMofEQUS >= 3) f[2] = f_C;

	// 従属変数の初期値を格納
	x_0[0] = 0;
	if(NUMofEQUS >= 2) x_0[1] = M_PI/4;
	if(NUMofEQUS >= 3) x_0[2] = M_PI/8;
	fprintf(stdout, "Initial Phase Difference of frog1 and frog2: %f\n", fabs(x_0[0] - x_0[1]));

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
	outputPhaseTimeRel(x, t_0, t_end, dt);

	// 相平面に描くヌルクラインを描画するためのデータを出力
	// outputNullclineSource();
	// TODO: これで出力した結果を，Rでどう行列に直してヌルクライン描けばいいのか…。

	// ラスタープロット用のデータを出力
	outputRasterPlotSource(x, t_0, t_end, dt);

	return 0;
}
