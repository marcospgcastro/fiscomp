# include <math.h>
# include <stdio.h>
# include <stdlib.h>

int main (void) {

  double t = 0, dt = 0.1, point, time;
  double y_t,y_1, y_0 = 1;

  for(int k=1; k<=5; k++) {

    point = k;

    t=0;
    y_0 = 1;
    dt = 0.1;
    time = point/dt;

    for(int i=0; i<time; i++){

      y_1 = (double)y_0*(1 + dt) - (double)(1.00/2.00)*exp(t/2.0)*sin(5.0*t)*dt + (double)5.0*exp(t/2.0)*cos(5.0*t)*dt;
      y_0 = y_1;
      t = t + dt;
    }

    y_t = exp(t)+exp(t/2)*sin(5*t);
    printf("%.2f\t%10.10f\t%10.10f\t|%10.10f|\t%.2f %%\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ),(float)sqrt( (y_t-y_1)*(y_t-y_1) )*100/y_1);

    t=0;
    y_0 = 1;
    dt = 0.05;
    time = point/dt;
    for(int i=0; i<time; i++){

      y_1 = (double)y_0*(1 + dt) - (double)(1.00/2.00)*exp(t/2.0)*sin(5.0*t)*dt + (double)5.0*exp(t/2.0)*cos(5.0*t)*dt;
      y_0 = y_1;
      t = t + dt;
    }
    // printf("%10.10f\t%10.10f\t%10.10f\t%10.10f\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ));
    printf("%.2f\t%10.10f\t%10.10f\t|%10.10f|\t%.2f %%\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ),(float)sqrt( (y_t-y_1)*(y_t-y_1) )*100/y_1);

    t=0;
    y_0 = 1;
    dt = 0.01;
    time = point/dt;
    for(int i=0; i<time; i++){

      y_1 = (double)y_0*(1 + dt) - (double)(1.00/2.00)*exp(t/2.0)*sin(5.0*t)*dt + (double)5.0*exp(t/2.0)*cos(5.0*t)*dt;
      y_0 = y_1;
      t = t + dt;
    }
    // printf("%10.10f\t%10.10f\t%10.10f\t%10.10f\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ));
    printf("%.2f\t%10.10f\t%10.10f\t|%10.10f|\t%.2f %%\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ),(float)sqrt( (y_t-y_1)*(y_t-y_1) )*100/y_1);

    t=0;
    y_0 = 1;
    dt = 0.005;
    time = point/dt;
    for(int i=0; i<time; i++){

      y_1 = (double)y_0*(1 + dt) - (double)(1.00/2.00)*exp(t/2.0)*sin(5.0*t)*dt + (double)5.0*exp(t/2.0)*cos(5.0*t)*dt;
      y_0 = y_1;
      t = t + dt;
    }
    // printf("%10.10f\t%10.10f\t%10.10f\t%10.10f\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ));
    printf("%.2f\t%10.10f\t%10.10f\t|%10.10f|\t%.2f %%\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ),(float)sqrt( (y_t-y_1)*(y_t-y_1) )*100/y_1);

    t=0;
    y_0 = 1;
    dt = 0.001;
    time = point/dt;
    for(int i=0; i<time; i++){

      y_1 = (double)y_0*(1 + dt) - (double)(1.00/2.00)*exp(t/2.0)*sin(5.0*t)*dt + (double)5.0*exp(t/2.0)*cos(5.0*t)*dt;
      y_0 = y_1;
      t = t + dt;
    }
    // printf("%10.10f\t%10.10f\t%10.10f\t%10.10f\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ));
    printf("%.2f\t%10.10f\t%10.10f\t|%10.10f|\t%.2f %%\n\n",t,y_t,y_1,sqrt( (y_t-y_1)*(y_t-y_1) ),(float)sqrt( (y_t-y_1)*(y_t-y_1) )*100/y_1);

  }

  return 0;
}
