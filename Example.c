#include <stdio.h>
#include <stdlib.h>
//extern double pes_(double *a);
extern void load_gp_2ar_data_(void);
extern double pes_2ar_(double *xStar);

int main()
{
  double a,z;
  
  a = 2.89   *   1.8897259885789;
  load_gp_2ar_data_();
  printf("%lf\n",pes_2ar_(&a));
}
