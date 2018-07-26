#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<getopt.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  char *fvalue = NULL;
  char *nvalue = NULL;
  char *lvalue = NULL;
  int option;

  opterr = 0;


  while ((option = getopt(argc, argv, "f:n:l:")) != -1) // The : after the letters mean input is expected as an argument after those flags.
  {
    switch (option)
    {
      case 'f' : 
        fvalue = optarg;
        break;
        
      case 'n' : 
        nvalue = optarg;
        break;

      case 'l' : 
        lvalue = optarg;
        break;
      
      default:
        abort ();
    }
  }

  if (fvalue != NULL)
  {
    printf("%s\n", fvalue);
  }
  if (nvalue != NULL)
  {
    printf("%s\n", nvalue);
  }
  if (lvalue != NULL)
  {
    printf("%s\n", lvalue);
  }
  printf("%s\n", argv[optind]); // optdind is a remaining element in the array of argv chars. 
}
