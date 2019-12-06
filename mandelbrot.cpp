/*
 * 	Mandelbrot Set c++
 *	for ECE 231
 * 	First writen on November 22, 2019
 */

#include <iostream>
#include "Timer.h"
#include "vector"
#include "iostream"
extern "C"{
#include "gfx.h"
}
/*
   ==============
   Toggle complex
   ==============
   */

#define COMPLEX true
#if COMPLEX
#include "complex.h"
#endif

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800
#define MAX_ITERATIONS 100
/*

   =========================

   Julia Set (a,b) Constants

   =========================

*/

/*
 *
 * c = 1 − φ, 
 * c = (φ − 2) + (φ − 1)i = −0.4 + 0.6i
 * c = 0.285 + 0i Julia set for 
 * c = 0.285 + 0.01i  
 * c = 0.45 + 0.1428i  
 * c = −0.70176 − 0.3842i
 * c = −0.835 − 0.2321i
 * c = −0.8 + 0.156i
 * c = −0.7269 + 0.1889i 
 * c = −0.8i
 */

/*
   ==========================================
   completed function prototypes are all here
   ==========================================
*/

double getRange(int coordinates);
void drawSet(int n, int xPos, int yPos);
int getMandelbrot(int xPos, int yPos);
void insertJuliaConst(std::vector<Complex>&);
int getJuliaSet(int xPos,int yPos, double C_Real, double C_Imag);
int getJuliaSet_2nd(int xPos,int yPos, double C_Real, double C_Imag);
bool debug = false;

/*
   =============
   main function
   =============
*/

int main()
{
	std::vector<Complex> Julia_Const;
	insertJuliaConst(Julia_Const);
	gfx_open( WINDOW_WIDTH, WINDOW_HEIGHT, "Mandelbrot");
	std::cout << "\n\n	<< Use the up Arrow to move to the next Julia Set\n"

		     "	<< Use Space Bar for Mandelbrot set\n"

		     "	<< Use Down Arrow to see Tests\n"

		     "	<< To see More Read Line: 210\n"

		     "	<< Quit (q)\n\n";

	for (int xPos = 0; xPos < WINDOW_WIDTH; xPos ++)
	{
		for(int yPos = 0; yPos < WINDOW_HEIGHT; yPos ++)
		{
			int n = getMandelbrot(xPos,yPos);
			drawSet(n,xPos,yPos);
		}		
	}

	int num = 0;
	while(true)
	{
		if(gfx_event_waiting())
		{
			int button = gfx_wait();
			if(debug)
				std::cout << button << std::endl;
			if(button == 113) 
				break;
			if(button == 32)
			{
				for (int xPos = 0; xPos < WINDOW_WIDTH; xPos ++)
				{
					for(int yPos = 0; yPos < WINDOW_HEIGHT; yPos ++)
					{
						int n = getMandelbrot(xPos,yPos);
						drawSet(n,xPos,yPos);
					}
				}
			}

			if(button == 82)
			{
				for (int xPos = 0; xPos < WINDOW_WIDTH; xPos ++)
				{
					for(int yPos = 0; yPos < WINDOW_HEIGHT; yPos ++)
					{
						int n = getJuliaSet(xPos,yPos,Julia_Const[num].real(), Julia_Const[num].imag());
						drawSet(n,xPos,yPos);
					}
				}
				
			}

			if(button == 84)
			{
				std::cout << "\r[ Your Result ] \n ";
				for (int xPos = 0; xPos < WINDOW_WIDTH; xPos ++)
				{
					for(int yPos = 0; yPos < WINDOW_HEIGHT; yPos ++)
					{
						int n = getJuliaSet_2nd(xPos,yPos,Julia_Const[num].real(), Julia_Const[num].imag());
						drawSet(n,xPos,yPos);
					}
				}
			}
			num++;
			if(num == 10)
				num = 0;
		}
	}
	std::cout << std::endl;

	return 0;
}

/*
   =========
   Julia Set
   =========
*/
void insertJuliaConst(std::vector<Complex>& Julia_Const)

	Complex temp(1, -1);
	Complex temp1(-0.4, 0.6);
	Complex temp2(0.285, 0);
	Complex temp3(0.285, 0.01);
	Complex temp4(0.45, 0.1428);
	Complex temp5(-0.70176, -0.3842);
	Complex temp6(-0.835, -0.2321);
	Complex temp7(-0.8, 0.156);
	Complex temp8(-0.7269, 0.1889);
	Complex temp9(0,-0.8);

	Julia_Const.push_back(temp);
	Julia_Const.push_back(temp1);
	Julia_Const.push_back(temp2);
	Julia_Const.push_back(temp3);
	Julia_Const.push_back(temp4);
	Julia_Const.push_back(temp5);
	Julia_Const.push_back(temp6);
	Julia_Const.push_back(temp7);
	Julia_Const.push_back(temp8);
	Julia_Const.push_back(temp9);

}

int getJuliaSet(int xPos,int yPos, double C_Real, double C_Imag)
{
	int n = 0;
	double a = 0;
	double b = 0;
	a = getRange(xPos);
	b = getRange(yPos);

	while (n < MAX_ITERATIONS)
	{
		double aa = (a*a) - (b*b);
		double bb = 2*a*b;
		a = aa + C_Real;
		b = bb + C_Imag;
		if (abs(a+b) > 4)
		{
			break;
		}
		n++;
	}
	return n;
}

/*
   ====================================================
   Change the operator (+) to get an interesting result 
   ====================================================
*/
/**
 *	a = aa + C_Real; b = bb + C_Imag;
 * 	Lines: 242,243
 * 	look at your results using the down arrow.
 *
 **/

int getJuliaSet_2nd(int xPos,int yPos, double C_Real, double C_Imag)
{
	int n = 0;
	double a = 0;
	double b = 0;
	a = getRange(xPos);
	b = getRange(yPos);

	while (n < MAX_ITERATIONS)
	{
		double aa = (a*a) - (b*b);
		double bb = 2*a*b;
		a = aa + C_Real;		
		b = bb -  C_Imag;
		if (abs(a+b) > 4)
		{
			break;
		}
		n++;
	}
	return n;
}

// Change Color of The Mandelbrot/Julia Set by manipulating (n)

void drawSet(int n, int xPos, int yPos)
{
	double red = n*n*n % 255;          
	double green = (n * 3/2) % 256;    
	double blue = n / 2 % 255;
	gfx_color(red, green, blue);
	gfx_point(xPos,yPos);
}	

// Calculate range of Window
double getRange(int coordinates)
{
	return ((coordinates - 400) * .005);
}

#if !COMPLEX
// Not using Complex Class
int getMandelbrot(int xPos, int yPos)
{
	int n = 0;
	double a = 0;
	double b = 0;
	a = getRange(xPos);
	b = getRange(yPos);
	double ca = a;
	double cb = b;

	while (n < MAX_ITERATIONS)
	{
		double aa = (a*a) - (b*b);
		double bb = 2*a*b;
		a = aa + ca;
		b = bb + cb;
		if (abs(a+b) > 16.0)
		{
			break;
		}
		n++;
	}
	return n;
}

#else
// Using Complex Class

int getMandelbrot(int xPos, int yPos)
{
	int n = 0;
	Complex z((xPos - 400) * .005, (yPos - 400) * .005);
	Complex c = z;
	while( n < MAX_ITERATIONS )
	{
		z =  z*z + c;
		if(abs(z.real() + z.imag()) > 16)
			break;
		n ++;
	}
	return n;
}

#endif
