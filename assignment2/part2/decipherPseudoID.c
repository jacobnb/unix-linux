/*
Jacob Biederman
Assignment 2, Part 2:

Read in a realID from keyboard, convert from char array to an int (atoi?)
prompt the same way for low and high values of ranks (e.g. 1 and 10)
Accept all three arguments into the argument vector and skip interactive mode if given.
Compute pseudoID = ceiling[(ID/2.5+R)]*2 where R is a rank. Compute the formula for all the ranks from lowest to highest and output "pseudoID Rank" pairs one per line. Watch for rounding issues.
Bonus: Make it read a file with pseudo IDs and print the exact pseudo ID that uniqueily matches your real ID along side with the deciphered rank. Manually pre-populate a text file for this.

Concatenate the code and a sample output for your ID to a text file under a2/part2

*/
#include <stdio.h> //includes printf
#include <stdlib.h>
#include <math.h>
#define BSIZE 128

int computePseudo(const float id, const float rank);
int main (int argc, char* argv[]){
    int realID = 0;
    int lowRank = 0;
    int highRank = 0;
    if(argc == 4){ //first char* is null? probably points to self or callback.
        realID = atoi(argv[1]);
        lowRank = atoi(argv[2]);
        highRank = atoi(argv[3]);
    }
    else{

        char* input = (char *) malloc(1); //char * can hold a string, could change to char[]
        //malloc(1) is enough memory for ~26 chars, more than enough for the school id.
        printf("Please Enter your schoold ID: ");
        scanf("%s", input);
        realID = atoi(input);
        
        printf("Please Enter the low rank value: ");
        scanf("%s", input);
        lowRank = atoi(input);

        printf("Please enter the high rank value: ");
        scanf("%s", input);
        highRank = atoi(input);
        printf("Heres the input: %i\n", highRank);
        free(input);
        input = NULL;
    }
    int i = 0;
    for(i =0; i <= highRank; i = i+1){
        printf("%i ",computePseudo(realID, i));
        printf("%i\n",i);
    }

    
}

int computePseudo(const float id, const float rank){
    return ceil((id/2.5+rank))*2.0;
}
