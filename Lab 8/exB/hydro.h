//hydro.h
//ENSF 337 - Lab 8 Exercise B
//Quentin Jennings
#include "list.h"
#ifndef hydro_h
#define hydro_h
void displayHeader();
//displays intro screen

int readData(FlowList& source);
//reads and records years/flows into the flow list, returns # of records

int menu();
//displays the menu, returns user's choice (1-5)

void display(const FlowList* source, int num);
//displays the years, flows, and average of the flows (calls average)

void addData(FlowList* source, int &numRecords);
//prompts the user to enter new data, inserts data into linked list, updates # of records

void removeData(FlowList* source, int &numRecords);
//prompts user to indicate a year to be removed, removes it from the list, updates # of records

double average(const FlowList* source, int num);
//returns average flow of given list

void saveData(const FlowList* source);
//opens flow.txt file for writing and writes contents of linked list into the file in same format

void pressEnter();
//prompts user to press enter to continue, uses cin.get() to stall

void clearCin();
//clears the cin stream

#endif
