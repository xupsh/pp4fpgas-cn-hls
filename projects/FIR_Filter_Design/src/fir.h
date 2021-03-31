/*
	Filename: fir.h
		Header file
		FIR lab wirtten for WES/CSE237C class at UCSD.

*/
#ifndef FIR_H_
#define FIR_H_

const int N=11;
#include "ap_int.h"

typedef ap_int<32>	coef_t;
typedef ap_int<32>	data_t;
typedef ap_int<32>	acc_t;

void fir (
  data_t *y,
  data_t x
  );

#endif
