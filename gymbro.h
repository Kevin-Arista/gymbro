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

typedef struct {
        char name[25]; // anything
        char type[10]; // breakfast, lunch, dinner, snack
        char processed; // yes(y) or no(n);
        float grams; // in grams

        int calories; // auto                                 
        int year; // auto
        int month; // auto
        int day; // auto
        int hour; // auto
        int minute; // auto
} food;

typedef struct {
        int weight;
        meal food;
} workout;

typedef struct {

} log;
