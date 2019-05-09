#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNT 150
#define AVERAGE 0.0
#define SIGMA 1.5

double targetFunction(double x)
{
  double y;

  y = 0.8 * x + 0.5;
  // y = 0.08 * x*x + 0.5;

  return y;

}

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
  double noise1, noise2;
  double x, y;
  double deltaX;

  srand(0);

  x = 0.0;
  deltaX = 0.1;
  
  for(i=0; i<COUNT; i++) {

    y = targetFunction(x);

    brnd(SIGMA, AVERAGE, &noise1, &noise2);

    //printf("%lf\n", noise1);
    //printf("%lf\n", noise2);
    printf("%lf %lf\n", x, y+noise1);

    x = x + deltaX;
  }

  return 0;
}
