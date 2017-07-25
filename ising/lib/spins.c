/*

  UNIVERSIDADE FEDERAL FLUMINENSE
  INSTITUTO DE FÍSICA
  FÍSICA COMPUTACIONAL

  PROFESSOR: NUNO CROKIDAKIS
  ALUNO: MARCOS PAULO GOMES DE CASTRO - MATRÍCULA: 113.025.115

  PROGRAMA: ISING.C - SIMULAÇÃO DE MONTE CARLO PARA O MODELO DE ISING.
  MÉTODO: METROPOLE

  DATA: 15.07.2017

  § Simule  o  modelo  de  Ising  na  rede  quadrada   L x L,  com condições de contorno periódicas,
    considerando L=16, 24, 32, 64 e 128. Plote as  curvas das quantidades de interesse no equilíbrio
    (magnetização por spin média, energia média,   susceptibilidade  e  calor  específico) em função
    da temperatura para os 5 tamanhos de rede.  Lembre de descartar  alguns  passos  de  Monte Carlo
    para garantir que o sistema esteja no equilíbrio. Faça médias  temporais  sobre  uma  quantidade
    razoável de passos de Monte Carlo. Não é necessário fazer  médias  sobre  simulações diferentes.
    Verifique e discuta os efeitos de tamanho finito que falamos em sala, assim como o comportamento
    esperado para as quantidades de interesse.


*/

# include <math.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main (int argc,char *argv[]) {

  int L = (int)atoi(argv[1]);
  int sum,i,j,m,I,J,M,cnt,S[L+1][L+1], V[L+1][L+1];
  long int N;
  double r,C,Xsi,E,T;// = (double)atof(argv[2]); // Temperatura

  srand(time(NULL));

  do{

  for(int i=1; i<=L; i++) {
    for(int j=1; j<=L; j++) {
      r = (double)rand()/RAND_MAX;
      if( r <= 0.5 ) {
        V[i][j] =  1;
        cnt++;
      } else {
        V[i][j] = -1;
      }
    }
  }

  } while((double)cnt/(L*L) <= 0.55 && (double)cnt/(L*L) >= 0.45);


  double Val_M,Val_m,Val,sum_E,Med_Xsi,Med_m,Quad_E,Med_Quad_E,Med_E;


  for(int p = 10; p<=500; p = p + 5){
  T = (double)p/100;

  for(int i=1; i<=L; i++) {
    for(int j=1; j<=L; j++) {
      S[i][j] = V[i][j];
    }
  }

  Val_M = Val_m = Val = 0;
  Med_Xsi = Med_m = 0;
  sum_E = Quad_E = N = 0;

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

        E = (double)(2*S[i][j]*sum);
        if( E <= 0) {
          S[i][j] = (-1)*S[i][j];
          sum_E  += (double)(-S[i][j]*sum);
          Quad_E += sum*sum;
          N++;
        }

        r = (double)rand()/RAND_MAX;
        if( E >  0 && r <= exp(-E/T) ) {
          S[i][j] = (-1)*S[i][j];
          sum_E  += (double)(-S[i][j]*sum);
          Quad_E += sum*sum;
          N++;
        }
    }

    Med_E = (double)sum_E/(L*L*10000);
    Med_Quad_E = (double)Quad_E/(L*L*10000);

    C = (Med_Quad_E - Med_E*Med_E)/(T*T);

//  printf("%f\t %f\t %f\n",Med_E,Med_Quad_E,C);

    if(t > 9900) {

      // --------------------------------------------------------------

      M = 0;
      for(i=1; i<=L; i++) {
        for( j=1; j<=L; j++) {
          M += S[i][j]*S[i][j];
        }
      }

      m = 0;
      for(i=1; i<=L; i++) {
        for( j=1; j<=L; j++) {
          m += S[i][j];
        }
      }

      Val_M = (double)M/(L*L);
      Val_m = (double)m/(L*L);

      Xsi = ( Val_M - (Val_m)*(Val_m) )/T;

      Med_Xsi += (double)Xsi/100;
      Med_m   += (double)Val_m/100;

      // --------------------------------------------------------------
    }
  }

  printf("%1.3f\t %5.10f\t %5.10f\t %5.10f\t %5.10f\n",T,fabs(Med_m),Med_E*L*L,Med_Xsi,C);
  }

  return 0;
}
