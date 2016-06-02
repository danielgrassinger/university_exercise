#include "complex.h"

complex add(complex a, complex b){
  complex c;
  c.Re = a.Re + b.Re;
  c.Im = a.Im + b.Im;

  return c;
}
complex sub(complex a, complex b){
  complex c;
  c.Re = a.Re - b.Re;
  c.Im = a.Im - b.Im;

  return c;
}
complex mul(complex a, complex b){
  complex c;
  c.Re = (a.Re * b.Re) - (a.Im * b.Im);
  c.Im = (a.Re * b.Im) + (a.Im * b.Re);

  return c;
}
complex div(complex a, complex b){
  complex c;
  c.Re = ((a.Re * b.Re) + (a.Im * b.Im))/(b.Re*b.Re+b.Im*b.Im);
  c.Im = ((a.Im * b.Re) - (a.Re * b.Im))/(b.Re*b.Re+b.Im*b.Im);

  return c;
}
