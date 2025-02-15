#include <DistFuncMomentCalcModDecl.h> 
#include <cmath> 
void GkM0Star2x2vTensor_VX(const double intFac, const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double *fl, const double *fr, double *out) 
{ 
  // intFac:  =2pi/m for gyrokinetics (not used in Vlasov). 
  // w[NDIM]: Cell-center coordinates. 
  // dxv[4]:  cell length in each direction. 
  // fl/fr:   Distribution function in left/right cells 
  // out:     Increment to M_0^star from this cell surface. 
 
  const double dS = 0.5*dxvl[3]*intFac*(wr[2]-wl[2]); 
 

  out[0] += ((-0.5773502691896258*fr[3])+0.5773502691896258*fl[3]+0.5*fr[0]+0.5*fl[0])*dS; 
  out[1] += ((-0.5773502691896258*fr[6])+0.5773502691896258*fl[6]+0.5*fr[1]+0.5*fl[1])*dS; 
  out[2] += ((-0.5773502691896258*fr[7])+0.5773502691896258*fl[7]+0.5*fr[2]+0.5*fl[2])*dS; 
  out[3] += ((-0.5773502691896258*fr[11])+0.5773502691896258*fl[11]+0.5*fr[5]+0.5*fl[5])*dS; 
 
} 
 
void GkM0StarNonuniform2x2vTensor_VX(const double intFac, const double *wl, const double *wr, const double *dxvl, const double *dxvr, const double *fl, const double *fr, double *out) 
{ 
  // intFac:  =2pi/m for gyrokinetics (not used in Vlasov). 
  // w[NDIM]: Cell-center coordinates. 
  // dxv[4]:  cell length in each direction. 
  // fl/fr:   Distribution function in left/right cells 
  // out:     Increment to M_0^star from this cell surface. 
 
  const double dS = 0.5*dxvl[3]*intFac*(wr[2]-wl[2]); 
 
  const double dxvl2R2 = pow(dxvl[2],2);
  const double dxvl2R3 = pow(dxvl[2],3);
  const double dxvr2R2 = pow(dxvr[2],2);
  const double dxvr2R3 = pow(dxvr[2],3);

  out[0] += ((-(8.660254037844386*dxvl2R2*dxvr[2]*fr[3])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3))-(5.196152422706631*dxvl2R3*fr[3])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(5.196152422706631*dxvr2R3*fl[3])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(8.660254037844386*dxvl[2]*dxvr2R2*fl[3])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(3.0*fl[0]*dxvr2R3)/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(9.0*fl[0]*dxvl[2]*dxvr2R2)/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(9.0*fr[0]*dxvl2R2*dxvr[2])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(3.0*fr[0]*dxvl2R3)/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3))*dS; 
  out[1] += ((-(8.660254037844386*dxvl2R2*dxvr[2]*fr[6])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3))-(5.196152422706631*dxvl2R3*fr[6])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(5.196152422706631*dxvr2R3*fl[6])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(8.660254037844386*dxvl[2]*dxvr2R2*fl[6])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(3.0*fl[1]*dxvr2R3)/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(9.0*fl[1]*dxvl[2]*dxvr2R2)/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(9.0*fr[1]*dxvl2R2*dxvr[2])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(3.0*fr[1]*dxvl2R3)/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3))*dS; 
  out[2] += ((-(8.660254037844386*dxvl2R2*dxvr[2]*fr[7])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3))-(5.196152422706631*dxvl2R3*fr[7])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(5.196152422706631*dxvr2R3*fl[7])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(8.660254037844386*dxvl[2]*dxvr2R2*fl[7])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(9.0*dxvl2R2*dxvr[2]*fr[2])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(3.0*dxvl2R3*fr[2])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(3.0*dxvr2R3*fl[2])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(9.0*dxvl[2]*dxvr2R2*fl[2])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3))*dS; 
  out[3] += ((-(8.660254037844386*dxvl2R2*dxvr[2]*fr[11])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3))-(5.196152422706631*dxvl2R3*fr[11])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(5.196152422706631*dxvr2R3*fl[11])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(8.660254037844386*dxvl[2]*dxvr2R2*fl[11])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(9.0*dxvl2R2*dxvr[2]*fr[5])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(3.0*dxvl2R3*fr[5])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(3.0*dxvr2R3*fl[5])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3)+(9.0*dxvl[2]*dxvr2R2*fl[5])/(3.0*dxvr2R3+9.0*dxvl[2]*dxvr2R2+9.0*dxvl2R2*dxvr[2]+3.0*dxvl2R3))*dS; 
 
} 
 
void GkM1iM2Star2x2vTensor(const double *w, const double *dxv, const double intFac, const double m_, const double *Bmag, const double *f, double *outM1i, double *outM2) 
{ 
  // w[4]:    Cell-center coordinates. 
  // dxv[4]:  Cell length in each direciton. 
  // intFac:  =2pi/m for gyrokinetics. 
  // m_:      mass. 
  // Bmag[NC]: Magnetic field magnitude. 
  // f:       Distribution function. 
  // outM1i:  Contribution to M_1^star from this cell. 
  // outM2:   Contribution to M_2^star from this cell. 
 
  const double volFact = intFac*0.25*dxv[2]*dxv[3]; 
  double wvSq[2]; 
  wvSq[0]  = w[2]*w[2]; 
  wvSq[1]  = w[3]*w[3]; 
  double dvSq[2]; 
  dvSq[0] = dxv[2]*dxv[2]; 
  dvSq[1] = dxv[3]*dxv[3]; 
 
  outM1i[0] += 2.0*f[0]*w[2]*volFact; 
  outM1i[1] += 2.0*f[1]*w[2]*volFact; 
  outM1i[2] += 2.0*f[2]*w[2]*volFact; 
  outM1i[3] += 2.0*w[2]*f[5]*volFact; 
 
  double tmp[4]; 
  tmp[0] = 0.5773502691896258*dxv[3]*f[4]+2.0*f[0]*w[3]; 
  tmp[1] = 0.5773502691896258*dxv[3]*f[8]+2.0*f[1]*w[3]; 
  tmp[2] = 0.5773502691896258*dxv[3]*f[9]+2.0*f[2]*w[3]; 
  tmp[3] = 0.5773502691896258*dxv[3]*f[12]+2.0*w[3]*f[5]; 
 
  outM2[0] += ((1.0*Bmag[3]*tmp[3]+1.0*Bmag[2]*tmp[2]+1.0*Bmag[1]*tmp[1]+1.0*Bmag[0]*tmp[0])/m_+0.5773502691896258*dxv[2]*w[2]*f[3]+2.0*f[0]*wvSq[0])*volFact; 
  outM2[1] += ((1.0*Bmag[2]*tmp[3]+1.0*tmp[2]*Bmag[3]+1.0*Bmag[0]*tmp[1]+1.0*tmp[0]*Bmag[1])/m_+0.5773502691896258*dxv[2]*w[2]*f[6]+2.0*f[1]*wvSq[0])*volFact; 
  outM2[2] += ((1.0*Bmag[1]*tmp[3]+1.0*tmp[1]*Bmag[3]+1.0*Bmag[0]*tmp[2]+1.0*tmp[0]*Bmag[2])/m_+0.5773502691896258*dxv[2]*w[2]*f[7]+2.0*f[2]*wvSq[0])*volFact; 
  outM2[3] += ((1.0*Bmag[0]*tmp[3]+1.0*tmp[0]*Bmag[3]+1.0*Bmag[1]*tmp[2]+1.0*tmp[1]*Bmag[2])/m_+0.5773502691896258*dxv[2]*w[2]*f[11]+2.0*wvSq[0]*f[5])*volFact; 
 
} 
void GkBoundaryIntegral2x2vTensor_F_VX_P1(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[4]:   cell length in each direction. 
  // fIn[16]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.5*dxv[3]*intFac; 
 
  if (atLower) {
 
    out[0] += (1.732050807568877*fIn[3]-1.0*fIn[0])*dS; 
    out[1] += (1.732050807568877*fIn[6]-1.0*fIn[1])*dS; 
    out[2] += (1.732050807568877*fIn[7]-1.0*fIn[2])*dS; 
    out[3] += (1.732050807568877*fIn[11]-1.0*fIn[5])*dS; 
 
  } else {
 
    out[0] += (1.732050807568877*fIn[3]+fIn[0])*dS; 
    out[1] += (1.732050807568877*fIn[6]+fIn[1])*dS; 
    out[2] += (1.732050807568877*fIn[7]+fIn[2])*dS; 
    out[3] += (1.732050807568877*fIn[11]+fIn[5])*dS; 
 
  }
 
} 
 
void GkBoundaryIntegral2x2vTensor_F_VX_P2(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[4]:   cell length in each direction. 
  // fIn[81]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.5*dxv[3]*intFac; 
 
  if (atLower) {
 
    out[0] += ((-2.23606797749979*fIn[13])+1.732050807568877*fIn[3]-1.0*fIn[0])*dS; 
    out[1] += ((-2.23606797749979*fIn[23])+1.732050807568877*fIn[6]-1.0*fIn[1])*dS; 
    out[2] += ((-2.23606797749979*fIn[24])+1.732050807568877*fIn[7]-1.0*fIn[2])*dS; 
    out[3] += ((-2.23606797749979*fIn[34])+1.732050807568877*fIn[15]-1.0*fIn[5])*dS; 
    out[4] += ((-2.23606797749979*fIn[45])+1.732050807568877*fIn[21]-1.0*fIn[11])*dS; 
    out[5] += ((-2.23606797749979*fIn[46])+1.732050807568877*fIn[22]-1.0*fIn[12])*dS; 
    out[6] += ((-2.23606797749979*fIn[55])+1.732050807568877*fIn[32]-1.0*fIn[19])*dS; 
    out[7] += ((-2.23606797749979*fIn[56])+1.732050807568877*fIn[33]-1.0*fIn[20])*dS; 
    out[8] += ((-2.23606797749979*fIn[72])+1.732050807568877*fIn[54]-1.0*fIn[44])*dS; 
 
  } else {
 
    out[0] += (2.23606797749979*fIn[13]+1.732050807568877*fIn[3]+fIn[0])*dS; 
    out[1] += (2.23606797749979*fIn[23]+1.732050807568877*fIn[6]+fIn[1])*dS; 
    out[2] += (2.23606797749979*fIn[24]+1.732050807568877*fIn[7]+fIn[2])*dS; 
    out[3] += (2.23606797749979*fIn[34]+1.732050807568877*fIn[15]+fIn[5])*dS; 
    out[4] += (2.23606797749979*fIn[45]+1.732050807568877*fIn[21]+fIn[11])*dS; 
    out[5] += (2.23606797749979*fIn[46]+1.732050807568877*fIn[22]+fIn[12])*dS; 
    out[6] += (2.23606797749979*fIn[55]+1.732050807568877*fIn[32]+fIn[19])*dS; 
    out[7] += (2.23606797749979*fIn[56]+1.732050807568877*fIn[33]+fIn[20])*dS; 
    out[8] += (2.23606797749979*fIn[72]+1.732050807568877*fIn[54]+fIn[44])*dS; 
 
  }
 
} 
 
void GkBoundaryIntegral2x2vTensor_vF_VX_P1(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[4]:   cell length in each direction. 
  // fIn[16]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.5*dxv[3]*intFac; 
 
  if (atLower) {
 
    out[0] += (1.732050807568877*fIn[3]-1.0*fIn[0])*dS*vBoundary+(0.8660254037844386*dxv[2]*fIn[3]-0.5*fIn[0]*dxv[2])*dS; 
    out[1] += (1.732050807568877*fIn[6]-1.0*fIn[1])*dS*vBoundary+(0.8660254037844386*dxv[2]*fIn[6]-0.5*fIn[1]*dxv[2])*dS; 
    out[2] += (1.732050807568877*fIn[7]-1.0*fIn[2])*dS*vBoundary+(0.8660254037844386*dxv[2]*fIn[7]-0.5*dxv[2]*fIn[2])*dS; 
    out[3] += (1.732050807568877*fIn[11]-1.0*fIn[5])*dS*vBoundary+(0.8660254037844386*dxv[2]*fIn[11]-0.5*dxv[2]*fIn[5])*dS; 
 
  } else {
 
    out[0] += (1.732050807568877*fIn[3]+fIn[0])*dS*vBoundary+((-0.8660254037844386*dxv[2]*fIn[3])-0.5*fIn[0]*dxv[2])*dS; 
    out[1] += (1.732050807568877*fIn[6]+fIn[1])*dS*vBoundary+((-0.8660254037844386*dxv[2]*fIn[6])-0.5*fIn[1]*dxv[2])*dS; 
    out[2] += (1.732050807568877*fIn[7]+fIn[2])*dS*vBoundary+((-0.8660254037844386*dxv[2]*fIn[7])-0.5*dxv[2]*fIn[2])*dS; 
    out[3] += (1.732050807568877*fIn[11]+fIn[5])*dS*vBoundary+((-0.8660254037844386*dxv[2]*fIn[11])-0.5*dxv[2]*fIn[5])*dS; 
 
  }
 
} 
 
void GkBoundaryIntegral2x2vTensor_vF_VX_P2(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[4]:   cell length in each direction. 
  // fIn[81]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.5*dxv[3]*intFac; 
 
  if (atLower) {
 
    out[0] += ((-2.23606797749979*fIn[13])+1.732050807568877*fIn[3]-1.0*fIn[0])*dS*vBoundary; 
    out[1] += ((-2.23606797749979*fIn[23])+1.732050807568877*fIn[6]-1.0*fIn[1])*dS*vBoundary; 
    out[2] += ((-2.23606797749979*fIn[24])+1.732050807568877*fIn[7]-1.0*fIn[2])*dS*vBoundary; 
    out[3] += ((-2.23606797749979*fIn[34])+1.732050807568877*fIn[15]-1.0*fIn[5])*dS*vBoundary; 
    out[4] += ((-2.23606797749979*fIn[45])+1.732050807568877*fIn[21]-1.0*fIn[11])*dS*vBoundary; 
    out[5] += ((-2.23606797749979*fIn[46])+1.732050807568877*fIn[22]-1.0*fIn[12])*dS*vBoundary; 
    out[6] += ((-2.23606797749979*fIn[55])+1.732050807568877*fIn[32]-1.0*fIn[19])*dS*vBoundary; 
    out[7] += ((-2.23606797749979*fIn[56])+1.732050807568877*fIn[33]-1.0*fIn[20])*dS*vBoundary; 
    out[8] += ((-2.23606797749979*fIn[72])+1.732050807568877*fIn[54]-1.0*fIn[44])*dS*vBoundary; 
 
  } else {
 
    out[0] += (2.23606797749979*fIn[13]+1.732050807568877*fIn[3]+fIn[0])*dS*vBoundary; 
    out[1] += (2.23606797749979*fIn[23]+1.732050807568877*fIn[6]+fIn[1])*dS*vBoundary; 
    out[2] += (2.23606797749979*fIn[24]+1.732050807568877*fIn[7]+fIn[2])*dS*vBoundary; 
    out[3] += (2.23606797749979*fIn[34]+1.732050807568877*fIn[15]+fIn[5])*dS*vBoundary; 
    out[4] += (2.23606797749979*fIn[45]+1.732050807568877*fIn[21]+fIn[11])*dS*vBoundary; 
    out[5] += (2.23606797749979*fIn[46]+1.732050807568877*fIn[22]+fIn[12])*dS*vBoundary; 
    out[6] += (2.23606797749979*fIn[55]+1.732050807568877*fIn[32]+fIn[19])*dS*vBoundary; 
    out[7] += (2.23606797749979*fIn[56]+1.732050807568877*fIn[33]+fIn[20])*dS*vBoundary; 
    out[8] += (2.23606797749979*fIn[72]+1.732050807568877*fIn[54]+fIn[44])*dS*vBoundary; 
 
  }
 
} 
 
void GkBoundaryIntegral2x2vTensor_vF_VY_P1(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[4]:   cell length in each direction. 
  // fIn[16]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.5*dxv[2]*intFac; 
 
  if (atLower) {
 
    out[0] += (1.732050807568877*fIn[4]-1.0*fIn[0])*dS*vBoundary; 
    out[1] += (1.732050807568877*fIn[8]-1.0*fIn[1])*dS*vBoundary; 
    out[2] += (1.732050807568877*fIn[9]-1.0*fIn[2])*dS*vBoundary; 
    out[3] += (1.732050807568877*fIn[12]-1.0*fIn[5])*dS*vBoundary; 
 
  } else {
 
    out[0] += (1.732050807568877*fIn[4]+fIn[0])*dS*vBoundary; 
    out[1] += (1.732050807568877*fIn[8]+fIn[1])*dS*vBoundary; 
    out[2] += (1.732050807568877*fIn[9]+fIn[2])*dS*vBoundary; 
    out[3] += (1.732050807568877*fIn[12]+fIn[5])*dS*vBoundary; 
 
  }
 
} 
 
void GkBoundaryIntegral2x2vTensor_vF_VY_P2(const bool atLower, const double intFac, const double vBoundary, const double *dxv, const double *fIn, double *out) 
{ 
  // atLower:   =true(false) if in cell at lower(upper) velocity boundary. 
  // intFac:    =2pi/m or 4pi/m for GkLBO (not used for Vlasov). 
  // vBoundary: velocity at the boundary of the velocity grid. 
  // dxv[4]:   cell length in each direction. 
  // fIn[81]:    distribution function at velocity boundaries. 
  // out:       int dS of f|^(vmax)_(vmin) or vf^(vmax)_(vmin). 
 
  const double dS = 0.5*dxv[2]*intFac; 
 
  if (atLower) {
 
    out[0] += ((-2.23606797749979*fIn[14])+1.732050807568877*fIn[4]-1.0*fIn[0])*dS*vBoundary; 
    out[1] += ((-2.23606797749979*fIn[28])+1.732050807568877*fIn[8]-1.0*fIn[1])*dS*vBoundary; 
    out[2] += ((-2.23606797749979*fIn[29])+1.732050807568877*fIn[9]-1.0*fIn[2])*dS*vBoundary; 
    out[3] += ((-2.23606797749979*fIn[41])+1.732050807568877*fIn[16]-1.0*fIn[5])*dS*vBoundary; 
    out[4] += ((-2.23606797749979*fIn[47])+1.732050807568877*fIn[25]-1.0*fIn[11])*dS*vBoundary; 
    out[5] += ((-2.23606797749979*fIn[48])+1.732050807568877*fIn[26]-1.0*fIn[12])*dS*vBoundary; 
    out[6] += ((-2.23606797749979*fIn[60])+1.732050807568877*fIn[35]-1.0*fIn[19])*dS*vBoundary; 
    out[7] += ((-2.23606797749979*fIn[61])+1.732050807568877*fIn[36]-1.0*fIn[20])*dS*vBoundary; 
    out[8] += ((-2.23606797749979*fIn[73])+1.732050807568877*fIn[57]-1.0*fIn[44])*dS*vBoundary; 
 
  } else {
 
    out[0] += (2.23606797749979*fIn[14]+1.732050807568877*fIn[4]+fIn[0])*dS*vBoundary; 
    out[1] += (2.23606797749979*fIn[28]+1.732050807568877*fIn[8]+fIn[1])*dS*vBoundary; 
    out[2] += (2.23606797749979*fIn[29]+1.732050807568877*fIn[9]+fIn[2])*dS*vBoundary; 
    out[3] += (2.23606797749979*fIn[41]+1.732050807568877*fIn[16]+fIn[5])*dS*vBoundary; 
    out[4] += (2.23606797749979*fIn[47]+1.732050807568877*fIn[25]+fIn[11])*dS*vBoundary; 
    out[5] += (2.23606797749979*fIn[48]+1.732050807568877*fIn[26]+fIn[12])*dS*vBoundary; 
    out[6] += (2.23606797749979*fIn[60]+1.732050807568877*fIn[35]+fIn[19])*dS*vBoundary; 
    out[7] += (2.23606797749979*fIn[61]+1.732050807568877*fIn[36]+fIn[20])*dS*vBoundary; 
    out[8] += (2.23606797749979*fIn[73]+1.732050807568877*fIn[57]+fIn[44])*dS*vBoundary; 
 
  }
 
} 
 
