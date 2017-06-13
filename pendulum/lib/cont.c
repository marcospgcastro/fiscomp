# include <stdio.h>
# include <stdlib.h>

int main (void) {

  double sum  = 0;
  double cont = 0;
  int door = 0;

  float aux, auy;

  FILE *pt = fopen("/opt/uff/grad/fiscomp/pendulum/var/data/data.itemapmax.dat","r");

  for(int i=1; i<= 4000; i++) {

    fscanf(pt,"%f\t",&aux);
    fscanf(pt,"%f\n",&auy);

    if(auy < 0.02 && auy > -0.02) {
       sum = sum + aux;
       cont++;
       door = 1;
    }
    else if(door == 1){
      printf("%4.10f\n",(double)sum/cont);
      cont = sum = 0;
      door = 0;
    }
  }
  fclose(pt);

  return 0;
}
