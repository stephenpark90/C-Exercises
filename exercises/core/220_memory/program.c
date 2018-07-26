#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DICTIONARY_SIZE 99171 // There are 99171 words in the dictionary file.

int main (void)
{
  // Define the variables.
  FILE *file;
  char line[20]; // Define an array of characters of length [20] for each line. We assume a word is not greater than 20 characters.
  char** dict = calloc(DICTIONARY_SIZE,sizeof(char*)); // Define the dict as an array of 99171 strings each the size of a char*.
  int index = 0; // Used for incrementing in the while loop.

  // Open the file.
  file = fopen("/usr/share/dict/words", "r");

  // If the file is null, then return an error and exit.
  if (file == NULL)
  {
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
  }

  // Populate the dictionary.
  while (fgets(line, sizeof line, file) != NULL) // Point to an array of characters, take the size of it as the max # of characters to read, and do it from the file.
  {
    line[strlen(line) - 1] = '\0'; // Remove the newline character from the line's array of characters.
    dict[index] = calloc(sizeof(char), sizeof(line)); // Allocate a char-size block of memory for the size of the line to the space for the next word in the dictionary array.
    strcpy(dict[index], line); // Copy the line in the dictionary file to the dictionary array.
    index++; // Increment the index value for the while loop.
  }

  // Print the dictionary.
  for (int i = 0; i < DICTIONARY_SIZE; i++)
  {
    for (int j = 0; j < DICTIONARY_SIZE - 1; j++)
    {
      printf("Bob\n%s%s\n", dict[i], dict[j]);
    }
  }

  // Free the memory we've allocated.
  for (int i =0; i < DICTIONARY_SIZE; i++)
  {
    free(dict[i]);
  }
  free(dict);

  // Close the file.
  fclose(file);

  return 0;
}
