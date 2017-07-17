/*

  UNIVERSIDADE FEDERAL FLUMINENSE
  INSTITUTO DE FÍSICA
  FÍSICA COMPUTACIONAL

  PROFESSOR: NUNO CROKIDAKIS
  ALUNO: MARCOS PAULO GOMES DE CASTRO - MATRÍCULA: 113.025.115

  PROGRAMA: ISING.C - SIMULAÇÃO DE MONTE CARLO PARA O MODELO DE ISING.
  MÉTODO: METROPOLE

  DATA: 15.07.2017

  § Simule   o   modelo  de  Ising   na   rede   quadrada   L x L,   com  condições  de  contorno  periódicas,
    considerando L=128. Inicie com uma configuração aleatória de spins, com 50% de spins +1 e 50% de spins -1.
    Plote curvas da magnetização por spin em função do tempo. Você deve ver a magnetização flutuar e variar no
    tempo, até atingir o equilíbrio. Considere diferentes temperaturas, algumas abaixo de Tc=2.27 (por exemplo
    T=1.0, 1.5, 1.8, 2.0 e 2.2) e outras acima de Tc (por exemplo 2.5, 2.7, 3.0 e 3.5). Não é necessário fazer
    médias sobre simulações diferentes.

*/

# include <math.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main (int argc,char *argv[]) {

  int L = (int)atoi(argv[1]);

  int sum,i,j,I,J,M, S[L+1][L+1];

  double r,E,T = (double)atof(argv[2]); // Temperatura

  srand(time(NULL));

  for(int i=1; i<=L; i++) {
    for(int j=1; j<=L; j++) {
      r = (double)rand()/RAND_MAX;
      if( r <= 0.5 ) {
        S[i][j] =  1;
      } else {
        S[i][j] = -1;
      }
    }
  }

  for(int t=1; t <=10000; t++) {

    for(int k=1; k<=L*L; k++) {

      i = (int)(rand() % L + 1);

      j = (int)(rand() % L + 1);

        sum = 0;

        I = i - 1; if(i == 1) I = L;
        sum += S[I][j];

        J = j - 1; if(j == 1) J = L;
        sum += S[i][J];

        I = i + 1; if(i == L) I = 1;
        sum += S[I][j];

        J = j + 1; if(j == L) J = 1;
        sum += S[i][J];

        E = (double)2*S[i][j]*sum;
        if( E <= 0) S[i][j] = (-1)*S[i][j];

        r = (double)rand()/RAND_MAX;
        if( E >  0 && r <= exp(-1*E/T) ) S[i][j] = (-1)*S[i][j];

    }

    M = 0;
    for(i=1; i<=L; i++) {
      for( j=1; j<=L; j++) {
        M += S[i][j];
      }
    }

    printf("%5d\t%3.10f\n",t,(double)M/(L*L));
  }

  return 0;
}
