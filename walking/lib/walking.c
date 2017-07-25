# include <stdio.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>

int main (void) {

 srand(time(NULL));

 double r, S[100000];
 int  p,W[100000];

 for(int j=1; j<=10000; j++) S[j] = W[j] = 0;

 for(int i=1; i<=10000; i++) {
   p = 50000; W[p]++;

   for(int j=1; j<=100000; j++) {

     r = (double)rand()/RAND_MAX;

     if(r > 0.5) p++; W[p]++;
     if(r < 0.5) p--; W[p]++;

   }

    for(int j=1; j<=100000; j++) S[j] += (double)W[j]/10000000000000;
 }

   for(int j=1; j<=100000; j++) {
     if(S[j] > 0.00000000000001 && S[j] < 1 ) printf("%d\t %2.10f\n",j,S[j]);
   }

 return 0 ;

}
