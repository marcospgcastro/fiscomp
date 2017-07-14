# include <stdio.h>
# include <math.h>

# define D 0.2
# define T 512

int main (void) {

  double  aux, u[T+1], ua[T+1];

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

  int cnt=0;
  for(int i=0; i<=T; i++){
    if( u[i] > 0.000000000000000000001 ){
      cnt++;
    } else break;
  }

  for(int i=cnt; i>=0; i--){
    printf("%6d\t %20.16lf\n",-1*i,u[i]);
  }

  for(int i=1; i<=cnt; i++){
    printf("%6d\t %20.16lf\n",i,u[i]);
  }

/*
  for(int i=0; i<=T; i++){
    if( u[i] > 0.000000000000000000001 ){
      printf("%6d\t %20.16lf\n",i,u[i]);
      //aux += (float)i*i*u[i];
    } else break;
  }

  //printf("%20.16f\n",sqrt(2*aux));
*/
  return 0;
}
