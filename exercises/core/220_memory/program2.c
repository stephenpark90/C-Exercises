#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 1024

int main(){

	FILE *fp = fopen("/usr/share/dict/words", "r");

	char buffer[N];
	char **dictionary;
	int count = 0;

	while(fgets(buffer, N, fp) != NULL) {
		count++;

		for(int x = 0; x < (sizeof(buffer) / sizeof(char)); x++)
		{
			if(buffer[x] == '\n')
			{
				buffer[x] = '\0';
				break;
			}
		}

		if(count == 1)
		{
			dictionary = (char**) malloc(sizeof(char*));
			*dictionary = (char*) malloc(sizeof(buffer) / sizeof(char));
			strncpy(*dictionary, buffer, (sizeof(buffer) / sizeof(char)));
		}
		else
		{
			dictionary = (char**) realloc(dictionary, sizeof(char*)*(count));
			*(dictionary + count - 1) = (char*) malloc(sizeof(buffer) /sizeof(char));
			strncpy(*(dictionary + count -1), buffer, (sizeof(buffer)/sizeof(char)));
		}
	}

	for(int y = 0; y < count; y++)
	{
		for(int z = 0; z < count; z++)
		{
			printf("Bob\n%s%s\n", dictionary[y], dictionary[z]);
		}
	}


	free(dictionary);

	return 0;


}
