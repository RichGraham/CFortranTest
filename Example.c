#include <stdio.h>
#include <stdlib.h>
#include <math.h>
extern void load_gp_2ar_data_(void);
extern double pes_2ar_(double *xStar);

extern void load_gp_co2_ar_data_(void);
extern double pes_co2_ar_(double *xStar);

extern void load_gp_2co2_data_(void);
extern double pes_2co2_(double *xStar);

static double sqLength(double *u, double *v);

int main()
{
  int i,itot=500;
  double r,z, beta1=0, beta2=0, alpha2=0;
  double rab[3]={0.0};
  double rDist[9]={0.0};
  double O1[4]={0.0},O2[4]={0.0},O3[4]={0.0},O4[4]={0.0},C1[4]={0.0},C2[4]={0.0};
  double lCO = 1.1632;
  
  load_gp_co2_ar_data_();
  load_gp_2ar_data_();
  load_gp_2co2_data_();

  for(i = 1  ;   i <= itot    ;   i++){
    //2Ar
    r = (  0.5 + 15.0*i/(1.0*itot) );

    //CO2-Ar
    rab[0]= r;
    rab[1]= sqrt( pow(lCO*sin(beta1),2) +pow(lCO*cos(beta1)-r,2)  );
    rab[2]= sqrt( pow(lCO*sin(beta1),2) +pow(lCO*cos(beta1)+r,2)  );

    //2CO2
    //CO2 1
    //C is already at the origin
    O1[1]=lCO * sin( beta1);
    O1[3]=lCO *cos(beta1);
  
    O2[1]=-lCO * sin( beta1);
    O2[3]=-lCO * cos(beta1);
  
 
    //CO2 2
    C2[3]= r;
  
    O3[1] =  lCO * sin(beta2) * cos(alpha2);
    O3[2] =  lCO * sin(beta2) * sin(alpha2);
    O3[3] =  r  +  lCO * cos(beta2);
  
    O4[1] =  -lCO * sin(beta2) * cos(alpha2);
    O4[2] =  -lCO * sin(beta2) * sin(alpha2);
    O4[3] =  r  -  lCO * cos(beta2);
    
    //for(i = 1  ;   i <= 3   ;   i++)
    //  printf("%lf ", O1[i]);
    //printf("\n");
    
    rDist[0]= sqrt( sqLength(O1,O3) );
    rDist[1]= sqrt( sqLength(O1,C2) );
    rDist[2]= sqrt( sqLength(O1,O4) );


    rDist[3]= sqrt( sqLength(C1,O3) );
    rDist[4]= sqrt( sqLength(C1,C2) );
    rDist[5]= sqrt( sqLength(C1,O4) );
    
    rDist[6]= sqrt( sqLength(O2,O3) );
    rDist[7]= sqrt( sqLength(O2,C2) );
    rDist[8]= sqrt( sqLength(O2,O4) );

    //for(i = 0  ;   i <= 8   ;   i++)
    //  printf("%lf ", rDist[i]);
    //printf("\n");
    
    printf("%lf %le %le %le\n",r,  pes_2ar_(&r),pes_co2_ar_(rab),pes_2co2_(rDist));
  }

}


static double sqLength(double *u, double *v)
{  
  //returns the square of the distance between two vectors
  double sum=0.0;
  int i;
  
  for(i = 1  ;   i <= 3   ;   i++)
    sum +=   (  v[i]-u[i]  ) * (  v[i]-u[i]  );
  
  return sum;
}
