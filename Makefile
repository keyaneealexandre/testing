# Makefile for project 1
#
# You should not need to modify this file.

CC		= gcc

CFLAGS		= -g  -Wall -std=c99

CLIBS		=

all: problem1 problem2 problem3

problem1: problem1.c
	$(CC) $(CFLAGS) -o problem1 problem1.c

problem2: problem2.c bst.o bst.h
	$(CC) $(CFLAGS) -o problem2 problem2.c bst.o

problem3: problem3.c
	$(CC) $(CFLAGS) -o problem3 problem3.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

clean:
	rm -f *~ *.o a.out core problem1 problem2 problem3 bst.o *.o

run_problem1:
	./problem1

run_problem2:
	./problem2

run_problem3:
	./problem3


test_problem1:
	valgrind ./problem1

test_problem2:
	valgrind ./problem2

test_problem3:
	valgrind ./problem3
