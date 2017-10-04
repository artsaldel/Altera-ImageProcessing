#include <stdio.h>

volatile char *onchip_control = (char *) 0x000211ee; //Como escribo un char tiene que ser tipo char
volatile int *onchip_data_limits = (int *) 0x000211f8;
volatile int *onchip_data_old_image = (int *) 0x00021200; //Como escribo entero tiene que ser tipo int
volatile int *onchip_data_new_image = (int *) 0x00030900;

int main() {
	int pixel, pixel_mayor;
	while (1) {
		while (*onchip_control != 'B')
			// polling the control byte
			;
		int n = *(onchip_data_limits); // contiene el n
		int m = *(onchip_data_limits + 1); // contiene el m
		int i, j;
		int k = 0;

		while (k < n*m) {
			for (i = 2 + k; i < n+k - 2; i++) {
				pixel_mayor = *(onchip_data_old_image + i);
				for (j = i - 2; j <= i + 2; j++) {
					if (pixel_mayor < (pixel = *(onchip_data_old_image + j))) {
						pixel_mayor = *(onchip_data_old_image + j);

						if (i == 2 + k) {
							*(onchip_data_new_image + j) = pixel; //pixel actual

						} else if ((i != 2 + k) & (j == (i + 2))) {
							*(onchip_data_new_image + j) = pixel; //pixel actual
						}
					} else {
						if (i == 2+k) {
							*(onchip_data_new_image + j) = pixel; //pixel actual

						} else if ((i != 2+k) & (j == (i + 2))) {
							*(onchip_data_new_image + j) = pixel; //pixel actual
						}
					}
				}
				*(onchip_data_new_image + i) = pixel_mayor; //pixel centro
			}
			k = k + n;

		}

		*onchip_control = 'H'; // pass the control right to the host PC
	}
	return 0;
}
