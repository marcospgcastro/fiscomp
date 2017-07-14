/* PROGRAMA DO PROFESSRO PAULO */

# include <stdio.h>
# include <math.h>

# define D 0.2
# define T 512

int 	x,t;
double  r,DE,u[T+1],ua[T+1];

# define tol 0.0000000000000001

int main(void) {

 u[0] =1; for(x = 1; x<=T; x++) u[x] = 0;
 t = 0;

 do{
  t++;
  for( x= 0; x<=t; x++ ) ua[x] = u[x];
  u[0] = ua[0] + 2*D*( ua[1] - ua[0]);
  for(x = 1; x<=t; x++) u[x] = ua[x] + D*(ua[x+1] - 2*ua[x] + ua[x-1] );
 } while(t<T);
 DE = 0.0;
 for(x=0; x<=t; x++) if(u[x]>tol) {
  printf("\n %6d %20.16lf",x,u[x]);
  DE += x*x*u[x];
 } else break;
  printf("\n\n  Delta(t=%d) = %20.16lf",t,sqrt(2*DE));
  printf("\n\n");

  return 0;
}
