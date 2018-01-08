#include <stdio.h>
#include <stdlib.h>
extern double pes_(double *a);

int main()
{
  double a,z;
  
  a = 4.0;
  z = pes_(&a); /* Call Fortran add routine */ 
/* Note: Fortran indexes arrays 1..n */
/* C indexes arrays 0..(n-1) */ 

  printf("The result is %lf \n", z);
}
