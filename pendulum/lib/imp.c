# include <stdio.h>
# include <stdlib.h>

int main ( void ) {

   FILE *pt = fopen("/opt/uff/grad/fiscomp/pendulum/var/data/data.contmax.dat","r");

   float aux;

   for(int i=1; i<=13; i++){
     fscanf(pt,"%f\n",&aux);
     printf("%2.10f\n",aux);
     fscanf(pt,"%f\n",&aux);
   }

   fclose(pt);
   return 0;
}
