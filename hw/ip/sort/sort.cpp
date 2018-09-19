
const static int SIZE = 16;

typedef int DTYPE;

void sort(DTYPE A[SIZE], DTYPE OUT[SIZE]) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=OUT
#pragma HLS INTERFACE axis register both port=A

	DTYPE temp[SIZE];

	for(int k = 0; k<SIZE; k++){
		temp[k] = A[k];
	}

    for(int i = 1; i < SIZE; i++) {

      DTYPE item = temp[i];

	  int j = i;

      DTYPE t = temp[j-1];


      while(j > 0 && temp[j-1] > item && j > 0) {

		  temp[j] = temp[j-1];

		  j--;

	  }

	  temp[j] = item;

  }
    for(int z = 0; z < SIZE; z++){
    	OUT[z] = temp[z];
    }


}
