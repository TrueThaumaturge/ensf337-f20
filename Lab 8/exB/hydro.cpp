//hydro.cpp
//ENSF 337 - Lab 8 Exercise B
//Quentin Jennings

#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
using namespace std;

#include "hydro.h"

#define VERSION "1.0"
#define LABSECTION "03"
#define PROGRAMNAME "Flow Studies - Fall 2020"
#define FILENAME "flow.txt"

int main(void)
{
    FlowList List;
    int numRecords;

    displayHeader();
    numRecords = readData(List);

    while(1)
    {
        switch(menu())
        {
            case 1: //displays flow list and avg
                display(&List, numRecords);
                break;
            case 2: //adds a data node to list
                addData(&List, numRecords);
                break;
            case 3: //saves data into file
                saveData(&List);
                break;
            case 4: //removes a data node from list
                removeData(&List, numRecords);
                break;
            case 5: //terminates program
                cout << "\nProgram terminated.\n";
                return 0;
            default: //invalid input
                cout << "\nError: Invalid input. (should be 1, 2, 3, 4, or 5)\n";
                break;
        }
        //clears the stream and waits for a response after each selection
        clearCin();
        pressEnter();
    }
}

void displayHeader()
{
    cout << "Program: " << PROGRAMNAME << endl;
    cout << "Version: " << VERSION << endl;
    cout << "Lab Section: B" << LABSECTION << endl;
    cout << "Produced By: Quentin Jennings" << endl;
    pressEnter();
}

void pressEnter()
{
    cout << "\n<<< Press Enter to Continue >>>\n";
    cin.get();
}

int readData(FlowList& source)
{
    ifstream inStream (FILENAME);
    if(inStream.fail())
    {
        cout << "Error: File " << FILENAME << " not found, could not read data. Closing program.\n";
        exit(-1);
    }

    int yr;
    double fl;
    int num = 0;

    while(!inStream.eof())
    {
        inStream >> yr;
        inStream >> fl;
        source.insert(yr, fl);
        num++;
    }
    inStream.close();

    return num;
}

int menu()
{
    cout << "Please select one of the following operations:\n";
    cout << "1. Display flow list and the average flow.\n";
    cout << "2. Add data to the flow list.\n";
    cout << "3. Save data into file.\n";
    cout << "4. Remove data from the flow list.\n";
    cout << "5. Quit Program.\n";
    cout << "\nEnter your choice (1, 2, 3, 4, or 5):\n";

    int n = 0;
    cin >> n;
    return n;

}

void display(const FlowList* source, int num)
{
    cout << "Year:     Flow: (billions of cubic meters)\n";

    Node* current = source->getHead();
    while(current != 0)
    {
        cout << setw(10) << left << current->item.year << setiosflags(ios::fixed) << setprecision(2) << current->item.flow << endl;
        current = current->next;
    }

    cout << "\nThe annual average of the flow is: " << setiosflags(ios::fixed) << setprecision(2) << average(source, num) << endl;
}

double average(const FlowList* source, int num)
{
    double sum = 0;
    Node* current = source->getHead();

    while(current != 0)
    {
        sum += current->item.flow;
        current = current->next;
    }

    return sum / num;
}

void addData(FlowList* source, int &numRecords)
{
    int yr;
    double fl;

    cout << "\nPlease enter a year: ";
    cin >> yr;

    if(source->exists(yr))
    {
        cout  << "\nError: data already exists for the year " << yr << ".\n";
    }
    else
    {
        clearCin();
        cout << "Please enter the flow: ";
        cin >> fl;
        source->insert(yr, fl);
        numRecords++;
        cout << "\nNew data record inserted successfully.\n";
    }
}

void removeData(FlowList* source, int &numRecords)
{
    int yr;
    cout << "\nPlease enter a year: ";
    cin >> yr;

    if(source->remove(yr))
    {
        numRecords--;
        cout << "\nData node successfully removed.\n";
    }
    else
        cout << "\nData node not removed as no node was found for the year " << yr;


}

void saveData(const FlowList* source)
{
    ofstream outStream("flow.txt");
    if(outStream.fail())
    {
        cout << "Error: File output stream unsuccessful. Closing program.\n";
        exit(-1);
    }
    Node* current = source->getHead();
    while(current != 0)
    {
        outStream << setiosflags(ios::fixed) << setprecision(2) << current->item.year << "      " << current->item.flow << endl;
        current = current->next;
    }
    outStream.close();
    cout << "Data successfully saved into " << FILENAME << ".\n";
}

void clearCin()
{
    cin.clear();
    while((getchar()) != '\n');
}
