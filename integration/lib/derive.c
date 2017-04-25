# include <math.h>
# include <stdio.h>
# include <stdlib.h>

double f(double x) {
  double f;
  f = ( sin(x*x)*exp(x/3) )/( sqrt(x*x + 4) );
  return f;
}


int main (void) {
  printf("%2.10f\n",f(3));
  return 0;
}
