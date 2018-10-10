#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"
#include <iostream>

typedef float DTYPE;

#define M 10 	/* Number of Stages = Log2N */
#define N 1024 	/* N OF FFT */


int reverse_bits(int input)
{
	int i; 
	int rev = 0;
	for (i = 0; i < M; i++) {
		rev = (rev << 1) | (input & 1);
		input = input >> 1;
	}
	return rev;
}

void bit_reverse(DTYPE read_real[N], DTYPE read_imag[N], DTYPE stage_real[N], DTYPE stage_imag[N]) 
{
	int reversed;
	DTYPE temp;

	for (int i = 0; i < N; i++) 
	{
		reversed = reverse_bits(i); // Find the bit reversed index
		if (i <= reversed) {
			// Swap the real values
			temp = read_real[i];
			stage_real[i] = read_real[reversed];
			stage_real[reversed] = temp;

			// Swap the imaginary values
			temp = read_imag[i];
			stage_imag[i] = read_imag[reversed];
			stage_imag[reversed] = temp;
		}
	}
}

void fft_stage(int stage, DTYPE read_real[N], DTYPE read_imag[N], DTYPE stage_real[N], DTYPE stage_imag[N]) 
{
  int FFTpts = 1 << stage;    // DFT = 2^stage = points in sub DFT
  int BF = FFTpts / 2;     // Butterfly WIDTHS in sub-DFT
  int step = N >> stage;  // Perform butterflies for j-th stage

butterfly_loop:
	for (int j = 0; j < BF; j++) 
	{
		// Compute butterflies that use same W**k
dft_loop:
		for(int t = 0; t < step; t++) 
		{
			int i = j + t*FFTpts;
#pragma HLS pipeline
			int k = j * step;
			DTYPE w = -(2.0 * 3.14159  / N) * j;
			DTYPE c = hls :: cosf (w);
			DTYPE s = hls :: sinf (w);
			int i_lower = i + BF; // index of lower point in butterfly
			DTYPE temp_real = read_real[i_lower] * c - read_imag[i_lower] * s;
			DTYPE temp_imag = read_imag[i_lower] * c + read_real[i_lower] * s;
			stage_real[i_lower] = read_real[i] - temp_real;
			stage_imag[i_lower] = read_imag[i] - temp_imag;
			stage_real[i] = read_real[i] + temp_real;
			stage_imag[i] = read_imag[i] + temp_imag;
		}
	}
}

void fft(DTYPE sample_real[N], DTYPE sample_imag[N], DTYPE out_real[N], DTYPE out_imag[N])
{
#pragma HLS INTERFACE axis register both port=sample_imag
#pragma HLS INTERFACE axis register both port=sample_real
#pragma HLS INTERFACE axis register both port=out_real
#pragma HLS INTERFACE axis register both port=out_imag
#pragma HLS INTERFACE ap_ctrl_none port=return

	DTYPE temp_real[N];
	DTYPE temp_imag[N];
	DTYPE read_real[N];
	DTYPE read_imag[N];
	
	DTYPE stage_real[M][N];
#pragma HLS array_partition variable=stage_real dim=1 complete
	DTYPE stage_imag[M][N];
#pragma HLS array_partition variable=stage_imag dim=1 complete

read_loop:
	for (int i = 0; i < N; i++)
	{
		read_real[i] = sample_real[i];
		read_imag[i] = sample_imag[i];
	}

	bit_reverse(read_real,read_imag,stage_real[0],stage_imag[0]);

stage_loop:
	for (int stage = 1; stage < M; stage++) 
	{ 
#pragma HLS unroll
		fft_stage(stage, stage_real[stage-1], stage_imag[stage-1], stage_real[stage], stage_imag[stage]);
	}
	fft_stage(M, stage_real[M-1], stage_imag[M-1], temp_real, temp_imag);
	
	
write_loop:
	for (int i = 0; i < N; i++)
	{
		out_real[i] = temp_real[i];
		out_imag[i] = temp_imag[i];
	}
}

