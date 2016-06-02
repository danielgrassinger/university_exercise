#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex{
  float Re;
  float Im;
}complex;

complex add(complex, complex);
complex sub(complex, complex);
complex mul(complex, complex);
complex div(complex, complex);

#endif
