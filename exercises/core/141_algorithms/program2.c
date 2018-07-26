#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void plotLineLow(int x0,int y0, int x1,int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;

	if(dy < 0)
	{
		yi = -1;
		dy = -dy;
	}

	int D = 2*dy - dx;
	int y = y0;

	for(int x = x0; x <= x1; x++)
	{
		printf("%d,%d\n", x, y);

		if(D > 0)
		{
			y = y + yi;
			D = D - 2*dx;
		}
		D = D + 2*dy;
	}
}

void plotLineHigh(int x0,int y0, int x1,int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;

	if(dx < 0)
	{
		xi = -1;
		dx = -dx;
	}

	int D = 2*dx - dy;
	int x = x0;


	for(int y = y0; y <= y1; y++)
	{
	printf("%d,%d\n",x,y);
		if(D > 0)
		{
			x = x + xi;
			D = D - 2*dy;
		}
		D = D + 2*dx;
	}
}

void plotLine(int x0, int y0, int x1, int y1)
{
	if(abs(y1 - y0) < abs(x1 - x0))
	{
		if(x0 > x1)
		{
			plotLineLow(x1, y1, x0, y0);
		}
		else
		{
			plotLineLow(x0, y0, x1, y1);
		}
	}
	else
	{
		if(y0 > y1)
		{
			plotLineHigh(x1, y1, x0, y0);
		}
		else
		{
			plotLineHigh(x0, y0, x1, y1);
		}
	}
}



int main(void)
{
  srand((unsigned)time(NULL));
  int x0 = rand()%100;
  int y0 = rand()%100;
  int x1 = rand()%100;
  int y1 = rand()%100;

  /* Student Implementation */
  //printf("%d,%d\n", x0, y0);
plotLine(x0, y0, x1, y1);




  return EXIT_SUCCESS;
}
