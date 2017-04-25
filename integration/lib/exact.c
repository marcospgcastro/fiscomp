# include <math.h>
# include <stdio.h>
# include <stdlib.h>

double f(double x) {
  double f;
  f = ( sin(x*x)*exp(x/3) )/( sqrt(x*x + 4) );
  return f;
}


int main (void) {

  double derive, delta_x, x=3;

  derive = (double)exp(x/3)*sin(x*x)*( (double)1/3 + (double)2*x*cos(x*x)/sin(x*x) - (double)x/( (x*x + 4) ) )/( sqrt(x*x + 4) );
  printf("%10.10f\n",derive);

  return 0;
}















