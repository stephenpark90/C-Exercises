#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

int main(void)
{
  srand((unsigned)time(NULL));
  char text[41] = { '\0' };
  int index;
  for(index = 0; index < 40; index++)
  {
    if( rand() % 2 ) // 0 or 1, uppercase or lowercase
      text[index] = rand() % 26 + 65; // uppercase
    else
      text[index] = rand() % 26 + 97; // lowercase
  }

  /* Student implementation */

  for (index = 0; index < 40; index++)
  {
    if ((text[index] >= 97) && (text[index] <= 109)) // If the letter is lowercase a-m,
    {
      //printf("before rot13: %c\n", text[index]);
      text[index] = text[index] + 13; 
    }
    else if ((text[index] >= 110) && (text[index] <= 122))
    {
      text[index] = text[index] - 13;
    }
    else if ((text[index] >= 65) && (text[index] <= 77))
    {
      text[index] = text[index] + 13;
    }
    else if ((text[index] >= 78) && (text[index] <= 90))
    {
      text[index] = text[index] - 13;
    }
    printf("%c", text[index]);
  }
  return 0;
}
