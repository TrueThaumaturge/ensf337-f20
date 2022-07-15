// ENSF 337 - fall 2020 - lab 5 - exercise D
// M. Moussavi
// lab5exe_D.c

#include <stdio.h>
#include <stdlib.h>
#include "lab5exe_D.h"

int main(void) {
    char input_filename[30] = "lab5exe_D.txt";
    char output_filename[30]= "lab5exe_D_output.txt";
    IntVector intVec;
    intVec.number_of_data = 0;
    
    read_text_file(&intVec, input_filename);
    
    display_single_column(&intVec);
    
    display_multiple_column(&intVec, 4, output_filename);
    
    return 0;
}

void read_text_file (IntVector* vec, const char* input_filename){
    int nscan;
    FILE *fp = fopen (input_filename, "r");
    
    if(fp == NULL){
        fprintf(stdout, "Sorry cannot open the text file %s.\n", input_filename);
        exit(1);
    }
    
    do{
        nscan = fscanf(fp,"%d", &vec->storage[vec->number_of_data]);
        if(nscan == 1)
            (vec->number_of_data)++;
        else if (nscan != EOF){
            fprintf(stderr, "Invalid data in %s.\n", input_filename);
            exit(1);
        }
    }while ((nscan != EOF) & (vec->number_of_data < MAX_CAPACITY));
    
    fclose(fp);
}

void display_single_column(const IntVector* intV){
    int i;
    for (i = 0; i < intV ->number_of_data; i++ )
        printf("%10d\n", intV ->storage[i]);
}

void display_multiple_column(const IntVector *intV, int col, const char* output_filename)
{	
	int loopTrue = 1; //exit condition for do/while loop
	int indexNum = 0; //index variable used as part of nested for loop - keeps the index from the previous loop, used to print values
    FILE *fp = fopen(output_filename, "w"); //opens the output file for writing and creates file pointer fp
	
	if(fp == NULL){ //closes program if there's an error opening the file
        printf("Error: cannot open the text file %s. Exiting program.\n", output_filename);
        exit(1);
    }
	
	if(col > intV -> number_of_data) //if there are more columns than data points, sets the number of columns equal to the number of data points
		col = intV -> number_of_data;
		
	//nested print loop
	do{ //each loop marks a new row
		for(int j = 0; j < col; j++) //each j index marks a new column in the row	
		{
			if(indexNum >= (intV -> number_of_data)){ //breaks loop if the index passes the number of data (index starts at 0 so this statement works)
				loopTrue = 0;
				break;
			}
			fprintf(fp, "%10d\t", intV -> storage[indexNum]); //prints the current index in the storage followed by a tab		
			indexNum++; //increments index
		}
		fprintf(fp, "\n"); //starts new line at end of row
	}while(loopTrue); //loops until specific break condition is met
	
	fclose(fp); //closes file when done
}

