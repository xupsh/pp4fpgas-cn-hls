

#define N 32

#define M 32

#define P 32



typedef int BaseType;


void matrixm(int A[N][M], int B[M][P], int AB[N][P], int test [N][P]) {
#pragma HLS INTERFACE axis register both port=test
#pragma HLS INTERFACE axis register both port=AB
#pragma HLS INTERFACE axis register both port=B
#pragma HLS INTERFACE axis register both port=A
#pragma HLS INTERFACE ap_ctrl_none port=return

 int tempA[N][M];
 int tempB[M][P];
 int tempAB[N][P];

 for (int ia = 0; ia<N ;ia++){
	 for(int ja = 0; ja< M; ja++){
		 tempA[ia][ja] = A[ia][ja];
	 }
 }
 for (int ib = 0; ib<M ;ib++){
	 for(int jb = 0; jb< P; jb++){
		 tempB[ib][jb] = B[ib][jb];
	 }
 }
  /* for each row and column of AB */

  row: for(int i = 0; i < N; ++i) {

    col: for(int j = 0; j < P; ++j) {

      #pragma HLS PIPELINE II=1

      /* compute (AB)i,j */

      int ABij = 0;

    product: for(int k = 0; k < M; ++k) {

        ABij += tempA[i][k] * tempB[k][j];

      }

      tempAB[i][j] = ABij;

    }

  }
  for (int iab = 0; iab<N ;iab++){
 	 for(int jab = 0; jab< P; jab++){
 		 AB[iab][jab] = tempAB[iab][jab];
 	 }
  }
  for (int iab = 0; iab<N ;iab++){
 	 for(int jab = 0; jab< P; jab++){
 		 test[iab][jab] = tempAB[iab][jab];
 	 }
  }

}
