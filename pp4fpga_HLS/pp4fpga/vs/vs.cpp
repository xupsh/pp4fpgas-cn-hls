
typedef struct rgb_pixel {

    unsigned char R;

    unsigned char G;

    unsigned char B;

} rgb_pixel;

#define MAX_HEIGHT 20

#define MAX_WIDTH 32


rgb_pixel filter(rgb_pixel window[3][3]) {

	unsigned char h[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};

	int r = 0, b = 0, g = 0;

 for (int i = 0; i < 3; i++) {

	 for (int j = 0; j < 3; j++) {

			r += window[i][j].R * h[i][j];

			g += window[i][j].G * h[i][j];

			b += window[i][j].B * h[i][j];

		}

	}

	rgb_pixel output;

	output.R = r / 16;

	output.G = g / 16;

	output.B = b / 16;

	return output;

}

void vs(rgb_pixel pixel_in[MAX_HEIGHT][MAX_WIDTH],

					rgb_pixel pixel_out[MAX_HEIGHT][MAX_WIDTH]) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=pixel_in
#pragma HLS INTERFACE axis register both port=pixel_out


	rgb_pixel tempin[MAX_HEIGHT][MAX_WIDTH], tempout[MAX_HEIGHT][MAX_WIDTH];

	for(int i = 0; i<MAX_HEIGHT; i++){
		for(int j = 0; j<MAX_WIDTH; j++){
				tempin[i][j].R = pixel_in[i][j].R;
				tempin[i][j].G = pixel_in[i][j].G;
				tempin[i][j].B = pixel_in[i][j].B;
			}
	}

	rgb_pixel window[3][3];

for (int row = 0; row < MAX_HEIGHT; row++) {

	for (int col = 0; col < MAX_WIDTH; col++) {

			for (int i = 0; i < 3; i++) {

				for (int j = 0; j < 3; j++) {

					int wi = row + i - 1;

					int wj = col + j - 1;

					if (wi < 0 || wi >= MAX_HEIGHT || wj < 0 || wj >= MAX_WIDTH) {

						window[i][j].R = 0;

						window[i][j].G = 0;

						window[i][j].B = 0;

					} else

						window[i][j].R = tempin[wi][wj].R;
						window[i][j].G = tempin[wi][wj].G;
						window[i][j].B = tempin[wi][wj].B;

				}

			}

			if (row == 0 || col == 0 || row == (MAX_HEIGHT - 1) || col == (MAX_WIDTH - 1)) {

				tempout[row][col].R = 0;

				tempout[row][col].G = 0;

				tempout[row][col].B = 0;

			} else

				tempout[row][col] = filter(window);

		}

	}

	for(int i = 0; i<MAX_HEIGHT; i++){
		for(int j = 0; j<MAX_WIDTH; j++){
			pixel_out[i][j].R = tempout[i][j].R;
			pixel_out[i][j].G = tempout[i][j].G;
			pixel_out[i][j].B = tempout[i][j].B;
		}
	}

}

