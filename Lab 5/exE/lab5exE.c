/* File: lab5exE.c
 * ENSF Fall 2020 - lab 5 - Exercise E
 */

#include "lab5exE.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    Point alpha = { "A1", 2.3, 4.5, 56.0 } ;
    Point beta = { "B1", 25.9, 30.0, 97.0 } ;
    printf ("Display the values in alpha, and beta: ");
    display_struct_point(alpha);
    display_struct_point(beta);
    
    Point *stp = &alpha;
    printf ("\n\nDisplay the values in *stp: ");
    display_struct_point(*stp);
    
    Point gamma = mid_point(stp, &beta, "M1");
    printf ("\n\nDisplay the values in gamma after calling mid_point function.");
    printf ("Expected result is: M1 <14.10, 17.25, 76.50>");
    
    printf("\n\nThe actual result of calling mid_point function is: ");
    display_struct_point(gamma);
    
    swap (stp, &beta);
    printf ("\n\nDisplay the values in *stp, and beta after calling swap function.");
    printf ("Expected to be:\nB1 <25.90, 30.00, 97.00>\nA1 <2.30, 4.50, 56.00>");
    
    
    printf("\n\nThe actual result of calling swap function is: ");
    display_struct_point(*stp);
    display_struct_point(beta);
    
    
    printf("\n\nThe distance between alpha and beta is: %.2f. ", distance(&alpha, &beta));
    printf ("(Expected to be: 53.74)");
    printf("\nThe distance between gamma and beta is: %.2f. ", distance(&gamma, &beta));
    printf ("(Expected to be: 26.87)");
    return 0;
}

void display_struct_point(const Point x)
{
    printf("\n%s <%.2lf, %.2lf, %.2lf>", x.label, x.x, x.y, x.z);
}


Point mid_point(const Point* p1, const Point* p2, const char* label)
{
    double midX, midY, midZ;
	int i;
	
	//calculations for middle coordinates: uses if/else statements depending on which of the two coordinates is higher to calculate midpoint accordingly
	if(p1 -> x < p2 -> x)
		midX = p1 -> x + (p2 -> x - p1 -> x) / 2;
	else
		midX = p2 -> x + (p1 -> x - p2 -> x) / 2;
	
	if(p1 -> y < p2 -> y)
		midY = p1 -> y + (p2 -> y - p1 -> y) / 2;
	else
		midY = p2 -> y + (p1 -> y - p2 -> y) / 2;
	
	if(p1 -> z < p2 -> z)
		midZ = p1 -> z + (p2 -> z - p1 -> z) / 2;
	else
		midZ = p2 -> z + (p1 -> z - p2 -> z) / 2;
	
    Point middle;

	for(i = 0; label[i] != '\0'; i++) //simple loop that copies label into middle
		middle.label[i] = label[i];
	middle.label[i] = '\0'; //then adds a null at the end to make it a proper string
	
	//sets the Point's coordinates to the calculated midpoints
	middle.x = midX;
	middle.y = midY;
	middle.z = midZ;
    
    return middle;
}

void swap(Point* p1, Point *p2)
{
	int i;
	Point temp;
	
	//copies p1 into a temporary point
	temp.x = p1 -> x;
	temp.y = p1 -> y;
	temp.z = p1 -> z;
	
	for(i = 0; p1 -> label[i] != '\0'; i++)
		temp.label[i] = p1 -> label[i];
	temp.label[i] = '\0';
	
	//copies p2 into p1
	p1 -> x = p2 -> x;
	p1 -> y = p2 -> y;
	p1 -> z = p2 -> z;
	
	for(i = 0; p2 -> label[i] != '\0'; i++)
		p1 -> label[i] = p2 -> label[i];
	p1 -> label[i] = '\0';
	
	//copies temp into p2
	p2 -> x = temp.x;
	p2 -> y = temp.y;
	p2 -> z = temp.z;
	
	for(i = 0; temp.label[i] != '\0'; i++)
		p2 -> label[i] = temp.label[i];
	p2 -> label[i] = '\0';
}

double distance(const Point* p1, const Point* p2)
{
	//a simple equation using math functions and pointer notation can replicate the calculation easily in one line, nice!
	return sqrt(pow(((*p1).x - (*p2).x), 2) + pow(((*p1).y - (*p2).y), 2) + pow(((*p1).z - (*p2).z), 2));
}

