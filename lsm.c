#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct dataset {
  double x;
  double y;
};

void inputData(struct dataset data[], int dataNumber, char filename[256])
{
  FILE *fp;
  int i;

  fp = fopen(filename, "r");
  if(fp==NULL) {
    printf("Error.\n");
    printf("Can't open file.\n");
    exit(1);
  }
  
  for(i=0; i<dataNumber; i++) {
    fscanf(fp, "%lf", &data[i].x);
    fscanf(fp, "%lf", &data[i].y);
  }
  
  fclose(fp);
}

void dispData(struct dataset data[], int dataNumber)
{
  int i;
  
  for(i=0; i<dataNumber; i++) {
    printf("%lf %lf\n", data[i].x, data[i].y);
  }

}

void lsm(struct dataset data[], int dataNumber)
{
  int i;
  double xsum =0;
  double dxsum =0;
  double ysum =0;
  double xysum =0;

  dispData(data, dataNumber);

  printf("\n");

  for(i=0; i<dataNumber; i++) {
    xsum += data[i].x;
  }

  for(i=0; i<dataNumber; i++) {
    dxsum += data[i].x * data[i].x;
  }

  for(i=0; i<dataNumber; i++) {
    xysum += data[i].x * data[i].y;
  }
  for(i=0; i<dataNumber; i++) {
    ysum += data[i].y;
  }

  double under = (dxsum * dataNumber) - (xsum * xsum);

  //double a = dxsum * xysum + xsum * ysum;
  double a = dataNumber * xysum + (-xsum) * ysum;
  //double b = xsum * xysum + dataNumber * ysum;
  double b = (-xsum) * xysum + dxsum * ysum;

  double aa = a / under;
  double bb = b / under;

  printf("(%lf %lf)(a) = (%lf)\n",dxsum,xsum,xysum);
  printf("(%lf %d)(b) = (%lf)\n",xsum,dataNumber,ysum);
  printf("\n%lf %lf\n",aa,bb);
}


int main(int argc, char *argv[])
{
  struct dataset *data;
  int dataNumber;
  char filename[256];

  if(argc-1 != 2) {
    printf("Error.\n");
    printf("Usage: ./a.out [Data Number] [Filename]\n");
    exit(1);
  }
  
  dataNumber = atoi(argv[1]);
  strcpy(filename, argv[2]);

  data = (struct dataset *)malloc(sizeof(struct dataset)*dataNumber);

  inputData(data, dataNumber, filename);

  lsm(data, dataNumber);

  return 0;
}
