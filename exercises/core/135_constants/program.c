#include <stdio.h>
#include <stdlib.h>
#include "program.h"


// Don't alter the main function.  Modify the 'modify_me' function
int main(void)
{
    return modify_me();
}

int modify_me()
{
    system("clear"); // clear screen [optional]
   

    // YOUR CODE HERE
    #ifdef PT
      printf("Name: Platinum \n");
      printf("Symbol: Pt \n");
      printf("Atomic number: 78 \n");
    #endif


    #ifdef AU 
      printf("Name: Gold \n");
      printf("Symbol: Au \n");
      printf("Atomic number: 79 \n");
    #endif


    #ifdef AG
      printf("Name: Silver \n");
      printf("Symbol: Ag \n");
      printf("Atomic number: 47 \n");
    #endif
    return 0; // don't change this
}
