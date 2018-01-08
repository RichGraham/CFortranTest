#include <stdio.h>
#include <stdlib.h>
//#include <fortran.h>
extern double pes_(double *a);
extern void setvars_(void);

int main()
{
  double a,z;
  
  a = 2.0;

    z = pes_(&a); 
  printf("The result is %lf \n", z);

  setvars_();
  z = pes_(&a); 
  printf("The result is %lf \n", z);
}
