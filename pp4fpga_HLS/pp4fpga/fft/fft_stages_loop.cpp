#include "ap_int.h"
#include "ap_fixed.h"
#include "fft_streaming.h"
#include "hls_math.h"
#include <iostream>
//#include "tw_r.h"
//#include "tw_i.h"

#define numM 10 			/* Number of Stages = Log2N */
#define SIZE 1024 		/* SIZE OF FFT */
#define SIZE2 SIZE>>1

unsigned int reverse_bits(unsigned int input) {
	int i, rev = 0;
	for (i = 0; i < numM; i++) {
		rev = (rev << 1) | (input & 1);
		input = input >> 1;
	}
	return rev;
}

void bit_reverse(DTYPE X_R[SIZE], DTYPE X_I[SIZE],
		 DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
  unsigned int reversed;
  unsigned int i;
  DTYPE temp;
  int z;
    DTYPE read_real[SIZE];
    DTYPE read_imag[SIZE];
    DTYPE Out_TR[SIZE];
    DTYPE Out_TI[SIZE];
  read_loop:
    for (z = 0; z < SIZE; z += 1) {
  #pragma HLS PIPELINE
    		read_real[z] = X_R[z];
    		read_imag[z] = X_I[z];
    	}
  for (int i = 0; i < SIZE; i++) {
	  reversed = reverse_bits(i); // Find the bit reversed index
		if (i <= reversed) {
			// Swap the real values
			temp = read_real[i];
			Out_TR[i] = read_real[reversed];
			Out_TR[reversed] = temp;

			// Swap the imaginary values
			temp = read_imag[i];
			Out_TI[i] = read_imag[reversed];
			Out_TI[reversed] = temp;
		}
	}
  for (z = 0; z < SIZE; z += 1) {
	  OUT_R[z] = Out_TR[z];
	  OUT_I[z] = Out_TI[z];
   	}
}

void fft_stage(int stage, DTYPE X_R[SIZE], DTYPE X_I[SIZE],
		     DTYPE Out_R[SIZE], DTYPE Out_I[SIZE]) {
  int DFTpts = 1 << stage;    // DFT = 2^stage = points in sub DFT
  int numBF = DFTpts / 2;     // Butterfly WIDTHS in sub-DFT
  int step = SIZE >> stage;  // Perform butterflies for j-th stage

  int z;
   DTYPE read_real[SIZE];
   DTYPE read_imag[SIZE];
   DTYPE Out_TR[SIZE];
   DTYPE Out_TI[SIZE];
 read_loop:
   for (z = 0; z < SIZE; z += 1) {
 //#pragma HLS PIPELINE
   		read_real[z] = X_R[z];
   		read_imag[z] = X_I[z];
   	}
  butterfly_loop:
  for (int j = 0; j < numBF; j++) {
    // Compute butterflies that use same W**k
  dft_loop:
      for(int t = 0; t < step; t++) {
          int i = j + t*DFTpts;
          //    for (int i = j; i < SIZE; i += DFTpts) {
#pragma HLS pipeline
          int k = j*step;
      DTYPE c = hls :: cosf (W_real[k]);
      DTYPE s = hls :: sinf (W_imag[k]);
      int i_lower = i + numBF; // index of lower point in butterfly
      DTYPE temp_R = read_real[i_lower] * c - read_imag[i_lower] * s;
      DTYPE temp_I = read_imag[i_lower] * c + read_real[i_lower] * s;
      Out_TR[i_lower] = read_real[i] - temp_R;
      Out_TI[i_lower] =  read_imag[i] - temp_I;
      Out_TR[i] = read_real[i] + temp_R;
      Out_TI[i] = read_imag[i] + temp_I;
    }
  }
  write_loop:
  for (z = 0; z < SIZE; z += 1) {
	  Out_R[z] = Out_TR[z];
	  Out_I[z] = Out_TI[z];
  	}
}

void fft(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE])
{
#pragma HLS INTERFACE axis register both port=X_R
#pragma HLS INTERFACE axis register both port=X_I
#pragma HLS INTERFACE axis register both port=OUT_R
#pragma HLS INTERFACE axis register both port=OUT_I
 //#pragma HLS dataflow
  DTYPE Stage_R[numM][SIZE], Stage_I[numM][SIZE];
  #pragma HLS array_partition variable=Stage_R dim=1 complete
  #pragma HLS array_partition variable=Stage_I dim=1 complete
 int i;
 DTYPE temp_real[SIZE];
 DTYPE temp_imag[SIZE];
 DTYPE read_real[SIZE];
 DTYPE read_imag[SIZE];
  read_loop:
    for (i = 0; i < SIZE; i += 1) {
    		read_real[i] = X_R[i];
    		read_imag[i] = X_I[i];
    }
  bit_reverse(read_real, read_imag, Stage_R[0], Stage_I[0]);
 stage_loop:
  for (int stage = 1; stage < numM; stage++) { // Do M-1 stages of butterflies
 #pragma HLS unroll
    fft_stage(stage, Stage_R[stage-1], Stage_I[stage-1], Stage_R[stage], Stage_I[stage]);
  }
  fft_stage(numM, Stage_R[numM-1], Stage_I[numM-1], temp_real, temp_imag);

    write_loop:
  for (i = 0; i < SIZE; i += 1) {
     OUT_R[i] = temp_real[i];
     OUT_I[i] = temp_imag[i];
  	}
}
