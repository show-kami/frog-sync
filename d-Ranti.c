// gcc -pedantic -Wall lib_RungeKutta.o lib_Frog100PhaseDeriv.o d-Ranti.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib_RungeKutta.h"
#include "lib_Frog100PhaseDeriv.h"

#define NUMofEQUS 100

int NumOfSlice(double start, double end, double step){
	return (end - start) / step + 1;
}

FILE* myfopen(char* FileName, char* type){
	FILE* fp = fopen(FileName, type);
	if(fp == NULL){
		printf("ERROR: File Not Found.\n");
		exit(1);
	}
	return fp;
}

int main(void){
	double **x;
	double (*f[NUMofEQUS])(double t, double *x);
	double x_0[NUMofEQUS];
	double t_0, t_end, dt;
	FILE* fp;
	int fi,fj;
	int NumOfSlices;
	double d;
	char str[1000];

	/* 格子間隔の入力 */
	printf("type the grid space...\n");
	fgets(str, sizeof(str), stdin);
	strtok(str, "\n"); /* fgetsで取得した行には末尾に改行が含まれてしまっているので，削除する */
	d = atof(str);
	printf("grid space: %f\n", d);

	// 微分方程式へのポインタを格納
	makePointerToFrogPhaseDeriv(f, NUMofEQUS);

	// 独立変数のスパンを決め，その分の独立変数・従属変数計算結果を格納する配列を用意
	t_0 = 0;
	t_end = 5;
	dt = 0.1;
	NumOfSlices = NumOfSlice(t_0, t_end, dt);
	x = malloc(sizeof(double *) * (NUMofEQUS + 1)); /* 解くべき方程式の本数+1だけのメモリを用意 */
	for(fi=0; fi<NUMofEQUS + 1; fi++){
		x[fi] = malloc(sizeof(double) * NumOfSlices);
	}

	// d-Rantiグラフを作成するための計算を実行・データを出力
	for(fj = 0; fj < 10; fj++){
		/* 必要な変数を定義 */
		double OrderPara_Re = 0;
		double OrderPara_Im = 0;
		double OrderPara_Abs = 0;

		/* 初期値を乱数によって格納 */
		srand(112+fj);
		for(fi = 0; fi < NUMofEQUS; fi++){
			x_0[fi] = (double)rand()/RAND_MAX * 2 * M_PI; /* 0-2piの間の一様乱数を格納しておく */
		}

		/* 数値計算を実行 */
		fprintf(stderr, "start calculating (%d times) ...\n", fj);
		executeRK(f, NUMofEQUS, t_0, t_end, dt, x_0, x);

		/* 秩序パラメータの最終値を計算 */
		for(fi = 0; fi < NUMofEQUS; fi++){
			double phase = x[fi+1][NumOfSlices-1];
			OrderPara_Re += cos(2*phase);
			OrderPara_Im += sin(2*phase);
		}
		OrderPara_Re = OrderPara_Re / NUMofEQUS;
		OrderPara_Im = OrderPara_Im / NUMofEQUS;
		OrderPara_Abs = sqrt(pow(OrderPara_Re, 2) + pow(OrderPara_Im, 2));

		/* 計算結果を書き込み */
		fp = myfopen("output_DRanti.csv", "a");
		fprintf(fp, "%f, %d, %f\n", d, fj, OrderPara_Abs);
	}

	return 0;
}
