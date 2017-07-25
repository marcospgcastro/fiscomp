# include <stdio.h>
# include <math.h>

int main (void) {

 double p = 0.75, tol = 0.0000000000000001;
 int T = 1024;

 int x,t;
 double r, u[T+2], ua[T+2];


 u[0] = 1; for(x = 1; x<T+1; x++) u[x] = 0;
 t = 0;

 do{
   t++;
   for(x=0; x<t+1; x++) ua[x] = u[x];

   u[0] = p*ua[1]*(2 - p*ua[1]);
   for(x=1; x<=t; x++) u[x] = 1 - (1-p*ua[x+1])*(1-p*ua[x-1]);
 } while(t<T);

 for(x=0; x<t; x++) {
   if(u[x]>tol) printf("%d %20.16lf\n",x,u[x]);
 }

 return 0 ;

}
