#include <stdio.h>
#include <stdlib.h>
#include <math.h>
extern double pes_(double *a);
//extern void load_gp_2ar_data_(void);
//extern double pes_2ar_(double *xStar);

extern void load_gp_co2_ar_data_(void);
extern double pes_co2_ar_(double *xStar);


int main()
{
  int i,itot=500;
  double r,z, beta1=0;
  double rab[3]={0};
  double lCO = 1.1632;
  
  load_gp_co2_ar_data_();
  //load_gp_2ar_data_();

  for(i = 1  ;   i <= itot    ;   i++){
    r = (  0.5 + 15.0*i/(1.0*itot) );
    rab[0]= r;
    rab[1]= sqrt( pow(lCO*sin(beta1),2) +pow(lCO*cos(beta1)-r,2)  );
    rab[2]= sqrt( pow(lCO*sin(beta1),2) +pow(lCO*cos(beta1)+r,2)  );
    printf("%lf %le\n",r, pes_co2_ar_(rab));
  }

  r = 2.89   *   1.8897259885789;
  //printf("%lf\n",pes_2ar_(&a));

}
