#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <complex>
#include <complex.h>

typedef int	coef_t;
typedef int	data_t;
typedef int	acc_t;

void linear_filter(float *b, __complex__ double *x, int fs);

void downsample_impl(__complex__ double *x, int M, __complex__ double *z);

void discrim_impl(__complex__ double *x, int fs);

void mono_FM_impl(__complex__ double *x, int fs, __complex__ double *z_out);

