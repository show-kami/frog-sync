#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_RungeKutta.h"

//--------------------------------------------------------------------------
// 関数名	:executeRK
// 概要		:常微分方程式 dx/dt = f(t, x) をルンゲ・クッタ法によって数値的に解き，結果をtxtに書き出す。
// 戻り値	:void
// 引数		:double *f (解くべき常微分方程式の導関数 dx/dt=f(t,x)へのポインタ)
// 引数		:int num (解くべき常微分方程式の連立本数)
// 引数		:double t_0		(独立変数のスパン: 初期値)
// 引数		:double t_end (独立変数のスパン: 終了値)
// 引数		:double dt 		(独立変数の刻み幅)
// 引数		:double *x_0 (従属変数の初期値を格納する配列の先頭要素へのポインタ)
// 引数		:double **X (数値計算結果を格納する配列の先頭要素へのポインタ: x[0]に独立変数を，x[1]~に従属変数を入れる。xはnum x NumOfSliceの多次元配列)
//--------------------------------------------------------------------------
void executeRK(double (*f[])(double t, double *x), int num, double t_0, double t_end, double dt, double *x_0, double **X){
	int NumOfSlice;
	double *t; /* わかりやすく，独立変数を格納する配列を用意する。最後にX[0]にまとめて代入する */
	double **x; /* わかりやすく，従属変数を格納する配列を用意する。最後にX[1]~にまとめて代入する */
	int index, fi;
	int TerminationIndex = 0; /* 2変数のときは，変数間の差の変化がなくなってきたら (i.e. 2変数が同期したら)計算を打ち切る。そのときの計算回数を格納する */
	index = 0;
	NumOfSlice = (t_end - t_0) / dt + 1;
	t = malloc(sizeof(double) * NumOfSlice);
	x = malloc(sizeof(double *) * num);
	for(fi = 0; fi < num; fi++){
		x[fi] = malloc(sizeof(double) * NumOfSlice);
	}

	t[0] = t_0; /* 独立変数 */
	for(fi = 0; fi < num; fi++){
		x[fi][0] = x_0[fi]; /* 従属変数 */
	}

	// ルンゲ・クッタ法を実行
	do{
		/* 時刻t-dtでの従属変数の値を元に，時刻tでの従属変数の値を計算する */
		double *tmp = malloc(sizeof(double) * num);
		double *k1 = malloc(sizeof(double) * num);
		double *k2 = malloc(sizeof(double) * num);
		double *k3 = malloc(sizeof(double) * num);
		double *k4 = malloc(sizeof(double) * num);
		if(tmp == NULL || k1 == NULL || k2 == NULL || k3 == NULL || k4 == NULL){
			fprintf(stderr, "ERROR: Allocation has been failed.\n");
			exit(1);
		}

		/* 各導関数について，k1を計算 */
		for(fi = 0; fi < num; fi++){
			tmp[fi] = x[fi][index];
		}
		for(fi = 0; fi < num; fi++){
			k1[fi]  = (*f[fi])(t[index], tmp);
		}

		/* 各導関数について，k2を計算 */
		for(fi = 0; fi < num; fi++){
			tmp[fi] = x[fi][index] + dt * k1[fi] / 2;
		}
		for(fi = 0; fi < num; fi++){
			k2[fi]  = (*f[fi])(t[index] + dt/2 , tmp);
		}

		/* 各導関数について，k3を計算 */
		for(fi = 0; fi < num; fi++){
			tmp[fi] = x[fi][index] + dt * k2[fi] / 2;
		}
		for(fi = 0; fi < num; fi++){
			k3[fi]  = (*f[fi])(t[index] + dt/2 , tmp);
		}

		/* 各導関数について，k4を計算 */
		for(fi = 0; fi < num; fi++){
			tmp[fi] = x[fi][index] + dt * k3[fi];
		}
		for(fi = 0; fi < num; fi++){
			k4[fi]  = (*f[fi])(t[index] + dt , tmp); 
		}

		/* k1~k4の値をもとに，解の値を計算 */
		for(fi = 0; fi < num; fi++){
			x[fi][index + 1] = x[fi][index] + dt * (k1[fi] + 2*k2[fi] + 2*k3[fi] + k4[fi]) / 6;
			t[index + 1] = t_0 + dt * (index + 1);
		}

		/* 2元連立の場合に限って，位相差が変わらなくなってきたら計算を打ち切る */
		if (num == 2){
			double  DerivativeOfPhaseDiff;
			tmp[0] = x[0][index + 1];
			tmp[1] = x[1][index + 1];
			DerivativeOfPhaseDiff = (*f[0])(t[index] , tmp) - (*f[1])(t[index], tmp);
			if (fabs(DerivativeOfPhaseDiff) < 0.001){
				TerminationIndex = index + 1;
				fprintf(stdout, "MESSAGE: Phase Difference has been settled. Calculation can be terminated.\n");
				fprintf(stdout, "         calculation was tried %d times. (t = %f)\n", TerminationIndex, t[TerminationIndex]);
				break;
			}
		}

		/* 終了処理 */
		free(tmp);
		free(k1);
		free(k2);
		free(k3);
		free(k4);
		index++;
	} while(index < NumOfSlice);
	if(TerminationIndex == 0){
		TerminationIndex = index;
	}

	// 数値計算結果を，返される配列にコピーする
	for(index = 0; index < NumOfSlice; index++){
		if (index < TerminationIndex){
			X[0][index] = t[index];
			for(fi = 0; fi < num; fi++){
				X[fi+1][index] = x[fi][index];
			}
		} else {
			X[0][index] = t[TerminationIndex];
			for(fi = 0; fi < num; fi++){
				X[fi+1][index] = x[fi][TerminationIndex];
			}
		}
	}

	// 終了処理
	free(t);
	return;
}
