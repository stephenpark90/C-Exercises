/*******************************************************************************
*  FILE NAME : 117_fgets.c
*  AUTHOR : Jason Enochs 
*  CREATION DATE : 10-May-2017
*  LAST MODIFIED : 28-Feb-2018
*  DESCRIPTION : 
*
*******************************************************************************/
#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char line[256];
    char i = '5';
    do
    {
    	printf("\nPlease enter a character: ");
    	if (fgets(line, sizeof(line), stdin) != NULL) 
    	{
            if (1 == sscanf(line, "%c", &i)) 
	    {
                printf("\nYou entered %c\n", i);
            }
    	}
        else
            return 1;
    }while(!isalpha(i));

    return 0;
}
