#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<getopt.h>
#include<unistd.h>
#include<ctype.h>


int main(int argc, char** argv){
	int fflag = 0;
	int nflag = 0;
	int lflag = 0;
	int c;
	char * fvalue = NULL;
	char * nvalue = NULL;
	char * lvalue = NULL;

	while((c = getopt(argc, argv, "f:n:l:")) != -1) //the : following a letter means it takes an argument
	switch(c)
	{
	case 'f':
	fflag = 1;
	fvalue = optarg;
	break;
	case 'n':
	nflag = 1;
	nvalue = optarg;
	break;
	case 'l':
	lflag = 1;
	lvalue = optarg;
	break;
	}

	if(fflag)
	printf("%s\n",fvalue);
	if(nflag)
	printf("%s\n",nvalue);
	if(lflag)
	printf("%s\n",lvalue);


	/*optind is a remaining element in the array of argv chars . if there are additional characters in the 
	command line that are not addressed above, we can print them out by doing the below*/
	for(int i = optind; i <argc; i++)
	{
	printf("%s\n", argv[i]);
	}

	return 0;

}
