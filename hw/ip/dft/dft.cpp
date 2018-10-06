#include "ap_int.h"
#include "ap_fixed.h"

#include "ap_axi_sdata.h"

#include "hls_math.h"//Required for cos and sin functions

typedef float IN_TYPE;		// Data type for the input signal

typedef float TEMP_TYPE; // Data type for the temporary variables

//
//typedef ap_axiu<32,1,1,1> IN_TYPE;		// Data type for the input signal
//
//typedef ap_axiu<32,1,1,1> TEMP_TYPE; // Data type for the temporary variables
#define N 128							// DFT Size

//#include"hls_video.h"

void dft(IN_TYPE sample_real[N], IN_TYPE sample_imag[N], IN_TYPE out_real[N], IN_TYPE out_imag[N]) {
#pragma HLS INTERFACE axis register both port=sample_imag
#pragma HLS INTERFACE axis register both port=sample_real
#pragma HLS INTERFACE axis register both port=out_real
#pragma HLS INTERFACE axis register both port=out_imag
#pragma HLS INTERFACE ap_ctrl_none port=return

	int i, j;

	TEMP_TYPE w;

	TEMP_TYPE c, s;



	// Temporary arrays to hold the intermediate frequency domain results

	TEMP_TYPE temp_real[N];

	TEMP_TYPE temp_imag[N];


	TEMP_TYPE read_real[N];

	TEMP_TYPE read_imag[N];
	for (i = 0; i < N; i += 1) {

		read_real[i] = sample_real[i];

		read_imag[i] = sample_imag[i];

	}


	// Calculate each frequency domain sample iteratively

	for (i = 0; i < N; i += 1) {

		temp_real[i] = 0;

		temp_imag[i] = 0;



		// (2 * pi * i)/N

		w = (2.0 * 3.14159  / N) * (TEMP_TYPE)i;



		// Calculate the jth frequency sample sequentially

		for (j = 0; j < N; j += 1) {
#pragma HLS PIPELINE

			// Utilize HLS tool to calculate sine and cosine values

			c = hls::cosf(j * w);

			s = hls::sinf(j * w);



			// Multiply the current phasor with the appropriate input sample and keep

			// running sum

			temp_real[i] += (read_real[j] * c - read_imag[j] * s);

			temp_imag[i] += (read_real[j] * s + read_imag[j] * c);

		}

	}



	// Perform an inplace DFT, i.e., copy result into the input arrays

	for (i = 0; i < N; i += 1) {

		out_real[i] = temp_real[i];

		out_imag[i] = temp_imag[i];

	}

}



//#include <math.h>
//#include "hls_math.h"//Required for cos and sin functions
//
//typedef float IN_TYPE;		// Data type for the input signal
//
//typedef float TEMP_TYPE; // Data type for the temporary variables
//
//#define N  256				// DFT Size
//
////#include"hls_video.h"
//
//void dft(IN_TYPE sample_real[N], IN_TYPE out_real[N]) {
//#pragma HLS INTERFACE axis  port=sample_real
//
//#pragma HLS INTERFACE axis  port=out_real
//
//#pragma HLS INTERFACE ap_ctrl_none port=return
//
//	int i, j;
//
//	TEMP_TYPE w;
//
//	TEMP_TYPE c, s;
//
//
//
//	// Temporary arrays to hold the intermediate frequency domain results
//
//	TEMP_TYPE temp_real[N];
//
//
//
//	TEMP_TYPE read_real[N];
//
//	TEMP_TYPE read_imag[N];
//	for (i = 0; i < N; i += 1) {
//
//		read_real[i] = sample_real[i];
//
//
//	}
//
//
//	// Calculate each frequency domain sample iteratively
//
//	for (i = 0; i < N; i += 1) {
//
//		temp_real[i] = 0;
//
//
//
//
//
//		// (2 * pi * i)/N
//
//		w = (2.0 * 3.1415926  / N) * (TEMP_TYPE)i;
//
//
//
//		// Calculate the jth frequency sample sequentially
//
//		for (j = 0; j < N; j += 1) {
//
//			// Utilize HLS tool to calculate sine and cosine values
//
//			c = hls::cosf(j * w);
//
//			s = hls::sinf(j * w);
//
//
//
//			// Multiply the current phasor with the appropriate input sample and keep
//
//			// running sum
//
//			temp_real[i] += read_real[j] * c;
//
//
//
//		}
//
//	}
//
//
//
//	// Perform an inplace DFT, i.e., copy result into the input arrays
//
//	for (i = 0; i < N; i += 1) {
//
//		out_real[i] = temp_real[i];
//
//
//	}
//
//}
