#include<stdio.h>

#define N 1024

int main(void){

	FILE *fp = fopen("sshd_config", "r");
	if(fp == NULL)
	{
		fprintf(stderr, "error: file did not exist\n");
		exit(EXIT_FAILURE);
	}

	char buffer[N];
	while(	fgets(buffer, N, fp) != NULL)
	{
		if(buffer[0] == '#' || buffer[0] == '\n')
		continue;
		else printf("%s", buffer);
	}
	fclose(fp);
	return 0;


}
