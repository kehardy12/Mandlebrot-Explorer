#include <stdio.h>
#include "gfx.h"

#define MAXITER 1000

/* nice colors for mandelbrot set */
void set_color(int it)
{
	if (it == MAXITER)
	{
		gfx_color(0,0,0);
		return;
	}
	switch (it % 16)
	{
		case 0: gfx_color(66, 30, 15); break;
		case 1: gfx_color(25, 7, 26); break;
		case 2: gfx_color(9, 1, 47); break;
		case 3: gfx_color(4, 4, 73); break;
		case 4: gfx_color(0, 7, 100); break;
		case 5: gfx_color(12, 44, 138); break;
		case 6: gfx_color(24, 82, 177); break;
		case 7: gfx_color(57, 125, 209); break;
		case 8: gfx_color(134, 181, 229); break;
		case 9: gfx_color(211, 236, 248); break;
		case 10: gfx_color(241, 233, 191); break;
		case 11: gfx_color(248, 201, 95); break;
		case 12: gfx_color(255, 170, 0); break;
		case 13: gfx_color(204, 128, 0); break;
		case 14: gfx_color(153, 87, 0); break;
		case 15: gfx_color(106, 52, 3); break;
	}
}

int main()
{
	return 0;
}
