#define INPUT_SIZE 8

#define VALUE_SIZE 256

#include <assert.h>
#include "ap_int.h"
#include "ap_fixed.h"
#include "ap_axi_sdata.h"

typedef ap_axiu<32,1,1,1> data_t;

void histogram(data_t* in, data_t* hist) {
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE axis register both port=in
    #pragma HLS INTERFACE axis register both port=hist

	int tempI[INPUT_SIZE];
	int tempV[VALUE_SIZE];

    int val;
    int current;
    int tempr; // temp receive for receiving channel

    int old = -1;
    for(int i = 0; i < INPUT_SIZE; i++) {
    	val = in->data;
        tempI[i] = val;
   	  hist->data = val;
   	  hist->keep = in->keep;

   	  hist->dest = in->dest;

   	  hist->id = in->id;


   	  hist->last = in->last;

   	  hist->strb = in->strb;

   	  hist->user = in->user;
    }

    for(int i = 0; i < INPUT_SIZE; i++) {
        val = tempI[i];
        tempV[val] = tempV[val]+1;
    }
//    for(int j = 0; j < INPUT_SIZE; j++) {
//
//
//        val = in[i];
//
//        assert(old != val);
//
//        hist[val] = hist[val] + 1;
//
//        old = val;
//
//    }
    for(int j = 0; j < VALUE_SIZE; j++){
	    tempr = in->data;
	    current = tempV[j];
	    hist->data = current;
	    hist->keep = in->keep;

	    hist->dest = in->dest;

	    hist->id = in->id;


	    hist->last = in->last;

	    hist->strb = in->strb;

	    hist->user = in->user;
    }
}
