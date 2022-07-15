//list.h
//ENSF 337 - Lab 8 Exercise B
//Quentin Jennings

#ifndef list_h
#define list_h
struct ListItem { //structure for the item in a node
    int year;
    double flow;
};

struct Node { //structure for a node in a linked list
    ListItem item;
    Node* next;
};

class FlowList { //class for the linked list
public:
    FlowList();
    void insert(const int srcYear, const double srcFlow);
    // A node will be created with a ListItem comprised of the input year and flow.
    // The new node will be inserted as to keep the order of the list by year.
    bool remove(const int srcYear);
    // The list will be traversed until a node with the year is found.
    // If said node exists, it is deleted and the before pointer is adjusted.
    // Returns true if node is removed, returns false otherwise.
    bool exists(const int srcYear)const;
    // Returns true if input number srcYear exists within the list.
    Node* getHead()const{return head;}
    // Getter function for head pointer

private:
    Node* head;
    // Pointer to the head of linked list
};

#endif
