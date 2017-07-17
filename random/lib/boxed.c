/*  UNIVERSIDADE FDERAL FLUMINENSE
    INSTITUTO DE FÍSICA
    FÍSICA COMPUTACIONAL

    PROFESSOR: NUNO CROKIDAKIS
    ALUNO: MARCOS PAULO GOMES DE CASTRO - MATRÍCULA: 113.025.115

    PROGRAMA: RANDOM.C - PROGRAMA GERADOR DE RANDÔMICOS

    §   USANDO  AS SEMENTE X_0 = 27 GERAR PARA OS SEGUINTES VALORES SEQUENCIAS PSEUDO-RANDÔMICAS:

	i	a = 85,	   m=256;
  	ii	a = 899,   m=32768;
  	iii	a = 16807, m=4294967295;
  	iv	a = 16807, m=2147483647;
*/

# include <math.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int main (void) {

  int long cont,l = 5e3 ,i, Y = 27,X = 43;

  int a = 16807;
  int m = 2147483647;

  double p,q;

  cont = 0;
  for(i=1; i<=l; i++) {
    for(int j=0; j<=5; j++) X = a*X % m;
    for(int j=0; j<=7; j++) Y = a*Y % m;
     p = (double)X/(m-1);
     q = (double)Y/(m-1);

     printf("%.10f\t%.10f\n",p,q); X = Y;
  }

  return 0;
}
