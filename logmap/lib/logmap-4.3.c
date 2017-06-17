// UNIVERSIDADE FEDERAL FLUMINENSE
// INSTITUTO DE FÍSICA
// FÍSICA COMPUTACIONAL
// PROFESSOR: NUNO CROKIDAKIS
// ALUNO: MARCOS PAULO G DE CASTRO
//
// PROGRAMA: LOGMAP.C - MAPA LOGÍSTICO EM LINGUAGEM C
// DATA: 13/06/2017

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

float logmap(float X,float r,int L) {

  float Y;
  for(int i=1; i<=L; i++) {
    Y = r*X*(1 - X);
    X = Y;
    printf("%.10f\n",Y);
  }

  return 0;
}

int main (void) {

  logmap(0.01, 3.47, 10000);

  return 0;
}
