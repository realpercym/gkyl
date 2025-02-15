#include <DistFuncMomentCalcModDecl.h> 
#include <cmath> 
void GkM0Star1x1vTensor_VX(const double intFac, const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double *fl, const double *fr, double *out) 
{ 
  // intFac:  =2pi/m for gyrokinetics (not used in Vlasov). 
  // w[NDIM]: Cell-center coordinates. 
  // dxv[2]:  cell length in each direction. 
  // fl/fr:   Distribution function in left/right cells 
  // out:     Increment to M_0^star from this cell surface. 
 
  const double dS = 1.0*intFac*(wr[1]-wl[1]); 
 

  out[0] += ((-0.408248290463863*fr[2])+0.408248290463863*fl[2]+0.3535533905932737*fr[0]+0.3535533905932737*fl[0])*dS; 
  out[1] += ((-0.408248290463863*fr[3])+0.408248290463863*fl[3]+0.3535533905932737*fr[1]+0.3535533905932737*fl[1])*dS; 
 
} 
 
void GkM0StarNonuniform1x1vTensor_VX(const double intFac, const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double *fl, const double *fr, double *out) 
{ 
  // intFac:  =2pi/m for gyrokinetics (not used in Vlasov). 
  // w[NDIM]: Cell-center coordinates. 
  // dxv[2]:  cell length in each direction. 
  // fl/fr:   Distribution function in left/right cells 
  // out:     Increment to M_0^star from this cell surface. 
 
  const double dS = 1.0*intFac*(wr[1]-wl[1]); 
 
  const double dxvl1R2 = pow(dxvl[1],2);
  const double dxvl1R3 = pow(dxvl[1],3);
  const double dxvr1R2 = pow(dxvr[1],2);
  const double dxvr1R3 = pow(dxvr[1],3);

  out[0] += ((-(8.660254037844386*dxvl1R2*dxvr[1]*fr[2])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3))-(5.196152422706631*dxvl1R3*fr[2])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(5.196152422706631*dxvr1R3*fl[2])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(8.660254037844386*dxvl[1]*dxvr1R2*fl[2])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(3.0*fl[0]*dxvr1R3)/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(9.0*fl[0]*dxvl[1]*dxvr1R2)/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(9.0*fr[0]*dxvl1R2*dxvr[1])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(3.0*fr[0]*dxvl1R3)/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3))*dS; 
  out[1] += ((-(8.660254037844386*dxvl1R2*dxvr[1]*fr[3])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3))-(5.196152422706631*dxvl1R3*fr[3])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(5.196152422706631*dxvr1R3*fl[3])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(8.660254037844386*dxvl[1]*dxvr1R2*fl[3])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(9.0*dxvl1R2*dxvr[1]*fr[1])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(3.0*dxvl1R3*fr[1])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(3.0*dxvr1R3*fl[1])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3)+(9.0*dxvl[1]*dxvr1R2*fl[1])/(4.242640687119286*dxvr1R3+12.72792206135786*dxvl[1]*dxvr1R2+12.72792206135786*dxvl1R2*dxvr[1]+4.242640687119286*dxvl1R3))*dS; 
 
} 
 
void GkM1iM2Star1x1vTensor(const double *w, const double *dxv, const double intFac, const double m_, const double *Bmag, const double *f, double *outM1i, double *outM2) 
{ 
  // w[2]:    Cell-center coordinates. 
  // dxv[2]:  Cell length in each direciton. 
  // intFac:  =2pi/m for gyrokinetics. 
  // m_:      mass. 
  // Bmag[NC]: Magnetic field magnitude. 
  // f:       Distribution function. 
  // outM1i:  Contribution to M_1^star from this cell. 
  // outM2:   Contribution to M_2^star from this cell. 
 
  const double volFact = 0.5*dxv[1]; 
  double wvSq[1]; 
  wvSq[0]  = w[1]*w[1]; 
  double dvSq[1]; 
  dvSq[0] = dxv[1]*dxv[1]; 
 
  outM1i[0] += 1.414213562373095*f[0]*w[1]*volFact; 
  outM1i[1] += 1.414213562373095*f[1]*w[1]*volFact; 
 
  outM2[0] += (0.408248290463863*dxv[1]*w[1]*f[2]+1.414213562373095*f[0]*wvSq[0])*volFact; 
  outM2[1] += (0.408248290463863*dxv[1]*w[1]*f[3]+1.414213562373095*f[1]*wvSq[0])*volFact; 
 
} 
void GkBoundaryIntegral1x1vTensor_F_VX_P1(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[2]:   cell length in each direction. 
  // fIn[4]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 1.0*intFac; 
 
  if (atLower) {
 
    out[0] += (1.224744871391589*fIn[2]-0.7071067811865475*fIn[0])*dS; 
    out[1] += (1.224744871391589*fIn[3]-0.7071067811865475*fIn[1])*dS; 
 
  } else {
 
    out[0] += (1.224744871391589*fIn[2]+0.7071067811865475*fIn[0])*dS; 
    out[1] += (1.224744871391589*fIn[3]+0.7071067811865475*fIn[1])*dS; 
 
  }
 
} 
 
void GkBoundaryIntegral1x1vTensor_F_VX_P2(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[2]:   cell length in each direction. 
  // fIn[9]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 1.0*intFac; 
 
  if (atLower) {
 
    out[0] += ((-1.58113883008419*fIn[5])+1.224744871391589*fIn[2]-0.7071067811865475*fIn[0])*dS; 
    out[1] += ((-1.58113883008419*fIn[7])+1.224744871391589*fIn[3]-0.7071067811865475*fIn[1])*dS; 
    out[2] += ((-1.58113883008419*fIn[8])+1.224744871391589*fIn[6]-0.7071067811865475*fIn[4])*dS; 
 
  } else {
 
    out[0] += (1.58113883008419*fIn[5]+1.224744871391589*fIn[2]+0.7071067811865475*fIn[0])*dS; 
    out[1] += (1.58113883008419*fIn[7]+1.224744871391589*fIn[3]+0.7071067811865475*fIn[1])*dS; 
    out[2] += (1.58113883008419*fIn[8]+1.224744871391589*fIn[6]+0.7071067811865475*fIn[4])*dS; 
 
  }
 
} 
 
void GkBoundaryIntegral1x1vTensor_vF_VX_P1(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[2]:   cell length in each direction. 
  // fIn[4]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 1.0*intFac; 
 
  if (atLower) {
 
    out[0] += (1.224744871391589*fIn[2]-0.7071067811865475*fIn[0])*dS*vBoundary+(0.6123724356957944*dxv[1]*fIn[2]-0.3535533905932737*fIn[0]*dxv[1])*dS; 
    out[1] += (1.224744871391589*fIn[3]-0.7071067811865475*fIn[1])*dS*vBoundary+(0.6123724356957944*dxv[1]*fIn[3]-0.3535533905932737*dxv[1]*fIn[1])*dS; 
 
  } else {
 
    out[0] += (1.224744871391589*fIn[2]+0.7071067811865475*fIn[0])*dS*vBoundary+((-0.6123724356957944*dxv[1]*fIn[2])-0.3535533905932737*fIn[0]*dxv[1])*dS; 
    out[1] += (1.224744871391589*fIn[3]+0.7071067811865475*fIn[1])*dS*vBoundary+((-0.6123724356957944*dxv[1]*fIn[3])-0.3535533905932737*dxv[1]*fIn[1])*dS; 
 
  }
 
} 
 
void GkBoundaryIntegral1x1vTensor_vF_VX_P2(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[2]:   cell length in each direction. 
  // fIn[9]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 1.0*intFac; 
 
  if (atLower) {
 
    out[0] += ((-1.58113883008419*fIn[5])+1.224744871391589*fIn[2]-0.7071067811865475*fIn[0])*dS*vBoundary; 
    out[1] += ((-1.58113883008419*fIn[7])+1.224744871391589*fIn[3]-0.7071067811865475*fIn[1])*dS*vBoundary; 
    out[2] += ((-1.58113883008419*fIn[8])+1.224744871391589*fIn[6]-0.7071067811865475*fIn[4])*dS*vBoundary; 
 
  } else {
 
    out[0] += (1.58113883008419*fIn[5]+1.224744871391589*fIn[2]+0.7071067811865475*fIn[0])*dS*vBoundary; 
    out[1] += (1.58113883008419*fIn[7]+1.224744871391589*fIn[3]+0.7071067811865475*fIn[1])*dS*vBoundary; 
    out[2] += (1.58113883008419*fIn[8]+1.224744871391589*fIn[6]+0.7071067811865475*fIn[4])*dS*vBoundary; 
 
  }
 
} 
 
