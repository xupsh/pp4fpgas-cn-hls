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

# define SIZE 20000

void linear_filterc(float *b, float *xr, float *xi, int fs);

void linear_filter(float *b, float *x, int fs);

void linear_filter2(float *b, float *x, int fs);

void downsample_implc(float *xr, float *xi, int M, int fs, float *zr, float *zi);

void downsample_impl(float *x, int M, int fs, float *z);

void discrim_impl(float *xr, float *xi, int fs, float *xx);

void mono_FM_impl(float *xr, float *xi, int fs, float *z_out);
