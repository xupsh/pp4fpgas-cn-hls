/*
	Filename: phasedetector.cpp
		Phase detector

	INPUT:
		I: signal for I sample
		Q: signal for Q sample
		length: array size

	OUTPUT:
		R: Radius
		Theta: Angle

*/

#include "phasedetector.h"

void phasedetector (
  data_t *I,
  data_t *Q,

  data_t *R,
  data_t *Theta,

  int size
  ){
#pragma HLS INTERFACE s_axilite port=size bundle=CTRL
#pragma HLS INTERFACE axis depth=1024 port=Theta
#pragma HLS INTERFACE axis depth=1024 port=R
#pragma HLS INTERFACE axis depth=1024 port=Q
#pragma HLS INTERFACE axis depth=1024 port=I
	data_t mid1[size];
	data_t mid2[size];
	phasedetector_label0:for (int i=0;i<size;i++)
	{
#pragma HLS LOOP_TRIPCOUNT min=1024 max=1024
		fir(I[i],Q[i],&mid1[i],&mid2[i]);
		cordiccart2pol(mid1[i],mid2[i],&R[i],&Theta[i]);
	}
}




