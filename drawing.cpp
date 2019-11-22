
#include <iostream>
#include <cmath>
#include <unistd.h>

extern "C" {
#include "gfx.h"
}

void draw_polygon(int *x, int *y, int n, bool closed = false)
{
	for (int i = 0; i < n - 1; i ++)
		gfx_line(x[i],y[i],x[i+1],y[i+1]);
	if (closed)
		gfx_line(x[0],y[0],x[n-1],y[n-1]);
}

void draw_circle(int xc, int yc, int radius)
{
	int x[18];
	int y[18];
	for (int i = 0; i < 18; i++)
	{
		double angle = i*20.0*3.14159/180.0;
		x[i] = xc + cos(angle)*radius;
		y[i] = yc + sin(angle)*radius;
	}

	draw_polygon(x, y, 18, true);
}

int draw_state(int x, int y)
{
	gfx_clear();

	gfx_color(255, 255, 0);
	draw_circle(x, y, 50);

	gfx_color(0, 255, 0);
	draw_circle(x, y, 40);

	gfx_color(0, 255, 255);
	draw_circle(x, y, 30);

	gfx_color(255, 0, 255);
	draw_circle(x, y, 20);
}

int main()
{
	gfx_open(500, 500, "My first window");

	int x = 50;
	int y = 50;
	while(true)
	{
		
		if (gfx_event_waiting())
		{
			int button = gfx_wait();
			std::cout << "got event: " << button << std::endl;
			if (button == 'x')
				break;
		}
		else
		{
			x = x + 1;
			y = y + 1;
			if (x > 500) x = 10;
			if (y > 500) y = 10;

			usleep(10000);
			draw_state(x, y);
		}
	}

	return 0;
}

