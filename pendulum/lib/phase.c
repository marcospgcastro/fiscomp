# include <stdio.h>
# include <stdlib.h>

int main (void) {

  FILE *pt = fopen("/opt/uff/grad/fiscomp/pendulum/var/data/data.imp.dat","r");

    float data, aux = 0;

    for(int i=1; i<=35; i++)
    {
       fscanf(pt,"%f\n",&data);
       printf("%2.10f\n",(float)(data - aux));
       aux = data;
    }

  fclose(pt);

  return 0;
}
