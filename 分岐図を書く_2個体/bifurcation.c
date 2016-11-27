#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMofEQUS 2
#define PHI_DIV_NUM 1000
#define GAMMA_START 0
#define GAMMA_END 2

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

double Interaction(double theta_passive, double theta_active, double gamma){
	double K = 1.0;
	// double gamma = 0.25;
	double PhaseDiff = theta_active - theta_passive;
	return -K * (sin(PhaseDiff) - gamma * sin(2 * PhaseDiff));
}

double FrogDerivative(int IDNo, double gamma, double *phase){
	double omega = 8 * M_PI;
	double SigmaInteraction = 0;
	int fi;
	for(fi = 0; fi < NUMofEQUS; fi++){
		if(fi != IDNo){
			SigmaInteraction += Interaction(phase[IDNo], phase[fi], gamma);
		}
	}
	return omega + SigmaInteraction / (NUMofEQUS - 1);
}

// dφ/dt の値を返す
double PhaseDeriv(double phi, double gamma){
	double K = 1.0;
	return 2 * K * (sin(phi) - gamma * sin(2*phi));
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
	double **x;
	double x_0[NUMofEQUS];
	double t_0, t_end, dt;
	double gamma;
	int i,fi;
	FILE *fp = myfopen("output_forBifurcation.csv", "w");

	// 従属変数の初期値を格納
	x_0[0] = 0;
	if(NUMofEQUS >= 2) x_0[1] = M_PI/4;
	if(NUMofEQUS >= 3) x_0[2] = M_PI/8;
	fprintf(stdout, "Initial Phase Difference of frog1 and frog2: %f\n", fabs(x_0[0] - x_0[1]));

	// 独立変数のスパンを決め，その分の独立変数・従属変数計算結果を格納する配列を用意
	t_0 = 0;
	t_end = 100;
	dt = 0.01;
	x = malloc(sizeof(double *) * (NUMofEQUS + 1)); /* 解くべき方程式の本数+1だけのメモリを用意 */
	for(i=0; i<NUMofEQUS + 1; i++){
		x[i] = malloc(sizeof(double) * NumOfSlice(t_0, t_end, dt));
	}

	// 数値計算を実行
	gamma = GAMMA_START;
	fprintf(fp, "gamma, StableEquil_1, StableEquil_2, UnstableEquil_1, UnstableEquil_2\n");
	do{
		/* 必要な変数を定義 */
		double dphidt[2][PHI_DIV_NUM]; 
			/* φ=0...2piをPHI_DIV_NUM分割して，dphidt[0]にそれらφの値を格納する */
			/* それぞれのφにおけるdφ/dtの値を，dphidt[1]にこの配列に格納する。 */
		double phi_equil[4] = {-1, -1, -1, -1};
			/* φの平衡解を格納する。 */
			/* phi_equil[0]とphi_equil[1]には安定平衡解を。 */
			/* phi_equil[2]とphi_equil[3]には不安定平衡解を。 */

		/* dφ/dt = 2K~~ とφとの関係を調べる */
		for(fi = 0; fi < PHI_DIV_NUM; fi++){
			dphidt[0][fi] = 2 * M_PI * fi / PHI_DIV_NUM;
			dphidt[1][fi] = PhaseDeriv(dphidt[0][fi], gamma);
		}

		// 平衡点を見つける
		for(fi = 0; fi < PHI_DIV_NUM; fi++){
			// double IfThisValueIsMinusThenEquivSolExists = dphidt[1][fi] * dphidt[1][fi-1];
			// 	// TODO: fi-1を参照するから，fi=0のときやばい
			// double IfThisValueIsMinusThenSolIsStable = Phase2ndDeriv(dphidt[0][fi], gamma);
			if(dphidt[1][fi-1] >= 0 && dphidt[1][fi] <= 0){
				/* 安定平衡解を見つけたとき */
				/* phi_stable1が空いていればそこに，空いていなければphi_stable2に，安定平衡となるφを格納 */
				if(phi_equil[0] == -1){
					phi_equil[0] = dphidt[0][fi];
				} else if(phi_equil[1] == -1){
					if(dphidt[1][fi-1] == 0 || dphidt[1][fi] == 0) continue;
					phi_equil[1] = dphidt[0][fi];
				} else {
					fprintf(stderr, "ERROR: too many stable equilibrium solutions exist when (gamma, phi) = (%f, %f).\n", gamma, dphidt[0][fi]);
					exit(1);
				}
			}
			if(dphidt[1][fi-1] <= 0 && dphidt[1][fi] >= 0){
				/* 不安定平衡解を見つけた時 */
				if(phi_equil[2] == -1){
					phi_equil[2] = dphidt[0][fi];
				} else if(phi_equil[3] == -1){
					if(dphidt[1][fi-1] == 0 || dphidt[1][fi] == 0) continue;
					phi_equil[3] = dphidt[0][fi];
				} else{
					fprintf(stderr, "ERROR: too many unstable equilibrium solutions exist when (gamma, phi) = (%f, %f).\n", gamma, dphidt[0][fi]);
					exit(1);
				}
			}
		}

		// ファイルに出力
		fprintf(fp, "%.3f", gamma);
		for(fi=0; fi<4; fi++){
			if(phi_equil[fi] == -1){
				fprintf(fp, ", -1");
			} else {
				fprintf(fp, ", %f", phi_equil[fi]);
			}
		}
		fprintf(fp, "\n");

		gamma += 0.001;
	} while (gamma < GAMMA_END);

	// executeRK(f, NUMofEQUS, t_0, t_end, dt, x_0, x);

	fclose(fp);
	return 0;
}
