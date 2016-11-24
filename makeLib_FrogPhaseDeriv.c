// 各個体の位相の導関数を，入力された個体数の分だけ作成してcファイル・hファイルにまとめる。

#include <stdio.h>
#include <stdlib.h>

FILE* myfopen(char* FileName, char* type){
	FILE* fp = fopen(FileName, type);
	if(fp == NULL){
		printf("ERROR: File Not Found.\n");
		exit(1);
	}
	return fp;
}

int main(void){
	int NumOfFrogs;
	char str[1000];
	int fi;
	FILE *fp;

	printf("How many frogs are you gonna consider? ...\n");
	fgets(str,sizeof(str), stdin);
	NumOfFrogs = atoi(str);
	if (NumOfFrogs == 0){
		fprintf(stderr, "ERROR: typed value is something wrong.\n");
		exit(1);
	}

	// まずヘッダファイルを作成
	fp = myfopen("lib_FrogPhaseDeriv.h", "w");
	fprintf(fp, "#ifndef _LIB_FROGPHASEDERIV_H_\n");
	fprintf(fp, "#define _LIB_FROGPHASEDERIV_H_\n\n");
	for(fi = 0; fi < NumOfFrogs; fi++){
		fprintf(fp, "double f_%d(double t, double *x);\n", fi);
	}
	fprintf(fp, "void makePointerToFrogPhaseDeriv(double (*f[])(double t, double *x), int n);\n");
	fprintf(fp, "\n#endif // _LIB_FROGPHASEDERIV_H_\n");
	fclose(fp);

	// .cファイルを作成。ヘッダなどのインクルードをまず書く。
	fp = myfopen("lib_FrogPhaseDeriv.c", "w");
	fprintf(fp, "#include <stdio.h>\n");
  fprintf(fp, "#include <stdlib.h>\n");
  fprintf(fp, "#include <math.h>\n");
  fprintf(fp, "#include \"lib_FrogPhaseDeriv.h\"\n\n");

	// .cの本体のうち，相互作用関数の部分を書く
	fprintf(fp, "double Interaction(double theta_passive, double theta_active){");
	fprintf(fp, "\tdouble K = 1.0;\n");
	fprintf(fp, "\tdouble gamma = 0.25;\n");
	fprintf(fp, "\tdouble PhaseDiff = theta_active - theta_passive;\n");
	fprintf(fp, "\treturn -K * (sin(PhaseDiff) - gamma * sin(2 * PhaseDiff));\n");
  fprintf(fp, "}\n\n");

	// .cの本体のうち，各個体の位相の導関数の部分を書く
	for(fi = 0; fi < NumOfFrogs; fi++){
		fprintf(fp, "double f_%d(double t, double *x){\n", fi);
	  fprintf(fp, "\tint IndividualID = %d;\n", fi);
	  fprintf(fp, "\tdouble omega = 8 * M_PI;\n");
	  fprintf(fp, "\tdouble result = omega;\n");
	  fprintf(fp, "\tint fi;\n");
	  fprintf(fp, "\tfor(fi = 0; fi < %d; fi++){\n", NumOfFrogs);
	  fprintf(fp, "\t\tif(fi != IndividualID){\n");
	  fprintf(fp, "\t\t\tresult += Interaction(x[IndividualID], x[fi]) / %d;\n", NumOfFrogs-1);
	  fprintf(fp, "\t\t}\n");
	  fprintf(fp, "\t}\n");
	  fprintf(fp, "\treturn result;\n");
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

	if (remove("lib_FrogPhaseDeriv.o") == 0){
		fprintf(stdout, "MESSAGE: lib_FrogPhaseDeriv.o is deleted.\n");
		fprintf(stdout, "\ttype commands below on Terminal to make the .o file again\n");
		fprintf(stdout, "\tgcc -pedantic -Wall -c lib_FrogPhaseDeriv.c\n");
	}

	return 0;
}
