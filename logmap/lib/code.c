# include <stdio.h>

float logmap(float X,float r,int L)
 {

  float Y;
  for(int i=1; i<=L; i++)
  {
    Y = r*X*(1 - X);
    X = Y;
    printf("%.10f\n",Y);
  }

  return 0;
}

int main (void)
 {

  float A;    //   Valor inicial de x
  float B;    //   Valor de Lambda
  int   C;    //   Numero de iterações

  logmap(A,B,C);

  return 0;
}
