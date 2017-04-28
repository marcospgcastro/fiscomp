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

  for(long int i=1; i<=100000000; i=i*10)
  {
    delta_x = (double)1/i;
    derive = ( f(x+delta_x) - f(x) )/delta_x;
    printf("%10.10f\t%10.10f\n",derive,sqrt( (derive-(-4.0896256947))*(derive-(-4.0896256947))));
  }

  return 0;
}
