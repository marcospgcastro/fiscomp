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

  double h, t, time, k1, k2, k3, k4, Yt, Yn, Yn1;

  for(int p=1; p<=5; p++) {

    t = (double)p;
    Yt = exp(t)+exp(0.5*t)*sin(5*t);

    t=0;
    Yn=1;
    h=0.1;
    time = p/h;
    for(int i=1; i<=time; i++) {
      k1 = h*F(t,Yn);
      k2 = h*F(t+h/2,Yn+k1/2);
      k3 = h*F(t+h/2,Yn+k2/2);
      k4 = h*F(t+h,Yn+k3);
      Yn1 = Yn + ( k1 + 2*k2 + 2*k3 + k4)/6;
      Yn = Yn1;
      t = t+h;
    }
    printf("%.2f\t%4.14f\t%4.14f\t|%4.14f|\t%.14f %%\n",t,Yn,Yt,sqrt((Yt-Yn)*(Yt-Yn)),sqrt((Yt-Yn)*(Yt-Yn))*100/Yn);

    t=0;
    Yn=1;
    h=0.05;
    time = p/h;
    for(int i=1; i<=time; i++) {
      k1 = h*F(t,Yn);
      k2 = h*F(t+h/2,Yn+k1/2);
      k3 = h*F(t+h/2,Yn+k2/2);
      k4 = h*F(t+h,Yn+k3);
      Yn1 = Yn + ( k1 + 2*k2 + 2*k3 + k4)/6;
      Yn = Yn1;
      t = t+h;
    }
    printf("%.2f\t%4.14f\t%4.14f\t|%4.14f|\t%.14f %%\n",t,Yn,Yt,sqrt((Yt-Yn)*(Yt-Yn)),sqrt((Yt-Yn)*(Yt-Yn))*100/Yn);

    t=0;
    Yn=1;
    h=0.01;
    time = p/h;
    for(int i=1; i<=time; i++) {
      k1 = h*F(t,Yn);
      k2 = h*F(t+h/2,Yn+k1/2);
      k3 = h*F(t+h/2,Yn+k2/2);
      k4 = h*F(t+h,Yn+k3);
      Yn1 = Yn + ( k1 + 2*k2 + 2*k3 + k4)/6;
      Yn = Yn1;
      t = t+h;
    }
    printf("%.2f\t%4.14f\t%4.14f\t|%4.14f|\t%.14f %%\n",t,Yn,Yt,sqrt((Yt-Yn)*(Yt-Yn)),sqrt((Yt-Yn)*(Yt-Yn))*100/Yn);

    t=0;
    Yn=1;
    h=0.005;
    time = p/h;
    for(int i=1; i<=time; i++) {
      k1 = h*F(t,Yn);
      k2 = h*F(t+h/2,Yn+k1/2);
      k3 = h*F(t+h/2,Yn+k2/2);
      k4 = h*F(t+h,Yn+k3);
      Yn1 = Yn + ( k1 + 2*k2 + 2*k3 + k4)/6;
      Yn = Yn1;
      t = t+h;
    }
    printf("%.2f\t%4.14f\t%4.14f\t|%4.14f|\t%.14f %%\n",t,Yn,Yt,sqrt((Yt-Yn)*(Yt-Yn)),sqrt((Yt-Yn)*(Yt-Yn))*100/Yn);

    t=0;
    Yn=1;
    h=0.001;
    time = p/h;
    for(int i=1; i<=time; i++) {
      k1 = h*F(t,Yn);
      k2 = h*F(t+h/2,Yn+k1/2);
      k3 = h*F(t+h/2,Yn+k2/2);
      k4 = h*F(t+h,Yn+k3);
      Yn1 = Yn + ( k1 + 2*k2 + 2*k3 + k4)/6;
      Yn = Yn1;
      t = t+h;
    }
    printf("%.2f\t%4.14f\t%4.14f\t|%4.14f|\t%.14f %%\n\n",t,Yn,Yt,sqrt((Yt-Yn)*(Yt-Yn)),sqrt((Yt-Yn)*(Yt-Yn))*100/Yn);

  }
  return 0;
}
