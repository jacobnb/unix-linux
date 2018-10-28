#Compiler and compiler flags
CC=gcc
CFLAGS = -g -Wall -pedantic -Wmissing-declarations -Wmissing-prototypes -D__EXTENSIONS__ -D_GNU_SOURCE
# -ansi disables c style comments
all: countln

countln: countln.o
	$(CC) $(CFLAGS) -o $@ $<
countln.o: countln.c
	$(CC) $(CFLAGS) -c countln.c
clean:
	rm countln.o countln

#not sure why this causes an error, but from everything I've read online it's a bad idea to include a run target in make.
#usage: make run ARGS=filename
run: countln 
	./countln $(ARGS)
