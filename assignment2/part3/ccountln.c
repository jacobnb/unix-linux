/*Get arguments from argv, if no arguments then usage() {Usage: ./ccountln source1.c [source2.h] ...}
reserve vars: fileBuf = 2-4k chars, linesOfText = int, wordsNo = int

void scan(int fid); //for each filename arg, open() the file, get the fid, and scan fid, else print error perror() call close when done.
read() into buffer, scan buffer, keep track of lines and words.*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BSIZE 4000 /*enough buffer for 4k chars*/

void scan(int fid); /*load and scan info from a file*/
void usage(void); /*print usage information*/
/* Global Vars */
char fileBuf[BSIZE + 1];
int linesOfText=0;
int wordsNo=0;

int main(int argc, char* argv[]){
	int i;
	int fid;
	if(argc <=1){
		usage();
		return 0;
	}
	for(i = 1; i < argc; i = i+1){
		fid = open(argv[i], O_RDONLY);
		if(fid < 0)
			perror(argv[i]);
		else
			scan(fid);
	} 

	printf("Lines of Text: %i\n", linesOfText);
	printf("Words        : %i\n", wordsNo);
	printf("ccountln terminates.\n");
	return 0;
}

void scan(int fid){
	ssize_t nbytes; /*for read()*/
	int i;
	char c; /*character to avoid accessing array element repeatedly. not sure if faster */
	/*read() into buffer scan buffer, move to next*/
	int previousCharNotSpace = 0;
	while(1){ 	
		nbytes = read(fid, fileBuf, BSIZE);
		if(nbytes == 0)/*eof*/
			return;
		for(i = 0; fileBuf[i] != '\0'; i++){
			c = (char)fileBuf[i]; 
			/*Counts the number of lines, will be more than or equal to wc*/
			if(c == '\n')
				linesOfText++;

			/*Counts the number of words, even accounting for multiple spaces does not perfectly match wc. On longer files this will be more than or equal to wc*/
			if(c == ' ' || c == '\n' || c == '\r' || c == '\t'){
				if(previousCharNotSpace){
					wordsNo++;
					previousCharNotSpace = 0;
				}
			}
			else{
				previousCharNotSpace = 1;
			}
		}
	}
}
void usage(){
	printf("Usage: ./ccountln source1.c [source2.h] ...\n");
}
