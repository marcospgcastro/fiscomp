# include <math.h>
# include <stdio.h>
# include <stdlib.h>

int main (void) {

  double t = 0, dt = 0.1, point, time;
  double y_t,y_1, y_0 = 1;

  t=0;
  y_0 = 1;
  dt = 0.05;
  for(int i=0; i<100; i++){
    y_1 = y_0*(1 + dt) - 0.5*exp(t/2.0)*sin(5.0*t)*dt + 5.0*exp(t/2.0)*cos(5.0*t)*dt;
    y_0 = y_1;
    t = t + dt;

    printf("%.5f\t%10.14f\n",t,y_1);
  }

  return 0;
}
