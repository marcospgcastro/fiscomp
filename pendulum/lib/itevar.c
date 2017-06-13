# include <math.h>
# include <stdio.h>
# include <stdlib.h>

int main (void) {

  double teta[3];
  float  l,g,v_0,gamma, delta_t, tempo, val;
  int    cont, t=1;

  g = 9.80;		// m/s^2
  l = 2.00;  		// m

  for(double i = 0.2; i <= 8.8; i = i+0.4){

    v_0 = i;
    delta_t = 0.01;

    teta[t] = 0;
    teta[t-1] = (float)(v_0/l)*delta_t;

    cont = 0;
    tempo = 0;

    teta[t+1] = 0.0;
    val = 0.0;

    while(teta[t+1] <= 0.0)
    {
      teta[t+1] = ( 2*teta[t] - (g/l)*(delta_t)*(delta_t)*sin( teta[t] ) - teta[t-1] );
      tempo = tempo + delta_t;
      if(val > teta[t+1])
      {
        val = teta[t+1];
      }
      teta[t-1] = teta[t];
      teta[t] = teta[t+1];
    }
    printf("  %2.10f\t  %2.10f\n",(float)sqrt(val*val),(float)tempo);
  }

  return 0;
}
