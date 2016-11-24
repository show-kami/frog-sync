#ifndef _LIB_RUNGEKUTTA_TERMINALPLUSMINUSEPSILON_H_
#define _LIB_RUNGEKUTTA_TERMINALPLUSMINUSEPSILON_H_
 
//  関数avgのプロトタイプ宣言
void executeRK(double (*f[])(double t, double *x), int num, double t_0, double t_end, double dt, double *x_0, double **X);
 
#endif // _LIB_RUNGEKUTTA_TERMINALPLUSMINUSEPSILON_H_
