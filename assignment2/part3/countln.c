/*Get arguments from argv, if no arguments then usage() {Usage: ./ccountln source1.c [source2.h] ...}
reserve vars: fileBuf = 2-4k chars, linesOfText = int, wordsNo = int

void scan(int fid); //for each filename arg, open() the file, get the fid, and scan fid, else print error perror() call close when done.
read() into buffer, scan buffer, keep track of lines and words.*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BSIZE 128 /*should be enough for 3k+ chars */

void scan(int fid);

/* Global Vars */
char fileBuf[BSIZE + 1];
int linesOfText=0;
int wordsNo=0;
int main(int argc, char* argv[]){
	int i;
	int fid;
	for(i = 1; i < argc; i = i+1){
		fid = open(argv[i], O_RDONLY);
		if(fid < 0)
			perror(argv[i]);
		else
			scan(fid);
	} 
	return 0;
}
/*to print 
msg = (char*)strdup("Usage: shlnno filename\n");
		write(STDOUT_FILENO, msg, strlen(msg));
		free(msg);
*/


void scan(int fid){
	ssize_t nbytes; /*for read()*/
	/*read() into buffer scan buffer, move to next*/
	nbytes = read(fd, fileBuf, BSIZE);
	if(nbytes ==0){
		/*eof*/
	break;
	}
	


}
