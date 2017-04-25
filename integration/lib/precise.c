# include <math.h>
# include <stdio.h>
# include <stdlib.h>

double f(double x) {
  double f;
  f = ( sin(x*x)*exp(x/3) )/( sqrt(x*x + 4) );
  return f;
}


int main (void) {

  double derive, delta_x, point, x=3;

  point = (double)exp(x/3)*sin(x*x)*( (double)1/3 + (double)2*x*cos(x*x)/sin(x*x) - (double)x/( (x*x + 4) ) )/( sqrt(x*x + 4) );

  for(long int i=1; i<=100000000; i=i*10)
  {
    delta_x = (double)1/i;
    derive = ( f(x+delta_x) - f(x) )/delta_x;
    printf("%2.10f\n",sqrt( (point-derive)*(point-derive) ));
  }

  return 0;
}
