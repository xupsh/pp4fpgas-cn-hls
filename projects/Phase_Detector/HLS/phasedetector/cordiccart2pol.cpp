#include "phasedetector.h"

data_t Kvalues[NO_ITER] = {1,	0.500000000000000,	0.250000000000000,	0.125000000000000,	0.0625000000000000,	0.0312500000000000,	0.0156250000000000,	0.00781250000000000,	0.00390625000000000,	0.00195312500000000,	0.000976562500000000,	0.000488281250000000,	0.000244140625000000,	0.000122070312500000,	6.10351562500000e-05,	3.05175781250000e-05};

data_t angles[NO_ITER] = {0.785398163397448,	0.463647609000806,	0.244978663126864,	0.124354994546761,	0.0624188099959574,	0.0312398334302683,	0.0156237286204768,	0.00781234106010111,	0.00390623013196697,	0.00195312251647882,	0.000976562189559320,	0.000488281211194898,	0.000244140620149362,	0.000122070311893670,	6.10351561742088e-05,	3.05175781155261e-05};


void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta)
{
	// Write your code here
	data_t coefficient = 1.64676025812107;
	data_t currentx;
	data_t currenty;
	acc_t theta1;
	// Write your code here
	if( x >= 0)
	{
		currentx = x;
		currenty = y;
		theta1 = 0;
	}
	else
	{
		if( y <= 0)
		{
		 	currentx = -y;
			currenty = x;
			theta1 = 1.570796327;
		}
		else
		{
			currentx = y;
			currenty = -x;
			theta1 = -1.570796327;
		}

	}

	cordiccart2pol_label0:for (coef_t i = 0; i < NO_ITER; i++)
	{
		int sigma = (currenty < 0) ? 1 : -1;
		data_t factor = Kvalues[i];

		data_t temp_cos = currentx;

		currentx = currentx - currenty*sigma*factor;
		currenty = temp_cos*sigma*factor+currenty;

		theta1 = theta1 + sigma*angles[i];

	}

	*r = currentx/coefficient;
	*theta = -theta1;
}

