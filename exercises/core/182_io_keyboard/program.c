#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int alphaOnly(char* string)
{
  int return_value = 1; // Default boolean to true.
  if (strlen(string) < 1)
  {
    return 0; // Invalid length.
  }
  for (int i = 0; i < strlen(string); i++)
  {
    if (!isalpha(string[i]))
    {
      return_value = 0; // Boolean is false. String contains non-alphabet characters.
    }
  }
  return(return_value);
}

void string_tolower(char* string)
{
  for (int i = 0; i < strlen(string); i++)
  {
    string[i] = tolower(string[i]); // Use the standard C library to change the case to lowercase for each letter in the string.
  }
}

int main(void)
{
  char input[16]; // Input must not exceed 15 characters plus the newline and null character.

  do
  {  
    printf("I’ve spun your straw into gold now guess my name: "); // Prompt the user.
   
    if (fgets(input, sizeof(input), stdin) != NULL) // If the input is not empty,
    {
      input[strcspn(input, "\n")] = 0; // Remove the newline character

      if (!alphaOnly(input)) // If the input is not alphabet-only.
      {
        printf("Invalid input, try again!\n"); // User entered a number.
      }
      else // User's input is not empty and is not a number.
      {
        string_tolower(input); // Change the input to all lowercase.
        if (strcmp(input, "rumpelstiltskin") != 0)
        {
          printf("Wrong, try again!\n"); // Entry is valid but not "Rumpelstiltskin".
        }
      }
    }
    else
    {
      fprintf(stderr, "READ ERROR!\n"); // User input is empty.
      return (EXIT_FAILURE);
    }
  }
  while (strcmp(input, "rumpelstiltskin") != 0); // Loop while input is not "Rumpelstiltskin".
  printf("Who told you!\n"); // User entered "Rumpelstiltskin".
  return (EXIT_SUCCESS);
}
