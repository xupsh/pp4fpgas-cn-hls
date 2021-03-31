#include<math.h>
#include "dft.h"
#include"coefficients32.h"

void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE])
{
//Write your code here
    int i, j;
	DTYPE c,s;

	DTYPE temp_real[SIZE];
#pragma HLS ARRAY_PARTITION variable=temp_real complete dim=1
	DTYPE temp_imag[SIZE];
#pragma HLS ARRAY_PARTITION variable=temp_imag complete dim=1

	dft_label0:for (i=0;i<SIZE;i+=1){
#pragma HLS PIPELINE
		temp_real[i] = 0;
		temp_imag[i] = 0;
	}

	dft_label1:for(j = 0; j < SIZE; j += 1){
#pragma HLS PIPELINE

		dft_label2:for(i = 0; i< SIZE; i+= 1){
			c= cos_coefficients_table[(i*j) % SIZE];
			s= sin_coefficients_table[(i*j) % SIZE];

			temp_real[i] += (real_sample[j]*c - imag_sample[j]*s);
			temp_imag[i] += (real_sample[j]*s + imag_sample[j]*c);
		}
	}

		dft_label3:for (i=0;i<SIZE;i+=1){
#pragma HLS PIPELINE
			real_sample[i] = temp_real[i];
			imag_sample[i] = temp_imag[i];
		}



}
