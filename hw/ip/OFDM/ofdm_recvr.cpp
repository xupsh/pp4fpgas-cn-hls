#include "fft.h"

static unsigned short count;
static DTYPE xr[ SIZE ];
static DTYPE xi[ SIZE ];
static DTYPE xr_out[ SIZE ];
static DTYPE xi_out[ SIZE ];
static int   dout[ SIZE ];

void ofdm_receiver( volatile DTYPE *inptr, volatile uint32_t *outptr, int SIZE )
{
#pragma HLS INTERFACE s_axilite port=SIZE bundle=CTRL
#pragma HLS INTERFACE axis depth=35000 port=inptr
#pragma HLS INTERFACE axis depth=35000 port=outptr

	*outptr++ = dout[ count ];

	xr[ count ] = *inptr++;
	xi[ count ] = *inptr++;
	count++;
	if( count == 1024 ){
		count = 0;
		demod( xr, xi, dout, xr_out, xi_out );
	}
}
