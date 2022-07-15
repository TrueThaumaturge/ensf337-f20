/*
 *  lab3exe_C.c
 *  ENSF 337, lab3 Exercise C
 *
 *  In this program the implementatiom of function pascal_trangle is missing.
 *  Studtent must complete this function.
 */

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
 PROMISES: displays a pascal_triangle. the first 5 line of the function's output
 should have the following format:
 row 0:  1
 row 1:  1   1
 row 2:  1   2   1
 row 3:  1   3   3   1
 row 4:  1   4   6   4   1
 */

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);
    if(nrow <= 0 || nrow > 20) {
        printf("Error: the maximum number of rows can be 20.\n");
        exit(1);
    }

    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) {
    //variable declaration - 2 arrays with a starting value of 1 and every other value equal to 0
    int prevRow[20] = {1};
    int curRow[20] = {1};
    int temp; //used to store

    for(int i=0; i < n; i++) //2d loop - i represents row number
    {
        printf("row %d:\t", i); //prints row label

        for(int j = 0; j <= i; j++) //2d loop - j represents column number
        {
            curRow[j] = prevRow[j-1] + prevRow[j]; //calculates the current number by adding the two numbers from the previous row
            printf("%d\t", curRow[j]); //then prints said number
        }
        printf("\n");

        //copies the current row into the previous row AFTER all the values are printed - when we move on to the next row the current row becomes the previous, makes sense?
        for(int j=0; j <=i; j++)
            prevRow[j] = curRow[j]; //sets each value individually
    }
}
