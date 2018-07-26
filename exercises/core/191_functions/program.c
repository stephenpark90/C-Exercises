#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int compare(const void* a, const void* b);

int main(void)
{
  int array[1024] = { 0 };

  /* Fill array with random numbers */
  srand((unsigned)time(NULL));

  int index;
  for(index = 0; index < 1024; index++)
    array[index] = rand() % 100;
  /* ------------------------------- */

  /* Student implementation */
	qsort(array, 1024, sizeof(int), compare);
	for(index = 0; index < 1024; index++)
	{
		printf("%d\n", array[index]);

	}


  return 0;
}

int compare(const void* a, const void* b)
{
/* Student implementation */
return (*(int*)b - *(int*)a);
}
