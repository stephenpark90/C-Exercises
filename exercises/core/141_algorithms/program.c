#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(void)
{
  srand((unsigned)time(NULL));
  int x0 = rand()%100;
  int y0 = rand()%100;
  int x1 = rand()%100;
  int y1 = rand()%100;

  /* Student Implementation */
  //printf("%d,%d\n", x0, y0);

  signed int dx = x1 - x0;
  signed int dy = y1 - y0;
  signed int D = (2*dy) - dx;
  signed int y = y0;
 
    for (int x = x0; x < x1; x++)
    { 
      printf("%d,%d\n", x, y);
      if (D > 0)
      {
        y = y + 1;
        D = D - (2*dx);
      }
      D = D + (2*dy);
    }

  printf("%d,%d\n", x1, y1);
  return EXIT_SUCCESS;
}
