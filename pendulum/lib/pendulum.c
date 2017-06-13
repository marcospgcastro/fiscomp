# include <math.h>
# include <stdio.h>
# include <stdlib.h>

int main (void) {

  double teta[3];
  float  l,g,v_0,gamma, delta_t, tempo;
  int    cont, t=1;

  g = 9.80;	// m/s^2
  l = 2.00;  	// m
  v_0 = 1.00;	// m/s
  delta_t = 0.01;

  // teta[t-1] = 0.0;
  // teta[t] = (float)(v_0/l)*delta_t;

  teta[t] = 0;
  teta[t-1] = (float)(v_0/l)*delta_t;

  cont = 0;
  tempo = 0;

  for(int i=1; i<=1000; i++) {
    teta[t+1] = ( 2*teta[t] - (g/l)*(delta_t)*(delta_t)*sin( teta[t] ) - teta[t-1] );

    tempo = tempo + delta_t;
    printf("  %2.2f\t  %2.10f\n",(float)tempo,(float)teta[t+1]);

    teta[t-1] = teta[t];
    teta[t] = teta[t+1];
  }

  return 0;
}
