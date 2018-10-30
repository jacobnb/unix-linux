#Compiler and compiler flags
CC=gcc
CFLAGS = -g -Wall -pedantic -Wmissing-declarations -Wmissing-prototypes -D__EXTENSIONS__ -D_GNU_SOURCE
# -ansi disables c style comments
all: ccountln

countln: ccountln.o
	$(CC) $(CFLAGS) -o $@ $<
countln.o: ccountln.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm ccountln.o ccountln

#not sure why this causes an error, but from everything I've read online it's a bad idea to include a run target in make. Additionally I couldn't find an example in the provided code of 'run'
#usage: make run ARGS=filename
run: ccountln 
	./ccountln $(ARGS)
