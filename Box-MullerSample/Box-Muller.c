#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void brnd(double sigma, double average, double *num1, double *num2)
{
  double r1, r2;

  r1 = (double)rand()/RAND_MAX;
  r2 = (double)rand()/RAND_MAX;

  *num1 = sigma * sqrt(-2*log(r1)) * cos(2*3.14159*r2) + average;
  *num2 = sigma * sqrt(-2*log(r1)) * sin(2*3.14159*r2) + average;

}

int main(void)
{
  int i, j;
  double num1, num2;

  srand(0);

  
  for(i=0; i<1000; i++) {

    brnd(2.5, 0.0, &num1, &num2);

    printf("%lf\n", num1);
    printf("%lf\n", num2);
  }

  return 0;
}
