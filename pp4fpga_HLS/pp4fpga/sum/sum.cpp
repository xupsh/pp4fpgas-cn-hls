
#define SIZE 128

#include "ap_int.h"
#include "ap_fixed.h"
#include "ap_axi_sdata.h"

//typedef ap_axiu<32,1,1,1> data_t;
//
//void sum(data_t* in, data_t* out) {
//
//#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE axis register both port=out
//#pragma HLS INTERFACE axis register both port=in
//
//
//
//	int temp;
//
//	int A;
//
//	  for(int i=0; i < SIZE; i++) {
//
//	   temp = in->data;
//	    out->data = A;
//
//		out->keep = in->keep;
//
//		out->dest = in->dest;
//
//		out->id = in->id;
//
//
//		out->last = in->last;
//
//		out->strb = in->strb;
//
//		out->user = in->user;
////		in->last = 1;
//
//		A = A + temp;
//	  }
//
//}

void sum(int in[SIZE], int out[SIZE]) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=in
#pragma HLS INTERFACE axis register both port=out
	int tempout[SIZE];
	int tempin[SIZE];
 for(int i=0; i < SIZE; i++) {

	tempin[i] = in[i];

  }
  tempout[0] = tempin[0];

  for(int i=1; i < SIZE; i++) {

	  tempout[i] = tempout[i-1] + tempin[i];

  }

  for(int i=0; i < SIZE; i++) {

 	out[i] = tempout[i];

   }

}
