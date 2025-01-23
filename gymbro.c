#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "gymbro.h"
#define EOF (-1)
// #define NULL void *0

int main(int argc, char *argv[]){
	extern const char *keys[];
	extern char flags[];

	const char *filename = "help.txt";
	
	if( argc <= 1 ){
		printf("For help:\n./gymbro --help\n");
		return 1; 
	}
	else if( strcmp(argv[1],"--help") ==  0 ){
		FILE *fp = fopen(filename, "rb");
		
		if(fp == NULL){
			printf("[Err No. %d] %s\n", errno, strerror(errno));
			return 1;
		}

		char * buff;
		buff = malloc(sizeof(char) * 10);
		memset( buff, '\0', sizeof(char) * 10);
		// sizeof(buff) will be size of pointer
		int buff_size = 0;

		while ( !feof(fp) ){	
			if( fgets(buff, 10, fp) != NULL ){
				buff_size = strlen(buff);
				fwrite(buff, sizeof(char), buff_size, stdout);
			}
		}
		free(buff);
		fclose(fp);
	}
	else{
		// we have an unknown number of args
		for(int i = 1; i < argc; i + 2){
			// check if keywords are valid keys!
				// even then, check if they have their proper flags!
			printf("yet to be implemented");
			return 0;
		}
	}
	
}
