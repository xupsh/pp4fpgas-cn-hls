/*
	Filename: fir.cpp
		Complex FIR or Match filter
		firI1 and firI2 share coef_t c[N]
		firQ1 and firQ2 share coef_t c[N]
		
	INPUT:
		I: signal for I sample
		I: signal for Q sample

	OUTPUT:
		X: filtered output
		Y: filtered output

*/

#include "phasedetector.h"

void firI1 (
  data_t *y,
  data_t x
  ) {
#pragma HLS PIPELINE
#pragma HLS INTERFACE s_axilite port=return bundle=ap_start
#pragma HLS INTERFACE s_axilite port=y
#pragma HLS INTERFACE s_axilite port=x
	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};

	// Write your code here
	static
	data_t shift_reg[N];
	acc_t acc;
	int i;
	acc = 0;
	TDL:
	for(i = N - 1;i > 0;i--){

		shift_reg[i] = shift_reg[i - 1];
	}
	shift_reg[0] = x;
	acc = 0;

	MAC:
	for(i = N-1;i >= 0;i--)
	{

		acc += shift_reg[i] * c[i];
		}
	* y = acc;
}


void firI2 (
  data_t *y,
  data_t x
  ) {
#pragma HLS PIPELINE
#pragma HLS INTERFACE s_axilite port=return bundle=ap_start
#pragma HLS INTERFACE s_axilite port=y
#pragma HLS INTERFACE s_axilite port=x
	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};

	// Write your code here
	static
	data_t shift_reg[N];
	acc_t acc;
	int i;
	acc = 0;
	TDL:
	for(i = N - 1;i > 0;i--){

		shift_reg[i] = shift_reg[i - 1];
	}
	shift_reg[0] = x;
	acc = 0;

	MAC:
	for(i = N-1;i >= 0;i--)
	{

		acc += shift_reg[i] * c[i];
	}
	* y = acc;
}




void firQ1 (
  data_t *y,
  data_t x
  ) {
#pragma HLS PIPELINE
#pragma HLS INTERFACE s_axilite port=return bundle=ap_start
#pragma HLS INTERFACE s_axilite port=y
#pragma HLS INTERFACE s_axilite port=x
	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};


	// Write your code here
	static
		data_t shift_reg[N];
		acc_t acc;
		int i;
		acc = 0;
		TDL:
		for(i = N - 1;i > 0;i--){

			shift_reg[i] = shift_reg[i - 1];
		}
		shift_reg[0] = x;
		acc = 0;

		MAC:
		for(i = N-1;i >= 0;i--)
		{

			acc += shift_reg[i] * c[i];
		}
		* y = acc;
}

void firQ2 (
  data_t *y,
  data_t x
  ) {
#pragma HLS PIPELINE
#pragma HLS INTERFACE s_axilite port=return bundle=ap_start
#pragma HLS INTERFACE s_axilite port=y
#pragma HLS INTERFACE s_axilite port=x
	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};


	// Write your code here
	static
		data_t shift_reg[N];
		acc_t acc;
		int i;
		acc = 0;
		TDL:
		for(i = N - 1;i > 0;i--){

			shift_reg[i] = shift_reg[i - 1];
		}
		shift_reg[0] = x;
		acc = 0;

		MAC:
		for(i = N-1;i >= 0;i--)
		{

			acc += shift_reg[i] * c[i];
		}
		* y = acc;
}


void fir (
  data_t I,
  data_t Q,

  data_t *X,
  data_t *Y
  ) {

	// Write your code here
	data_t I1;
	data_t Q1;
	data_t I2;
	data_t Q2;
	firI1(&I1,I);
	firQ1(&Q1,I);
	firI2(&I2,Q);
	firQ2(&Q2,Q);
	
	//Calculate X
	*X = I1 + Q2;
	//Calculate Y
	*Y = I2 - Q1;


}
