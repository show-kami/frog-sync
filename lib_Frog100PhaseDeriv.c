#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_Frog100PhaseDeriv.h"

double Interaction(double theta_passive, double theta_active, int passive, int active){
	double K = 11.500000;
	double gamma = 1.300000;
	int x_passive = passive % 10;
	int y_passive = passive / 10;
	int x_active = active % 10;
	int y_active = active / 10;
	double distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
	double PhaseShiftPara = (distance / 345 + 0.02) / 0.25 * 2 * M_PI;
	double PhaseDiff = theta_active - theta_passive + PhaseShiftPara;
	return -K * (sin(PhaseDiff) - gamma * sin(2 * PhaseDiff));
}

double f_0(double t, double *x){
	int IndividualID = 0;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_1(double t, double *x){
	int IndividualID = 1;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_2(double t, double *x){
	int IndividualID = 2;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_3(double t, double *x){
	int IndividualID = 3;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_4(double t, double *x){
	int IndividualID = 4;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_5(double t, double *x){
	int IndividualID = 5;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_6(double t, double *x){
	int IndividualID = 6;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_7(double t, double *x){
	int IndividualID = 7;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_8(double t, double *x){
	int IndividualID = 8;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_9(double t, double *x){
	int IndividualID = 9;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_10(double t, double *x){
	int IndividualID = 10;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_11(double t, double *x){
	int IndividualID = 11;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_12(double t, double *x){
	int IndividualID = 12;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_13(double t, double *x){
	int IndividualID = 13;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_14(double t, double *x){
	int IndividualID = 14;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_15(double t, double *x){
	int IndividualID = 15;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_16(double t, double *x){
	int IndividualID = 16;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_17(double t, double *x){
	int IndividualID = 17;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_18(double t, double *x){
	int IndividualID = 18;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_19(double t, double *x){
	int IndividualID = 19;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_20(double t, double *x){
	int IndividualID = 20;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_21(double t, double *x){
	int IndividualID = 21;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_22(double t, double *x){
	int IndividualID = 22;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_23(double t, double *x){
	int IndividualID = 23;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_24(double t, double *x){
	int IndividualID = 24;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_25(double t, double *x){
	int IndividualID = 25;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_26(double t, double *x){
	int IndividualID = 26;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_27(double t, double *x){
	int IndividualID = 27;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_28(double t, double *x){
	int IndividualID = 28;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_29(double t, double *x){
	int IndividualID = 29;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_30(double t, double *x){
	int IndividualID = 30;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_31(double t, double *x){
	int IndividualID = 31;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_32(double t, double *x){
	int IndividualID = 32;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_33(double t, double *x){
	int IndividualID = 33;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_34(double t, double *x){
	int IndividualID = 34;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_35(double t, double *x){
	int IndividualID = 35;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_36(double t, double *x){
	int IndividualID = 36;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_37(double t, double *x){
	int IndividualID = 37;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_38(double t, double *x){
	int IndividualID = 38;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_39(double t, double *x){
	int IndividualID = 39;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_40(double t, double *x){
	int IndividualID = 40;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_41(double t, double *x){
	int IndividualID = 41;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_42(double t, double *x){
	int IndividualID = 42;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_43(double t, double *x){
	int IndividualID = 43;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_44(double t, double *x){
	int IndividualID = 44;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_45(double t, double *x){
	int IndividualID = 45;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_46(double t, double *x){
	int IndividualID = 46;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_47(double t, double *x){
	int IndividualID = 47;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_48(double t, double *x){
	int IndividualID = 48;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_49(double t, double *x){
	int IndividualID = 49;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_50(double t, double *x){
	int IndividualID = 50;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_51(double t, double *x){
	int IndividualID = 51;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_52(double t, double *x){
	int IndividualID = 52;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_53(double t, double *x){
	int IndividualID = 53;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_54(double t, double *x){
	int IndividualID = 54;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_55(double t, double *x){
	int IndividualID = 55;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_56(double t, double *x){
	int IndividualID = 56;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_57(double t, double *x){
	int IndividualID = 57;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_58(double t, double *x){
	int IndividualID = 58;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_59(double t, double *x){
	int IndividualID = 59;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_60(double t, double *x){
	int IndividualID = 60;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_61(double t, double *x){
	int IndividualID = 61;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_62(double t, double *x){
	int IndividualID = 62;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_63(double t, double *x){
	int IndividualID = 63;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_64(double t, double *x){
	int IndividualID = 64;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_65(double t, double *x){
	int IndividualID = 65;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_66(double t, double *x){
	int IndividualID = 66;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_67(double t, double *x){
	int IndividualID = 67;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_68(double t, double *x){
	int IndividualID = 68;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_69(double t, double *x){
	int IndividualID = 69;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_70(double t, double *x){
	int IndividualID = 70;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_71(double t, double *x){
	int IndividualID = 71;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_72(double t, double *x){
	int IndividualID = 72;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_73(double t, double *x){
	int IndividualID = 73;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_74(double t, double *x){
	int IndividualID = 74;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_75(double t, double *x){
	int IndividualID = 75;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_76(double t, double *x){
	int IndividualID = 76;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_77(double t, double *x){
	int IndividualID = 77;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_78(double t, double *x){
	int IndividualID = 78;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_79(double t, double *x){
	int IndividualID = 79;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_80(double t, double *x){
	int IndividualID = 80;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_81(double t, double *x){
	int IndividualID = 81;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_82(double t, double *x){
	int IndividualID = 82;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_83(double t, double *x){
	int IndividualID = 83;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_84(double t, double *x){
	int IndividualID = 84;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_85(double t, double *x){
	int IndividualID = 85;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_86(double t, double *x){
	int IndividualID = 86;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_87(double t, double *x){
	int IndividualID = 87;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_88(double t, double *x){
	int IndividualID = 88;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_89(double t, double *x){
	int IndividualID = 89;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_90(double t, double *x){
	int IndividualID = 90;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_91(double t, double *x){
	int IndividualID = 91;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_92(double t, double *x){
	int IndividualID = 92;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_93(double t, double *x){
	int IndividualID = 93;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_94(double t, double *x){
	int IndividualID = 94;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_95(double t, double *x){
	int IndividualID = 95;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_96(double t, double *x){
	int IndividualID = 96;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_97(double t, double *x){
	int IndividualID = 97;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_98(double t, double *x){
	int IndividualID = 98;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}

double f_99(double t, double *x){
	int IndividualID = 99;
	double omega = 8 * M_PI;
	double InteractionTotal = 0;
	int fi;
	double WeightTotal = 0;
	double Weight, distance;
	int x_passive, y_passive, x_active, y_active;
	for(fi = 0; fi < 100; fi++){
		if(fi != IndividualID){
			x_passive = IndividualID % 10;
			y_passive = IndividualID / 10;
			x_active = fi % 10;
			y_active = fi / 10;
			distance = sqrt(pow(x_passive - x_active, 2) + pow(y_passive - y_active, 2));
			Weight = 1 / distance;
			InteractionTotal += Weight * Interaction(x[IndividualID], x[fi], IndividualID, fi);
			WeightTotal += Weight;
		}
	}
	return omega + InteractionTotal / WeightTotal;
}


void makePointerToFrogPhaseDeriv(double (*f[])(double t, double *x), int n){
	f[0] = f_0; if (n == 1) return;
	f[1] = f_1; if (n == 2) return;
	f[2] = f_2; if (n == 3) return;
	f[3] = f_3; if (n == 4) return;
	f[4] = f_4; if (n == 5) return;
	f[5] = f_5; if (n == 6) return;
	f[6] = f_6; if (n == 7) return;
	f[7] = f_7; if (n == 8) return;
	f[8] = f_8; if (n == 9) return;
	f[9] = f_9; if (n == 10) return;
	f[10] = f_10; if (n == 11) return;
	f[11] = f_11; if (n == 12) return;
	f[12] = f_12; if (n == 13) return;
	f[13] = f_13; if (n == 14) return;
	f[14] = f_14; if (n == 15) return;
	f[15] = f_15; if (n == 16) return;
	f[16] = f_16; if (n == 17) return;
	f[17] = f_17; if (n == 18) return;
	f[18] = f_18; if (n == 19) return;
	f[19] = f_19; if (n == 20) return;
	f[20] = f_20; if (n == 21) return;
	f[21] = f_21; if (n == 22) return;
	f[22] = f_22; if (n == 23) return;
	f[23] = f_23; if (n == 24) return;
	f[24] = f_24; if (n == 25) return;
	f[25] = f_25; if (n == 26) return;
	f[26] = f_26; if (n == 27) return;
	f[27] = f_27; if (n == 28) return;
	f[28] = f_28; if (n == 29) return;
	f[29] = f_29; if (n == 30) return;
	f[30] = f_30; if (n == 31) return;
	f[31] = f_31; if (n == 32) return;
	f[32] = f_32; if (n == 33) return;
	f[33] = f_33; if (n == 34) return;
	f[34] = f_34; if (n == 35) return;
	f[35] = f_35; if (n == 36) return;
	f[36] = f_36; if (n == 37) return;
	f[37] = f_37; if (n == 38) return;
	f[38] = f_38; if (n == 39) return;
	f[39] = f_39; if (n == 40) return;
	f[40] = f_40; if (n == 41) return;
	f[41] = f_41; if (n == 42) return;
	f[42] = f_42; if (n == 43) return;
	f[43] = f_43; if (n == 44) return;
	f[44] = f_44; if (n == 45) return;
	f[45] = f_45; if (n == 46) return;
	f[46] = f_46; if (n == 47) return;
	f[47] = f_47; if (n == 48) return;
	f[48] = f_48; if (n == 49) return;
	f[49] = f_49; if (n == 50) return;
	f[50] = f_50; if (n == 51) return;
	f[51] = f_51; if (n == 52) return;
	f[52] = f_52; if (n == 53) return;
	f[53] = f_53; if (n == 54) return;
	f[54] = f_54; if (n == 55) return;
	f[55] = f_55; if (n == 56) return;
	f[56] = f_56; if (n == 57) return;
	f[57] = f_57; if (n == 58) return;
	f[58] = f_58; if (n == 59) return;
	f[59] = f_59; if (n == 60) return;
	f[60] = f_60; if (n == 61) return;
	f[61] = f_61; if (n == 62) return;
	f[62] = f_62; if (n == 63) return;
	f[63] = f_63; if (n == 64) return;
	f[64] = f_64; if (n == 65) return;
	f[65] = f_65; if (n == 66) return;
	f[66] = f_66; if (n == 67) return;
	f[67] = f_67; if (n == 68) return;
	f[68] = f_68; if (n == 69) return;
	f[69] = f_69; if (n == 70) return;
	f[70] = f_70; if (n == 71) return;
	f[71] = f_71; if (n == 72) return;
	f[72] = f_72; if (n == 73) return;
	f[73] = f_73; if (n == 74) return;
	f[74] = f_74; if (n == 75) return;
	f[75] = f_75; if (n == 76) return;
	f[76] = f_76; if (n == 77) return;
	f[77] = f_77; if (n == 78) return;
	f[78] = f_78; if (n == 79) return;
	f[79] = f_79; if (n == 80) return;
	f[80] = f_80; if (n == 81) return;
	f[81] = f_81; if (n == 82) return;
	f[82] = f_82; if (n == 83) return;
	f[83] = f_83; if (n == 84) return;
	f[84] = f_84; if (n == 85) return;
	f[85] = f_85; if (n == 86) return;
	f[86] = f_86; if (n == 87) return;
	f[87] = f_87; if (n == 88) return;
	f[88] = f_88; if (n == 89) return;
	f[89] = f_89; if (n == 90) return;
	f[90] = f_90; if (n == 91) return;
	f[91] = f_91; if (n == 92) return;
	f[92] = f_92; if (n == 93) return;
	f[93] = f_93; if (n == 94) return;
	f[94] = f_94; if (n == 95) return;
	f[95] = f_95; if (n == 96) return;
	f[96] = f_96; if (n == 97) return;
	f[97] = f_97; if (n == 98) return;
	f[98] = f_98; if (n == 99) return;
	f[99] = f_99; if (n == 100) return;
}

