// UNIVERSIDADE FEDERAL FLUMINENSE
// INSTITUTO DE FÍSICA
// FÍSICA COMPUTACIONAL
// PROFESSOR: NUNO CROKIDAKIS
// ALUNO: MARCOS PAULO G DE CASTRO
//
// PROGRAMA: LOGMAP.C - MAPA LOGÍSTICO EM LINGUAGEM C
// DATA: 15/06/2017

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

float logmap(float r) {

  float Y, X = 0.01;
  for(int i=1; i<=10000; i++) {
    Y = r*X*(1 - X);
    X = Y;
  }
  return Y;
}

int main (void) {

  float X, Y, X_long, dl = 0.001, r = 0.0;
  for(int i=1; i<=4000; i++) {

    r=r+dl;
    Y = 0;
    X = X_long = logmap(r);
    while( sqrt((X_long - Y)*(X_long - Y)) > 0.01 ) {
      Y = r*X*(1 - X);
      X = Y;
      printf("%.10f\t%.10f\n",r,Y);
    }
  }

  return 0;
}
