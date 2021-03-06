# include <math.h>
# include <stdio.h>
# include <stdlib.h>

double g(double t) {

  double g = 5.0*exp(0.5*t)*cos(5.0*t) - 0.5*exp(0.5*t)*sin(5.0*t);
  return g;
}

double F(double T, double Yn ){

  double F = Yn + g(T);
  return F;
}

int main (void) {

  double h, t, k1, k2, Yn, Yn1;

  t=0;
  Yn=1;
  h=0.05;
  for(int i=1; i<=100; i++) {
    k1 = h*F(t,Yn);
    k2 = h*F(t+h,Yn+k1);
    Yn1 = Yn + 0.5*( k1 + k2 );
    Yn = Yn1;
    t = t+h;
    printf("%.5f\t%10.15f\n",t,Yn);
  }

  return 0;
}
