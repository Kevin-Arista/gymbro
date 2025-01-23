CC = gcc
CFLAGS = -g -Wall

gymbro: gymbro.o
	${CC} gymbro.o -o gymbro

gymbro.o: gymbro.c gymbro.h
	${CC} ${CFLAGS} -c gymbro.c 

.PHONY: clean

clean:
	rm -f *.o gymbro

.PHONY: all

all: clean gymbro
