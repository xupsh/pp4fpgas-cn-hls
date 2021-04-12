#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <complex>
#include <complex.h>
#include "fm.h"

using namespace std;

void linear_filterc(float *b, float *xr, float *xi, int fs)
{
	float buffr[64] = {0};
#pragma HLS ARRAY_PARTITION variable=buffr block factor=8 dim=1
	float buffi[64] = {0};
#pragma HLS ARRAY_PARTITION variable=buffi block factor=8 dim=1
	for (int i=0; i<fs; i++)
	{
#pragma HLS PIPELINE
#pragma HLS LOOP_TRIPCOUNT min=20000 max=20000
		for (int j=0; j<63; j++)
		{
			buffr[63-j] = buffr[62-j];
			buffi[63-j] = buffi[62-j];
		}
		buffr[0] = xr[i];
		buffi[0] = xi[i];
		float tempr = 0;
		float tempi = 0;
		for (int j=0; j<64; j++)
		{
			tempr += buffr[j] *b[j];
			tempi += buffi[j] *b[j];
		}
		xr[i] = tempr;
		xi[i] = tempi;
	}
}

void linear_filter(float *b, float *x, int fs)
{
	float buff[64] = {0};
#pragma HLS ARRAY_PARTITION variable=buff block factor=8 dim=1
	for (int i=0; i<fs; i++)
	{
#pragma HLS PIPELINE
#pragma HLS LOOP_TRIPCOUNT min=2000 max=2000
		for (int j=0; j<63; j++)
		{
			buff[63-j] = buff[62-j];
		}
		buff[0] = x[i];
		float temp = 0;
		for (int j=0; j<64; j++)
		{
			temp += buff[j] *b[j];
		}
		x[i] = temp;
	}
}

void linear_filter2(float *b, float *x, int fs)
{
	float buff[2] = {0};
#pragma HLS ARRAY_PARTITION variable=buff complete dim=1
	for (int i=0; i<fs; i++)
	{
#pragma HLS PIPELINE
#pragma HLS LOOP_TRIPCOUNT min=2000 max=2000
		buff[1] = buff[0];
		buff[0] = x[i];
		float temp = 0;
		for (int j=0; j<2; j++)
		{
			temp += buff[j] *b[j];
		}
		x[i] = temp;
	}
}

void downsample_implc(float *xr, float *xi, int M, int fs, float *zr, float *zi)
{
	for (int i=0; i<(fs/M); i++)
	{
#pragma HLS PIPELINE
#pragma HLS LOOP_TRIPCOUNT min=2000 max=2000
		zr[i] = xr[M*i];
		zi[i] = xi[M*i];
	}
}

void downsample_impl(float *x, int M, int fs, float *z)
{
	for (int i=0; i<(fs/M); i++)
	{
#pragma HLS LOOP_TRIPCOUNT min=400 max=400
		z[i] = x[M*i];
	}
}

void discrim_impl(float *xr, float *xi, float *xx)
{
	float b[2] = {1,-1};
	float xro[SIZE/10];
	float xio[SIZE/10];
	for (int i = 0; i<SIZE/10; i++)
	{
#pragma HLS PIPELINE
		xro[i] = xr[i];
		xio[i] = xi[i];
	}
	linear_filter2(b, xr, SIZE/10);
	linear_filter2(b, xi, SIZE/10);
	for (int i = 0; i<SIZE/10; i++)
	{
#pragma HLS PIPELINE
		xx[i] = (xro[i] * xi[i] - xio[i] * xr[i])/(xro[i]*xro[i]-xio[i]*xio[i]);
	}
}

void mono_FM_impl(float *xr, float *xi, int fs, float *z_out)
{
#pragma HLS INTERFACE axis depth=400 port=z_out
#pragma HLS INTERFACE axis depth=20000 port=xi
#pragma HLS INTERFACE axis depth=20000 port=xr
#pragma HLS INTERFACE s_axilite port=fs bundle=CTRL
	float b[64] = {-0.00057098, -0.00022201,  0.0002486 ,  0.00079229,  0.00129681,
        			0.00157633,  0.00141003,  0.00063018, -0.00076622, -0.00252994,
       				-0.00414857, -0.0049459 , -0.00428825, -0.00184781,  0.00216364,
       				0.00688941,  0.01092662,  0.01264875,  0.01069752,  0.00451942,
       				-0.00521788, -0.01648693, -0.02613759, -0.03050801, -0.02629528,
       				-0.01147865,  0.01395219,  0.04768449,  0.08531217,  0.12109753,
        			0.14911115,  0.16448689,  0.16448689,  0.14911115,  0.12109753,
        			0.08531217,  0.04768449,  0.01395219, -0.01147865, -0.02629528,
       				-0.03050801, -0.02613759, -0.01648693, -0.00521788,  0.00451942,
       				0.01069752,  0.01264875,  0.01092662,  0.00688941,  0.00216364,
       				-0.00184781, -0.00428825, -0.0049459 , -0.00414857, -0.00252994,
       				-0.00076622,  0.00063018,  0.00141003,  0.00157633,  0.00129681,
        			0.00079229,  0.0002486 , -0.00022201, -0.00057098};

	float lwxr[SIZE];
	float lwxi[SIZE];
	float swz[SIZE/50];

	for (int i = 0; i < SIZE; i++)
	{
		lwxr[i] = xr[i];
		lwxi[i] = xi[i];
	}

	float zr[SIZE/10];
	float zi[SIZE/10];
	float zz[SIZE/10];

    linear_filterc(b, lwxr, lwxi, fs);

	downsample_implc(lwxr, lwxi, 10, fs, zr, zi);

    discrim_impl(zr, zi, zz);

    float bb[64] = {-0.00036654, -0.00013417,  0.00015024,  0.00050861,  0.0009492 ,
        			0.00145387,  0.00196926,  0.0024045 ,  0.00263739,  0.00252959,
        			0.00194958,  0.00080089, -0.00094856, -0.00324077, -0.00591034,
       				-0.00867995, -0.01117124, -0.01293192, -0.01347777, -0.01234556,
       				-0.00915132, -0.00364692,  0.00423247,  0.01433693,  0.0262916 ,
        			0.0395107 ,  0.05323597,  0.06659648,  0.07868416,  0.08863713,
        			0.09572185,  0.09940465,  0.09940465,  0.09572185,  0.08863713,
        			0.07868416,  0.06659648,  0.05323597,  0.0395107 ,  0.0262916 ,
        			0.01433693,  0.00423247, -0.00364692, -0.00915132, -0.01234556,
       				-0.01347777, -0.01293192, -0.01117124, -0.00867995, -0.00591034,
       				-0.00324077, -0.00094856,  0.00080089,  0.00194958,  0.00252959,
        			0.00263739,  0.0024045 ,  0.00196926,  0.00145387,  0.0009492 ,
        			0.00050861,  0.00015024, -0.00013417, -0.00036654};
    
    linear_filter(bb, zz, fs/10);
    
    downsample_impl(zz, 5, fs/10, swz);

    for (int i = 0; i < SIZE/50; i++)
    {
   		z_out[i] = swz[i];
   	}

}
