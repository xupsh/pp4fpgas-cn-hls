/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.

	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"

void fir (
  data_t *y,
  data_t x
  )
{
#pragma HLS INTERFACE s_axilite port=return bundle=ap_start
#pragma HLS INTERFACE s_axilite port=y
#pragma HLS INTERFACE s_axilite port=x
	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0,53};
	static
	data_t shift_reg[N];
	acc_t acc;
	int i;
	acc = 0;
	TDL:
	for(i = N - 1;i > 0;i--){
	#pragma HLS UNROLL
		shift_reg[i] = shift_reg[i - 1];
	}
	shift_reg[0] = x;
	acc = 0;

	MAC:
	for(i = N-1;i >= 0;i--)
	{
	#pragma HLS UNROLL
		acc += shift_reg[i] * c[i];
	}
	* y = acc;
}


