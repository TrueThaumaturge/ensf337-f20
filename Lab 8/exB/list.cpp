//list.cpp
//ENSF 337 - Lab 8 Exercise B
//Quentin Jennings
#include <iostream>
using namespace std;

#include <stdlib.h>
#include "list.h"

FlowList::FlowList(): head(0) {}

void FlowList::insert(const int srcYear, const double srcFlow)
{
    //creates the new node to be inserted
    Node* newNode = new Node;
    newNode->item.year = srcYear;
    newNode->item.flow = srcFlow;

    //special case needed for if the node is first - the node becomes the new head and the head comes after it
    if(head == 0 || srcYear <= head->item.year)
    {
        newNode->next = head;
        head = newNode;
    }
    //otherwise finds where it needs to be inserted and adjusts next pointers
    else
    {
        Node *before = head; //the node before the new node
        Node *after = head->next; //the node after the new node
        while(after != 0 && srcYear > after->item.year) //traverses to needed location
        {
            before = after;
            after = after->next;
        }
        newNode->next = after;
        before->next = newNode;
    }
}

bool FlowList::remove(const int srcYear)
{
    //if the list is empty, do nothing
    if(head == 0 || srcYear < head->item.year)
    {
        return false;
    }

    Node *delete_this = 0;
    //if the head needs to be deleted
    if(srcYear == head->item.year)
    {
        delete_this = head;
        head = head->next;
    }
    //otherwise, checks the rest of the list and marks the node to be deleted if found
    else
    {
        Node *before = head;
        Node *current = head->next;
        while(current != 0 && srcYear > current->item.year)
        {
            before = current;
            current = current->next;
        }
        if(current != 0 && current->item.year == srcYear)
        {
            before->next = current->next;
            delete_this = current;
        }
    }

    if(delete_this==0)
        return false;
    else
    {
        free(delete_this);
        return true;
    }
}

bool FlowList::exists(const int srcYear)const
{
    //checks head first
    if(srcYear == head->item.year)
        return true;
    //then checks rest of list, similar to remove function
    else
    {
        Node* current = head->next;
        while(current != 0 && srcYear > current->item.year)
            current = current->next;
        if(current != 0 && current->item.year == srcYear)
            return true;
    }
    return false;
}
