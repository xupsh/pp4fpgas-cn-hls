
#define N 11

#include "ap_int.h"
#include "ap_fixed.h"

#include "ap_axi_sdata.h"


typedef int coef_t;

typedef ap_axiu<32,1,1,1> data_t;

typedef int acc_t;

void fir(data_t *y, int x , data_t *input) {
    #pragma HLS INTERFACE axis register both port=input
    #pragma HLS INTERFACE axis register both port=y
    #pragma HLS INTERFACE s_axilite port=x bundle=x_axilite
    #pragma HLS INTERFACE ap_ctrl_none port=return

	coef_t c[N] = {1, 0, -1, 0, 2, 3, 2, 0, -1, 0, 1};

	static int shift_reg[N];

	acc_t acc;

	int i;



	acc = 0;

Shift_Accum_Loop:

	for (i = N - 1; i >= 0; i--) {


		if (i == 0) {

			acc += x * c[0];

			shift_reg[0] = x;

		} else {

			shift_reg[i] = shift_reg[i - 1];

			acc += shift_reg[i] * c[i];

		}

	}

	y->data = acc;
	y->keep = input->keep;

	y->dest = input->dest;

	y->id = input->id;


	y->last = input->last;

	y->strb = input->strb;

	y->user = input->user;

}



//
//#define N 11
//
//#include "ap_int.h"
//
//
//
//typedef int coef_t;
//
//typedef int data_t;
//
//typedef int acc_t;
//
//void fir(data_t&y, int x) {
//
//	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
//
//	static int shift_reg[N];
//
//	acc_t acc;
//
//	int i;
//
//
//
//	acc = 0;
//
//Shift_Accum_Loop:
//
//	for (i = N - 1; i >= 0; i--) {
//
//		if (i == 0) {
//
//			acc += x * c[0];
//
//			shift_reg[0] = x;
//
//		} else {
//
//			shift_reg[i] = shift_reg[i - 1];
//
//			acc += shift_reg[i] * c[i];
//
//		}
//
//	}
//
//	y = acc;
//
//}

