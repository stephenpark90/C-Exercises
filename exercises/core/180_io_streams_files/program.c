#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINESIZE 256 // 256 is a magic number. It is not expected to have more than 256 char per line.

int main()
{
  FILE *file;
  char line[LINESIZE]; // Define an array of characters of length [256] for each line.

  // Open the file.
  file = fopen("sshd_config", "r");

  if (file == NULL)
  {
    printf("Could not open the file.");
    return 0;
  }

  while (fgets(line, sizeof line, file) != NULL) // Point to an array of characters, take the size of it as the max # of characters to read, and do it from the file.
  {
    if ((line[0] != '#') && (line[0] != '\n')) // If the line does not start with a # or is a blank line,
    {
      fputs(line, stdout); // Write the line.
    }
  }

  // Close the file.
  fclose(file);

  return 0;
}
