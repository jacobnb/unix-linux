#Compier and compiler flags
CC=gcc

#vpath = include directories
# use %.c to instead of *.c
# use \ to escape newline character.

#CFLAGS = -Wall -o hello.exe
all: hello.exe

hello.exe: hello.o
	gcc -o $@ $< #==hello.exe hello.o
hello.o: hello.c
	gcc -c hello.c
clean:
	rm hello.o hello.exe
