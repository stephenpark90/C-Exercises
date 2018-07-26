#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
 * This is the practice test for C programming.
 * Enter your details below
 *
 * RANK: CPT
 * NAME: Moir, Andrew J
 * DATE: 20180712
 *
 * Add code to accomplish the task for each question.
 * Do not change the function prototypes given below.
 * You should include any header files needed by your answers. 
 * Follow instructions given by your instructor for submitting.
 * Do not move, remove, or modify the preprocessor statements (#ifdef/#endif)
 * You can perform a basic test of your code with "make checkit"
 * The basic tests will *NOT* check all possibilities to be checked by grading.
 */


#ifndef SUPPRESS_PRACTICE_QUESTION_1

/*
 * Correct the practice_q1 function so that properly computes the 
 * sum of all the parameters and returns it.
 * if (practice_q1(111, 222, 333, 444) != 1110)
 * {
 *   printf("Incorrect\n");
 * }
 */

long practice_q1(int parm1, int parm2, int parm3, int parm4)
{
  long sum = 0;
  sum = sum + parm1;
  sum += parm2;
  sum = sum + parm3;
  sum = sum + parm4;
  return sum;
}

#endif //SUPPRESS_PRACTICE_QUESTION_1


#ifndef SUPPRESS_PRACTICE_QUESTION_2
/*
 * For practice_q2, use the input to produce the desired output described below.
 * See the example call.
 * Parameters:
 * array is defined as an two dimensional integer array.
 *    The first dimension is allocated with arrayLen members.
 *    The second dimension is defined as 3 integers.
 * key is the first int in the second dimension that is sought.
 *
 * Steps to complete:
 * 1. Find the first member in the second dimension which matches the key parameter.
 * 2. Once the member is located, return the sum of all 3 integers in the second dimension.
 * 3. If the key is not found as the first integer in the second dimension, return -1.
 *
 * An illustrative example call:
 * int array[][3] = {{20,   61,  82},
 *                   {65,   19,  25},
 *                   {128, 325, 900},
 *                   {42, 165,   92},
 *                   {91, 78,   105},
 *                   {512, 22,   75}};
 * int arrayLen = sizeof(array)/sizeof(array[0]);
 * int key = 42;
 * int expected = 42 + 165 + 92;
 * if (practice_q2(array, arrayLen, key) != expected)
 * {
 *   printf("Incorrect\n");
 * }
 * NOTE: This code will not compile and run properly, it is only illustrative 
 * of the concept and what is expected.
 */

int practice_q2(int **array, int arrayLen, int key)
{
  for (int i = 0; i < arrayLen; i++)
  {
    for (int j = 0; j <= 2; j++)
    {
      if (array[i][j] == key)
      {
        int rowSum = array[i][0] + array[i][1] + array[i][2];
        return rowSum;
      }
    }
  }
  return -1;
//  return INT_MAX;  
}

#endif //SUPPRESS_PRACTICE_QUESTION_2


#ifndef SUPPRESS_PRACTICE_QUESTION_3
/*
 * For practice_q3, create a structure using the order and types specified.
 * The name of the structure members are NOT important, the ORDER and TYPE is.
 * Once the structure is created, create a pointer to this type on the heap 
 * and set the value of the members to those listed in the value column below.
 * 
 * Order  Type                             Value
 * -----  ----                             -----
 *  1     char array 31 bytes in length    "C programming for the LULZ"
 *  2     unsigned integer                 0xC0FFEE00
 *  3     float                            3.1415
 *  
 * Return the pointer you allocated without freeing it. 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *practice_q3()
{
  struct dataType
  {
    char c[31]; // char 31 bytes in length
    unsigned int i;
    float f;
  };

  // Creat a pointer to this type on the heap.
  struct dataType* structInstance = malloc(sizeof(struct dataType));
  
  // Assign values to the members.
  strcpy(structInstance->c, "C programming for the LULZ"); // A string literal is a pointer. You can't assign a ptr to an array. You Use strcpy to copy the contents of the string literal to array c. 
  structInstance->i = 0xC0FFEE00;
  structInstance->f = 3.1415;

  return structInstance; 
}

#endif //SUPPRESS_PRACTICE_QUESTION_3

#ifndef SUPPRESS_PRACTICE_QUESTION_4
/*
 * For practice_q4, read a line from the standard input stream (up
 * to 100 bytes in length) and print it out to the standard output 
 * stream. Read another line in (up to 100 bytes) and print it out
 * to the standard error stream. Ensure that only one new line is
 * present on the output. Return 0 to the caller upon completion 
 * unless an error occurs. If an error occurs, return 1.
 *
 * NOTE: No more than 100 bytes, including the newline, for each
 * call will be provided to your function.
 *
 * Assume your function will be called like this:
 * int main()
 * {
 *   practice_q4();
 *   return 0;
 * }
 */
int practice_q4()
{
  char input[100]; // A line up to 100 bytes in length.

  fgets(input, sizeof(input), stdin); // Point to an array of characters (input), take the size of it as the max # of characters to read, and do it from the standard input.
  fputs(input, stdout); // Print that line to the standard out.

  fgets(input, sizeof(input), stdin); // Read another line in.
  fputs(input, stderr); // Print to the standard error stream.

  if (input == NULL)
  {
    return 1; // If an error occurs, return 1. 
  }

  return 0; // If there is no error, return 0.
}


#endif //SUPPRESS_PRACTICE_QUESTION_4

#ifndef SUPPRESS_PRACTICE_QUESTION_5
/* 
 * For practice_q5, validate the input parameters and return a 
 * bit mask as specified:
 * if numericValue is positive, set return bit 0x1 to on(1).
 * if numericValue is zero, set return bit 0x2 to on(1).
 * if numericValue is negative, set return bit 0x4 to on(1).
 * if numericValue is even, set return bit 0x8 to on(1).
 *     Assume 0 is an even number for this exercise.
 * if numericValue is odd, set return bit 0x10 to on(1).
 * if message is NULL, set return bit 0x20 to on(1).
 * if message is not NULL and the length of message < 1, 
 *     set return bit 0x40 to on(1).
 * Return the composite number you created to the caller
 */
unsigned int practice_q5(int numericValue, char *message)
{
  int returnBit = 0;

  if (numericValue > 0)
  {
    returnBit |= 0x1; // Set bit 0x1 to ON.
  }
  else if (numericValue == 0)
  {
    returnBit |= 0x2; // Set bit 0x2 to ON.
  }
  else // numericValue is < 0
  {
    returnBit |= 0x4; // Set bit 0x4 to ON.
  }
  if (numericValue %2 == 0) // numericValue is even
  {
    returnBit |= 0x8; // Set bit 0x8 to ON.
  }
  else // numericValue is odd
  {
    returnBit |= 0x10; // Set bit 0x10 to ON.
  }
  if (message == NULL)
  {
    returnBit |= 0x20; // Set bit 0x20 to ON.
  }
  else if ((message != NULL) && (strlen(message) < 1))
  {
    returnBit |= 0x40; // Set bit 0x40 to ON.
  }

  return returnBit;
}

#endif //SUPPRESS_PRACTICE_QUESTION_5

