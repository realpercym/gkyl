#include <gkyl_lagrangeFix_kernels.h>

void lagrangeFix_vlasov_1x1v_ser_p3(double *dm0, double *dm1, double *dm2, double *lo, double *L, double *Nv, double *vc, double *f) {
  double lambda0 [4];
  double lambda1 [4];
  double lambda2 [4];

  lambda0[0] = pow(L[0],-6)*(360.0*Nv[0]*dm0[0]*pow(lo[0],4)+Nv[0]*(720.0*L[0]*dm0[0]-720.0*dm1[0])*pow(lo[0],3)+Nv[0]*(504.0*dm0[0]*pow(L[0],2)+360.0*dm2[0]-1080.0*L[0]*dm1[0])*pow(lo[0],2)+Nv[0]*(18.0*dm0[0]*pow(L[0],4)-72.0*dm1[0]*pow(L[0],3)+60.0*dm2[0]*pow(L[0],2))+Nv[0]*lo[0]*(144.0*dm0[0]*pow(L[0],3)-504.0*dm1[0]*pow(L[0],2)+360.0*L[0]*dm2[0]));
  lambda0[1] = pow(L[0],-6)*(360.0*Nv[0]*dm0[1]*pow(lo[0],4)+Nv[0]*(720.0*L[0]*dm0[1]-720.0*dm1[1])*pow(lo[0],3)+Nv[0]*(504.0*dm0[1]*pow(L[0],2)+360.0*dm2[1]-1080.0*L[0]*dm1[1])*pow(lo[0],2)+Nv[0]*(18.0*dm0[1]*pow(L[0],4)-72.0*dm1[1]*pow(L[0],3)+60.0*dm2[1]*pow(L[0],2))+Nv[0]*lo[0]*(144.0*dm0[1]*pow(L[0],3)-504.0*dm1[1]*pow(L[0],2)+360.0*L[0]*dm2[1]));
  lambda0[2] = (360.0*dm0[2]*pow(Nv[0],5)*pow(lo[0],4)+(720.0*L[0]*dm0[2]-720.0*dm1[2])*pow(Nv[0],5)*pow(lo[0],3)+((504.0*dm0[2]*pow(L[0],2)+360.0*dm2[2]-1080.0*L[0]*dm1[2])*pow(Nv[0],5)-24.0*Nv[0]*dm0[2]*pow(L[0],2))*pow(lo[0],2)+lo[0]*((144.0*dm0[2]*pow(L[0],3)-504.0*dm1[2]*pow(L[0],2)+360.0*L[0]*dm2[2])*pow(Nv[0],5)+Nv[0]*(24.0*dm1[2]*pow(L[0],2)-24.0*dm0[2]*pow(L[0],3)))+(18.0*dm0[2]*pow(L[0],4)-72.0*dm1[2]*pow(L[0],3)+60.0*dm2[2]*pow(L[0],2))*pow(Nv[0],5)+Nv[0]*(12.0*dm1[2]*pow(L[0],3)-8.0*dm0[2]*pow(L[0],4)))*pow(pow(L[0],6)*pow(Nv[0],4)-1.0*pow(L[0],6),-1);
  lambda0[3] = (360.0*dm0[3]*pow(Nv[0],5)*pow(lo[0],4)+(720.0*L[0]*dm0[3]-720.0*dm1[3])*pow(Nv[0],5)*pow(lo[0],3)+((504.0*dm0[3]*pow(L[0],2)+360.0*dm2[3]-1080.0*L[0]*dm1[3])*pow(Nv[0],5)-24.0*Nv[0]*dm0[3]*pow(L[0],2))*pow(lo[0],2)+lo[0]*((144.0*dm0[3]*pow(L[0],3)-504.0*dm1[3]*pow(L[0],2)+360.0*L[0]*dm2[3])*pow(Nv[0],5)+Nv[0]*(24.0*dm1[3]*pow(L[0],2)-24.0*dm0[3]*pow(L[0],3)))+(18.0*dm0[3]*pow(L[0],4)-72.0*dm1[3]*pow(L[0],3)+60.0*dm2[3]*pow(L[0],2))*pow(Nv[0],5)+Nv[0]*(12.0*dm1[3]*pow(L[0],3)-8.0*dm0[3]*pow(L[0],4)))*pow(pow(L[0],6)*pow(Nv[0],4)-1.0*pow(L[0],6),-1);
  lambda1[0] = -1.0*pow(L[0],-6)*(720.0*Nv[0]*dm0[0]*pow(lo[0],3)+Nv[0]*(1080.0*L[0]*dm0[0]-1440.0*dm1[0])*pow(lo[0],2)+Nv[0]*(72.0*dm0[0]*pow(L[0],3)-384.0*dm1[0]*pow(L[0],2)+360.0*L[0]*dm2[0])+Nv[0]*lo[0]*(504.0*dm0[0]*pow(L[0],2)+720.0*dm2[0]-1440.0*L[0]*dm1[0]));
  lambda1[1] = -1.0*pow(L[0],-6)*(720.0*Nv[0]*dm0[1]*pow(lo[0],3)+Nv[0]*(1080.0*L[0]*dm0[1]-1440.0*dm1[1])*pow(lo[0],2)+Nv[0]*(72.0*dm0[1]*pow(L[0],3)-384.0*dm1[1]*pow(L[0],2)+360.0*L[0]*dm2[1])+Nv[0]*lo[0]*(504.0*dm0[1]*pow(L[0],2)+720.0*dm2[1]-1440.0*L[0]*dm1[1]));
  lambda1[2] = -1.0*(720.0*dm0[2]*pow(Nv[0],5)*pow(lo[0],3)+(1080.0*L[0]*dm0[2]-1440.0*dm1[2])*pow(Nv[0],5)*pow(lo[0],2)+lo[0]*((504.0*dm0[2]*pow(L[0],2)+720.0*dm2[2]-1440.0*L[0]*dm1[2])*pow(Nv[0],5)-24.0*Nv[0]*dm0[2]*pow(L[0],2))+(72.0*dm0[2]*pow(L[0],3)-384.0*dm1[2]*pow(L[0],2)+360.0*L[0]*dm2[2])*pow(Nv[0],5)+Nv[0]*(24.0*dm1[2]*pow(L[0],2)-12.0*dm0[2]*pow(L[0],3)))*pow(pow(L[0],6)*pow(Nv[0],4)-1.0*pow(L[0],6),-1);
  lambda1[3] = -1.0*(720.0*dm0[3]*pow(Nv[0],5)*pow(lo[0],3)+(1080.0*L[0]*dm0[3]-1440.0*dm1[3])*pow(Nv[0],5)*pow(lo[0],2)+lo[0]*((504.0*dm0[3]*pow(L[0],2)+720.0*dm2[3]-1440.0*L[0]*dm1[3])*pow(Nv[0],5)-24.0*Nv[0]*dm0[3]*pow(L[0],2))+(72.0*dm0[3]*pow(L[0],3)-384.0*dm1[3]*pow(L[0],2)+360.0*L[0]*dm2[3])*pow(Nv[0],5)+Nv[0]*(24.0*dm1[3]*pow(L[0],2)-12.0*dm0[3]*pow(L[0],3)))*pow(pow(L[0],6)*pow(Nv[0],4)-1.0*pow(L[0],6),-1);
  lambda2[0] = pow(L[0],-6)*(360.0*Nv[0]*dm0[0]*pow(lo[0],2)+Nv[0]*(60.0*dm0[0]*pow(L[0],2)+360.0*dm2[0]-360.0*L[0]*dm1[0])+Nv[0]*(360.0*L[0]*dm0[0]-720.0*dm1[0])*lo[0]);
  lambda2[1] = pow(L[0],-6)*(360.0*Nv[0]*dm0[1]*pow(lo[0],2)+Nv[0]*(60.0*dm0[1]*pow(L[0],2)+360.0*dm2[1]-360.0*L[0]*dm1[1])+Nv[0]*lo[0]*(360.0*L[0]*dm0[1]-720.0*dm1[1]));
  lambda2[2] = (360.0*dm0[2]*pow(Nv[0],5)*pow(lo[0],2)+(60.0*dm0[2]*pow(L[0],2)+360.0*dm2[2]-360.0*L[0]*dm1[2])*pow(Nv[0],5)+lo[0]*(360.0*L[0]*dm0[2]-720.0*dm1[2])*pow(Nv[0],5))*pow(pow(L[0],6)*pow(Nv[0],4)-1.0*pow(L[0],6),-1);
  lambda2[3] = (360.0*dm0[3]*pow(Nv[0],5)*pow(lo[0],2)+(60.0*dm0[3]*pow(L[0],2)+360.0*dm2[3]-360.0*L[0]*dm1[3])*pow(Nv[0],5)+lo[0]*(360.0*L[0]*dm0[3]-720.0*dm1[3])*pow(Nv[0],5))*pow(pow(L[0],6)*pow(Nv[0],4)-1.0*pow(L[0],6),-1);

  f[0] = f[0] + 0.05892556509887893*pow(Nv[0],-3)*(12.0*L[0]*lambda2[0]*pow(Nv[0],2)*pow(vc[0],2)+12.0*L[0]*lambda1[0]*vc[0]*pow(Nv[0],2)+12.0*L[0]*lambda0[0]*pow(Nv[0],2)+lambda2[0]*pow(L[0],3));
  f[1] = f[1] + 0.05892556509887893*pow(Nv[0],-3)*(12.0*L[0]*lambda2[1]*pow(Nv[0],2)*pow(vc[0],2)+12.0*L[0]*vc[0]*lambda1[1]*pow(Nv[0],2)+12.0*L[0]*lambda0[1]*pow(Nv[0],2)+lambda2[1]*pow(L[0],3));
  f[2] = f[2] + 0.08333333333333333*(4.898979485566357*lambda2[0]*vc[0]*pow(L[0],2)+2.449489742783178*lambda1[0]*pow(L[0],2))*pow(Nv[0],-2);
  f[3] = f[3] + 0.08333333333333333*(4.898979485566357*vc[0]*lambda2[1]*pow(L[0],2)+2.449489742783178*lambda1[1]*pow(L[0],2))*pow(Nv[0],-2);
  f[4] = f[4] + 0.05892556509887893*pow(Nv[0],-3)*(12.0*L[0]*lambda2[2]*pow(Nv[0],2)*pow(vc[0],2)+12.0*L[0]*vc[0]*lambda1[2]*pow(Nv[0],2)+12.0*L[0]*lambda0[2]*pow(Nv[0],2)+lambda2[2]*pow(L[0],3));
  f[5] = f[5] + 0.05270462766947297*lambda2[0]*pow(L[0],3)*pow(Nv[0],-3);
  f[6] = f[6] + 0.01666666666666667*(24.49489742783179*vc[0]*lambda2[2]*pow(L[0],2)+12.24744871391589*lambda1[2]*pow(L[0],2))*pow(Nv[0],-2);
  f[7] = f[7] + 0.05270462766947299*lambda2[1]*pow(L[0],3)*pow(Nv[0],-3);
  f[8] = f[8] + 0.05892556509887893*pow(Nv[0],-3)*(12.0*L[0]*lambda2[3]*pow(Nv[0],2)*pow(vc[0],2)+12.0*L[0]*vc[0]*lambda1[3]*pow(Nv[0],2)+12.0*L[0]*lambda0[3]*pow(Nv[0],2)+lambda2[3]*pow(L[0],3));
  f[9] = f[9] + 0.0;
  f[10] = f[10] + 0.0119047619047619*(34.2928563989645*vc[0]*lambda2[3]*pow(L[0],2)+17.14642819948225*lambda1[3]*pow(L[0],2))*pow(Nv[0],-2);
  f[11] = f[11] + 0.0;
}

