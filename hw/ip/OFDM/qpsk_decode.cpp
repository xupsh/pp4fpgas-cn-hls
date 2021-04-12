#include "fft.h"
#include <stdio.h>

void qpsk_decode(DTYPE R[SIZE], DTYPE I[SIZE], int D[SIZE]) {

	for (int i=0;i<SIZE;i++)
	{
		int a = i/(SIZE/4);
		if (R[i]>0)
		{
			if (I[i]>0)
			{
				D[(4*i+a)%SIZE] = 0;
			}
			else if (I[i]<0)
			{
				D[(4*i+a)%SIZE] = 1;
			}
			else
			{
				D[(4*i+a)%SIZE] = 0;
			}
		}
		else if (R[i]<0)
		{
			if (I[i]>0)
			{
				D[(4*i+a)%SIZE] = 2;
			}
			else if (I[i]<0)
			{
				D[(4*i+a)%SIZE] = 3;
			}
			else
			{
				D[(4*i+a)%SIZE] = 0;
			};
		}
		else
		{
			D[(4*i+a)%SIZE] = 0;
		}
	}
}

