
const static int SIZE = 4; // SIZE of square matrix

const static int NNZ = 9; //Number of non-zero elements

const static int NUM_ROWS = 4;// SIZE;

typedef float DTYPE;

void spmv(int rowPtr[NUM_ROWS+1], int columnIndex[NNZ],

		DTYPE values[NNZ], DTYPE y[SIZE], DTYPE x[SIZE])
{

    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE axis register both port=rowPtr
    #pragma HLS INTERFACE axis register both port=columnIndex
    #pragma HLS INTERFACE axis register both port=values
    #pragma HLS INTERFACE axis register both port=y
    #pragma HLS INTERFACE axis register both port=x

    int tempr[NUM_ROWS+1];
    int tempc[NNZ];
    DTYPE tempv[NNZ];
    DTYPE tempy[SIZE];
    DTYPE tempx[SIZE];

    for(int i = 0; i<NUM_ROWS+1; i ++){
	    tempr[i] = rowPtr[i];
    }
    for(int i = 0; i<NNZ; i ++){
	    tempc[i] = columnIndex[i];
    }
    for(int i = 0; i<NNZ; i ++){
	    tempv[i] = values[i];
    }
    for(int i = 0; i<SIZE; i ++){
	    tempx[i] = x[i];
    }

    for (int i = 0; i < NUM_ROWS; i++) {

		DTYPE y0 = 0;

	    for (int k = tempr[i]; k < tempr[i+1]; k++) {

            #pragma HLS pipeline

			y0 += tempv[k] * tempx[tempc[k]];
		}

		tempy[i] = y0;
	}

    for(int i = 0; i < SIZE; i++){
	    y[i] = tempy[i];
    }
}
