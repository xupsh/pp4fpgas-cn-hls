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

  int length
  ){
	data_t mid1[length];
	data_t mid2[length];
	for (int i=0;i<length;i++)
	{
		fir(I[i],Q[i],&mid1[i],&mid2[i]);
		cordiccart2pol(mid1[i],mid2[i],&R[i],&Theta[i]);
	}
}




