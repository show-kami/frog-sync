// 各個体の位相の導関数を，入力された個体数の分だけ作成してcファイル・hファイルにまとめる。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* myfopen(char* FileName, char* type){
	FILE* fp = fopen(FileName, type);
	if(fp == NULL){
		printf("ERROR: File Not Found.\n");
		exit(1);
	}
	return fp;
}

int main(void){
	int NumOfFrogs = 100;
	double K = 8.0;
	double gamma = 1.3;
	double IdentityDistance = 0.25; /* カエルを配置する格子点の間隔を0.25 mにする。 */
	int fi;
	FILE *fp;
	int Decay_distance = 1; /* 1のとき，相互作用関数が距離の2乗に反比例して減衰するようにする。0のとき，減衰しないようにする。 */
	char PhaseShiftPara[] = "(distance / 345 + 0.03) / 0.25 * 2 * M_PI";

	// まずヘッダファイルを作成
	fp = myfopen("lib_Frog100PhaseDeriv.h", "w");
	fprintf(fp, "#ifndef _LIB_FROG100PHASEDERIV_H_\n");
	fprintf(fp, "#define _LIB_FROG100PHASEDERIV_H_\n\n");
	fprintf(fp, "double Interaction(double theta_passive, double theta_active, int passive, int active);\n");
	for(fi = 0; fi < NumOfFrogs; fi++){
		fprintf(fp, "double f_%d(double t, double *x);\n", fi);
	}
	fprintf(fp, "void makePointerToFrogPhaseDeriv(double (*f[])(double t, double *x), int n);\n");
	fprintf(fp, "\n#endif // _LIB_FROG100PHASEDERIV_H_\n");
	fclose(fp);

	// .cファイルを作成。ヘッダなどのインクルードをまず書く。
	fp = myfopen("lib_Frog100PhaseDeriv.c", "w");
	fprintf(fp, "#include <stdio.h>\n");
  fprintf(fp, "#include <stdlib.h>\n");
  fprintf(fp, "#include <math.h>\n");
  fprintf(fp, "#include \"lib_Frog100PhaseDeriv.h\"\n\n");

	// .cの本体のうち，相互作用関数の部分を書く
	fprintf(fp, "double Interaction(double theta_passive, double theta_active, int passive, int active){\n");
	fprintf(fp, "\tdouble K = %f;\n", K);
	fprintf(fp, "\tdouble gamma = %f;\n", gamma);
	fprintf(fp, "\tint x_passive = passive %% 10;\n");
	fprintf(fp, "\tint y_passive = passive / 10;\n");
	fprintf(fp, "\tint x_active = active %% 10;\n");
	fprintf(fp, "\tint y_active = active / 10;\n");
	fprintf(fp, "\tdouble distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2)) * %f;\n" ,IdentityDistance);
	fprintf(fp, "\tdouble PhaseShiftPara = %s;\n", PhaseShiftPara);
	fprintf(fp, "\tdouble PhaseDiff = theta_active - theta_passive + PhaseShiftPara;\n");
	fprintf(fp, "\treturn -K * (sin(PhaseDiff) - gamma * sin(2 * PhaseDiff));\n");
  fprintf(fp, "}\n\n");

	// .cの本体のうち，各個体の位相の導関数の部分を書く
	for(fi = 0; fi < NumOfFrogs; fi++){
		fprintf(fp, "double f_%d(double t, double *x){\n", fi);
	  fprintf(fp, "\tint IndividualID = %d;\n", fi);
	  fprintf(fp, "\tdouble omega = 8 * M_PI;\n");
	  fprintf(fp, "\tdouble InteractionTotal = 0;\n");
	  fprintf(fp, "\tint fi;\n");
	  fprintf(fp, "\tdouble WeightTotal = 0;\n");
	  fprintf(fp, "\tdouble Weight, distance;\n");
	  fprintf(fp, "\tint x_passive, y_passive, x_active, y_active;\n");
	  fprintf(fp, "\tfor(fi = 0; fi < %d; fi++){\n", NumOfFrogs);
	  fprintf(fp, "\t\tif(fi != IndividualID){\n");
	  fprintf(fp, "\t\t\tx_passive = IndividualID %% 10;\n");
	  fprintf(fp, "\t\t\ty_passive = IndividualID / 10;\n");
	  fprintf(fp, "\t\t\tx_active = fi %% 10;\n");
	  fprintf(fp, "\t\t\ty_active = fi / 10;\n");
	  if(Decay_distance == 0){
	  	fprintf(fp, "\t\t\tWeight = 1;\n");
	  } else if(Decay_distance == 1){
	  	fprintf(fp, "\t\t\tdistance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2)) * %f;\n", IdentityDistance);
	  	fprintf(fp, "\t\t\tWeight = 1 / pow(distance, 2);\n");
	  } else {
	  	fprintf(stderr, "ERROR: value of Decay_distance is wrong.\n");
	  	exit(1);
	  }
	  fprintf(fp, "\t\t\tInteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);\n");
	  fprintf(fp, "\t\t\tWeightTotal += Weight;\n");
	  fprintf(fp, "\t\t}\n");
	  fprintf(fp, "\t}\n");
	  // fprintf(fp, "\treturn omega + InteractionTotal / WeightTotal;\n");
	  fprintf(fp, "\treturn omega + InteractionTotal / %d;\n", NumOfFrogs - 1);
    fprintf(fp, "}\n\n");
	}
	fprintf(fp, "\n");

	// おまけで，main.cで使うmakePointerToFrogPhaseDeriv関数もここに書いておく。
	// makePointerToFrogPhaseDerivは，各個体の位相の微分方程式へのポインタを用意する関数。
	fprintf(fp, "void makePointerToFrogPhaseDeriv(double (*f[])(double t, double *x), int n){\n");
	for(fi = 0; fi < NumOfFrogs; fi++){
		fprintf(fp, "\tf[%d] = f_%d; if (n == %d) return;\n", fi, fi, fi+1);
	}
	fprintf(fp, "}\n\n");

	fclose(fp);

	if (remove("lib_Frog100PhaseDeriv.o") == 0){
		fprintf(stdout, "MESSAGE: lib_Frog100PhaseDeriv.o is deleted.\n");
		fprintf(stdout, "\ttype commands below on Terminal to make the .o file again\n");
		fprintf(stdout, "\tgcc -pedantic -Wall -c lib_Frog100PhaseDeriv.c\n");
	}

	fprintf(stdout, "completed.\n");

	return 0;
}
