# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

int main (int argc,char *argv[]) {

  int     T =    (int)atoi(argv[2]);
  double  D = (double)atof(argv[1]);

  double aux, u[T+1], ua[T+1];

  u[0] = 1;
  for(int i=1; i<=T; i++) {
    u[i] = 0;
  }

  for(int t=1; t<=T; t++) {

     for(int i=0; i<=t; i++) {
       ua[i] = u[i];
     }

     u[0] = ua[0] + 2*D*( ua[1] - ua[0] );
     for(int i=1; i<=t; i++) {
       u[i] = ua[i] + D*( ua[i+1] - 2*ua[i]+ua[i-1]);
     }
  }

   double sum = 0;

/*
   for(int i=T; i>=1; i--){
    if( u[i] > 0.0000000000000001 ){
      // printf("%6d\t %20.16lf\n",-i,u[i]);
    }
  }

*/

  for(int i=0; i<=T; i++){
    if( u[i] > 0.0000000000001 ){
      // printf("%6d\t %20.16lf\n",i,u[i]);
      sum += i*i*u[i];
    }
  }

  printf("%d\t %f\t %f\n",T,sqrt(2*sum),log(sqrt(2*sum)));

  return 0;
}
