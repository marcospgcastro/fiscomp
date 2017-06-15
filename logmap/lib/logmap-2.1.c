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

  float Y = 0;
  printf("%.10f\t%.10f\n",X,Y);
  for(int i=1; i<=L; i++) {
    Y = r*X*(1 - X);
    printf("%.10f\t%.10f\n",X,Y);
    X = Y;
    printf("%.10f\t%.10f\n",X,Y);
  }

  return 0;
}

int main (void) {

  logmap(0.5, 0.9, 100);

  return 0;
}
