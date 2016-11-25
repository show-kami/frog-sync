#ifndef _LIB_FROGPHASEDERIV_H_
#define _LIB_FROGPHASEDERIV_H_

double f_0(double t, double *x);
double f_1(double t, double *x);
void makePointerToFrogPhaseDeriv(double (*f[])(double t, double *x), int n);

#endif // _LIB_FROGPHASEDERIV_H_
