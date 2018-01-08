#include <stdio.h>
#include <stdlib.h>
//extern double pes_(double *a);
extern void load_gp_data_(void);

int main()
{
  double a,z;
  
  a = 2.0;

  load_gp_data_();
}
