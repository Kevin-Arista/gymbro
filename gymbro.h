#ifndef GYMBRO_H 
#define GYMBRO_H

// "array of pointers that point to characters"
const char *keys[] = {"--weight", "--food", "--journal", "--exercise"};

// an array of pointers to character value (may end until we reach null terminator)
const char *flags[] = {"-W", "-F", "-J", "-E"};

typedef struct {
	const char *key;
	const char *flagv[];
} action;

#endif
