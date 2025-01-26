#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "gymbro.h"
#define EOF (-1)
#define TRUE 1
#define FALSE 0
// #define NULL (void *)0


// TODO: fix logic, so we return error msg in else block
int isFlag(char *arg){
	int boolean = FALSE;

	if( arg[0] == '-' && arg[1] != '-' ){
		boolean = TRUE;
	}
	return boolean;
}

int isValidFlag(char *arg){
	int boolean = FALSE;
	int len = sizeof(flags) / sizeof(flags[0]);

	for( int i = 0; i < len; i++ ){
		if( strcmp(arg, flags[i]) == 0 ){
			boolean = TRUE;
		}
	}
	return boolean;
}

int validFlagArgs(){return 0;}

int isKey(char *arg){
	int boolean = FALSE;
	if( arg[0] == '-' && arg[1] == '-' ){
		boolean = TRUE;
	}
	return boolean;
}

int isValidKey(char *arg){
	int boolean = FALSE;
	int len = sizeof(keys) / sizeof(keys[0]);

	for( int i = 0; i < len; i++ ){
		if( strcmp(arg, keys[i]) == 0 ){
			boolean = TRUE;
		}
	}
	return boolean;
}

int main(int argc, char *argv[]){
	extern const char *keys[];
	extern const char *flags[];
	const char *filename = "help.txt";
	
	if( argc == 1 ){
		fprintf(stderr, "Missing program arguments.\n");
		fprintf(stderr, "For help:\n./gymbro --help\n");
		return 1; 
	}
	else if( (argc == 2) && (strcmp(argv[1],"--help") ==  0) ){
		FILE *fp = fopen(filename, "rb");
		
		if(fp == NULL){
			fprintf(stderr, "[Err No. %d] %s\n", errno, strerror(errno));
			return 1;
		}

		char * buff;
		buff = malloc(sizeof(char) * 10);
		memset( buff, '\0', sizeof(char) * 10);
		// sizeof(buff) will be size of pointer
		int buff_size = 0;

		fseek(fp, 0L, SEEK_END);
		if( ftell(fp) == 0 ){
			// help.txt is empty
			fprintf(stderr, "File: %s is empty.\n", filename);
			return 1;
		}
		else{
			fseek(fp, 0L, SEEK_SET);
			while (!feof(fp)){	
				if( fgets(buff, 10, fp) != NULL ){
					buff_size = strlen(buff);
					fwrite(buff, sizeof(char), buff_size, stdout);
				}
			}		
		}

		free(buff);
		fclose(fp);
		return 0;
	}
	else{
		for(int i = 1; i < argc; i++){
			if( isFlag(argv[i]) ){
				if( isValidFlag(argv[i]) ){
					if( validFlagArgs() ){
						printf("Recorded.\n");
					}
					else{
						fprintf(stderr, "Incorrect usage of flag argument.\n\n");
						fprintf(stderr, "To list all available flags:\n./gymbro --help\n");
					}
				}
				else{
					fprintf(stderr, "Flag does not exist.\n\n");
					fprintf(stderr, "To list all available flags:\n./gymbro --help\n");
				}
			}
			else if( isKey(argv[i]) && isValidKey(argv[i]) ){
				printf("Input type: keyword\n");
			}
			else{
				printf("Input type: parameter\n");
				//check if a struct has been initiated, check if a keyword or flag has been initiated
			}
		}
		return 0;
	}
	return 1;
}
